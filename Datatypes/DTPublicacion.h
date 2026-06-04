#ifndef DTPUBLICACION_H
#define DTPUBLICACION_H

#include <string>
#include "../Clases/Enums.h"
#include "../ICollection/interfaces/ICollectible.h"
#include "DTFecha.h"

class DTPublicacion : public ICollectible {
private:
    int idPub;
    DTFecha fecha;
    TipoPublicacion tipo;
    std::string texto;
    double precio;
    std::string nombreInmobiliaria;

public:
    DTPublicacion();
    DTPublicacion(int idPub, DTFecha fecha, TipoPublicacion tipo, std::string texto,
                  double precio, std::string nombreInmobiliaria);
    virtual ~DTPublicacion();

    int getIdPub() const;
    DTFecha getFecha() const;
    TipoPublicacion getTipo() const;
    std::string getTexto() const;
    double getPrecio() const;
    std::string getNombreInmobiliaria() const;
};

#endif
