#include "Publicacion.h"
#include "../Administra/Administra.h"
#include "../Agenda/Agenda.h"
#include "../../ICollection/collections/List.h"
#include "../../ICollection/interfaces/IIterator.h"
using namespace std;

namespace
{
    bool mismaFecha(DTFecha a, DTFecha b)
    {
        return a.getDia() == b.getDia() && a.getMes() == b.getMes() &&
               a.getAnio() == b.getAnio();
    }
}

Publicacion::Publicacion()
    : idPub(0), tipo(TipoPublicacion::VENTA), precio(0), esActiva(true),
      administra(nullptr), agendas(new List()) {}

Publicacion::Publicacion(int idPub, DTFecha fecha, TipoPublicacion tipo, string texto, double precio, Administra *administra)
    : idPub(idPub), fecha(fecha), tipo(tipo), texto(texto), precio(precio),
      esActiva(true), administra(administra), agendas(new List()) {}

Publicacion::~Publicacion()
{
    eliminarAgendas();
    delete agendas;
}

int Publicacion::getIdPub()
{
    return idPub;
}
DTFecha Publicacion::getFecha()
{
    return fecha;
}
TipoPublicacion Publicacion::getTipo()
{
    return tipo;
}
string Publicacion::getTexto()
{
    return texto;
}
double Publicacion::getPrecio()
{
    return precio;
}
bool Publicacion::getEsActiva()
{
    return esActiva;
}
Administra *Publicacion::getAdministra()
{
    return administra;
}
ICollection *Publicacion::getAgendas()
{
    return agendas;
}

void Publicacion::desactivar()
{
    esActiva = false;
}

bool Publicacion::desactivar(TipoPublicacion tipo)
{
    if (esActiva && this->tipo == tipo)
    {
        esActiva = false;
        return true;
    }
    return false;
}

bool Publicacion::puedePublicar(TipoPublicacion tipo, DTFecha fecha)
{
    return !(this->tipo == tipo && mismaFecha(this->fecha, fecha));
}

bool Publicacion::cumpleFiltroPublicacion(TipoPublicacion tipoBuscado, double min, double max, TipoInteres interes)
{
    if (!esActiva || tipo != tipoBuscado)
    {
        return false;
    }
    if (precio < min || precio > max)
    {
        return false;
    }
    return administra == nullptr || administra->cumpleInteres(interes);
}

bool Publicacion::cumpleFiltro(TipoPublicacion tipoBuscado, double min, double max, TipoInteres interes)
{
    return cumpleFiltroPublicacion(tipoBuscado, min, max, interes);
}

DTPublicacion Publicacion::obtenerDT(string nombreInmobiliaria)
{
    return DTPublicacion(idPub, fecha, tipo, texto, precio, nombreInmobiliaria);
}

DTDetalleInmueble Publicacion::obtenerDTDetalle()
{
    if (administra == nullptr)
    {
        return DTDetalleInmueble();
    }
    return administra->obtenerDTDetalle();
}

void Publicacion::vincularAgenda(Agenda *agenda)
{
    if (agenda != nullptr && !agendas->member(agenda))
    {
        agendas->add(agenda);
    }
}

void Publicacion::desvincularAgenda(Agenda *agenda)
{
    if (agenda != nullptr)
    {
        agendas->remove(agenda);
    }
}

void Publicacion::eliminarAgendas()
{
    ICollection *aEliminar = new List();
    IIterator *it = agendas->getIterator();
    while (it->hasCurrent())
    {
        Agenda *agenda = dynamic_cast<Agenda *>(it->getCurrent());
        if (agenda != nullptr)
        {
            aEliminar->add(agenda);
        }
        it->next();
    }
    delete it;

    it = aEliminar->getIterator();
    while (it->hasCurrent())
    {
        Agenda *agenda = dynamic_cast<Agenda *>(it->getCurrent());
        if (agenda != nullptr)
        {
            agendas->remove(agenda);
            agenda->desvincularCliente();
            agenda->desvincularPublicacion();
            delete agenda;
        }
        it->next();
    }
    delete it;
    delete aEliminar;
}
