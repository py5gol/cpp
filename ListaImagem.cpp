#include "ListaImagem.h"

ListaImagem::ListaImagem () {
}

ListaImagem::~ListaImagem () {
}

void ListaImagem::incluir (char * s) {

    int t = lista.size ();
    
    Imagem * img = new Imagem (t, s);
    
    lista.push_back (img);

}

void ListaImagem::excluir (int i) {

    if (lista.size() > 0) {
    
        Imagem * a;
        
        list<Imagem*>::iterator it = lista.begin ();
        
        while (it != lista.end()) {
        
            if ( (*it)->getCodigo() == i ) {
                a = (*it);
            
                it = lista.erase (it);
                cout << "Imagem " << i << " excluido com sucesso." << endl;
                break;
                
            }
            
            it++;
    
        }
    
    } else {
    
        cout << endl << "Nenhuma imagem cadastrada." << endl;    
    
    }
    
    cout << endl << "Pressione uma tecla para continuar." << endl;
    
    getchar();

}

void ListaImagem::listar () {

    if (lista.size() > 0) {
    
        cout << "Imagens cadastradas: " << endl;
    
        list<Imagem *>::const_iterator it;
        
        for (it = lista.begin(); it != lista.end(); it++) {
    
            cout << (*it)->getCodigo() << "\t" << (*it)->getNome() << endl;
    
        }
    
    } else {
    
        cout << endl << "Nenhuma imagem cadastrada." << endl;    
    
    }
    
    cout << endl << "Pressione uma tecla para continuar." << endl;
    
    getchar();

}

