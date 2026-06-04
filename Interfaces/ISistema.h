#ifndef ISISTEMA_H
#define ISISTEMA_H

#include <string>
#include "../Clases/Enums.h"
#include "../Datatypes/DTDetalleInmueble.h"

class ICollection;

class ISistema {
public:
    virtual bool existeUsuario(std::string nickname) const = 0;

    virtual Status altaCliente(std::string nickname, std::string contrasenia, std::string nombre,
                               std::string email, std::string apellido, std::string documento) = 0;
    virtual Status altaPropietario(std::string nickname, std::string contrasenia, std::string nombre,
                                   std::string email, std::string cuentaBancaria,
                                   std::string telefono) = 0;
    virtual Status altaInmobiliaria(std::string nickname, std::string contrasenia, std::string nombre,
                                    std::string email, std::string direccion, std::string telefono,
                                    std::string url) = 0;

    virtual int agregarCasa(std::string nicknamePropietario, std::string direccion,
                            std::string numPuerta, int superficie, int anioConstruccion,
                            bool esHorizontal, TipoTecho techo) = 0;
    virtual int agregarApartamento(std::string nicknamePropietario, std::string direccion,
                                   std::string numPuerta, int superficie, int anioConstruccion,
                                   int numPiso, bool tieneAscensor, double gastosComunes) = 0;

    virtual ICollection *listarInmobiliarias() = 0;
    virtual ICollection *listarInmuebles(std::string nickname) = 0;
    virtual ICollection *listarInmueblesAdministrados(std::string nickname) = 0;
    virtual Status administrarInmueble(int idInm) = 0;

    virtual Status altaPublicacion(int idInm, TipoPublicacion tipo, std::string texto,
                                   double precio) = 0;
    virtual ICollection *listarPublicaciones(TipoPublicacion tipo, double min, double max,
                                             TipoInteres interes) = 0;
    virtual DTDetalleInmueble consultarDetalleInmueble(int idPub) = 0;

    virtual ICollection *listarInmuebles() = 0;
    virtual DTDetalleInmueble ingresarCodigoInmueble(int idInm) = 0;
    virtual Status eliminarInmueble() = 0;

    virtual void cargarDatosPrueba() = 0;
    virtual ~ISistema() {}
};

#endif
