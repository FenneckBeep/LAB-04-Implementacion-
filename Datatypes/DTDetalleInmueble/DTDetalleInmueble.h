#ifndef DTDETALLEINMUEBLE_H
#define DTDETALLEINMUEBLE_H

#include <string>
#include "../../Enums/Enums.h"
#include "../../ICollection/interfaces/ICollectible.h"
using namespace std;

class DTDetalleInmueble : public ICollectible {
private:
    int idInm;
    string direccion;
    string numPuerta;
    int superficie;
    int anioConstruccion;
    TipoInmueble tipo;
    string descripcionExtra;

public:
    DTDetalleInmueble();
    DTDetalleInmueble(int idInm, string direccion, string numPuerta,
                      int superficie, int anioConstruccion, TipoInmueble tipo);
    DTDetalleInmueble(int idInm, string direccion, string numPuerta,
                      int superficie, int anioConstruccion, TipoInmueble tipo,
                      string descripcionExtra);
    virtual ~DTDetalleInmueble();

    int getIdInm() ;
    string getDireccion() ;
    string getNumPuerta() ;
    int getSuperficie() ;
    int getAnioConstruccion() ;
    TipoInmueble getTipo() ;
    string getDescripcionExtra() ;
};

#endif


