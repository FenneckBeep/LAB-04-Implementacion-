#include "Cliente.h"
#include "Agenda.h"
#include "../ICollection/collections/List.h"

Cliente::Cliente()
    : Usuario(), apellido(""), documento(""), agendas(new List()) {}

Cliente::Cliente(std::string nickname, std::string contrasenia, std::string nombre,
                 std::string email, std::string apellido, std::string documento)
    : Usuario(nickname, contrasenia, nombre, email),
      apellido(apellido), documento(documento), agendas(new List()) {}

Cliente::~Cliente() {
    // Cliente no crea Agenda en AltaUsuario; solo libera la coleccion de referencias.
    delete agendas;
}

std::string Cliente::getApellido() {
    return apellido;
}

std::string Cliente::getDocumento() {
    return documento;
}

ICollection *Cliente::getAgendas() {
    return agendas;
}

void Cliente::vincularAgenda(Agenda *agenda) {
    // member compara direcciones, por eso evita agregar la misma agenda dos veces.
    if (agenda != nullptr && !agendas->member(agenda)) {
        agendas->add(agenda);
    }
}

void Cliente::desvincularAgenda(Agenda *agenda) {
    if (agenda != nullptr) {
        agendas->remove(agenda);
    }
}

TipoUsuario Cliente::obtenerTipoUser() {
    return TipoUsuario::cliente;
}
