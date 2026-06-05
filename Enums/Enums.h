#ifndef ENUMS_H
#define ENUMS_H

enum class TipoTecho {
    LIVIANO,
    PESADO,
    DOS_AGUAS
};

enum class TipoPublicacion {
    VENTA,
    ALQUILER
};

enum class TipoUsuario {
    CLIENTE,
    INMOBILIARIA,
    PROPIETARIO
};

enum class TipoInmueble {
    CASA,
    APARTAMENTO
};

enum class TipoInteres {
    AMBOS,
    CASA,
    APARTAMENTO
};

enum class Status {
    OK,
    ERROR
};

#endif
