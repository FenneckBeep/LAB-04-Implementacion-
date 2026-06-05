#include "Sistema.h"
#include "../Administra/Administra.h"
#include "../../Datatypes/DTPropietario/DTPropietario.h"
#include "../../Datatypes/DTInmobiliaria/DTInmobiliaria.h"
#include "../../Datatypes/DTInmueble/DTInmueble.h"
#include "../../Datatypes/DTInmuebleAdministrado/DTInmuebleAdministrado.h"
#include "../../Datatypes/DTPublicacion/DTPublicacion.h"
#include "../../Datatypes/DTDetalleInmueble/DTDetalleInmueble.h"
#include "../../ICollection/Integer.h"
#include "../../ICollection/String.h"
#include "../../ICollection/collections/List.h"
#include "../../ICollection/collections/OrderedDictionary.h"
#include "../../ICollection/interfaces/ICollectible.h"
#include "../../ICollection/interfaces/ICollection.h"
#include "../../ICollection/interfaces/IIterator.h"
#include <ctime>
#include <iostream>
#include <limits>

using namespace std;

namespace {
class ValorDiccionarioSeguro : public ICollectible {
public:
    ValorDiccionarioSeguro() {}
};

void destruirDiccionarioSeguro(IDictionary *diccionario) {
    if (diccionario == nullptr) {
        return;
    }
    if (diccionario->isEmpty()) {
        ValorDiccionarioSeguro *dummy = new ValorDiccionarioSeguro();
        diccionario->add(new Integer(-1), dummy);
        delete diccionario;
        delete dummy;
        return;
    }
    delete diccionario;
}
}

Sistema::Sistema()
    : usuarios(new OrderedDictionary()), inmuebles(new OrderedDictionary()),
      publicaciones(new OrderedDictionary()), inmobiliariaRecordada(nullptr),
      inmuebleRecordado(nullptr), propietarioRecordado(nullptr),
      superficieInmuebleRecordada(0), anioConstruccionRecordado(0),
      hayUsuarioRecordado(false), hayInmuebleRecordado(false),
      proximoIdInmueble(1), proximoIdPublicacion(1) {}

Sistema::~Sistema() {
    IIterator *itPub = publicaciones->getIterator();
    while (itPub->hasCurrent()) {
        delete dynamic_cast<Publicacion *>(itPub->getCurrent());
        itPub->next();
    }
    delete itPub;

    IIterator *itInm = inmuebles->getIterator();
    while (itInm->hasCurrent()) {
        delete dynamic_cast<Inmueble *>(itInm->getCurrent());
        itInm->next();
    }
    delete itInm;

    IIterator *itUsu = usuarios->getIterator();
    while (itUsu->hasCurrent()) {
        delete dynamic_cast<Usuario *>(itUsu->getCurrent());
        itUsu->next();
    }
    delete itUsu;

    destruirDiccionarioSeguro(publicaciones);
    destruirDiccionarioSeguro(inmuebles);
    destruirDiccionarioSeguro(usuarios);
}

Usuario *Sistema::buscarUsuario(string nickname)  {
    String *clave = new String((char*)nickname.c_str());
    Usuario *usuario = dynamic_cast<Usuario *>(usuarios->find(clave));
    delete clave;
    return usuario;
}

Inmueble *Sistema::buscarInmueble(int idInm)  {
    Integer *clave = new Integer(idInm);
    Inmueble *inmueble = dynamic_cast<Inmueble *>(inmuebles->find(clave));
    delete clave;
    return inmueble;
}

Publicacion *Sistema::buscarPublicacion(int idPub)  {
    Integer *clave = new Integer(idPub);
    Publicacion *publicacion = dynamic_cast<Publicacion *>(publicaciones->find(clave));
    delete clave;
    return publicacion;
}

DTFecha Sistema::obtenerFechaActual()  {
    time_t ahora = time(nullptr);
    tm *local = localtime(&ahora);
    if (local == nullptr) {
        return DTFecha();
    }
    return DTFecha(local->tm_mday, local->tm_mon + 1, local->tm_year + 1900);
}

bool Sistema::existeUsuario(string nickname)  {
    return buscarUsuario(nickname) != nullptr;
}

Status Sistema::existeUsuario(string nickname, string contrasenia,
                              string nombre, string email) {
    if (existeUsuario(nickname)) {
        hayUsuarioRecordado = false;
        return Status::ERROR;
    }
    nicknameRecordado = nickname;
    contraseniaRecordada = contrasenia;
    nombreRecordado = nombre;
    emailRecordado = email;
    hayUsuarioRecordado = true;
    return Status::OK;
}

Status Sistema::altaUsuario_Cliente(string apellido, string documento) {
    if (!hayUsuarioRecordado || existeUsuario(nicknameRecordado)) {
        hayUsuarioRecordado = false;
        return Status::ERROR;
    }
    usuarios->add(new String((char*)nicknameRecordado.c_str()),
                  new Cliente(nicknameRecordado, contraseniaRecordada, nombreRecordado,
                              emailRecordado, apellido, documento));
    hayUsuarioRecordado = false;
    return Status::OK;
}

Status Sistema::altaUsuario_Propietario(string cuentaBancaria, string telefono) {
    if (!hayUsuarioRecordado || existeUsuario(nicknameRecordado)) {
        hayUsuarioRecordado = false;
        return Status::ERROR;
    }
    usuarios->add(new String((char*)nicknameRecordado.c_str()),
                  new Propietario(nicknameRecordado, contraseniaRecordada, nombreRecordado,
                                  emailRecordado, cuentaBancaria, telefono));
    hayUsuarioRecordado = false;
    return Status::OK;
}

Status Sistema::altaUsuario_Inmobiliaria(string direccion, string telefono,
                                         string url) {
    if (!hayUsuarioRecordado || existeUsuario(nicknameRecordado)) {
        hayUsuarioRecordado = false;
        return Status::ERROR;
    }
    Inmobiliaria *inmobiliaria = new Inmobiliaria(nicknameRecordado, contraseniaRecordada,
                                                  nombreRecordado, emailRecordado, direccion,
                                                  telefono, url);
    usuarios->add(new String((char*)nicknameRecordado.c_str()), inmobiliaria);
    inmobiliariaRecordada = inmobiliaria;
    hayUsuarioRecordado = false;
    return Status::OK;
}

Status Sistema::altaCliente(string nickname, string contrasenia, string nombre,
                            string email, string apellido, string documento) {
    if (existeUsuario(nickname, contrasenia, nombre, email) == Status::ERROR) {
        return Status::ERROR;
    }
    return altaUsuario_Cliente(apellido, documento);
}

Status Sistema::altaPropietario(string nickname, string contrasenia, string nombre,
                                string email, string cuentaBancaria,
                                string telefono) {
    if (existeUsuario(nickname, contrasenia, nombre, email) == Status::ERROR) {
        return Status::ERROR;
    }
    return altaUsuario_Propietario(cuentaBancaria, telefono);
}

Status Sistema::altaInmobiliaria(string nickname, string contrasenia, string nombre,
                                 string email, string direccion, string telefono,
                                 string url) {
    if (existeUsuario(nickname, contrasenia, nombre, email) == Status::ERROR) {
        return Status::ERROR;
    }
    return altaUsuario_Inmobiliaria(direccion, telefono, url);
}

ICollection *Sistema::listarPropietarios() {
    ICollection *resultado = new List();
    IIterator *it = usuarios->getIterator();
    while (it->hasCurrent()) {
        Propietario *propietario = dynamic_cast<Propietario *>(it->getCurrent());
        if (propietario != nullptr) {
            resultado->add(new DTPropietario(propietario->getNickname(),
                                             propietario->getNombre()));
        }
        it->next();
    }
    delete it;
    return resultado;
}

Status Sistema::agregarPropietario(string nickname) {
    Propietario *propietario = dynamic_cast<Propietario *>(buscarUsuario(nickname));
    if (propietario == nullptr) {
        propietarioRecordado = nullptr;
        return Status::ERROR;
    }
    propietarioRecordado = propietario;
    return Status::OK;
}

Status Sistema::agregarInmueble(string direccion, string numPuerta,
                                int superficie, int anioConstruccion) {
    if (propietarioRecordado == nullptr || superficie <= 0 || anioConstruccion <= 0) {
        hayInmuebleRecordado = false;
        return Status::ERROR;
    }
    direccionInmuebleRecordada = direccion;
    numPuertaInmuebleRecordada = numPuerta;
    superficieInmuebleRecordada = superficie;
    anioConstruccionRecordado = anioConstruccion;
    hayInmuebleRecordado = true;
    return Status::OK;
}

int Sistema::agregarCasa(bool esHorizontal, TipoTecho techo) {
    if (!hayInmuebleRecordado || propietarioRecordado == nullptr) {
        return 0;
    }
    int id = proximoIdInmueble++;
    Inmueble *inmueble = new Casa(id, direccionInmuebleRecordada, numPuertaInmuebleRecordada,
                                  superficieInmuebleRecordada, anioConstruccionRecordado,
                                  propietarioRecordado, esHorizontal, techo);
    inmuebles->add(new Integer(id), inmueble);
    propietarioRecordado->vincularInmueble(inmueble);
    hayInmuebleRecordado = false;
    propietarioRecordado = nullptr;
    return id;
}

int Sistema::agregarApartamento(int numPiso, bool tieneAscensor, double gastosComunes) {
    if (!hayInmuebleRecordado || propietarioRecordado == nullptr) {
        return 0;
    }
    int id = proximoIdInmueble++;
    Inmueble *inmueble = new Apartamento(id, direccionInmuebleRecordada,
                                         numPuertaInmuebleRecordada,
                                         superficieInmuebleRecordada,
                                         anioConstruccionRecordado, propietarioRecordado,
                                         numPiso, tieneAscensor, gastosComunes);
    inmuebles->add(new Integer(id), inmueble);
    propietarioRecordado->vincularInmueble(inmueble);
    hayInmuebleRecordado = false;
    propietarioRecordado = nullptr;
    return id;
}

int Sistema::agregarCasa(string nicknamePropietario, string direccion,
                         string numPuerta, int superficie, int anioConstruccion,
                         bool esHorizontal, TipoTecho techo) {
    Propietario *propietario = dynamic_cast<Propietario *>(buscarUsuario(nicknamePropietario));
    if (propietario == nullptr) {
        return 0;
    }
    propietarioRecordado = propietario;
    if (agregarInmueble(direccion, numPuerta, superficie, anioConstruccion) == Status::ERROR) {
        propietarioRecordado = nullptr;
        return 0;
    }
    return agregarCasa(esHorizontal, techo);
}

int Sistema::agregarApartamento(string nicknamePropietario, string direccion,
                                string numPuerta, int superficie, int anioConstruccion,
                                int numPiso, bool tieneAscensor, double gastosComunes) {
    Propietario *propietario = dynamic_cast<Propietario *>(buscarUsuario(nicknamePropietario));
    if (propietario == nullptr) {
        return 0;
    }
    propietarioRecordado = propietario;
    if (agregarInmueble(direccion, numPuerta, superficie, anioConstruccion) == Status::ERROR) {
        propietarioRecordado = nullptr;
        return 0;
    }
    return agregarApartamento(numPiso, tieneAscensor, gastosComunes);
}

Status Sistema::representarPropietario(string nicknameInmobiliaria,
                                       string nicknamePropietario) {
    Inmobiliaria *inmobiliaria = dynamic_cast<Inmobiliaria *>(buscarUsuario(nicknameInmobiliaria));
    Propietario *propietario = dynamic_cast<Propietario *>(buscarUsuario(nicknamePropietario));
    if (inmobiliaria == nullptr || propietario == nullptr) {
        return Status::ERROR;
    }
    inmobiliaria->vincularPropietario(propietario);
    return Status::OK;
}

ICollection *Sistema::listarInmobiliarias() {
    ICollection *resultado = new List();
    IIterator *it = usuarios->getIterator();
    while (it->hasCurrent()) {
        Inmobiliaria *inmobiliaria = dynamic_cast<Inmobiliaria *>(it->getCurrent());
        if (inmobiliaria != nullptr) {
            DTInmobiliaria dt = inmobiliaria->obtenerDT();
            resultado->add(new DTInmobiliaria(dt.getNickname(), dt.getNombre()));
        }
        it->next();
    }
    delete it;
    return resultado;
}

ICollection *Sistema::listarInmuebles(string nickname) {
    Inmobiliaria *inmobiliaria = dynamic_cast<Inmobiliaria *>(buscarUsuario(nickname));
    if (inmobiliaria == nullptr) {
        inmobiliariaRecordada = nullptr;
        return new List();
    }
    inmobiliariaRecordada = inmobiliaria;
    return inmobiliaria->listarInmuebles();
}

ICollection *Sistema::listarInmueblesAdministrados(string nickname) {
    Inmobiliaria *inmobiliaria = dynamic_cast<Inmobiliaria *>(buscarUsuario(nickname));
    if (inmobiliaria == nullptr) {
        inmobiliariaRecordada = nullptr;
        return new List();
    }
    inmobiliariaRecordada = inmobiliaria;
    return inmobiliaria->listarInmueblesAdministrados();
}

Status Sistema::administrarInmueble(int idInm) {
    if (inmobiliariaRecordada == nullptr) {
        return Status::ERROR;
    }
    Inmueble *inmueble = buscarInmueble(idInm);
    if (inmueble == nullptr || inmueble->getPropietario() == nullptr) {
        return Status::ERROR;
    }
    if (!inmobiliariaRecordada->representa(inmueble->getPropietario())) {
        return Status::ERROR;
    }
    inmobiliariaRecordada->administrarInmueble(inmueble, obtenerFechaActual());
    return Status::OK;
}

Status Sistema::altaPublicacion(int idInm, TipoPublicacion tipo, string texto, double precio) {
    if (inmobiliariaRecordada == nullptr || precio <= 0) {
        return Status::ERROR;
    }
    Inmueble *inmueble = buscarInmueble(idInm);
    if (inmueble == nullptr) {
        return Status::ERROR;
    }
    Administra *administra = inmobiliariaRecordada->obtenerAdministracionDe(inmueble);
    if (administra == nullptr) {
        return Status::ERROR;
    }
    int idPub = proximoIdPublicacion;
    DTFecha fecha = obtenerFechaActual();
    if (!administra->puedePublicar(idPub, tipo, fecha)) {
        return Status::ERROR;
    }
    administra->desactivarPublicaciones(tipo);
    proximoIdPublicacion++;
    Publicacion *publicacion = new Publicacion(idPub, fecha, tipo, texto, precio, administra);
    publicaciones->add(new Integer(idPub), publicacion);
    administra->vincularPub(publicacion);
    return Status::OK;
}

ICollection *Sistema::listarPublicaciones(TipoPublicacion tipo, double min, double max,
                                          TipoInteres interes) {
    ICollection *resultado = new List();
    IIterator *it = publicaciones->getIterator();
    while (it->hasCurrent()) {
        Publicacion *pub = dynamic_cast<Publicacion *>(it->getCurrent());
        if (pub != nullptr && pub->cumpleFiltro(tipo, min, max, interes)) {
            string nombreInmobiliaria = "";
            if (pub->getAdministra() != nullptr && pub->getAdministra()->getInmobiliaria() != nullptr) {
                nombreInmobiliaria = pub->getAdministra()->getInmobiliaria()->getNombre();
            }
            DTPublicacion dt = pub->obtenerDT(nombreInmobiliaria);
            resultado->add(new DTPublicacion(dt.getIdPub(), dt.getFecha(), dt.getTipo(), dt.getTexto(),
                                             dt.getPrecio(), dt.getNombreInmobiliaria()));
        }
        it->next();
    }
    delete it;
    return resultado;
}

DTDetalleInmueble Sistema::consultarDetalleInmueble(int idPub) {
    Publicacion *pub = buscarPublicacion(idPub);
    if (pub == nullptr) {
        return DTDetalleInmueble();
    }
    return pub->obtenerDTDetalle();
}

ICollection *Sistema::listarInmuebles() {
    ICollection *resultado = new List();
    IIterator *it = inmuebles->getIterator();
    while (it->hasCurrent()) {
        Inmueble *inm = dynamic_cast<Inmueble *>(it->getCurrent());
        if (inm != nullptr) {
            string nombreProp = "";
            if (inm->getPropietario() != nullptr) {
                nombreProp = inm->getPropietario()->getNombre();
            }
            resultado->add(new DTInmueble(inm->getIdInm(), inm->getDireccion(), nombreProp));
        }
        it->next();
    }
    delete it;
    return resultado;
}

DTDetalleInmueble Sistema::ingresarCodigoInmueble(int idInm) {
    inmuebleRecordado = buscarInmueble(idInm);
    if (inmuebleRecordado == nullptr) {
        return DTDetalleInmueble();
    }
    return inmuebleRecordado->obtenerDTDetalle();
}

void Sistema::eliminarPublicacionesDe(Administra *administra) {
    if (administra == nullptr) {
        return;
    }
    ICollection *aEliminar = new List();
    IIterator *it = administra->getPublicaciones()->getIterator();
    while (it->hasCurrent()) {
        Publicacion *pub = dynamic_cast<Publicacion *>(it->getCurrent());
        if (pub != nullptr) {
            aEliminar->add(pub);
        }
        it->next();
    }
    delete it;

    it = aEliminar->getIterator();
    while (it->hasCurrent()) {
        Publicacion *pub = dynamic_cast<Publicacion *>(it->getCurrent());
        if (pub != nullptr) {
            Integer *clave = new Integer(pub->getIdPub());
            publicaciones->remove(clave);
            delete clave;
            administra->desvincularPub(pub);
            delete pub;
        }
        it->next();
    }
    delete it;
    delete aEliminar;
}

Status Sistema::eliminarInmueble() {
    if (inmuebleRecordado == nullptr) {
        return Status::ERROR;
    }

    Inmueble *inmueble = inmuebleRecordado;
    ICollection *admins = new List();
    IIterator *it = inmueble->getAdministraciones()->getIterator();
    while (it->hasCurrent()) {
        Administra *administra = dynamic_cast<Administra *>(it->getCurrent());
        if (administra != nullptr) {
            admins->add(administra);
        }
        it->next();
    }
    delete it;

    it = admins->getIterator();
    while (it->hasCurrent()) {
        Administra *administra = dynamic_cast<Administra *>(it->getCurrent());
        if (administra != nullptr) {
            eliminarPublicacionesDe(administra);
            ICollection *inmobiliarias = administra->getInmobiliarias();
            if (inmobiliarias != nullptr) {
                IIterator *itInmo = inmobiliarias->getIterator();
                while (itInmo->hasCurrent()) {
                    Inmobiliaria *inm = dynamic_cast<Inmobiliaria *>(itInmo->getCurrent());
                    if (inm != nullptr) {
                        inm->desvincularAdministracion(administra);
                    }
                    itInmo->next();
                }
                delete itInmo;
            }
            inmueble->desvincularAdministracion(administra);
            delete administra;
        }
        it->next();
    }
    delete it;
    delete admins;

    if (inmueble->getPropietario() != nullptr) {
        inmueble->getPropietario()->desvincularInmueble(inmueble);
    }

    Integer *clave = new Integer(inmueble->getIdInm());
    inmuebles->remove(clave);
    delete clave;
    inmuebleRecordado = nullptr;
    delete inmueble;
    return Status::OK;
}

void Sistema::vincularRepresentacion(string nicknameInmobiliaria, string nicknamePropietario) {
    representarPropietario(nicknameInmobiliaria, nicknamePropietario);
}

void Sistema::cargarDatosPrueba() {
    altaCliente("cli1", "123456", "Ana", "ana@mail.com", "Perez", "12345678");
    altaPropietario("prop1", "123456", "Bruno", "bruno@mail.com", "UY001", "099111222");
    altaPropietario("prop2", "123456", "Carla", "carla@mail.com", "UY002", "099333444");
    altaInmobiliaria("inmo1", "123456", "Central", "central@mail.com", "18 de Julio 1000",
                     "24000000", "www.central.uy");
    altaInmobiliaria("inmo2", "123456", "Costa", "costa@mail.com", "Rambla 200",
                     "26000000", "www.costa.uy");

    vincularRepresentacion("inmo1", "prop1");
    vincularRepresentacion("inmo1", "prop2");
    vincularRepresentacion("inmo2", "prop2");

    int casa = agregarCasa("prop1", "Rivera", "1234", 120, 2000, true, TipoTecho::LIVIANO);
    int apto = agregarApartamento("prop2", "Bulevar", "456", 70, 2010, 5, true, 5500);

    administrarInmueble(casa);
    administrarInmueble(apto);
    altaPublicacion(casa, TipoPublicacion::VENTA, "Casa luminosa con patio", 150000);
    altaPublicacion(apto, TipoPublicacion::ALQUILER, "Apartamento cerca de servicios", 32000);
}

   

