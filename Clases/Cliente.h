#ifndef CLIENTE_H
#define CLIENTE_H

#include "Usuario.h"

class ICollection;
class Agenda;

class Cliente : public Usuario {
private:
    std::string apellido;
    std::string documento;
    ICollection *agendas;

public:
    Cliente();
    Cliente(std::string nickname, std::string contrasenia, std::string nombre, std::string email,
            std::string apellido, std::string documento);
    virtual ~Cliente();

    std::string getApellido() const;
    std::string getDocumento() const;
    ICollection *getAgendas() const;

    void vincularAgenda(Agenda *agenda);
    void desvincularAgenda(Agenda *agenda);
    TipoUsuario obtenerTipoUser() const override;
};

#endif
