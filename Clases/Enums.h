#ifndef ENUMS_H
#define ENUMS_H

enum class TipoTecho {
    liviano,
    dosAguas,
    plano
};

enum class TipoPublicacion {
    venta,
    alquiler
};

enum class TipoUsuario {
    cliente,
    inmobiliaria,
    propietario
};

enum class TipoInmueble {
    casa,
    apartamento
};

enum class TipoInteres {
    todos,
    casa,
    apartamento
};

enum class Status {
    ok,
    error
};

#endif
