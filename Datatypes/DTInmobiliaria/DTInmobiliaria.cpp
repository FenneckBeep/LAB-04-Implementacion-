#include "DTInmobiliaria.h"
using namespace std;

DTInmobiliaria::DTInmobiliaria() {}

DTInmobiliaria::DTInmobiliaria(string nickname, string nombre)
    : nickname(nickname), nombre(nombre) {}

DTInmobiliaria::~DTInmobiliaria() {}

string DTInmobiliaria::getNickname()  {
    return nickname;
}

string DTInmobiliaria::getNombre()  {
    return nombre;
}


