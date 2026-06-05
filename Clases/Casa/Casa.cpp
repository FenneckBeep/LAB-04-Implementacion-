#include "Casa.h"
using namespace std;

Casa::Casa() : Inmueble(), esHorizontal(false), techo(TipoTecho::LIVIANO) {}

Casa::Casa(int idInm, string direccion, string numPuerta, int superficie,
           int anioConstruccion, Propietario *propietario, bool esHorizontal, TipoTecho techo)
    : Inmueble(idInm, direccion, numPuerta, superficie, anioConstruccion, propietario),
      esHorizontal(esHorizontal), techo(techo) {}

bool Casa::getEsHorizontal()  { return esHorizontal; }
TipoTecho Casa::getTecho()  { return techo; }

TipoInmueble Casa::obtenerTipoInmueble()  {
    return TipoInmueble::CASA;
}

DTDetalleInmueble Casa::obtenerDTDetalle()  {
    string extra = esHorizontal ? "Casa horizontal" : "Casa no horizontal";
    return DTDetalleInmueble(getIdInm(), getDireccion(), getNumPuerta(), getSuperficie(),
                             getAnioConstruccion(), TipoInmueble::CASA, extra);
}


