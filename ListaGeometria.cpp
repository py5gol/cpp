#include "ListaGeometria.h"

ListaGeometria::ListaGeometria () { writer = new io::WKTWriter(); }

ListaGeometria::~ListaGeometria () {

    for (list<Geometria*>::iterator it = lista.begin(); it != lista.end(); it++) {
        delete (*it);
    }

}

void ListaGeometria::incluir (int tipo, string wkt) {

    io::WKTReader * reader = new io::WKTReader();
    Geometry *g = reader->read (wkt);

    int tam = lista.size ();

    if (tipo == 1) {
        Ponto * p = new Ponto (tam, g);
        lista.push_back (p);
    }
    
    if (tipo == 2) {
        Linha * l = new Linha (tam, g);
        lista.push_back (l);
    }
    
    if (tipo == 3) {
        Poligono * p = new Poligono (tam, g);
        lista.push_back (p);
    }
    
}

void ListaGeometria::listar () {

    if (lista.size() > 0) {
    
        //io::WKTWriter * writer = new io::WKTWriter();

        cout << "Geometrias cadastradas: " << endl;
    
        list<Geometria *>::const_iterator it;
        
        for (it = lista.begin(); it != lista.end(); it++) {
    
            cout << (*it)->getCodigo() << "\t" << writer->write((*it)->getGeometria()) << endl;
    
        }
    
    } else {
    
        cout << endl << "Nenhuma geometria cadastrada." << endl;    
    
    }
    
    cout << endl << "Pressione uma tecla para continuar." << endl;
    
    cin.get ();
    
}

void ListaGeometria::excluir (int i) {

    if (lista.size() > 0) {
    
        list<Geometria*>::iterator it = lista.begin ();
        
        while (it != lista.end()) {
        
            if ((*it)->getCodigo() == i) {
            
                it = lista.erase (it);
                cout << "Geometria " << i << " excluida com sucesso." << endl;
                break;
                
            }
            
            it++;
    
        }
    
    } else {
    
        cout << endl << "Nenhuma geometria cadastrada." << endl;    
    
    }
    
    cout << endl << "Pressione uma tecla para continuar." << endl;
    
    cin.get();

}

void ListaGeometria::detalhar (int i) {

    if (lista.size() > 0) {
    
        list<Geometria*>::iterator it = lista.begin ();
        
        while (it != lista.end()) {
        
            if ( (*it)->getCodigo() == i ) {

                (*it)->imprimeInfo();            
                break;
                
            }
            
            it++;
    
        }
    
    } else {
    
        cout << endl << "Nenhuma geometria cadastrada." << endl;    
    
    }
    
    cout << endl << "Pressione uma tecla para continuar." << endl;
    
    cin.get();

}

void ListaGeometria::salvar () {
    ofstream saida ("./geometrias.dat", ios::out);
    
    if (!saida) {
        cout << "Arquivo nao pode ser aberto." << endl;
        cout << "Pressione uma tecla para continuar." << endl;
        cout << ">> ";
        cin.get ();
        return;
    }

    if (lista.size() > 0) {
        list<Geometria *>::const_iterator it;

        //string s = writer->write ((*it)->getGeometria());
        
        for (it = lista.begin(); it != lista.end(); it++) {
            saida << (*it)->getTipo() << writer->write ((*it)->getGeometria()) << endl;
        }
    
        cout << endl << "Gravacao encerrada com sucesso." << endl;

    } else {
        cout << endl << "Nenhuma geometria cadastrada." << endl;    
    
    }
    
    saida.close();

    cout << endl << "Pressione uma tecla para continuar." << endl;
    cout << ">> ";
    cin.get ();
    return;

}

void ListaGeometria::carregar () {
    ifstream entrada ("./geometrias.dat", ios::in);
    
    if (!entrada) {
        cerr << "Arquivo nao pode ser aberto." << endl;
        fflush (stdin);
        cout << endl << "Pressione uma tecla para continuar." << endl;
        cout << ">> ";
        cin.get ();
        return;
    }

    string linha, linha2;
    string tipoS;
    int tipo;
    while (entrada.good()) {
        getline (entrada, linha);

        if (linha.length () == 0) {
            break;
        }
        
        tipoS = linha.substr (0, 1);
        tipo = atoi (tipoS.c_str());
        linha.replace (0, 1, " ");
        linha2 = linha.substr (1, linha.length ()-1);
        incluir (tipo, linha2);
    }

    entrada.close();
    cout << endl << "Carregamento encerrado com sucesso." << endl;
    cout << endl << "Pressione uma tecla para continuar." << endl;
    cout << ">> ";
    cin.get ();
    return;
}

list<Geometria*>::const_iterator ListaGeometria::begin () {
    return lista.begin ();
}

list<Geometria*>::const_iterator ListaGeometria::end () {
    return lista.end ();
}

