#ifndef DTINMOBILIARIA_H
#define DTINMOBILIARIA_H

#include <string>
#include "../ICollection/interfaces/ICollectible.h"

class DTInmobiliaria : public ICollectible {
private:
    std::string nickname;
    std::string nombre;

public:
    DTInmobiliaria();
    DTInmobiliaria(std::string nickname, std::string nombre);
    virtual ~DTInmobiliaria();

    std::string getNickname() const;
    std::string getNombre() const;
};

#endif
