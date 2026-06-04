#ifndef PUBLICACION_H
#define PUBLICACION_H

#include <string>
#include "../Datatypes/DTFecha.h"
#include "../Datatypes/DTPublicacion.h"
#include "../Datatypes/DTDetalleInmueble.h"
#include "../ICollection/interfaces/ICollectible.h"
#include "Enums.h"

class ICollection;
class Administra;
class Agenda;

class Publicacion : public ICollectible {
private:
    int idPub;
    DTFecha fecha;
    TipoPublicacion tipo;
    std::string texto;
    double precio;
    bool esActiva;
    Administra *administra;
    ICollection *agendas;

public:
    Publicacion();
    Publicacion(int idPub, DTFecha fecha, TipoPublicacion tipo, std::string texto,
                double precio, Administra *administra);
    virtual ~Publicacion();

    int getIdPub() const;
    DTFecha getFecha() const;
    TipoPublicacion getTipo() const;
    std::string getTexto() const;
    double getPrecio() const;
    bool getEsActiva() const;
    Administra *getAdministra() const;
    ICollection *getAgendas() const;

    void desactivar();
    bool cumpleFiltro(TipoPublicacion tipo, double min, double max, TipoInteres interes) const;
    DTPublicacion obtenerDT(std::string nombreInmobiliaria) const;
    DTDetalleInmueble obtenerDTDetalle() const;
    void vincularAgenda(Agenda *agenda);
    void desvincularAgenda(Agenda *agenda);
    void eliminarAgendas();
};

#endif
