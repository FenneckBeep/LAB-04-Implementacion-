#ifndef DTINMUEBLEADMINISTRADO_H
#define DTINMUEBLEADMINISTRADO_H

#include <string>
#include "../../ICollection/interfaces/ICollectible.h"
using namespace std;

class DTInmuebleAdministrado : public ICollectible {
private:
    int idInm;
    string direccion;
    string nombreProp;

public:
    DTInmuebleAdministrado();
    DTInmuebleAdministrado(int idInm, string direccion, string nombreProp);
    virtual ~DTInmuebleAdministrado();

    int getIdInm() ;
    string getDireccion() ;
    string getNombreProp() ;
};

#endif


