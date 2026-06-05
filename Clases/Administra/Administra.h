#ifndef ADMINISTRA_H
#define ADMINISTRA_H

#include <iostream>
#include "../../ICollection/interfaces/ICollectible.h"
#include "../Publicacion/Publicacion.h"
#include "../Inmobiliaria/Inmobiliaria.h"
#include "../Inmueble/Inmueble.h"
#include "../../Datatypes/DTFecha/DTFecha.h"
#include "../../Datatypes/DTDetalleInmueble/DTDetalleInmueble.h"

#include "../../Enums/Enums.h"

class Administra : public ICollectible {
private:
    DTFecha fecha;
    ICollection *inmobiliarias;
    Inmueble *inmueble;
    ICollection *publicaciones;

public:
    Administra();
    Administra(DTFecha fecha, Inmobiliaria *inmobiliaria, Inmueble *inmueble);
    virtual ~Administra();

    DTFecha getFecha();
    ICollection *getInmobiliarias();
    Inmobiliaria *getInmobiliaria();
    Inmueble *getInmueble();
    ICollection *getPublicaciones();

    void vincularInmobiliaria(Inmobiliaria *inmobiliaria);
    void desvincularInmobiliaria(Inmobiliaria *inmobiliaria);
    void vincularPub(Publicacion *publicacion);
    void desvincularPub(Publicacion *publicacion);
    bool puedePublicar(TipoPublicacion tipo);
    bool puedePublicar(int idPub, TipoPublicacion tipo, DTFecha fecha);
    void desactivarPublicaciones(TipoPublicacion tipo);
    bool cumpleInteres(TipoInteres interes);
    DTDetalleInmueble obtenerDTDetalle();
};

#endif
