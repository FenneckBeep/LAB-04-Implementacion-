#include "Cliente.h"
#include "../Agenda/Agenda.h"
#include "../../ICollection/collections/List.h"
using namespace std;

Cliente::Cliente() : Usuario(), apellido(""), documento(""), agendas(new List()) {}

Cliente::Cliente(string nickname, string contrasenia, string nombre, string email, string apellido, string documento)
    : Usuario(nickname, contrasenia, nombre, email), apellido(apellido), documento(documento), agendas(new List()) {}

Cliente::~Cliente() {
    delete agendas;
}

string Cliente::getApellido()  { 
    return apellido; }
string Cliente::getDocumento()  { 
    return documento; }
ICollection *Cliente::getAgendas()  { 
    return agendas; 
}

void Cliente::vincularAgenda(Agenda *agenda) {
    if (agenda != nullptr && !agendas->member(agenda)) {
        agendas->add(agenda);
    }
}

void Cliente::desvincularAgenda(Agenda *agenda) {
    if (agenda != nullptr) {
        agendas->remove(agenda);
    }
}

TipoUsuario Cliente::obtenerTipoUser()  {
    return TipoUsuario::CLIENTE;
}


