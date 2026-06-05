#ifndef INMUEBLE_H
#define INMUEBLE_H

#include <iostream>
#include <string>
#include "../../Datatypes/DTDetalleInmueble/DTDetalleInmueble.h"
#include "../../Datatypes/DTInmueble/DTInmueble.h"
#include "../../Datatypes/DTInmuebleAdministrado/DTInmuebleAdministrado.h"
#include "../../Datatypes/DTFecha/DTFecha.h"
#include "../../ICollection/interfaces/ICollectible.h"
#include "../Administra/Administra.h"
#include "../Propietario/Propietario.h"
#include "../Administra/Administra.h"
#include "../Inmobiliaria/Inmobiliaria.h"
#include "../Publicacion/Publicacion.h"
#include "../../ICollection/collections/List.h"
#include "../../ICollection/interfaces/IIterator.h"
#include "../../Enums/Enums.h"
using namespace std;

class Inmueble : public ICollectible {
private:
    int idInm;
    string direccion;
    string numPuerta;
    int superficie;
    int anioConstruccion;
    Propietario *propietario;
    ICollection *administraciones;

public:
    Inmueble();
    Inmueble(int idInm, string direccion, string numPuerta, int superficie,
             int anioConstruccion, Propietario *propietario);
    virtual ~Inmueble();

    int getIdInm() ;
    string getDireccion() ;
    string getNumPuerta() ;
    int getSuperficie() ;
    int getAnioConstruccion() ;
    Propietario *getPropietario() ;
    ICollection *getAdministraciones() ;

    void vincularPropietario(Propietario *propietario);
    void vincularInmobiliaria(Inmobiliaria *inmobiliaria);
    void vincularPubAdmin(Publicacion *publicacion);
    void eliminarAsociaciones();

    DTInmueble obtenerDT(string nombreProp) ;
    DTInmuebleAdministrado obtenerDTAdministrado() ;
    virtual DTDetalleInmueble obtenerDTDetalle() ;
    virtual TipoInmueble obtenerTipoInmueble()  = 0;
    bool puedePublicar(int idPub, TipoPublicacion tipo, DTFecha fecha) ;
    void vincularAdministracion(Administra *administra);
    void desvincularAdministracion(Administra *administra);
    void desvincularPropietario();
};

#endif


