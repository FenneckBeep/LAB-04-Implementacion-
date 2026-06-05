#include "DTDetalleInmueble.h"
using namespace std;

DTDetalleInmueble::DTDetalleInmueble()
    : idInm(0), superficie(0), anioConstruccion(0), tipo(TipoInmueble::CASA),
      descripcionExtra("") {}

DTDetalleInmueble::DTDetalleInmueble(int idInm, string direccion, string numPuerta,
                                     int superficie, int anioConstruccion, TipoInmueble tipo)
    : idInm(idInm), direccion(direccion), numPuerta(numPuerta), superficie(superficie),
      anioConstruccion(anioConstruccion), tipo(tipo), descripcionExtra("") {}

DTDetalleInmueble::DTDetalleInmueble(int idInm, string direccion, string numPuerta,
                                     int superficie, int anioConstruccion, TipoInmueble tipo,
                                     string descripcionExtra)
    : idInm(idInm), direccion(direccion), numPuerta(numPuerta), superficie(superficie),
      anioConstruccion(anioConstruccion), tipo(tipo), descripcionExtra(descripcionExtra) {}

DTDetalleInmueble::~DTDetalleInmueble() {}

int DTDetalleInmueble::getIdInm()  { return idInm; }
string DTDetalleInmueble::getDireccion()  { return direccion; }
string DTDetalleInmueble::getNumPuerta()  { return numPuerta; }
int DTDetalleInmueble::getSuperficie()  { return superficie; }
int DTDetalleInmueble::getAnioConstruccion()  { return anioConstruccion; }
TipoInmueble DTDetalleInmueble::getTipo()  { return tipo; }
string DTDetalleInmueble::getDescripcionExtra()  { return descripcionExtra; }


