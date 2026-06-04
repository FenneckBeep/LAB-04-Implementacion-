#ifndef DTDETALLEINMUEBLE_H
#define DTDETALLEINMUEBLE_H

#include <string>
#include "../Clases/Enums.h"
#include "../ICollection/interfaces/ICollectible.h"

class DTDetalleInmueble : public ICollectible {
private:
    int idInm;
    std::string direccion;
    std::string numPuerta;
    int superficie;
    int anioConstruccion;
    TipoInmueble tipo;
    std::string descripcionExtra;

public:
    DTDetalleInmueble();
    DTDetalleInmueble(int idInm, std::string direccion, std::string numPuerta,
                      int superficie, int anioConstruccion, TipoInmueble tipo);
    DTDetalleInmueble(int idInm, std::string direccion, std::string numPuerta,
                      int superficie, int anioConstruccion, TipoInmueble tipo,
                      std::string descripcionExtra);
    virtual ~DTDetalleInmueble();

    int getIdInm() const;
    std::string getDireccion() const;
    std::string getNumPuerta() const;
    int getSuperficie() const;
    int getAnioConstruccion() const;
    TipoInmueble getTipo() const;
    std::string getDescripcionExtra() const;
};

#endif
