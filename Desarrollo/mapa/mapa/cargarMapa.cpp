//
//  cargarMapa.cpp
//  mapa
//
//  Created by Julia Martínez Valera on 5/11/16.
//  Copyright © 2016 Julia Martínez Valera. All rights reserved.
//

#include "cargarMapa.hpp"

#include <iostream>
//#include "tinyxml2.h"
using namespace tinyxml2;
using namespace std;

cargarMapa::cargarMapa(){
    _width = 0;
    _height = 0;
    _tileWidth = 0;
    _tileHeight = 0;
    _numLayers = 0;
}

void cargarMapa::leerMapa() {
    ////////////////////////////////////////////////////////////////////////////////////
    // CAPA DE TEXTURAS
    ////////////////////////////////////////////////////////////////////////////////////
    XMLDocument doc;
   
    //doc.LoadFile("mapas/mapa1tiled.tmx");
    doc.LoadFile("../../../mapa/tiled/mapa2.tmx");
   
    
    //tamanyo mapa y de los tiles
    XMLElement* map = doc.FirstChildElement("map");
    map->QueryIntAttribute("width", &_width);
    map->QueryIntAttribute("height", &_height);
    map->QueryIntAttribute("tilewidth", &_tileWidth);
    map->QueryIntAttribute("tileheight", &_tileHeight);
    map->QueryIntAttribute("tileheight", &_tileHeight);
    
    cout << "width: "<<_width <<" height: "<<_height << endl; //w: tiles de ancho, h:tiles de alto del mapa tmx
    cout << "tilewd: "<<_tileWidth <<" tilehg: "<<_tileHeight << endl; //dimensiones del png de sprites
    
    //Imagen del tileset
    XMLElement *img = map->FirstChildElement("tileset")->FirstChildElement("image");
    const char *filename = img->Attribute("source");
    
    //guardar la altura y ancho de la tilesheet
    int _tswidth;
    int _tsheight;
    _tsheight = atoi(img->Attribute("height"));
    _tswidth = atoi(img->Attribute("width"));
    cout << "source-> "<<filename << endl;
    cout << "AnchoAllSprites: " <<_tswidth << " AltoAllSprites: "<<_tsheight<<endl;
    
    //Capas del mapa
    XMLElement *layer = map->FirstChildElement("layer"); //primera capa, la de patrones
    while(layer){
        _numLayers++;
        layer = layer->NextSiblingElement("layer"); //Creamos a capa
    }
    cout << "NumCapas: "<<_numLayers <<endl;
    
    int _tilemap[_width][_height][_numLayers];//matriz de enteros para saber donde hay mapa y donde no
    
    //RESERVO MEMORIA PARA LAS CAPAS Y SU TAMAÑO
    //reservo memoria como si fuera un vector y luego la recorro
    /* _tilemap = new int ** [_numLayers];
     for(int l = 0; l < _numLayers; l++) {
     _tilemap[l] = new int * [_height];
     }
     for(int l = 0; l < _numLayers; l++) {
     for(int y = 0; y < _height; y++) {
     _tilemap[l][y] = new int [_width];
     }
     }*/
   
    _level = new int [_width*_height];
    int cont = 0;
    //cargar los gids de diversas capas
    XMLElement  *data[_width*_height];
    //Carga la primera capa de textura
    data[0] = map->FirstChildElement("layer")->FirstChildElement("data")->FirstChildElement("tile");
    
    for(int l=0; l<_numLayers; l++){
        for(int y=0; y<_height; y++){
            for(int x=0; x<_width; x++){
                //en el vector level de tamaño del alto por ancho del mapa(capa), guardo todos los valores de los tiles de la capa
                _level[cont] = data[l]->IntAttribute("gid")-1; //hasta q llega a 260 desde 1(ancho*alto)
                
                cont++;
                data[l]->QueryIntAttribute("gid", &_tilemap[l][y][x]);
                
                //avanzo hasta el siguiente tag
                data[l] = data[l]->NextSiblingElement("tile");
                
                // muestra matriz de ints en la consola del mapa1
                cout<< _tilemap[l][y][x] << " ";
               // cout<<matrizMapa[l][y][x] << " ";
                if(x == _width-1){
                    cout<< endl;
                }
            }
        }
        cout << cont << endl;
    }
    
    ////////////////////////////////////////////////////////////////////////////////////
    // AQUI EMPIEZA LA CAPA DE OBJETOS
    ////////////////////////////////////////////////////////////////////////////////////
    cout <<"Empiezo a compilar objetos" <<endl;
    objs = map->FirstChildElement("objectgroup");
    XMLElement* colisionesXML = objs->FirstChildElement("object");
    cout <<"Empiezo a compilar objetos2" << endl;
    
    ////////////TILESET/////////////
    //sf::Texture textura;
    //textura.loadFromFile("sprites/spritesmas2.png");
    
 //   int x = 0;
 //   int contador = 0;
    
    while(colisionesXML){
        //AUN NO LE HE PUESTO EL TIPO A LAS COLISIONES
        //TIPO 1 -> POLILINEAS
        //TIPO 2 -> OBJECTS SIN HIJOS
        int tipo = colisionesXML->IntAttribute("type");
        int x = colisionesXML->IntAttribute("x");
        int y = colisionesXML->IntAttribute("y");
        int colheight = colisionesXML->IntAttribute("height");
        int colwidth = colisionesXML->IntAttribute("width");
//        if(tipo==25){
//            //int movX = colisionesXML->FirstChild("properties")->FirstChildElement("property")->Value();
//            XMLNode* propiedades = colisionesXML->FirstChild();
//            int movX = propiedades->FirstChildElement("property")->IntAttribute("value");
//            Juego::Instance()->arr_valoresCamara->at(contador) = movX;
//            contador++;
//            cout << "movX: "<< movX<<endl;
//            
//            
//        }
        
  
        //ESTAS 3 COSAS PARA QUE LAS HACIA ??????
//        nuevaColision = new sf::RectangleShape;
//        nuevaColision->setPosition(x, y);
//        nuevaColision->setSize(sf::Vector2f(colwidth, colheight));
        
//        if(tipo == 10){//paredes
//            nuevaColision->setFillColor(sf::Color::Transparent);
//            Juego::Instance()->getColisiones()->push_back(nuevaColision);
//        }else if(tipo == 11){//diamaante azul
//            nuevaColision->setFillColor(sf::Color::Transparent);
//            Juego::Instance()->getDiamAzul()->push_back(nuevaColision);
//        }else if(tipo == 15){ //copa
//            nuevaColision->setFillColor(sf::Color::Transparent);
//            
//            Juego::Instance()->getCogeCopa()->push_back(nuevaColision);
//        }else if(tipo == 13){ //bola lila
//            nuevaColision->setFillColor(sf::Color::Transparent);
//            Juego::Instance()->getBolaLila()->push_back(nuevaColision);
//        }else if(tipo == 12){ //diamante rojo
//            nuevaColision->setFillColor(sf::Color::Transparent);
//            Juego::Instance()->getDiamRojo()->push_back(nuevaColision);
//        }else if(tipo == 14){ //puerta
//            nuevaColision->setFillColor(sf::Color::Transparent);
//            Juego::Instance()->getCogePuerta()->push_back(nuevaColision);
//        }else if(tipo == 21){//pistola
//            nuevaColision->setFillColor(sf::Color::Transparent);
//            Juego::Instance()->getPistola()->push_back(nuevaColision);
//        }else if(tipo == 25){ //mueve la camara
//            nuevaColision->setFillColor(sf::Color::Transparent);
//            Juego::Instance()->getMueveCamara()->push_back(nuevaColision);
//            
//        }
        
        colisionesXML = colisionesXML->NextSiblingElement("object");
        
        x++;
    }
    
    
    /****************////////////////////////////////////////////////////////////**********************************/
    
//    //el jugador lo situo en la posicion que le asigno al coger el mapa desde la carpeta
//    Juego::Instance()->getJugador()->setPosition(pos_ini);
//    
//    
//    tilesMov = objs->NextSiblingElement("objectgroup")->FirstChildElement("object");
//    
//    
//    while(tilesMov){
//        sf::Vector2f pos =sf::Vector2f(tilesMov->IntAttribute("x"), tilesMov->IntAttribute("y"));
//        int type = tilesMov->IntAttribute("type");
//        cout <<"Tipo de obj: " << type << endl;//tipos de objetos q hay
//        
//        //PRUEBA PARA VER ANIMACIONES
//        if(type == 1){
//            
//            ////////////COPA/////////////                                  //si el tiempo es menor, voy mas rapido
//            typ_copa = new AnimatedSprite(sf::seconds(0.15), true, true); //tiempo entre un frame y otro
//            //typ_copa->setPosition(sf::Vector2f(100,100));
//            typ_copa->setPosition(sf::Vector2f(pos.x, pos.y));
//            Juego::Instance()->getCopa()->push_back(typ_copa); //para agregar animacionCopa a arr_copa
//            
//            
//        }else if(type == 2){
//            //////FUEGO INICIO GRANDE
//            typ_fuegog = new AnimatedSprite(sf::seconds(0.15), true, true); //tiempo entre un frame y otro
//            typ_fuegog->setPosition(sf::Vector2f(pos.x, pos.y));
//            
//            Juego::Instance()->getFuegog()->push_back(typ_fuegog);
//            
//            
//        }else if(type == 3){
//            ///////FUEGO PEQUEÑO INICIO
//            typ_fuegop = new AnimatedSprite(sf::seconds(0.15), true, true); //tiempo entre un frame y otro
//            typ_fuegop->setPosition(sf::Vector2f(pos.x, pos.y));
//            typ_fuegop->scale(0.25, 0.25);
//            Juego::Instance()->getFuegop()->push_back(typ_fuegop);
//            
//            
//        }else if(type == 4){
//            ///////LETRAS PRINCIPAL
//            typ_letrasp = new AnimatedSprite(sf::seconds(0.15), true, true);
//            typ_letrasp->setPosition(sf::Vector2f(pos.x-16, pos.y-32));
//            typ_letrasp->scale(0.25, 0.25);
//            
//            Juego::Instance()->getLetrasp()->push_back(typ_letrasp);
//            
//        }else if(type == 5){
//            ////////////ALGAS/////////////
//            typ_algas = new AnimatedSprite(sf::seconds(0.15), true, true); //tiempo entre un frame y otro
//            typ_algas->setPosition(sf::Vector2f(pos.x, pos.y));
//            Juego::Instance()->getAlgas()->push_back(typ_algas);
//            
//            
//        }else if(type == 6){
//            /////////FUEGO CON RAYA IZQUIERDA
//            typ_fuegoi = new AnimatedSprite(sf::seconds(0.15), true, true);
//            typ_fuegoi->setPosition(sf::Vector2f(pos.x, pos.y));
//            //typ_fuegoi->setScale(0.5);
//            typ_fuegoi->scale(0.25, 0.25);
//            Juego::Instance()->getFuegoi()->push_back(typ_fuegoi);
//            
//        }else if(type == 7){
//            //////FUEGO CON RAYA DERECHA
//            typ_fuegod = new AnimatedSprite(sf::seconds(0.15), true, true);
//            typ_fuegod->setPosition(sf::Vector2f(pos.x, pos.y));
//            typ_fuegod->scale(0.25, 0.25);
//            Juego::Instance()->getFuegod()->push_back(typ_fuegod);
//            
//            
//        }else if(type == 8){ ////////AGUA IZQUIERDA
//            typ_aguai = new AnimatedSprite(sf::seconds(0.15), true, true);
//            typ_aguai->setPosition(sf::Vector2f(pos.x, pos.y));
//            typ_aguai->scale(0.25, 0.25);
//            Juego::Instance()->getAguai()->push_back(typ_aguai);
//        }else if(type == 9){
//            /////AGUA DERECHA
//            typ_aguad = new AnimatedSprite(sf::seconds(0.15), true, true);
//            typ_aguad->setPosition(sf::Vector2f(pos.x, pos.y));
//            typ_aguad->scale(0.25, 0.25);
//            Juego::Instance()->getAguad()->push_back(typ_aguad);
//        }else if(type == 10){
//            ////////////ananya?????????????/////////////
//            typ_aranya = new AnimatedSprite(sf::seconds(0.15), true, true);
//            typ_aranya->setPosition(sf::Vector2f(pos.x, pos.y));
//            Juego::Instance()->getAranya()->push_back(typ_aranya);
//            
//        }
//        /////////Muerte//////////////////////////////////////
//        
//        tilesMov = tilesMov->NextSiblingElement("object");
//    }
//    cout <<"fin lee mapa"<< std::endl;
//    //Juego::Instance()->getJugador()->setPosition(pos_ini);
}

int cargarMapa::getWidth(){
    return _width;
}

int cargarMapa::getHeight(){
    return _height;
}



