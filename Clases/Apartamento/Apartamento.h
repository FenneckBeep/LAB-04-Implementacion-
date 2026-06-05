#ifndef APARTAMENTO_H
#define APARTAMENTO_H

#include "../Inmueble/Inmueble.h"

class Apartamento : public Inmueble {
private:
    int numPiso;
    bool tieneAscensor;
    double gastosComunes;

public:
    Apartamento();
    Apartamento(int idInm, string direccion, string numPuerta, int superficie,
                int anioConstruccion, Propietario *propietario, int numPiso,
                bool tieneAscensor, double gastosComunes);

    int getNumPiso() ;
    bool getTieneAscensor() ;
    double getGastosComunes() ;

    TipoInmueble obtenerTipoInmueble()  override;
    DTDetalleInmueble obtenerDTDetalle()  override;
};

#endif


