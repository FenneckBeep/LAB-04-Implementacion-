#ifndef INMOBILIARIA_H
#define INMOBILIARIA_H

#include "../Usuario/Usuario.h"
#include "../../Datatypes/DTInmobiliaria/DTInmobiliaria.h"
#include "../../Datatypes/DTInmueble/DTInmueble.h"
#include "../../Datatypes/DTFecha/DTFecha.h"

class ICollection;
class Propietario;
class Inmueble;
class Administra;

class Inmobiliaria : public Usuario {
private:
    string direccion;
    string telefono;
    string url;
    ICollection *propietarios;
    ICollection *administraciones;

public:
    Inmobiliaria();
    Inmobiliaria(string nickname, string contrasenia, string nombre, string email,
                 string direccion, string telefono, string url);
    virtual ~Inmobiliaria();

    string getDireccion() ;
    string getTelefono() ;
    string getUrl() ;
    ICollection *getPropietarios() ;
    ICollection *getAdministraciones() ;

    DTInmobiliaria obtenerDT() ;
    ICollection *listarInmuebles() ;
    ICollection *listarInmueblesAdministrados() ;
    bool representa(Propietario *propietario) ;
    Administra *obtenerAdministracionDe(Inmueble *inmueble) ;
    void vincularPropietario(Propietario *propietario);
    void desvincularPropietario(Propietario *propietario);
    Administra *administrarInmueble(Inmueble *inmueble, DTFecha fechaActual);
    void vincularAdministracion(Administra *administra);
    void desvincularAdministracion(Administra *administra);
    TipoUsuario obtenerTipoUser()  override;
};

#endif


