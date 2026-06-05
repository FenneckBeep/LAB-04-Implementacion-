#ifndef PUBLICACION_H
#define PUBLICACION_H

#include <string>
#include "../../Datatypes/DTFecha/DTFecha.h"
#include "../../Datatypes/DTPublicacion/DTPublicacion.h"
#include "../../Datatypes/DTDetalleInmueble/DTDetalleInmueble.h"
#include "../../ICollection/interfaces/ICollectible.h"
#include "../../Enums/Enums.h"
using namespace std;

class ICollection;
class Administra;
class Agenda;

class Publicacion : public ICollectible {
private:
    int idPub;
    DTFecha fecha;
    TipoPublicacion tipo;
    string texto;
    double precio;
    bool esActiva;
    Administra *administra;
    ICollection *agendas;

public:
    Publicacion();
    Publicacion(int idPub, DTFecha fecha, TipoPublicacion tipo, string texto,
                double precio, Administra *administra);
    virtual ~Publicacion();

    int getIdPub() ;
    DTFecha getFecha() ;
    TipoPublicacion getTipo() ;
    string getTexto() ;
    double getPrecio() ;
    bool getEsActiva() ;
    Administra *getAdministra() ;
    ICollection *getAgendas() ;

    void desactivar();
    bool desactivar(TipoPublicacion tipo);
    bool puedePublicar(TipoPublicacion tipo, DTFecha fecha) ;
    bool cumpleFiltro(TipoPublicacion tipo, double min, double max, TipoInteres interes) ;
    bool cumpleFiltroPublicacion(TipoPublicacion tipo, double min, double max, TipoInteres interes) ;
    DTPublicacion obtenerDT(string nombreInmobiliaria) ;
    DTDetalleInmueble obtenerDTDetalle() ;
    void vincularAgenda(Agenda *agenda);
    void desvincularAgenda(Agenda *agenda);
    void eliminarAgendas();
};

#endif


