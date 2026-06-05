#include "Propietario.h"
#include "../Inmueble/Inmueble.h"
#include "../Inmobiliaria/Inmobiliaria.h"
#include "../../ICollection/collections/List.h"
using namespace std;

Propietario::Propietario()
    : Usuario(), cuentaBancaria(""), telefono(""), inmuebles(new List()),
      inmobiliarias(new List()) {}

Propietario::Propietario(string nickname, string contrasenia, string nombre,
                         string email, string cuentaBancaria, string telefono)
    : Usuario(nickname, contrasenia, nombre, email), cuentaBancaria(cuentaBancaria),
      telefono(telefono), inmuebles(new List()), inmobiliarias(new List()) {}

Propietario::~Propietario() {
    delete inmuebles;
    delete inmobiliarias;
}

string Propietario::getCuentaBancaria()  { return cuentaBancaria; }
string Propietario::getTelefono()  { return telefono; }
ICollection *Propietario::getInmuebles()  { return inmuebles; }
ICollection *Propietario::getInmobiliarias()  { return inmobiliarias; }

void Propietario::vincularInmueble(Inmueble *inmueble) {
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

TipoUsuario Propietario::obtenerTipoUser()  {
    return TipoUsuario::PROPIETARIO;
}


