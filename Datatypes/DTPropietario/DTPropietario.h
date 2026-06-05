#ifndef DTPROPIETARIO_H
#define DTPROPIETARIO_H

#include <string>
#include "../../ICollection/interfaces/ICollectible.h"
using namespace std;

class DTPropietario : public ICollectible {
private:
    string nickname;
    string nombre;

public:
    DTPropietario();
    DTPropietario(string nickname, string nombre);
    virtual ~DTPropietario();

    string getNickname() ;
    string getNombre() ;
};

#endif


