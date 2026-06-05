#include "DTFecha.h"
using namespace std;

DTFecha::DTFecha() : dia(1), mes(1), anio(2026) {}

DTFecha::DTFecha(int dia, int mes, int anio) : dia(dia), mes(mes), anio(anio) {}

int DTFecha::getDia()  {
    return dia;
}

int DTFecha::getMes()  {
    return mes;
}

int DTFecha::getAnio()  {
    return anio;
}

