#include "DTPropietario.h"
using namespace std;

DTPropietario::DTPropietario() : nickname(""), nombre("") {}

DTPropietario::DTPropietario(string nickname, string nombre)
    : nickname(nickname), nombre(nombre) {}

DTPropietario::~DTPropietario() {}

string DTPropietario::getNickname()  { return nickname; }
string DTPropietario::getNombre()  { return nombre; }


