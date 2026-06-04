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

    std::string getCuentaBancaria() const;
    std::string getTelefono() const;
    ICollection *getInmuebles() const;
    ICollection *getInmobiliarias() const;

    void vincularInmueble(Inmueble *inmueble);
    void desvincularInmueble(Inmueble *inmueble);
    void vincularInmobiliaria(Inmobiliaria *inmobiliaria);
    void desvincularInmobiliaria(Inmobiliaria *inmobiliaria);
    TipoUsuario obtenerTipoUser() const override;
};

#endif
