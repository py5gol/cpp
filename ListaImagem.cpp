#include "ListaImagem.h"

ListaImagem::ListaImagem () {
}

ListaImagem::~ListaImagem () {

    for (list<Imagem*>::iterator it = lista.begin(); it != lista.end(); it++) {
        delete (*it);
    }

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

void ListaImagem::detalhar (int i) {

    if (lista.size() > 0) {
    
        list<Imagem*>::iterator it = lista.begin ();
        
        while (it != lista.end()) {
        
            if ( (*it)->getCodigo() == i ) {

                (*it)->imprimeInfo();            
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

void ListaImagem::salvar () {

    ofstream saida ("./imagens.dat", ios::out);
    
    if (!saida) {
    
        cerr << "Arquivo nao pode ser aberto." << endl;
        fflush (stdin);
        cout << endl << "Pressione uma tecla para continuar." << endl;
        cout << ">> ";
        getchar();
        return;

    }

    if (lista.size() > 0) {
    
        list<Imagem *>::const_iterator it;
        
        for (it = lista.begin(); it != lista.end(); it++) {
    
            saida << (*it)->getNome() << endl; 
    
        }
    
        cout << endl << "Gravacao encerrada com sucesso." << endl;

    } else {
    
        cout << endl << "Nenhuma imagem cadastrada." << endl;    
    
    }
    
    saida.close();

    cout << endl << "Pressione uma tecla para continuar." << endl;
    cout << ">> ";
    getchar();
    return;

}

void ListaImagem::carregar () {

    ifstream entrada ("./imagens.dat", ios::in);
    
    if (!entrada) {
    
        cerr << "Arquivo nao pode ser aberto." << endl;
        fflush (stdin);
        cout << endl << "Pressione uma tecla para continuar." << endl;
        cout << ">> ";
        getchar();
        return;

    }

    while (!entrada.eof()) {
    
        char nome [150];
        
        entrada >> nome;

        if (0 != strcmp (nome, "")) {
    
            incluir (nome);
    
        }
    
    }

    entrada.close();

    cout << endl << "Carregamento encerrado com sucesso." << endl;
    cout << endl << "Pressione uma tecla para continuar." << endl;
    cout << ">> ";
    getchar();
    return;

}

list<Imagem*>::const_iterator ListaImagem::begin () {
    return lista.begin ();
}

list<Imagem*>::const_iterator ListaImagem::end () {
    return lista.end ();
}

