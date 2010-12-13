#ifndef IVDNCONTROLE_H
#define IVDNCONTROLE_H
#include "ListaImagem.h"
#include "ListaGeometria.h"

class IvdnControle
{
public:
    IvdnControle ();
    virtual ~IvdnControle ();
    void calculaIvdn (ListaImagem &, ListaGeometria &);

};

#endif // POLIGONO_H
