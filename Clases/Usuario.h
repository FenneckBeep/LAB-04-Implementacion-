#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include "Enums.h"
#include "../ICollection/interfaces/ICollectible.h"

class Usuario : public ICollectible {
private:
    std::string nickname;
    std::string contrasenia;
    std::string nombre;
    std::string email;

public:
    Usuario();
    Usuario(std::string nickname, std::string contrasenia, std::string nombre, std::string email);
    virtual ~Usuario();

    std::string getNickname() const;
    std::string getContrasenia() const;
    std::string getNombre() const;
    std::string getEmail() const;

    virtual TipoUsuario obtenerTipoUser() const = 0;
};

#endif
