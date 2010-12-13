#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <string>
#include <list>
using namespace std;

#include "Imagem.h"
#include "ListaImagem.h"
#include "ListaGeometria.h"
#include "IvdnControle.h"

class Principal
{
public:
    Principal ();
    virtual ~Principal ();

    void menu_principal ();
    void menu_imagem ();
    void menu_geometria ();
    
    void imagem_cadastrar ();
    void imagem_excluir ();
    void imagem_detalhar ();
    void imagem_listar ();
    void imagem_salvar ();
    void imagem_carregar ();

    void geometria_listar ();
    void geometria_cadastrar ();
    void geometria_excluir ();
    void geometria_detalhar ();
    void geometria_salvar ();
    void geometria_carregar ();
    
    void calcular_ivdn ();
    

protected:
    ListaImagem lista_imagem;
    ListaGeometria lista_geometria;
    IvdnControle ivdnControle;

};

#endif // PRINCIPAL_H
