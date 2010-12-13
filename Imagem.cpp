#include "Imagem.h"
#include <stdio.h>
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

Imagem::Imagem ( int i, char * s ) {
    codigo = i;
    strcpy (nome, s);
    inicializa ();
}

Imagem::~Imagem ( ) {
}

char * Imagem::getNome () {
    return nome;
}

void Imagem::setNome (char * s) {
    strcpy (nome, s);
}

int Imagem::getCodigo () {
    return codigo;
}

void Imagem::setCodigo (int i) {
    codigo = i;
}

void Imagem::inicializa () {
    poDataset = (GDALDataset *) GDALOpen (nome, GA_ReadOnly);
    if (poDataset == NULL) {
        cout << "erro: nao foi possivel abrir a imagem." << endl;
    }

    double adfGeoTransform[6];
    strcpy (driver, poDataset->GetDriver()->GetDescription());

    w = poDataset->GetRasterXSize();
    h = poDataset->GetRasterYSize();
    z = poDataset->GetRasterCount();

    if ( poDataset->GetProjectionRef()  != NULL ) {
        strcpy (srs, poDataset->GetProjectionRef());
    }

    if ( poDataset->GetGeoTransform( adfGeoTransform ) == CE_None ) {
        x0 = adfGeoTransform[0];
        y0 = adfGeoTransform[3];
        
        xd = adfGeoTransform[1];
        yd = adfGeoTransform[5];
    }
}

void Imagem::imprimeInfo () {
    cout << "********************************************************" << endl;
    cout << "Imagem"        << endl;
    cout << "Codigo.....: " << codigo << endl;
    cout << "Nome.......: " << nome << endl;
    cout << "Driver.....: " << driver << endl;
    cout << "SRS........: " << srs << endl;
    cout << "Origem.....: " << x0 << ", " << y0 << endl;
    cout << "Tam. Pixel.: " << xd << ", " << yd << endl;
    cout << "********************************************************" << endl;
}

float Imagem::informaIvdn ( float x, float y) {
    GDALRasterBand  *poBand;
    int             nBlockXSize, nBlockYSize;
    int             bGotMin, bGotMax;
    double          adfMinMax[2];

    poBand = poDataset->GetRasterBand( 1 );
    poBand->GetBlockSize( &nBlockXSize, &nBlockYSize );

    int n1 = (x - x0)/xd;
    int n2 = (y - y0)/yd;

    float *pafScanline;
    int   nXSize = poBand->GetXSize();
    int   nYSize = poBand->GetYSize();

    pafScanline = (float *) CPLMalloc(sizeof(float)*nXSize);

    poBand->RasterIO( GF_Read, n1, n2, 1, 1, 
                          pafScanline, 1, 1, GDT_Float32, 
                          0, 0 );

    return pafScanline[0];
}

