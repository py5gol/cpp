#include "Linha.h"

Linha::Linha (int i, Geometry * g) : Geometria (i, g) {
}

Linha::~Linha () {
}

float Linha::getIvdnMedio () {
    return 0.75;
}

void Linha::imprimeInfo () {
    cout << "Geometria:" << endl;
    cout << "Tipo: Linha" << endl;
}

int Linha::getTipo () {
    return 2;
}

