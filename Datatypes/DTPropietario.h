#ifndef DTPROPIETARIO_H
#define DTPROPIETARIO_H

#include <string>
#include "../ICollection/interfaces/ICollectible.h"

class DTPropietario : public ICollectible {
private:
    std::string nickname;
    std::string nombre;

public:
    DTPropietario();
    DTPropietario(std::string nickname, std::string nombre);
    virtual ~DTPropietario();

    std::string getNickname() const;
    std::string getNombre() const;
};

#endif
