#include "Inmueble.h"

using namespace std;

Inmueble::Inmueble()
    : idInm(0), superficie(0), anioConstruccion(0), propietario(nullptr),
      administraciones(new List()) {}

Inmueble::Inmueble(int idInm, string direccion, string numPuerta, int superficie,
                   int anioConstruccion, Propietario *propietario)
    : idInm(idInm), direccion(direccion), numPuerta(numPuerta), superficie(superficie),
      anioConstruccion(anioConstruccion), propietario(propietario), administraciones(new List()) {
    if (propietario != nullptr) {
        propietario->vincularInmueble(this);
    }
}

Inmueble::~Inmueble() {
    delete administraciones;
}

int Inmueble::getIdInm()  { return idInm; }
string Inmueble::getDireccion()  { return direccion; }
string Inmueble::getNumPuerta()  { return numPuerta; }
int Inmueble::getSuperficie()  { return superficie; }
int Inmueble::getAnioConstruccion()  { return anioConstruccion; }
Propietario *Inmueble::getPropietario()  { return propietario; }
ICollection *Inmueble::getAdministraciones()  { return administraciones; }

void Inmueble::vincularPropietario(Propietario *nuevoPropietario) {
    if (nuevoPropietario == nullptr) {
        return;
    }
    if (propietario != nullptr && propietario != nuevoPropietario) {
        propietario->desvincularInmueble(this);
    }
    propietario = nuevoPropietario;
    propietario->vincularInmueble(this);
}

void Inmueble::vincularInmobiliaria(Inmobiliaria *inmobiliaria) {
    if (inmobiliaria == nullptr) {
        return;
    }
    Administra *admin = nullptr;
    IIterator *it = administraciones->getIterator();
    while (it->hasCurrent()) {
        admin = dynamic_cast<Administra *>(it->getCurrent());
        if (admin != nullptr) {
            break;
        }
        it->next();
    }
    delete it;
    if (admin != nullptr) {
        inmobiliaria->vincularAdministracion(admin);
        admin->vincularInmobiliaria(inmobiliaria);
    }
}

void Inmueble::vincularPubAdmin(Publicacion *publicacion) {
    if (publicacion == nullptr) {
        return;
    }
    IIterator *it = administraciones->getIterator();
    while (it->hasCurrent()) {
        Administra *admin = dynamic_cast<Administra *>(it->getCurrent());
        if (admin != nullptr) {
            admin->vincularPub(publicacion);
            break;
        }
        it->next();
    }
    delete it;
}

void Inmueble::eliminarAsociaciones() {
    ICollection *aEliminar = new List();
    IIterator *it = administraciones->getIterator();
    while (it->hasCurrent()) {
        Administra *admin = dynamic_cast<Administra *>(it->getCurrent());
        if (admin != nullptr) {
            aEliminar->add(admin);
        }
        it->next();
    }
    delete it;

    it = aEliminar->getIterator();
    while (it->hasCurrent()) {
        Administra *admin = dynamic_cast<Administra *>(it->getCurrent());
        if (admin != nullptr) {
            ICollection *inmobiliarias = admin->getInmobiliarias();
            if (inmobiliarias != nullptr) {
                IIterator *itInmo = inmobiliarias->getIterator();
                while (itInmo->hasCurrent()) {
                    Inmobiliaria *inm = dynamic_cast<Inmobiliaria *>(itInmo->getCurrent());
                    if (inm != nullptr) {
                        inm->desvincularAdministracion(admin);
                    }
                    itInmo->next();
                }
                delete itInmo;
            }
            administraciones->remove(admin);
        }
        it->next();
    }
    delete it;
    delete aEliminar;
}

DTInmueble Inmueble::obtenerDT(string nombreProp)  {
    return DTInmueble(idInm, direccion, nombreProp);
}

DTInmuebleAdministrado Inmueble::obtenerDTAdministrado()  {
    string nombreProp = "";
    if (propietario != nullptr) {
        nombreProp = propietario->getNombre();
    }
    return DTInmuebleAdministrado(idInm, direccion, nombreProp);
}

DTDetalleInmueble Inmueble::obtenerDTDetalle()  {
    return DTDetalleInmueble(idInm, direccion, numPuerta, superficie, anioConstruccion,
                             obtenerTipoInmueble());
}

bool Inmueble::puedePublicar(int idPub, TipoPublicacion tipo, DTFecha fecha)  {
    IIterator *it = administraciones->getIterator();
    while (it->hasCurrent()) {
        Administra *admin = dynamic_cast<Administra *>(it->getCurrent());
        if (admin != nullptr && admin->puedePublicar(idPub, tipo, fecha)) {
            delete it;
            return true;
        }
        it->next();
    }
    delete it;
    return false;
}

void Inmueble::vincularAdministracion(Administra *administra) {
    if (administra != nullptr && !administraciones->member(administra)) {
        administraciones->add(administra);
    }
}

void Inmueble::desvincularAdministracion(Administra *administra) {
    if (administra != nullptr) {
        administraciones->remove(administra);
    }
}

void Inmueble::desvincularPropietario() {
    propietario = nullptr;
}


