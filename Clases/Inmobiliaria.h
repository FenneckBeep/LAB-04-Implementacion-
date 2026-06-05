#ifndef INMOBILIARIA_H
#define INMOBILIARIA_H

#include "Usuario.h"
#include "../Datatypes/DTInmobiliaria.h"
#include "../Datatypes/DTInmueble.h"
#include "../Datatypes/DTFecha.h"

class ICollection;
class Propietario;
class Inmueble;
class Administra;

class Inmobiliaria : public Usuario {
private:
    std::string direccion;
    std::string telefono;
    std::string url;
    ICollection *propietarios;
    ICollection *administraciones;

public:
    Inmobiliaria();
    Inmobiliaria(std::string nickname, std::string contrasenia, std::string nombre, std::string email,
                 std::string direccion, std::string telefono, std::string url);
    virtual ~Inmobiliaria();

    std::string getDireccion();
    std::string getTelefono();
    std::string getUrl();
    ICollection *getPropietarios();
    ICollection *getAdministraciones();

    DTInmobiliaria obtenerDT();
    ICollection *listarInmuebles();
    ICollection *listarInmueblesAdministrados();
    bool representa(Propietario *propietario);
    Administra *obtenerAdministracionDe(Inmueble *inmueble);
    void vincularPropietario(Propietario *propietario);
    void desvincularPropietario(Propietario *propietario);
    Administra *administrarInmueble(Inmueble *inmueble, DTFecha fechaActual);
    void vincularAdministracion(Administra *administra);
    void desvincularAdministracion(Administra *administra);
    TipoUsuario obtenerTipoUser() override;
};

#endif
