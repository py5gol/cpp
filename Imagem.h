#ifndef IMAGEM_H
#define IMAGEM_H

#include "gdal_priv.h"
#include "cpl_conv.h"

class Imagem
{
public:
    Imagem (int, char *);
    virtual ~Imagem ();

    char * getNome ();
    void setNome (char *);
    
    int getCodigo ();
    void setCodigo (int);

    void inicializa ();
    void imprimeInfo ();
    float informaIvdn (float, float);

        
protected:
    int codigo;
    char nome [150];
    GDALDataset * poDataset;
    
    double x0;           // canto esquerdo superior
    double y0;           // canto esquerdo superior
    int w;               // largura em pixels
    int h;               // altura em pixels
    int z;               // numero de bandas da imagem
    double xd;           // largura do pixel
    double yd;           // altura do pixel
    char driver [50];    // nome do driver usado para manipular a imagem
    char srs [400];      // sistema de projecao

private:

};

#endif // IMAGEM_H
