#ifndef APARTAMENTO_H
#define APARTAMENTO_H

#include "Inmueble.h"

class Apartamento : public Inmueble {
private:
    int numPiso;
    bool tieneAscensor;
    double gastosComunes;

public:
    Apartamento();
    Apartamento(int idInm, std::string direccion, std::string numPuerta, int superficie,
                int anioConstruccion, Propietario *propietario, int numPiso,
                bool tieneAscensor, double gastosComunes);

    int getNumPiso() const;
    bool getTieneAscensor() const;
    double getGastosComunes() const;

    TipoInmueble obtenerTipoInmueble() const override;
    DTDetalleInmueble obtenerDTDetalle() const override;
};

#endif
