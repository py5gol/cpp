#ifndef POLIGONO_H
#define POLIGONO_H
#include "Geometria.h"

class Poligono : public Geometria
{
private:

public:
    Poligono (int, Geometry *);
    virtual ~Poligono ();

    float getIvdnMedio ();
    void imprimeInfo ();
    int getTipo ();
};

#endif // POLIGONO_H
