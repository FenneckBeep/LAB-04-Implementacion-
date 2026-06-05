#ifndef DTINMUEBLE_H
#define DTINMUEBLE_H

#include <string>
#include "../../ICollection/interfaces/ICollectible.h"
using namespace std;

class DTInmueble : public ICollectible {
private:
    int idInm;
    string direccion;
    string nombreProp;

public:
    DTInmueble();
    DTInmueble(int idInm, string direccion, string nombreProp);
    virtual ~DTInmueble();

    int getIdInm() ;
    string getDireccion() ;
    string getNombreProp() ;
};

#endif


