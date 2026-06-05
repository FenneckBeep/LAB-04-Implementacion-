#ifndef DTINMOBILIARIA_H
#define DTINMOBILIARIA_H

#include <string>
#include "../../ICollection/interfaces/ICollectible.h"
using namespace std;

class DTInmobiliaria : public ICollectible {
private:
    string nickname;
    string nombre;

public:
    DTInmobiliaria();
    DTInmobiliaria(string nickname, string nombre);
    virtual ~DTInmobiliaria();

    string getNickname() ;
    string getNombre() ;
};

#endif


