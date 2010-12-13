#include "Poligono.h"

Poligono::Poligono (int i, Geometry * g) : Geometria (i, g) {
}

Poligono::~Poligono () {
}

float Poligono::getIvdnMedio () {
    return 0.65;
}

void Poligono::imprimeInfo () {
    cout << "Geometria:" << endl;
    cout << "Tipo: Poligono" << endl;
}

int Poligono::getTipo () {
    return 3;
}

