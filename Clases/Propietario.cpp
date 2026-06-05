#include "Propietario.h"
#include "Inmueble.h"
#include "Inmobiliaria.h"
#include "../ICollection/collections/List.h"

Propietario::Propietario()
    : Usuario(), cuentaBancaria(""), telefono(""),
      inmuebles(new List()), inmobiliarias(new List()) {}

Propietario::Propietario(std::string nickname, std::string contrasenia,
                         std::string nombre, std::string email,
                         std::string cuentaBancaria, std::string telefono)
    : Usuario(nickname, contrasenia, nombre, email),
      cuentaBancaria(cuentaBancaria), telefono(telefono),
      inmuebles(new List()), inmobiliarias(new List()) {}

Propietario::~Propietario() {
    // Los inmuebles son objetos del sistema; aca solo se libera la lista que los referencia.
    delete inmuebles;
    delete inmobiliarias;
}

std::string Propietario::getCuentaBancaria() {
    return cuentaBancaria;
}

std::string Propietario::getTelefono() {
    return telefono;
}

ICollection *Propietario::getInmuebles() {
    return inmuebles;
}

ICollection *Propietario::getInmobiliarias() {
    return inmobiliarias;
}

void Propietario::vincularInmueble(Inmueble *inmueble) {
    // Un propietario puede tener muchos inmuebles, pero una misma instancia no se repite.
    if (inmueble != nullptr && !inmuebles->member(inmueble)) {
        inmuebles->add(inmueble);
    }
}

void Propietario::desvincularInmueble(Inmueble *inmueble) {
    if (inmueble != nullptr) {
        inmuebles->remove(inmueble);
    }
}

void Propietario::vincularInmobiliaria(Inmobiliaria *inmobiliaria) {
    if (inmobiliaria != nullptr && !inmobiliarias->member(inmobiliaria)) {
        inmobiliarias->add(inmobiliaria);
    }
}

void Propietario::desvincularInmobiliaria(Inmobiliaria *inmobiliaria) {
    if (inmobiliaria != nullptr) {
        inmobiliarias->remove(inmobiliaria);
    }
}

TipoUsuario Propietario::obtenerTipoUser() {
    return TipoUsuario::propietario;
}
