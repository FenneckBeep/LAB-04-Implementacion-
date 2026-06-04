#ifndef CASA_H
#define CASA_H

#include "Inmueble.h"

class Casa : public Inmueble {
private:
    bool esHorizontal;
    TipoTecho techo;

public:
    Casa();
    Casa(int idInm, std::string direccion, std::string numPuerta, int superficie,
         int anioConstruccion, Propietario *propietario, bool esHorizontal, TipoTecho techo);

    bool getEsHorizontal() const;
    TipoTecho getTecho() const;

    TipoInmueble obtenerTipoInmueble() const override;
    DTDetalleInmueble obtenerDTDetalle() const override;
};

#endif
