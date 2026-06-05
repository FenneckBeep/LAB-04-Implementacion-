#include "Usuario.h"

Usuario::Usuario()
    : nickname(""), contrasenia(""), nombre(""), email("") {}

// Clase base para los tres tipos de usuario del sistema.
Usuario::Usuario(std::string nickname, std::string contrasenia,
                 std::string nombre, std::string email)
    : nickname(nickname), contrasenia(contrasenia), nombre(nombre), email(email) {}

Usuario::~Usuario() {}

std::string Usuario::getNickname() {
    return nickname;
}

std::string Usuario::getContrasenia() {
    return contrasenia;
}

std::string Usuario::getNombre() {
    return nombre;
}

std::string Usuario::getEmail() {
    return email;
}
