#ifndef ISISTEMA_H
#define ISISTEMA_H
using namespace std;

#include <string>
#include "../Clases/Enums.h"
#include "../Datatypes/DTDetalleInmueble.h"

class ICollection;

class ISistema
{
public:
    virtual bool existeUsuario(string nickname) = 0;

    virtual Status altaCliente(string nickname, string apellido, string documento) = 0;
    virtual Status altaPropietario(string nickname, string contrasenia, string nombre, string email, string cuentaBancaria, string telefono) = 0;
    virtual Status altaInmobiliaria(string nickname, string contrasenia, string nombre, string email, string direccion, string telefono, string url) = 0;

    virtual int agregarCasa(string nicknamePropietario, string direccion, string numPuerta, int superficie, int anioConstruccion, bool esHorizontal, TipoTecho techo) = 0;
    virtual int agregarApartamento(string nicknamePropietario, string direccion, string numPuerta, int superficie, int anioConstruccion, int numPiso, bool tieneAscensor, double gastosComunes) = 0;

    virtual ICollection *listarInmobiliarias() = 0;
    virtual ICollection *listarInmuebles(string nickname) = 0;
    virtual ICollection *listarInmueblesAdministrados(string nickname) = 0;
    virtual Status administrarInmueble(int idInm) = 0;

    virtual Status altaPublicacion(int idInm, TipoPublicacion tipo, string texto, double precio) = 0;
    virtual ICollection *listarPublicaciones(TipoPublicacion tipo, double min, double max, TipoInteres interes) = 0;
    virtual DTDetalleInmueble consultarDetalleInmueble(int idPub) = 0;

    virtual ICollection *listarInmuebles() = 0;
    virtual DTDetalleInmueble ingresarCodigoInmueble(int idInm) = 0;
    virtual Status eliminarInmueble() = 0;

    virtual void cargarDatosPrueba() = 0;
    virtual ~ISistema() {}
};

#endif
