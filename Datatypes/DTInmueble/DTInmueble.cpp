#include "DTInmueble.h"
using namespace std;

DTInmueble::DTInmueble() : idInm(0) {}

DTInmueble::DTInmueble(int idInm, string direccion, string nombreProp)
    : idInm(idInm), direccion(direccion), nombreProp(nombreProp) {}

DTInmueble::~DTInmueble() {}

int DTInmueble::getIdInm()  {
    return idInm;
}

string DTInmueble::getDireccion()  {
    return direccion;
}

string DTInmueble::getNombreProp()  {
    return nombreProp;
}


