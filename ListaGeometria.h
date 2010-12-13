#ifndef LISTAGEOMETRIA_H
#define LISTAGEOMETRIA_H

#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include "Geometria.h"
#include "Ponto.h"
#include "Linha.h"
#include "Poligono.h"
#include "stdlib.h"

using namespace std;

class ListaGeometria
{
private:
    list<Geometria*> lista;
    io::WKTWriter * writer;

public:
    ListaGeometria ();
    virtual ~ListaGeometria ();

    void incluir (int, string);
    void listar ();
    void excluir (int);
    void detalhar (int);
    
    void salvar ();
    void carregar ();

    list<Geometria*>::const_iterator begin ();
    list<Geometria*>::const_iterator end ();
    
};

#endif // LISTAGEOMETRIA_H
