#include "Inmobiliaria.h"
#include "Propietario.h"
#include "Inmueble.h"
#include "Administra.h"
#include "../ICollection/collections/List.h"
#include "../ICollection/interfaces/IIterator.h"

Inmobiliaria::Inmobiliaria()
    : Usuario(), direccion(""), telefono(""), url(""),
      propietarios(new List()), administraciones(new List()) {}

Inmobiliaria::Inmobiliaria(std::string nickname, std::string contrasenia,
                           std::string nombre, std::string email,
                           std::string direccion, std::string telefono,
                           std::string url)
    : Usuario(nickname, contrasenia, nombre, email),
      direccion(direccion), telefono(telefono), url(url),
      propietarios(new List()), administraciones(new List()) {}

Inmobiliaria::~Inmobiliaria() {
    // Las administraciones son creadas por la inmobiliaria al administrar inmuebles.
    IIterator *it = administraciones->getIterator();
    while (it->hasCurrent()) {
        delete dynamic_cast<Administra *>(it->getCurrent());
        it->next();
    }
    delete it;

    delete propietarios;
    delete administraciones;
}

std::string Inmobiliaria::getDireccion() {
    return direccion;
}

std::string Inmobiliaria::getTelefono() {
    return telefono;
}

std::string Inmobiliaria::getUrl() {
    return url;
}

ICollection *Inmobiliaria::getPropietarios() {
    return propietarios;
}

ICollection *Inmobiliaria::getAdministraciones() {
    return administraciones;
}

DTInmobiliaria Inmobiliaria::obtenerDT() {
    return DTInmobiliaria(getNickname(), getNombre());
}

ICollection *Inmobiliaria::listarInmuebles() {
    ICollection *resultado = new List();
    IIterator *itProp = propietarios->getIterator();

    while (itProp->hasCurrent()) {
        Propietario *propietario = dynamic_cast<Propietario *>(itProp->getCurrent());
        if (propietario != nullptr) {
            IIterator *itInm = propietario->getInmuebles()->getIterator();
            while (itInm->hasCurrent()) {
                Inmueble *inmueble = dynamic_cast<Inmueble *>(itInm->getCurrent());
                // Para AltaAdministracion se muestran solo inmuebles representados no administrados.
                if (inmueble != nullptr && obtenerAdministracionDe(inmueble) == nullptr) {
                    resultado->add(new DTInmueble(inmueble->getIdInm(),
                                                  inmueble->getDireccion(),
                                                  propietario->getNombre()));
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

ICollection *Inmobiliaria::listarInmueblesAdministrados() {
    ICollection *resultado = new List();
    IIterator *it = administraciones->getIterator();

    while (it->hasCurrent()) {
        Administra *administra = dynamic_cast<Administra *>(it->getCurrent());
        if (administra != nullptr && administra->getInmueble() != nullptr) {
            Inmueble *inmueble = administra->getInmueble();
            DTInmuebleAdministrado dt = inmueble->obtenerDTAdministrado();
            resultado->add(new DTInmuebleAdministrado(dt.getIdInm(),
                                                      dt.getDireccion(),
                                                      dt.getNombreProp()));
        }
        it->next();
    }

    delete it;
    return resultado;
}

bool Inmobiliaria::representa(Propietario *propietario) {
    return propietario != nullptr && propietarios->member(propietario);
}

Administra *Inmobiliaria::obtenerAdministracionDe(Inmueble *inmueble) {
    IIterator *it = administraciones->getIterator();

    while (it->hasCurrent()) {
        Administra *administra = dynamic_cast<Administra *>(it->getCurrent());
        if (administra != nullptr && administra->getInmueble() == inmueble) {
            delete it;
            return administra;
        }
        it->next();
    }

    delete it;
    return nullptr;
}

void Inmobiliaria::vincularPropietario(Propietario *propietario) {
    if (propietario != nullptr && !propietarios->member(propietario)) {
        propietarios->add(propietario);
        // Link inverso para que Propietario tambien sepa quien lo representa.
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

    Administra *administracion = obtenerAdministracionDe(inmueble);
    if (administracion != nullptr) {
        return administracion;
    }

    administracion = new Administra(fechaActual, this, inmueble);
    vincularAdministracion(administracion);
    inmueble->vincularAdministracion(administracion);
    return administracion;
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

TipoUsuario Inmobiliaria::obtenerTipoUser() {
    return TipoUsuario::inmobiliaria;
}
