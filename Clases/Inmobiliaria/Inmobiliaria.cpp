#include "Inmobiliaria.h"
#include "../Propietario/Propietario.h"
#include "../Inmueble/Inmueble.h"
#include "../Administra/Administra.h"
#include "../../ICollection/collections/List.h"
#include "../../ICollection/interfaces/IIterator.h"
using namespace std;

Inmobiliaria::Inmobiliaria()
    : Usuario(), direccion(""), telefono(""), url(""), propietarios(new List()),
      administraciones(new List()) {}

Inmobiliaria::Inmobiliaria(string nickname, string contrasenia, string nombre,
                           string email, string direccion, string telefono,
                           string url)
    : Usuario(nickname, contrasenia, nombre, email), direccion(direccion), telefono(telefono),
      url(url), propietarios(new List()), administraciones(new List()) {}

Inmobiliaria::~Inmobiliaria() {
    IIterator *it = administraciones->getIterator();
    while (it->hasCurrent()) {
        Administra *administra = dynamic_cast<Administra *>(it->getCurrent());
        delete administra;
        it->next();
    }
    delete it;
    delete propietarios;
    delete administraciones;
}

string Inmobiliaria::getDireccion()  { return direccion; }
string Inmobiliaria::getTelefono()  { return telefono; }
string Inmobiliaria::getUrl()  { return url; }
ICollection *Inmobiliaria::getPropietarios()  { return propietarios; }
ICollection *Inmobiliaria::getAdministraciones()  { return administraciones; }

DTInmobiliaria Inmobiliaria::obtenerDT()  {
    return DTInmobiliaria(getNickname(), getNombre());
}

ICollection *Inmobiliaria::listarInmuebles()  {
    ICollection *resultado = new List();
    IIterator *itProp = propietarios->getIterator();
    while (itProp->hasCurrent()) {
        Propietario *prop = dynamic_cast<Propietario *>(itProp->getCurrent());
        if (prop != nullptr) {
            IIterator *itInm = prop->getInmuebles()->getIterator();
            while (itInm->hasCurrent()) {
                Inmueble *inm = dynamic_cast<Inmueble *>(itInm->getCurrent());
                if (inm != nullptr && obtenerAdministracionDe(inm) == nullptr) {
                    resultado->add(new DTInmueble(inm->getIdInm(), inm->getDireccion(), prop->getNombre()));
                }
                itInm->next();
            }
            delete itInm;
        }
        itProp->next();
    }
    delete itProp;
    return resultado;
}

ICollection *Inmobiliaria::listarInmueblesAdministrados()  {
    ICollection *resultado = new List();
    IIterator *it = administraciones->getIterator();
    while (it->hasCurrent()) {
        Administra *admin = dynamic_cast<Administra *>(it->getCurrent());
        if (admin != nullptr && admin->getInmueble() != nullptr &&
            admin->getInmueble()->getPropietario() != nullptr) {
            Inmueble *inm = admin->getInmueble();
            DTInmuebleAdministrado dt = inm->obtenerDTAdministrado();
            resultado->add(new DTInmuebleAdministrado(dt.getIdInm(), dt.getDireccion(),
                                                      dt.getNombreProp()));
        }
        it->next();
    }
    delete it;
    return resultado;
}

bool Inmobiliaria::representa(Propietario *propietario)  {
    return propietario != nullptr && propietarios->member(propietario);
}

Administra *Inmobiliaria::obtenerAdministracionDe(Inmueble *inmueble)  {
    IIterator *it = administraciones->getIterator();
    while (it->hasCurrent()) {
        Administra *admin = dynamic_cast<Administra *>(it->getCurrent());
        if (admin != nullptr && admin->getInmueble() == inmueble) {
            delete it;
            return admin;
        }
        it->next();
    }
    delete it;
    return nullptr;
}

void Inmobiliaria::vincularPropietario(Propietario *propietario) {
    if (propietario != nullptr && !propietarios->member(propietario)) {
        propietarios->add(propietario);
        propietario->vincularInmobiliaria(this);
    }
}

void Inmobiliaria::desvincularPropietario(Propietario *propietario) {
    if (propietario != nullptr) {
        propietarios->remove(propietario);
        propietario->desvincularInmobiliaria(this);
    }
}

Administra *Inmobiliaria::administrarInmueble(Inmueble *inmueble, DTFecha fechaActual) {
    if (inmueble == nullptr) {
        return nullptr;
    }
    Administra *existente = obtenerAdministracionDe(inmueble);
    if (existente != nullptr) {
        return existente;
    }
    Administra *administra = new Administra(fechaActual, this, inmueble);
    vincularAdministracion(administra);
    inmueble->vincularAdministracion(administra);
    return administra;
}

void Inmobiliaria::vincularAdministracion(Administra *administra) {
    if (administra != nullptr && !administraciones->member(administra)) {
        administraciones->add(administra);
    }
}

void Inmobiliaria::desvincularAdministracion(Administra *administra) {
    if (administra != nullptr) {
        administraciones->remove(administra);
    }
}

TipoUsuario Inmobiliaria::obtenerTipoUser()  {
    return TipoUsuario::INMOBILIARIA;
}


