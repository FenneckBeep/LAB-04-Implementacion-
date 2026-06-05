#include "Administra.h"
#include "../../ICollection/collections/List.h"
#include "../../ICollection/interfaces/IIterator.h"
using namespace std;

Administra::Administra()
    : fecha(DTFecha()), inmobiliarias(new List()), inmueble(nullptr), publicaciones(new List()) {}

Administra::Administra(DTFecha fecha, Inmobiliaria *inmobiliaria, Inmueble *inmueble)
    : fecha(fecha), inmobiliarias(new List()), inmueble(inmueble), publicaciones(new List()) {
    if (inmobiliaria != nullptr) {
        vincularInmobiliaria(inmobiliaria);
    }
}

Administra::~Administra() {
    delete inmobiliarias;
    delete publicaciones;
}

DTFecha Administra::getFecha() {
    return this->fecha;
}

ICollection *Administra::getInmobiliarias() {
    return this->inmobiliarias;
}

Inmobiliaria *Administra::getInmobiliaria() {
    IIterator *it = inmobiliarias->getIterator();
    Inmobiliaria *resultado = nullptr;
    if (it->hasCurrent()) {
        resultado = dynamic_cast<Inmobiliaria *>(it->getCurrent());
    }
    delete it;
    return resultado;
}

Inmueble *Administra::getInmueble() {
    return this->inmueble;
}

ICollection *Administra::getPublicaciones() {
    return this->publicaciones;
}

void Administra::vincularInmobiliaria(Inmobiliaria *inmobiliaria) {
    if (inmobiliaria != nullptr && !inmobiliarias->member(inmobiliaria)) {
        inmobiliarias->add(inmobiliaria);
        inmobiliaria->vincularAdministracion(this);
    }
}

void Administra::desvincularInmobiliaria(Inmobiliaria *inmobiliaria) {
    if (inmobiliaria != nullptr) {
        inmobiliarias->remove(inmobiliaria);
        inmobiliaria->desvincularAdministracion(this);
    }
}

void Administra::vincularPub(Publicacion *publicacion) {
    if (publicacion != nullptr && !publicaciones->member(publicacion)) {
        publicaciones->add(publicacion);
    }
}

void Administra::desvincularPub(Publicacion *publicacion) {
    if (publicacion != nullptr) {
        publicaciones->remove(publicacion);
    }
}

bool Administra::puedePublicar(TipoPublicacion tipo) {
    IIterator *it = publicaciones->getIterator();
    while (it->hasCurrent()) {
        Publicacion *pub = dynamic_cast<Publicacion *>(it->getCurrent());
        if (pub != nullptr && !pub->puedePublicar(tipo, fecha)) {
            delete it;
            return false;
        }
        it->next();
    }
    delete it;
    return true;
}

bool Administra::puedePublicar(int idPub, TipoPublicacion tipo, DTFecha fecha) {
    IIterator *it = publicaciones->getIterator();
    while (it->hasCurrent()) {
        Publicacion *pub = dynamic_cast<Publicacion *>(it->getCurrent());
        if (pub != nullptr && !pub->puedePublicar(tipo, fecha)) {
            delete it;
            return false;
        }
        it->next();
    }
    delete it;
    return true;
}

void Administra::desactivarPublicaciones(TipoPublicacion tipo) {
    IIterator *it = publicaciones->getIterator();
    while (it->hasCurrent()) {
        Publicacion *pub = dynamic_cast<Publicacion *>(it->getCurrent());
        if (pub != nullptr) {
            pub->desactivar(tipo);
        }
        it->next();
    }
    delete it;
}

bool Administra::cumpleInteres(TipoInteres interes) {
    if (inmueble == nullptr) {
        return false;
    }
    if (interes == TipoInteres::AMBOS) {
        return true;
    }
    return (interes == TipoInteres::CASA && inmueble->obtenerTipoInmueble() == TipoInmueble::CASA) ||
           (interes == TipoInteres::APARTAMENTO && inmueble->obtenerTipoInmueble() == TipoInmueble::APARTAMENTO);
}

DTDetalleInmueble Administra::obtenerDTDetalle() {
    if (inmueble == nullptr) {
        return DTDetalleInmueble();
    }
    return inmueble->obtenerDTDetalle();
}
