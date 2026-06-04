#ifndef DTINMUEBLE_H
#define DTINMUEBLE_H

#include <string>
#include "../ICollection/interfaces/ICollectible.h"

class DTInmueble : public ICollectible {
private:
    int idInm;
    std::string direccion;
    std::string nombreProp;

public:
    DTInmueble();
    DTInmueble(int idInm, std::string direccion, std::string nombreProp);
    virtual ~DTInmueble();

    int getIdInm() const;
    std::string getDireccion() const;
    std::string getNombreProp() const;
};

#endif
