#include "Ponto.h"

Ponto::Ponto (int i, Geometry * g) : Geometria (i, g) {
}

Ponto::~Ponto () {
}

float Ponto::getIvdnMedio () {
    return 0.85;
}

void Ponto::imprimeInfo () {
    cout << "Geometria:" << endl;
    cout << "Tipo: Ponto" << endl;
}

int Ponto::getTipo () {
    return 1;
}

