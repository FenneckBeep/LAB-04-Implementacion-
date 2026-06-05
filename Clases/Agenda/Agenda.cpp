#include "Agenda.h"
#include "../Cliente/Cliente.h"
#include "../Publicacion/Publicacion.h"
using namespace std;

Agenda::Agenda() : cliente(nullptr), publicacion(nullptr) {}

Agenda::Agenda(DTFecha visita, string metodoContacto, Cliente *cliente, Publicacion *publicacion)
    : visita(visita), metodoContacto(metodoContacto), cliente(cliente), publicacion(publicacion) {}

Agenda::~Agenda() {}

DTFecha Agenda::getVisita()  { return visita; }
string Agenda::getMetodoContacto()  { return metodoContacto; }
Cliente *Agenda::getCliente()  { return cliente; }
Publicacion *Agenda::getPublicacion()  { return publicacion; }

void Agenda::desvincularCliente() {
    if (cliente != nullptr) {
        Cliente *anterior = cliente;
        cliente = nullptr;
        anterior->desvincularAgenda(this);
    }
}

void Agenda::desvincularPublicacion() {
    if (publicacion != nullptr) {
        Publicacion *anterior = publicacion;
        publicacion = nullptr;
        anterior->desvincularAgenda(this);
    }
}


