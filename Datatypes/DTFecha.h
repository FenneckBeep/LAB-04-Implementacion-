#ifndef DTFECHA_H
#define DTFECHA_H

class DTFecha {
private:
    int dia;
    int mes;
    int anio;

public:
    DTFecha();
    DTFecha(int dia, int mes, int anio);

    int getDia() const;
    int getMes() const;
    int getAnio() const;
};

#endif
