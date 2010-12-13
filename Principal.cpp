#include "Principal.h"

Principal::Principal ( ) {

    cout << "inicializando objeto principal" << endl;

    cout << "antes do gdalallregister" << endl;
    GDALAllRegister();
    cout << "depois do gdalallregister" << endl;

    //imagens = new vector<Imagem *>;

    /*
    cout << "imagem 1" << endl;
    Imagem * img1 = new Imagem ( 1, (char *) "/discolocal/dados/MODIS_BR_2010001_NDVI.tif" );
    lista_imagem.incluir ((char *) "/discolocal/dados/MODIS_BR_2010001_NDVI.tif" );

    cout << "imagem 2" << endl;
    Imagem * img2 = new Imagem ( 2, (char *) "/discolocal/dados/MODIS_BR_2010017_NDVI.tif" );
    cout << "imagem 2." << endl;
    imagens.push_back(img2);

    cout << "imagem 3" << endl;
    imagens.push_back(new Imagem ( 3, (char *) "/discolocal/dados/MODIS_BR_2010033_NDVI.tif" ));

    cout << "imagem 4" << endl;
    imagens.push_back(new Imagem ( 4, (char *) "/discolocal/dados/MODIS_BR_2010049_NDVI.tif" ));

    cout << "imagem 5" << endl;
    imagens.push_back(new Imagem ( 5, (char *) "/discolocal/dados/MODIS_BR_2010065_NDVI.tif" ));
    */
    
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
	
    double x = -49.2122;
    double y = -25.3988;

    //for (list<Imagem*>::iterator it = imagens.begin(); it != imagens.end(); it++) {
    //    cout << (*it)->getNome() << ": " << (*it)->informaIvdn(x, y) << endl;
    //}
	
	menu_principal ();
}

Principal::~Principal ( ) {

    for (list<Imagem*>::iterator it = imagens.begin(); it != imagens.end(); it++) {
        delete (*it);
    }

    cout << "finalizando objeto principal" << endl;

}

void Principal::menu_principal () {

    int op = -1;
    
    while (op != 10) {
    
        cout << endl;
        cout << "1. Imagens"        << endl;
        cout << "2. Geometrias"     << endl;
        cout << "9. Gravar"         << endl;
        cout << "10. Sair"          << endl;
        cout << endl;
    
        cin >> op;
        
        switch (op) {
        
            case 1: {
                menu_imagem ();
            } break;
                
            case 2: {
            } break;
            
            case 10: {
                cout << "Fim" << endl;
                exit (0);
            } break;
            
            default: {
                cout << "Opcao invalida - Pressione uma tecla." << endl;
                getchar();
            }
            
        }
        
    }

}

void Principal::menu_imagem () {

    int op = -1;
    
    while (op != 9) {
    
        cout << endl;
        cout << "1. Listar todas imagens"       << endl;
        cout << "2. Cadastrar nova imagem"      << endl;
        cout << "3. Excluir imagem"             << endl;
        cout << "4. Visualizar detalhes"        << endl;
        cout << "9. Voltar"                     << endl;
        cout << endl;

        cout << ">> " << endl;
        cin >> op;
        
        switch (op) {
        
            case 1: {
                cout << "opcao 1" << endl;
                imagem_listar ();
                cout << "opcao 1." << endl;
            } break;
                
            case 2: {
                imagem_listar ();
                imagem_cadastrar ();
            } break;
            
            case 3: {
                imagem_excluir ();
            } break;
            
            case 4: {
                imagem_detalhar ();
            } break;
            
            case 9: {
                menu_principal ();
            } break;
            
            default: {
                cout << "Opcao invalida - Pressione uma tecla." << endl;
                getchar ();
            }
            
        }
        
    }

}

void Principal::imagem_cadastrar () {

    cout << "Informe caminho e nome da imagem: ";

    char s [150];
    
    cin >> s;
    
    lista_imagem.incluir (s);    

}

void Principal::imagem_excluir () {

    cout << "Informe o codigo da imagem: ";

    int i;
    
    cin >> i;
    
    lista_imagem.excluir (i);    


}

void Principal::imagem_listar () {

    lista_imagem.listar ();

}

void Principal::imagem_detalhar () {

    menu_imagem ();

}

void Principal::menu_geometria () {

    menu_imagem ();

}

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
    
    
    io::WKTReader * reader = new io::WKTReader();
    //reader->read ("POINT (-48.50 -24.50)");
    Geometry *g2 = reader->read ("POINT (-48.50 -24.50)");
 
    cout << writer->write(g2) << endl;   
    
}
