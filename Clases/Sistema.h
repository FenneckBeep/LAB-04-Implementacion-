#ifndef SISTEMA_H
#define SISTEMA_H

#include <string>
#include "../Interfaces/ISistema.h"
#include "Apartamento.h"
#include "Casa.h"
#include "Cliente.h"
#include "Inmobiliaria.h"
#include "Propietario.h"
#include "Publicacion.h"

class IDictionary;
class Usuario;
class Inmueble;

class Sistema : public ISistema {
private:
    IDictionary *usuarios;
    IDictionary *inmuebles;
    IDictionary *publicaciones;
    Inmobiliaria *inmobiliariaRecordada;
    Inmueble *inmuebleRecordado;
    int proximoIdInmueble;
    int proximoIdPublicacion;

    Usuario *buscarUsuario(std::string nickname) const;
    Inmueble *buscarInmueble(int idInm) const;
    Publicacion *buscarPublicacion(int idPub) const;
    DTFecha obtenerFechaActual() const;
    void eliminarPublicacionesDe(Administra *administra);
    void vincularRepresentacion(std::string nicknameInmobiliaria, std::string nicknamePropietario);

public:
    Sistema();
    virtual ~Sistema();

    bool existeUsuario(std::string nickname) const override;
    Status altaCliente(std::string nickname, std::string contrasenia, std::string nombre,
                       std::string email, std::string apellido, std::string documento) override;
    Status altaPropietario(std::string nickname, std::string contrasenia, std::string nombre,
                           std::string email, std::string cuentaBancaria,
                           std::string telefono) override;
    Status altaInmobiliaria(std::string nickname, std::string contrasenia, std::string nombre,
                            std::string email, std::string direccion, std::string telefono,
                            std::string url) override;

    int agregarCasa(std::string nicknamePropietario, std::string direccion, std::string numPuerta,
                    int superficie, int anioConstruccion, bool esHorizontal,
                    TipoTecho techo) override;
    int agregarApartamento(std::string nicknamePropietario, std::string direccion,
                           std::string numPuerta, int superficie, int anioConstruccion,
                           int numPiso, bool tieneAscensor, double gastosComunes) override;

    ICollection *listarInmobiliarias() override;
    ICollection *listarInmuebles(std::string nickname) override;
    ICollection *listarInmueblesAdministrados(std::string nickname) override;
    Status administrarInmueble(int idInm) override;

    Status altaPublicacion(int idInm, TipoPublicacion tipo, std::string texto,
                           double precio) override;
    ICollection *listarPublicaciones(TipoPublicacion tipo, double min, double max,
                                     TipoInteres interes) override;
    DTDetalleInmueble consultarDetalleInmueble(int idPub) override;

    ICollection *listarInmuebles() override;
    DTDetalleInmueble ingresarCodigoInmueble(int idInm) override;
    Status eliminarInmueble() override;

    void cargarDatosPrueba() override;
};

#endif
