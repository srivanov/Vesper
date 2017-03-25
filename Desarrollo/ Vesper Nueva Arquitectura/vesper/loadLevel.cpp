//
//  loadLevel.cpp
//  Arquitectura
//
//  Created by Gaspar Rodriguez Valero on 18/3/17.
//  Copyright © 2017 Gaspar Rodriguez Valero. All rights reserved.
//

#include "loadLevel.hpp"

//TO DO: revisar el cargador entero



loadLevel::loadLevel() : m_tilemap(nullptr){
    m_width = m_height = m_numLayers = m_tileWidth = m_tileHeight = 0;
}

loadLevel::~loadLevel(){
    if(m_tilemap)
      delete[] m_tilemap;
}

dvector2D loadLevel::ConvertDataPosition2D(tinyxml2::XMLElement *object){
    return dvector2D(atoi(object->ToElement()->Attribute("x"))/m_tileWidth, atoi(object->ToElement()->Attribute("y"))/m_tileHeight);
}

void loadLevel::readPolyline(XMLElement *object){
    dvector2D separador(INT_MAX, INT_MAX);
    XMLElement* polylinea = object->FirstChildElement("polyline");
    while (polylinea != NULL) {
        
        char *puntosLinea = strdup(polylinea->ToElement()->Attribute("points"));
        char* punto = strtok(puntosLinea, " ");
        while (punto){
            dvector2D point;
            sscanf(punto, "%f,%f", &point.x, &point.y);
            objetos.push_back(point);
            punto = strtok(0, " ");
        }
        free(puntosLinea);
        polylinea = polylinea->NextSiblingElement();
        objetos.push_back(separador);
    }
}

bool loadLevel::load(char* fichero) {
    
    char ruta[30] = "";
    
    strcat(ruta, "tiled/mapa");
    strcat(ruta, fichero);
    strcat(ruta, ".tmx");
    printf("\n%s\n", ruta);
    XMLDocument doc;
    doc.LoadFile(ruta);
    if(doc.NoChildren())
        return false;
    
    XMLElement* map = doc.FirstChildElement("map");
    map->QueryIntAttribute("width", &m_width);
    map->QueryIntAttribute("height", &m_height);
    map->QueryIntAttribute("tilewidth", &m_tileWidth);
    map->QueryIntAttribute("tileheight", &m_tileHeight);
    
    
    XMLElement *layer = map->FirstChildElement("layer");
    int w = m_width*m_height, query;
    m_tilemap = new int[w];
    
    if(!layer) throw LOADING_LEVEL;
    while(layer){
        XMLElement *data = layer->FirstChildElement("data")->FirstChildElement("tile");
        if(!data) throw READING_LAYER_DATA;
        
        for(int k=0; k < w ; k++){
            data->QueryIntAttribute("gid", &query);
            if(m_numLayers==0)
                m_tilemap[k] = query;
            else if(query!=0) {
                int y = (int) k / (m_width) ;
                int x = (int) k % (m_width) ;
                std::cout << x << "|" << y <<"|"<< query <<std::endl;
                m_obj.push_back(dvector3D(x,y,query));
                
            }
            data = data->NextSiblingElement("tile");
        }
        cout << endl;
        
        m_numLayers++;
        layer = layer->NextSiblingElement("layer");
    }
    /*
    int auxL = 0;
    for (size_t q = 0; q < w; q++) {
        int y = (int) q / (m_width-1) ;
        cout <<m_tilemap[q]<<"|";
        if(auxL<y){auxL=y;cout << endl;}
    }
     */
    
    
    //LEER CAPA DE OBJETOS
    XMLElement* objectGroup = map->FirstChildElement("objectgroup");
    
    if(objectGroup!=nullptr){
        XMLElement* object = objectGroup->FirstChildElement("object");
        vector<int> nums_nodos;
        vector<std::string> conexiones_nodos;
        vector<dvector3D*> posiciones;
        for (XMLElement* child = map->FirstChildElement("objectgroup"); child != NULL; child = child->NextSiblingElement("objectgroup")){
            
            
            int i=0;
            std::string name_capa = child->Attribute("name");
            
            if(object == NULL && (child != NULL))
                object = child->FirstChildElement();
            
            
            while (object != NULL){
                dvector2D a = ConvertDataPosition2D(object);
                if(name_capa == "muros"){
                    pos_objetos.push_back(a);
                    readPolyline(object);
                }else if(name_capa == "nodos"){
                    
                    dvector3D * pos_nodo = new dvector3D(a.x,a.y,0.0f);
                    XMLElement* properties = object->FirstChildElement();
                    if(!properties) throw READING_GRAPH_DATA;
                    XMLElement* property = properties->FirstChildElement();
                    if(!property) throw READING_GRAPH_DATA;
                    
                    int num_nodo = object->IntAttribute("name");
                    std::string conecta_nodos = property->Attribute("value");
                    
                    posiciones.push_back(pos_nodo);
                    nums_nodos.push_back(num_nodo);
                    conexiones_nodos.push_back(conecta_nodos);
                    
                    if(i == 0) i++;
                    
                }
                object = object->NextSiblingElement();
            }
        }
        
        
        std::map<int,GraphNode*> GraphN;
        std::map<int,GraphNode*>::iterator it,it_aux;
        
        for(size_t i = 0;i<nums_nodos.size();i++){
            GraphNode * nodo = new GraphNode(nums_nodos[i],posiciones[i]);
            GraphN.insert(std::pair<int, GraphNode*>(nums_nodos[i],nodo));
        }
        for (size_t i=0; i<nums_nodos.size(); i++) {
            vector<std::string> conexos = explode(conexiones_nodos[i], '-');
            it = GraphN.find(nums_nodos[i]);
            if(it==GraphN.end()) cout << "ERROR - No encontro Nodo base" << endl;
            for (size_t j = 0; j<conexos.size(); j++) {
                it_aux = GraphN.find(std::stoi(conexos[j]));
                if(it==GraphN.end()) throw GRAPH_NODO_CONNECTION;
                else
                    it->second->conectar(it_aux->second);
            }
        }
        Graph * Grafo = new Graph(GraphN);
        PathPlanning::instance()->init(Grafo);
    }
    
     
    CreateWorld();
    return true;
}

void loadLevel::CreateWorld(){
    ObjectFactory factory;
    /*
     FASES DE CARGA DEL MAPA EN MEMORIA
     
     0 - SUELO
     1 - OBJETOS CINEMATICOS
     2 - PLAYER
     3 - PAREDES
     4 - OBJETOS
     
     */
    
    //SUELO
    Ground * suelo = new Ground;
    suelo->inicializar(m_height, m_width);
    Mundo.push_back(suelo);
    
    //INICIALIZAR CAMARA Y PLAYER (AUTOCAMRA ACTIVADO)
    camara = new Camera;
    
    
    player = new Player;
    player->setObjectType(PLAYER);
    player->createPhysicsBody(DYNAMIC_BODY);
    player->addNodo("3d/sphere.3ds");
    
    
    // CONSTRUIR OBJETOS DE MUNDO
    Muro * muro = new Muro;
    muro->construirMuros(m_tilemap,objetos, pos_objetos, m_tileWidth, m_tileHeight,m_width,m_height);
    Mundo.push_back(muro);
    
    
    //CONSTRUIR OBJETOS
    size_t it=0, end=m_obj.size();
    
    size_t id = 1;
    
    for(int sd=0; sd<m_obj.size(); sd++) {
        if(m_obj.at(sd).z == VOID)
            cout << "_______ VOID: " << m_obj.at(sd).x << "|" << m_obj.at(sd).y << "|" << m_obj.at(sd).z << endl;
    }
    
    for (; it<end; it++) {
        
        ObjectType tipo = (ObjectType)m_obj[it].z;
        dvector3D pos(m_obj[it].x,m_obj[it].y,0);
        GameObject * g;
        
        if(
           tipo==PALA       ||
           tipo==MONEDAS    ||
           tipo==PIEDRA     ||
           tipo==LLAVE      ||
           (tipo>FUENTE && tipo<REHEN))
        {
            g = factory.PObject(it, pos, tipo);Mundo.push_back(g);
        }
        else if(tipo == ALARMA ||
               (tipo > LLAVE && tipo < REHEN))
        {
            g = factory.WObject(it, pos, tipo);Mundo.push_back(g);
            
        }
        else if(tipo==REHEN || tipo==ENEMIGOS){
            g = factory.Actores(it, pos, tipo);Mundo.push_back(g);

        }
        else if(tipo==PLAYER){
            player->setPosition(pos);
            camara->EnableAutoCamera(player->getPosition());
            continue;
        }
        if(!g) throw FACTORY_ERROR;
    }
   
    
    
}

const vector<std::string> loadLevel::explode(const std::string& s, const char& c){
    std::string buff{""};
    vector<std::string> v;
    
    for(auto n:s)
    {
        if(n != c) buff+=n; else
            if(n == c && buff != "") { v.push_back(buff); buff = ""; }
    }
    if(buff != "") v.push_back(buff);
    
    return v;
}
