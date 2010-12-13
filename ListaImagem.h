#ifndef LISTAIMAGEM_H
#define LISTAIMAGEM_H

#include <list>
#include "Imagem.h"

#include <iostream>
using std::cout;
using std::endl;

using namespace std;

class ListaImagem
{
private:
    list<Imagem*> lista;
    
public:
    ListaImagem ();

    virtual ~ListaImagem ();

    void incluir (char *);
    void listar ();
    void excluir (int);
};

#endif // LISTAIMAGEM_H
