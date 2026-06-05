#ifndef AGENDA_H
#define AGENDA_H

#include <string>
#include "../../Datatypes/DTFecha/DTFecha.h"
#include "../../ICollection/interfaces/ICollectible.h"
using namespace std;

class Cliente;
class Publicacion;

class Agenda : public ICollectible {
private:
    DTFecha visita;
    string metodoContacto;
    Cliente *cliente;
    Publicacion *publicacion;

public:
    Agenda();
    Agenda(DTFecha visita, string metodoContacto, Cliente *cliente, Publicacion *publicacion);
    virtual ~Agenda();

    DTFecha getVisita() ;
    string getMetodoContacto() ;
    Cliente *getCliente() ;
    Publicacion *getPublicacion() ;

    void desvincularCliente();
    void desvincularPublicacion();
};

#endif


