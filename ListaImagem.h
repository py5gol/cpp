#ifndef LISTAIMAGEM_H
#define LISTAIMAGEM_H

#include <iostream>
#include <fstream>
#include <list>
#include "Imagem.h"
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
    void detalhar (int);
    
    void salvar ();
    void carregar ();
};

#endif // LISTAIMAGEM_H
