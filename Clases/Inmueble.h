#ifndef INMUEBLE_H
#define INMUEBLE_H

#include <string>
#include "../Datatypes/DTDetalleInmueble.h"
#include "../Datatypes/DTInmueble.h"
#include "../ICollection/interfaces/ICollectible.h"
#include "Enums.h"

class ICollection;
class Propietario;
class Administra;

class Inmueble : public ICollectible {
private:
    int idInm;
    std::string direccion;
    std::string numPuerta;
    int superficie;
    int anioConstruccion;
    Propietario *propietario;
    ICollection *administraciones;

public:
    Inmueble();
    Inmueble(int idInm, std::string direccion, std::string numPuerta, int superficie,
             int anioConstruccion, Propietario *propietario);
    virtual ~Inmueble();

    int getIdInm() const;
    std::string getDireccion() const;
    std::string getNumPuerta() const;
    int getSuperficie() const;
    int getAnioConstruccion() const;
    Propietario *getPropietario() const;
    ICollection *getAdministraciones() const;

    DTInmueble obtenerDT(std::string nombreProp) const;
    virtual DTDetalleInmueble obtenerDTDetalle() const;
    virtual TipoInmueble obtenerTipoInmueble() const = 0;
    void vincularAdministracion(Administra *administra);
    void desvincularAdministracion(Administra *administra);
    void desvincularPropietario();
};

#endif
