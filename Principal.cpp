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

    cout << "finalizando objeto principal" << endl;

}

void Principal::menu_principal () {

    int op = -1;
    
    while (op != 10) {
    
        cout << endl;
        cout << "1. Imagens"        << endl;
        cout << "2. Geometrias"     << endl;
        cout << "3. Calcular IVDN"  << endl;
        cout << "10. Sair"          << endl;
        cout << endl;
    
        cin >> op;
        cin.ignore ();
        
        switch (op) {
        
            case 1: {
                menu_imagem ();
            } break;
                
            case 2: {
                menu_geometria ();
            } break;
            
            case 3: {
                calcular_ivdn ();
            } break;
            
            case 10: {
                exit (0);
            } break;
            
            default: {
                cout << "Opcao invalida - Pressione uma tecla." << endl;
                cin.get ();
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
        cout << "5. Gravar"                     << endl;
        cout << "6. Carregar"                   << endl;
        cout << "9. Voltar"                     << endl;
        cout << endl;

        cout << ">> ";
        cin >> op;
        cin.ignore ();
        cout << endl;
        
        switch (op) {
        
            case 1: {
                imagem_listar ();
            } break;
                
            case 2: {
                imagem_cadastrar ();
            } break;
            
            case 3: {
                imagem_excluir ();
            } break;
            
            case 4: {
                imagem_detalhar ();
            } break;
            
            case 5: {
                imagem_salvar ();
            } break;
            
            case 6: {
                imagem_carregar ();
            } break;
            
            case 9: {
                menu_principal ();
            } break;
            
            default: {
                cout << "Opcao invalida - Pressione uma tecla." << endl;
                cin.get ();
            }
            
        }
        
    }

}

void Principal::menu_geometria () {

    int op = -1;
    
    while (op != 9) {
    
        cout << endl;
        cout << "1. Listar todas geometrias"    << endl;
        cout << "2. Cadastrar nova geometria"   << endl;
        cout << "3. Excluir geometria"          << endl;
        cout << "4. Visualizar detalhes"        << endl;
        cout << "5. Gravar"                     << endl;
        cout << "6. Carregar"                   << endl;
        cout << "9. Voltar"                     << endl;
        cout << endl;

        cout << ">> ";

        fflush (stdin);
        
        cin >> op;
        
        cout << endl;
        
        switch (op) {
        
            case 1: {
                geometria_listar ();
            } break;
                
            case 2: {
                geometria_cadastrar ();
            } break;
            
            case 3: {
                geometria_excluir ();
            } break;
            
            case 4: {
                geometria_detalhar ();
            } break;
            
            case 5: {
                geometria_salvar ();
            } break;
            
            case 6: {
                geometria_carregar ();
            } break;
            
            case 9: {
                menu_principal ();
            } break;
            
            default: {
                cout << "Opcao invalida - Pressione uma tecla." << endl;
                cin.get();
            }
            
        }
        
    }

}

void Principal::imagem_cadastrar () {
    cout << "Informe caminho e nome da imagem: ";
    char s [150];
    cin >> s;
    cin.ignore ();
    cout << endl;
    lista_imagem.incluir (s);    
}

void Principal::imagem_excluir () {
    cout << "Informe o codigo da imagem: ";
    int i;
    cin >> i;
    cin.ignore ();
    cout << endl;
    lista_imagem.excluir (i);    
}

void Principal::imagem_listar () {
    lista_imagem.listar ();
}

void Principal::imagem_detalhar () {
    cout << "Informe o codigo da imagem: ";
    int i;
    cin >> i;
    cin.ignore ();
    cout << endl;
    lista_imagem.detalhar (i);
}

void Principal::imagem_salvar () {
    lista_imagem.salvar ();
}

void Principal::imagem_carregar () {
    lista_imagem.carregar ();
}

void Principal::geometria_listar () {
    lista_geometria.listar ();
}

void Principal::geometria_cadastrar () {
    int tipo;
    string wkt;
    cout << "Informe tipo da geometria (1. Ponto, 2. Linha, 3. Poligono): ";
    cin >> tipo;
    cin.ignore();
    cout << "Informe a geometria no formato WKT: ";
    getline (cin, wkt);
    lista_geometria.incluir (tipo, wkt);    
}

void Principal::geometria_excluir () {
    cout << "Informe o codigo da geometria: ";
    int i;
    cin >> i;
    cin.ignore ();
    cout << endl;
    lista_geometria.excluir (i);    
}

void Principal::geometria_detalhar () {
    cout << "Informe o codigo da geometria: ";
    int i;
    cin >> i;
    cin.ignore();
    cout << endl;
    lista_geometria.detalhar (i);
}

void Principal::geometria_salvar () {
    lista_geometria.salvar ();
}

void Principal::geometria_carregar () {
    lista_geometria.carregar ();
}


/****************************************************************************
 *
 ****************************************************************************/ 
int main () {
    Principal p;
}

