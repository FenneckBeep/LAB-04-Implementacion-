#ifndef USUARIO_H
#define USUARIO_H

#include <string>
using std::string;
#include "../../Enums/Enums.h"
#include "../../ICollection/interfaces/ICollectible.h"

class Usuario : public ICollectible {
private:
    string nickname;
    string contrasenia;
    string nombre;
    string email;

public:
    Usuario();
    Usuario(string nickname, string contrasenia, string nombre, string email);
    virtual ~Usuario();

    string getNickname() ;
    string getContrasenia() ;
    string getNombre() ;
    string getEmail() ;

    virtual TipoUsuario obtenerTipoUser()  = 0;
};

#endif


