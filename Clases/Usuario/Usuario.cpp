#include "Usuario.h"
using namespace std;

Usuario::Usuario() {}

Usuario::Usuario(string nickname, string contrasenia, string nombre, string email)
    : nickname(nickname), contrasenia(contrasenia), nombre(nombre), email(email) {}

Usuario::~Usuario() {}

string Usuario::getNickname() { 
    return nickname; 
}
string Usuario::getContrasenia() { 
    return contrasenia; 
}
string Usuario::getNombre() { 
    return nombre; 
}
string Usuario::getEmail() { 
    return email; 
}