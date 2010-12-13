#include "Geometria.h"

Geometria::Geometria (int i, Geometry * g) { 

    codigo = i;
    geometria = g;

}

Geometria::~Geometria () {}

int Geometria::getCodigo () { return codigo; }

Geometry * Geometria::getGeometria () { return geometria; }

