#include "Imagem.h"
#include <stdio.h>
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;


Imagem::Imagem ( int i, char * s ) {

    cout << "inicializando objeto imagem" << endl;
    codigo = i;
    cout << "antes do strcpy" << endl;
    strcpy (nome, s);
    cout << "depois do strcpy" << endl;

    inicializa ();

    imprimeInfo();
    /*
    */
}

Imagem::~Imagem ( ) {

    cout << "finalizando objeto imagem" << endl;

}

char * Imagem::getNome () { return nome; }

void Imagem::setNome (char * s) { strcpy (nome, s); };

void Imagem::inicializa () {

    cout << "antes do poDataset" << endl;
    poDataset = (GDALDataset *) GDALOpen (nome, GA_ReadOnly);
    cout << "depois do poDataset" << endl;
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
    cout << "Imagem" << endl;
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

    //cout << "Block: " << nBlockXSize << "x" << nBlockYSize << endl;
    //cout << "Type: " << GDALGetDataTypeName(poBand->GetRasterDataType()) << endl;
    //cout << "ColorInterp: " << GDALGetColorInterpretationName( poBand->GetColorInterpretation()) << endl;

    /*
    adfMinMax[0] = poBand->GetMinimum( &bGotMin );
    adfMinMax[1] = poBand->GetMaximum( &bGotMax );

    if( ! (bGotMin && bGotMax) )
        GDALComputeRasterMinMax((GDALRasterBandH)poBand, TRUE, adfMinMax);

    cout << "Min: " << adfMinMax[0] << endl;
    cout << "Max: " << adfMinMax[1] << endl;

    if( poBand->GetOverviewCount() > 0 )
        cout << "Band has " << poBand->GetOverviewCount() << " overvies." << endl;

    if( poBand->GetColorTable() != NULL )
        cout << "Band has a color table with " << poBand->GetColorTable()->GetColorEntryCount() << " entries" << endl;




    //double x0 = adfGeoTransform[0];
    //double y0 = adfGeoTransform[3];

    //double xd = adfGeoTransform[1];
    //double yd = adfGeoTransform[5];
    */

    int n1 = (x - x0)/xd;
    int n2 = (y - y0)/yd;

    //cout << "n1: " << n1 << endl;
    //cout << "n2: " << n2 << endl;


    float *pafScanline;
    int   nXSize = poBand->GetXSize();
    int   nYSize = poBand->GetYSize();



    //pafScanline = (float *) CPLMalloc(sizeof(float)*nXSize);
    pafScanline = (float *) CPLMalloc(sizeof(float)*nXSize);

    poBand->RasterIO( GF_Read, n1, n2, 1, 1, 
                          pafScanline, 1, 1, GDT_Float32, 
                          0, 0 );
    /*
    for (int j = 0; j < nYSize; j++) {
        poBand->RasterIO( GF_Read, 0, j, nXSize, 1, 
                          pafScanline, nXSize, 1, GDT_Float32, 
                          0, 0 );

        for (int i = 0; i < nXSize; i++) {
            cout << pafScanline[i] << endl;
        }
    }
    */

    return pafScanline[0];

}

