#include "Principal.h"

// Constructors/Destructors
//  

Principal::Principal ( ) {

	vector<Geometry *> *geoms = new vector<Geometry *>;
	
	// Define a precision model using 0,0 as the reference origin
	// and 2.0 as coordinates scale.
	PrecisionModel *pm = new PrecisionModel(2.0, 0, 0);

	// Initialize global factory with defined PrecisionModel
	// and a SRID of -1 (undefined).
	global_factory = new GeometryFactory(pm, -1);

	// We do not need PrecisionMode object anymore, it has
	// been copied to global_factory private storage
	delete pm;
	
	GDALAllRegister();
	
}

Principal::~Principal ( ) { }

Point * Principal::create_point (double x, double y) {

    Coordinate c (x, y);
    Point * p = global_factory->createPoint(c);
    return p;

}

int main () {
    Principal p;
    Geometry *g = (p.create_point (-48.5, -24.5));

    
    
    io::WKTWriter * writer = new io::WKTWriter();
    
    string tmp = writer->write(g);
    cout << tmp << endl;   
 
    p.poDataset = (GDALDataset *) GDALOpen ("/discolocal/MODIS_2009353_NDVI.tif", GA_ReadOnly);
    
    if (p.poDataset == NULL) {
        cout << "erro: nao foi possivel abrir a imagem." << endl;
    }
    
    
    double adfGeoTransform[6];
    
    cout << "Driver: " << p.poDataset->GetDriver()->GetDescription() << "/" << p.poDataset->GetDriver()->GetMetadataItem( GDAL_DMD_LONGNAME ) << endl ;
    
    cout << "Size is " << 
            p.poDataset->GetRasterXSize() << "x" << p.poDataset->GetRasterYSize() <<
            p.poDataset->GetRasterCount() << endl;

    if( p.poDataset->GetProjectionRef()  != NULL )
        cout << "Projection is " << p.poDataset->GetProjectionRef() << endl;

    if( p.poDataset->GetGeoTransform( adfGeoTransform ) == CE_None )
    {
        cout << "Origin = (" <<
                adfGeoTransform[0] << ", " << adfGeoTransform[3] << ")" << endl;

        cout << "Pixel Size = (" <<
                adfGeoTransform[1] << ", " << adfGeoTransform[5] << ")" << endl;
    }
    




        GDALRasterBand  *poBand;
        int             nBlockXSize, nBlockYSize;
        int             bGotMin, bGotMax;
        double          adfMinMax[2];
        
        poBand = p.poDataset->GetRasterBand( 1 );
        poBand->GetBlockSize( &nBlockXSize, &nBlockYSize );
        
        cout << "Block: " << nBlockXSize << "x" << nBlockYSize << endl;
        cout << "Type: " << GDALGetDataTypeName(poBand->GetRasterDataType()) << endl;
        cout << "ColorInterp: " << GDALGetColorInterpretationName( poBand->GetColorInterpretation()) << endl;

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




        double x0 = adfGeoTransform[0];
        double y0 = adfGeoTransform[3];
        
        double xd = adfGeoTransform[1];
        double yd = adfGeoTransform[5];
        
        double x = -49.2122;
        double y = -25.3988;
        
        int n1 = (x - x0)/xd;
        int n2 = (y - y0)/yd;
        
        cout << "n1: " << n1 << endl;
        cout << "n2: " << n2 << endl;
        
        

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

        cout << pafScanline[0] << endl;
    
}
