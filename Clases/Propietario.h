#ifndef PROPIETARIO_H
#define PROPIETARIO_H

#include "Usuario.h"

class ICollection;
class Inmueble;
class Inmobiliaria;

class Propietario : public Usuario {
private:
    std::string cuentaBancaria;
    std::string telefono;
    ICollection *inmuebles;
    ICollection *inmobiliarias;

public:
    Propietario();
    Propietario(std::string nickname, std::string contrasenia, std::string nombre,
                std::string email, std::string cuentaBancaria, std::string telefono);
    virtual ~Propietario();

    std::string getCuentaBancaria();
    std::string getTelefono();
    ICollection *getInmuebles();
    ICollection *getInmobiliarias();

    void vincularInmueble(Inmueble *inmueble);
    void desvincularInmueble(Inmueble *inmueble);
    void vincularInmobiliaria(Inmobiliaria *inmobiliaria);
    void desvincularInmobiliaria(Inmobiliaria *inmobiliaria);
    TipoUsuario obtenerTipoUser() override;
};

#endif
