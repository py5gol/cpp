#include "ListaImagem.h"

ListaImagem::ListaImagem () {
}

ListaImagem::~ListaImagem () {
}

void ListaImagem::incluir (char * s) {

    int t = lista.size ();
    
    Imagem * img = new Imagem ( t, s );
    
    lista.push_back (img);

}

void ListaImagem::listar () {

    list<Imagem *>::const_iterator it;
    
    for (it = lista.begin(); it != lista.end(); it++) {
        cout << (*it)->getNome() << endl;
    }

}

