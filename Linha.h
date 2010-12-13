#ifndef LINHA_H
#define LINHA_H
#include "Geometria.h"

class Linha : public Geometria
{
private:

public:
    Linha (int, Geometry *);
    virtual ~Linha ();

    float getIvdnMedio ();
    void imprimeInfo ();
    int getTipo ();
};

#endif // LINHA_H
