#ifndef PONTO_H
#define PONTO_H

#include <string>
#include "Geometria.h"

class Ponto : public Geometria
{
private:

public:
    Ponto (int i, Geometry *);
    virtual ~Ponto ();

    float getIvdnMedio ();
    void imprimeInfo ();
    int getTipo ();
};

#endif // PONTO_H
