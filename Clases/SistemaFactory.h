#ifndef SISTEMAFACTORY_H
#define SISTEMAFACTORY_H

class ISistema;

class SistemaFactory {
private:
    static ISistema *sistema;

public:
    static ISistema *getSistema();
    static void destruirSistema();
};

#endif
