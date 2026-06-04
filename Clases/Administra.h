#ifndef ADMINISTRA_H
#define ADMINISTRA_H

#include "../Datatypes/DTFecha.h"
#include "../Datatypes/DTDetalleInmueble.h"
#include "../ICollection/interfaces/ICollectible.h"
#include "Enums.h"

class ICollection;
class Inmobiliaria;
class Inmueble;
class Publicacion;

class Administra : public ICollectible {
private:
    DTFecha fecha;
    Inmobiliaria *inmobiliaria;
    Inmueble *inmueble;
    ICollection *publicaciones;

public:
    Administra();
    Administra(DTFecha fecha, Inmobiliaria *inmobiliaria, Inmueble *inmueble);
    virtual ~Administra();

    DTFecha getFecha() const;
    Inmobiliaria *getInmobiliaria() const;
    Inmueble *getInmueble() const;
    ICollection *getPublicaciones() const;

    void vincularInmueble(Inmueble *inmueble);
    void vincularPub(Publicacion *publicacion);
    void desvincularPub(Publicacion *publicacion);
    bool puedePublicar(TipoPublicacion tipo) const;
    bool cumpleInteres(TipoInteres interes) const;
    DTDetalleInmueble obtenerDTDetalle() const;
};

#endif
