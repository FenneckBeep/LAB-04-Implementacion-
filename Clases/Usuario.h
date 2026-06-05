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

    std::string getNickname();
    std::string getContrasenia();
    std::string getNombre();
    std::string getEmail();

    virtual TipoUsuario obtenerTipoUser() = 0;
};

#endif
