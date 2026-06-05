#include "DTInmuebleAdministrado.h"
using namespace std;

DTInmuebleAdministrado::DTInmuebleAdministrado() : idInm(0) {}

DTInmuebleAdministrado::DTInmuebleAdministrado(int idInm, string direccion,
                                               string nombreProp)
    : idInm(idInm), direccion(direccion), nombreProp(nombreProp) {}

DTInmuebleAdministrado::~DTInmuebleAdministrado() {}

int DTInmuebleAdministrado::getIdInm()  {
    return idInm;
}

string DTInmuebleAdministrado::getDireccion()  {
    return direccion;
}

string DTInmuebleAdministrado::getNombreProp()  {
    return nombreProp;
}


