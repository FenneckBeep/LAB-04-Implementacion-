#ifndef DTPUBLICACION_H
#define DTPUBLICACION_H

#include <string>
#include "../../Enums/Enums.h"
#include "../../ICollection/interfaces/ICollectible.h"
#include "../DTFecha/DTFecha.h"
using namespace std;

class DTPublicacion : public ICollectible {
private:
    int idPub;
    DTFecha fecha;
    TipoPublicacion tipo;
    string texto;
    double precio;
    string nombreInmobiliaria;

public:
    DTPublicacion();
    DTPublicacion(int idPub, DTFecha fecha, TipoPublicacion tipo, string texto,
                  double precio, string nombreInmobiliaria);
    virtual ~DTPublicacion();

    int getIdPub() ;
    DTFecha getFecha() ;
    TipoPublicacion getTipo() ;
    string getTexto() ;
    double getPrecio() ;
    string getNombreInmobiliaria() ;
};

#endif


