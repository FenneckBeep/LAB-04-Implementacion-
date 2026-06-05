#include "DTPublicacion.h"
using namespace std;

DTPublicacion::DTPublicacion()
    : idPub(0), tipo(TipoPublicacion::VENTA), precio(0) {}

DTPublicacion::DTPublicacion(int idPub, DTFecha fecha, TipoPublicacion tipo, string texto,
                             double precio, string nombreInmobiliaria)
    : idPub(idPub), fecha(fecha), tipo(tipo), texto(texto), precio(precio),
      nombreInmobiliaria(nombreInmobiliaria) {}

DTPublicacion::~DTPublicacion() {}

int DTPublicacion::getIdPub()  { return idPub; }
DTFecha DTPublicacion::getFecha()  { return fecha; }
TipoPublicacion DTPublicacion::getTipo()  { return tipo; }
string DTPublicacion::getTexto()  { return texto; }
double DTPublicacion::getPrecio()  { return precio; }
string DTPublicacion::getNombreInmobiliaria()  { return nombreInmobiliaria; }


