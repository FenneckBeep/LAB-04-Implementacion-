#ifndef AGENDA_H
#define AGENDA_H

#include <string>
#include "../Datatypes/DTFecha.h"
#include "../ICollection/interfaces/ICollectible.h"

class Cliente;
class Publicacion;

class Agenda : public ICollectible {
private:
    DTFecha visita;
    std::string metodoContacto;
    Cliente *cliente;
    Publicacion *publicacion;

public:
    Agenda();
    Agenda(DTFecha visita, std::string metodoContacto, Cliente *cliente, Publicacion *publicacion);
    virtual ~Agenda();

    DTFecha getVisita() const;
    std::string getMetodoContacto() const;
    Cliente *getCliente() const;
    Publicacion *getPublicacion() const;

    void desvincularCliente();
    void desvincularPublicacion();
};

#endif
