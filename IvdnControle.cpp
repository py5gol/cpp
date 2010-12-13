#include "IvdnControle.h"

IvdnControle::IvdnControle () {
}

IvdnControle::~IvdnControle () {
}

void IvdnControle::calculaIvdn (ListaImagem &lista_imagem, ListaGeometria &lista_geometria) {

    lista_imagem.listar ();
    lista_geometria.listar ();

    for (list<Imagem*>::const_iterator it = lista_imagem.begin(); it != lista_imagem.end(); it++) {

        //cout << "1" << (*it)->getCodigo() << "\t" << (*it)->getNome() << endl;

        for (list<Geometria*>::const_iterator it2 = lista_geometria.begin(); it2 != lista_geometria.end(); it2++) {

            float x = ((Point *)(*it2)->getGeometria())->getX();
            float y = ((Point *)(*it2)->getGeometria())->getY();
            float ivdn = (*it)->informaIvdn (x, y);
            
            cout << ivdn << endl;

        }
        
    }

}

