#include "Apartamento.h"
using namespace std;

Apartamento::Apartamento()
    : Inmueble(), numPiso(0), tieneAscensor(false), gastosComunes(0) {}

Apartamento::Apartamento(int idInm, string direccion, string numPuerta,
                         int superficie, int anioConstruccion, Propietario *propietario,
                         int numPiso, bool tieneAscensor, double gastosComunes)
    : Inmueble(idInm, direccion, numPuerta, superficie, anioConstruccion, propietario),
      numPiso(numPiso), tieneAscensor(tieneAscensor), gastosComunes(gastosComunes) {}

int Apartamento::getNumPiso()  { return numPiso; }
bool Apartamento::getTieneAscensor()  { return tieneAscensor; }
double Apartamento::getGastosComunes()  { return gastosComunes; }

TipoInmueble Apartamento::obtenerTipoInmueble()  {
    return TipoInmueble::APARTAMENTO;
}

DTDetalleInmueble Apartamento::obtenerDTDetalle()  {
    string extra = "Apartamento piso " + to_string(numPiso);
    if (tieneAscensor) {
        extra += ", con ascensor";
    } else {
        extra += ", sin ascensor";
    }
    return DTDetalleInmueble(getIdInm(), getDireccion(), getNumPuerta(), getSuperficie(),
                             getAnioConstruccion(), TipoInmueble::APARTAMENTO, extra);
}


