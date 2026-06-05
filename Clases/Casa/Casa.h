#ifndef CASA_H
#define CASA_H

#include "../Inmueble/Inmueble.h"
#include "../Propietario/Propietario.h"

class Casa : public Inmueble {
private:
    bool esHorizontal;
    TipoTecho techo;

public:
    Casa();
    Casa(int idInm, string direccion, string numPuerta, int superficie,
         int anioConstruccion, Propietario *propietario, bool esHorizontal, TipoTecho techo);

    bool getEsHorizontal() ;
    TipoTecho getTecho() ;

    TipoInmueble obtenerTipoInmueble();
    DTDetalleInmueble obtenerDTDetalle();
};

#endif


