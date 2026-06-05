#include "SistemaFactory.h"
using namespace std;


ISistema *SistemaFactory::sistema = nullptr;

ISistema *SistemaFactory::getSistema() {
    if (sistema == nullptr) {
        sistema = new Sistema();
    }
    return sistema;
}

void SistemaFactory::destruirSistema() {
    delete sistema;
    sistema = nullptr;
}
