#ifndef CLIENTE_H
#define CLIENTE_H

#include "../Usuario/Usuario.h"
using namespace std;

class ICollection;
class Agenda;

class Cliente : public Usuario {
private:
    string apellido;
    string documento;
    ICollection *agendas;

public:
    Cliente();
    Cliente(string nickname, string contrasenia, string nombre, string email,
            string apellido, string documento);
    virtual ~Cliente();

    string getApellido() ;
    string getDocumento() ;
    ICollection *getAgendas() ;

    void vincularAgenda(Agenda *agenda);
    void desvincularAgenda(Agenda *agenda);
    TipoUsuario obtenerTipoUser()  override;
};

#endif


