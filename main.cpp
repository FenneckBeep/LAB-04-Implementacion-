#include <iostream>
#include <limits>
#include <string>

#include <iostream>
#include <limits>
#include <string>

#include "Enums/Enums.h"

#include "Clases/Factory/SistemaFactory.h"
#include "Clases/Sistema/ISistema.h"

#include "DTInmobiliaria/DTInmobiliaria.h"
#include "DTInmueble/DTInmueble.h"
#include "DTInmuebleAdministrado/DTInmuebleAdministrado.h"
#include "DTPublicacion/DTPublicacion.h"
#include "DTDetalleInmueble/DTDetalleInmueble.h"
#include "DTPropietario/DTPropietario.h"

#include "ICollection/interfaces/ICollection.h"
#include "ICollection/interfaces/IIterator.h"

using namespace std;

void limpiarEntrada() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void liberarColeccion(ICollection *coleccion) {
    if (coleccion == nullptr) {
        return;
    }
    IIterator *it = coleccion->getIterator();
    while (it->hasCurrent()) {
        delete it->getCurrent();
        it->next();
    }
    delete it;
    delete coleccion;
}

// CORRECCIÓN: Cambiamos el tipo de retorno de int a TipoPublicacion
TipoPublicacion leerTipoPublicacion() {
    int tipo;
    cout << "Tipo de publicacion (1 venta, 2 ALQUILER): ";
    cin >> tipo;
    return tipo == 2 ? TipoPublicacion::ALQUILER : TipoPublicacion::VENTA;
}

TipoInteres leerTipoInteres() {
    int interes;
    cout << "Tipo de inmueble (1 todos, 2 casa, 3 apartamento): ";
    cin >> interes;
    if (interes == 2) return TipoInteres::CASA;
    if (interes == 3) return TipoInteres::APARTAMENTO;
    return TipoInteres::AMBOS; // Opción por defecto si elige "todos"
}

TipoTecho leerTipoTecho() {
    int techo;
    cout << "Tipo de techo (1 liviano, 2 dos aguas, 3 plano): ";
    cin >> techo;
    if (techo == 2) return TipoTecho::DOS_AGUAS;
    if (techo == 3) return TipoTecho::PESADO;
    return TipoTecho::LIVIANO;
}

void imprimirInmobiliarias(ICollection *inmobiliarias) {
    IIterator *it = inmobiliarias->getIterator();
    while (it->hasCurrent()) {
        DTInmobiliaria *dt = dynamic_cast<DTInmobiliaria *>(it->getCurrent());
        if (dt != nullptr) {
            cout << "- " << dt->getNickname() << " | " << dt->getNombre() << "\n";
        }
        it->next();
    }
    delete it;
}

void imprimirPropietarios(ICollection *propietarios) {
    IIterator *it = propietarios->getIterator();
    while (it->hasCurrent()) {
        DTPropietario *dt = dynamic_cast<DTPropietario *>(it->getCurrent());
        if (dt != nullptr) {
            cout << "- " << dt->getNickname() << " | " << dt->getNombre() << "\n";
        }
        it->next();
    }
    delete it;
}

void imprimirInmuebles(ICollection *inmuebles) {
    IIterator *it = inmuebles->getIterator();
    while (it->hasCurrent()) {
        DTInmueble *dt = dynamic_cast<DTInmueble *>(it->getCurrent());
        if (dt != nullptr) {
            cout << "- ID " << dt->getIdInm() << " | " << dt->getDireccion()
                 << " | propietario: " << dt->getNombreProp() << "\n";
        }
        it->next();
    }
    delete it;
}

void imprimirInmueblesAdministrados(ICollection *inmuebles) {
    IIterator *it = inmuebles->getIterator();
    while (it->hasCurrent()) {
        DTInmuebleAdministrado *dt = dynamic_cast<DTInmuebleAdministrado *>(it->getCurrent());
        if (dt != nullptr) {
            cout << "- ID " << dt->getIdInm() << " | " << dt->getDireccion()
                 << " | propietario: " << dt->getNombreProp() << "\n";
        }
        it->next();
    }
    delete it;
}

void imprimirPublicaciones(ICollection *publicaciones) {
    IIterator *it = publicaciones->getIterator();
    while (it->hasCurrent()) {
        DTPublicacion *dt = dynamic_cast<DTPublicacion *>(it->getCurrent());
        if (dt != nullptr) {
            cout << "- ID " << dt->getIdPub()
                 << " | precio: " << dt->getPrecio()
                 << " | inmobiliaria: " << dt->getNombreInmobiliaria()
                 << " | texto: " << dt->getTexto() << "\n";
        }
        it->next();
    }
    delete it;
}

void imprimirDetalle(DTDetalleInmueble detalle) {
    if (detalle.getIdInm() == 0) {
        cout << "No se encontro detalle.\n";
        return;
    }
    cout << "ID inmueble: " << detalle.getIdInm() << "\n";
    cout << "Direccion: " << detalle.getDireccion() << " " << detalle.getNumPuerta() << "\n";
    cout << "Superficie: " << detalle.getSuperficie() << "\n";
    cout << "Anio construccion: " << detalle.getAnioConstruccion() << "\n";
    cout << "Detalle: " << detalle.getDescripcionExtra() << "\n";
}

int main() {
    ISistema *sistema = SistemaFactory::getSistema();
    int opcion = -1;

    while (opcion != 0) {
        cout << "\n=== Laboratorio 4 - Laboratorio ===\n";
        cout << "1. Cargar datos de prueba\n";
        cout << "2. Alta cliente\n";
        cout << "3. Alta propietario\n";
        cout << "4. Alta inmobiliaria\n";
        cout << "5. Representar propietario\n";
        cout << "6. Alta inmueble\n";
        cout << "7. Alta administracion de propiedad\n";
        cout << "8. Alta publicacion\n";
        cout << "9. Consulta de publicacion\n";
        cout << "10. Eliminar inmueble\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        if (!(cin >> opcion)) {
            break;
        }

        switch (opcion) {
        case 1:
            sistema->cargarDatosPrueba();
            cout << "Datos de prueba cargados.\n";
            break;

        case 2: {
            string nick, pass, nombre, email, apellido, documento;
            cout << "Nickname: "; cin >> nick;
            cout << "Contrasenia: "; cin >> pass;
            limpiarEntrada();
            cout << "Nombre: "; getline(cin, nombre);
            cout << "Email: "; getline(cin, email);
            cout << "Apellido: "; getline(cin, apellido);
            cout << "Documento: "; getline(cin, documento);
            cout << (sistema->altaCliente(nick, pass, nombre, email, apellido, documento) == Status::OK
                     ? "Cliente creado.\n" : "No se pudo crear cliente.\n");
            break;
        }

        case 3: {
            string nick, pass, nombre, email, cuenta, telefono;
            cout << "Nickname: "; cin >> nick;
            cout << "Contrasenia: "; cin >> pass;
            limpiarEntrada();
            cout << "Nombre: "; getline(cin, nombre);
            cout << "Email: "; getline(cin, email);
            cout << "Cuenta bancaria: "; getline(cin, cuenta);
            cout << "Telefono: "; getline(cin, telefono);
            cout << (sistema->altaPropietario(nick, pass, nombre, email, cuenta, telefono) == Status::OK
                     ? "Propietario creado.\n" : "No se pudo crear propietario.\n");
            break;
        }

        case 4: {
            string nick, pass, nombre, email, direccion, telefono, url;
            cout << "Nickname: "; cin >> nick;
            cout << "Contrasenia: "; cin >> pass;
            limpiarEntrada();
            cout << "Nombre: "; getline(cin, nombre);
            cout << "Email: "; getline(cin, email);
            cout << "Direccion: "; getline(cin, direccion);
            cout << "Telefono: "; getline(cin, telefono);
            cout << "URL: "; getline(cin, url);
            cout << (sistema->altaInmobiliaria(nick, pass, nombre, email, direccion, telefono, url) == Status::OK
                     ? "Inmobiliaria creada.\n" : "No se pudo crear inmobiliaria.\n");
            break;
        }

        case 5: {
            ICollection *inmobiliarias = sistema->listarInmobiliarias();
            imprimirInmobiliarias(inmobiliarias);
            liberarColeccion(inmobiliarias);

            string nickInmo;
            cout << "Nickname de inmobiliaria: ";
            cin >> nickInmo;

            ICollection *propietarios = sistema->listarPropietarios();
            imprimirPropietarios(propietarios);
            liberarColeccion(propietarios);

            string nickProp;
            cout << "Nickname de propietario: ";
            cin >> nickProp;
            cout << (sistema->representarPropietario(nickInmo, nickProp) == Status::OK
                     ? "Propietario representado.\n" : "No se pudo crear la representacion.\n");
            break;
        }

        case 6: {
            ICollection *propietarios = sistema->listarPropietarios();
            imprimirPropietarios(propietarios);
            liberarColeccion(propietarios);

            string nickProp, direccion, numPuerta;
            int superficie, anioConstruccion;
            cout << "Nickname de propietario: ";
            cin >> nickProp;
            if (sistema->agregarPropietario(nickProp) == Status::ERROR) {
                cout << "No se encontro propietario.\n";
                break;
            }
            limpiarEntrada();
            cout << "Direccion: ";
            getline(cin, direccion);
            cout << "Numero de puerta: ";
            getline(cin, numPuerta);
            cout << "Superficie: ";
            cin >> superficie;
            cout << "Anio construccion: ";
            cin >> anioConstruccion;
            if (sistema->agregarInmueble(direccion, numPuerta, superficie,
                                          anioConstruccion) == Status::ERROR) {
                cout << "No se pudo recordar el inmueble.\n";
                break;
            }

            int tipoInmueble;
            cout << "Tipo de inmueble (1 casa, 2 apartamento): ";
            cin >> tipoInmueble;
            int idCreado = 0;
            if (tipoInmueble == 2) {
                int numPiso;
                char ascensor;
                double gastosComunes;
                cout << "Numero de piso: ";
                cin >> numPiso;
                cout << "Tiene ascensor (s/n): ";
                cin >> ascensor;
                cout << "Gastos comunes: ";
                cin >> gastosComunes;
                idCreado = sistema->agregarApartamento(numPiso, ascensor == 's' || ascensor == 'S',
                                                       gastosComunes);
            } else {
                char horizontal;
                cout << "Es horizontal (s/n): ";
                cin >> horizontal;
                TipoTecho techo = leerTipoTecho();
                idCreado = sistema->agregarCasa(horizontal == 's' || horizontal == 'S', techo);
            }
            cout << (idCreado != 0 ? "Inmueble creado con ID " : "No se pudo crear inmueble");
            if (idCreado != 0) {
                cout << idCreado;
            }
            cout << ".\n";
            break;
        }

        case 7: {
            ICollection *inmobiliarias = sistema->listarInmobiliarias();
            imprimirInmobiliarias(inmobiliarias);
            liberarColeccion(inmobiliarias);

            string nickname;
            cout << "Nickname de inmobiliaria: ";
            cin >> nickname;
            ICollection *inmuebles = sistema->listarInmuebles(nickname);
            imprimirInmuebles(inmuebles);
            liberarColeccion(inmuebles);

            int idInm;
            cout << "ID inmueble a administrar: ";
            cin >> idInm;
            cout << (sistema->administrarInmueble(idInm) == Status::OK
                     ? "Administracion creada.\n" : "No se pudo administrar el inmueble.\n");
            break;
        }

        case 8: {
            ICollection *inmobiliarias = sistema->listarInmobiliarias();
            imprimirInmobiliarias(inmobiliarias);
            liberarColeccion(inmobiliarias);

            string nickname;
            cout << "Nickname de inmobiliaria: ";
            cin >> nickname;
            ICollection *inmuebles = sistema->listarInmueblesAdministrados(nickname);
            imprimirInmueblesAdministrados(inmuebles);
            liberarColeccion(inmuebles);

            int idInm;
            double precio;
            string texto;
            cout << "ID inmueble: ";
            cin >> idInm;
            TipoPublicacion tipo = leerTipoPublicacion();
            cout << "Precio: ";
            cin >> precio;
            limpiarEntrada();
            cout << "Texto: ";
            getline(cin, texto);
            cout << (sistema->altaPublicacion(idInm, tipo, texto, precio) == Status::OK
                     ? "Publicacion creada.\n" : "No se pudo crear publicacion.\n");
            break;
        }

       case 9: {
            TipoPublicacion tipo = leerTipoPublicacion();
            TipoInteres interes = leerTipoInteres(); // <-- Volvemos a TipoInteres
            double min, max;
            cout << "Precio minimo: ";
            cin >> min;
            cout << "Precio maximo: ";
            cin >> max;
            ICollection *publicaciones = sistema->listarPublicaciones(tipo, min, max, interes);
            imprimirPublicaciones(publicaciones);
            liberarColeccion(publicaciones);

            int idPub;
            cout << "ID publicacion para ver detalle: ";
            cin >> idPub;
            
            imprimirDetalle(sistema->consultarDetalleInmueble(idPub));
            break;
        }

        case 10: {
            ICollection *inmuebles = sistema->listarInmuebles();
            imprimirInmuebles(inmuebles);
            liberarColeccion(inmuebles);

            int idInm;
            cout << "ID inmueble a eliminar: ";
            cin >> idInm;
            
            // Aquí lo llamamos por valor perfectamente
            DTDetalleInmueble detalle = sistema->ingresarCodigoInmueble(idInm);
            imprimirDetalle(detalle);
            if (detalle.getIdInm() != 0) {
                char confirma;
                cout << "Confirmar eliminacion (s/n): ";
                cin >> confirma;
                if (confirma == 's' || confirma == 'S') {
                    cout << (sistema->eliminarInmueble() == Status::OK
                             ? "Inmueble eliminado.\n" : "No se pudo eliminar.\n");
                }
            }
            break;
        }

        case 0:
            cout << "Fin.\n";
            break;

        default:
            cout << "Opcion invalida.\n";
            break;
        }
    }

    SistemaFactory::destruirSistema();
    return 0;
}