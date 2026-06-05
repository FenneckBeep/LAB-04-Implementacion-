#ifndef SISTEMA_H
#define SISTEMA_H

#include "ISistema.h"
#include "../Apartamento/Apartamento.h"
#include "../Casa/Casa.h"
#include "../Cliente/Cliente.h"
#include "../Inmobiliaria/Inmobiliaria.h"
#include "../Propietario/Propietario.h"
#include "../Publicacion/Publicacion.h"

class IDictionary;
class Usuario;
class Inmueble;

class Sistema : public ISistema
{
private:
    IDictionary *usuarios;
    IDictionary *inmuebles;
    IDictionary *publicaciones;
    Inmobiliaria *inmobiliariaRecordada;
    Inmueble *inmuebleRecordado;
    Propietario *propietarioRecordado;
    std::string nicknameRecordado;
    std::string contraseniaRecordada;
    std::string nombreRecordado;
    std::string emailRecordado;
    std::string direccionInmuebleRecordada;
    std::string numPuertaInmuebleRecordada;
    int superficieInmuebleRecordada;
    int anioConstruccionRecordado;
    bool hayUsuarioRecordado;
    bool hayInmuebleRecordado;
    int proximoIdInmueble;
    int proximoIdPublicacion;

    Usuario *buscarUsuario(std::string nickname);
    Inmueble *buscarInmueble(int idInm);
    Publicacion *buscarPublicacion(int idPub);
    DTFecha obtenerFechaActual();
    void eliminarPublicacionesDe(Administra *administra);
    void vincularRepresentacion(std::string nicknameInmobiliaria, std::string nicknamePropietario);

public:
    Sistema();
    virtual ~Sistema();

    bool existeUsuario(std::string nickname);
    Status existeUsuario(std::string nickname, std::string contrasenia, std::string nombre, std::string email) ;
    Status altaUsuario_Cliente(std::string apellido, std::string documento) ;
    Status altaUsuario_Propietario(std::string cuentaBancaria, std::string telefono) ;
    Status altaUsuario_Inmobiliaria(std::string direccion, std::string telefono, std::string url) ;
    Status altaCliente(std::string nickname, std::string contrasenia, std::string nombre, std::string email, std::string apellido, std::string documento) ;
    Status altaPropietario(std::string nickname, std::string contrasenia, std::string nombre, std::string email, std::string cuentaBancaria, std::string telefono) ;
    Status altaInmobiliaria(std::string nickname, std::string contrasenia, std::string nombre, std::string email, std::string direccion, std::string telefono, std::string url) ;

    int agregarCasa(std::string nicknamePropietario, std::string direccion, std::string numPuerta, int superficie, int anioConstruccion, bool esHorizontal, TipoTecho techo) ;
    int agregarApartamento(std::string nicknamePropietario, std::string direccion, std::string numPuerta, int superficie, int anioConstruccion, int numPiso, bool tieneAscensor, double gastosComunes) ;

    ICollection *listarPropietarios() ;
    Status agregarPropietario(std::string nickname) ;
    Status agregarInmueble(std::string direccion, std::string numPuerta, int superficie, int anioConstruccion) ;
    int agregarCasa(bool esHorizontal, TipoTecho techo) ;
    int agregarApartamento(int numPiso, bool tieneAscensor, double gastosComunes) ;
    Status representarPropietario(string nicknameInmobiliaria, string nicknamePropietario) ;

    ICollection *listarInmobiliarias() ;
    ICollection *listarInmuebles(std::string nickname) ;
    ICollection *listarInmueblesAdministrados(std::string nickname) ;
    Status administrarInmueble(int idInm) ;

    Status altaPublicacion(int idInm, TipoPublicacion tipo, std::string texto, double precio) ;
    ICollection *listarPublicaciones(TipoPublicacion tipo, double min, double max, TipoInteres interes) ;
    DTDetalleInmueble consultarDetalleInmueble(int idPub) ;

    ICollection *listarInmuebles() ;
    DTDetalleInmueble ingresarCodigoInmueble(int idInm) ;
    Status eliminarInmueble() ;

    void cargarDatosPrueba() ;
};

#endif
