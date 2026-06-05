#ifndef SISTEMAFACTORY_H
#define SISTEMAFACTORY_H
#include "../Sistema/ISistema.h"
#include "../Sistema/Sistema.h"

class SistemaFactory {
private:
    static ISistema *sistema;

public:
    static ISistema *getSistema();
    static void destruirSistema();
};

#endif
