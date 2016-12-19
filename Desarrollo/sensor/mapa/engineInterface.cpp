
#include "engineInterface.hpp"

engineInterface* engineInterface::pinstance = 0;

engineInterface* engineInterface::Instance(){ // CONSTRUCTOR
    if(pinstance == 0)
		pinstance = new engineInterface();

    
	return pinstance;
}

engineInterface::engineInterface(){
	
}

engineInterface::~engineInterface(){ // DESTRUCTOR
    
}

bool engineInterface::_createDevice(uint32_t ancho, uint32_t alto, uint32_t color, bool fullscreen, bool stencilbuffer, bool vsync, bool receiver){
	if(receiver)
		device = createDevice(EDT_OPENGL, dimension2d<u32>(ancho, alto), color, fullscreen, stencilbuffer, vsync, &r);
	else
		device = createDevice(EDT_OPENGL, dimension2d<u32>(ancho, alto), color, fullscreen, stencilbuffer, vsync, 0);
    if(!device){
        return false;
    }
    driver = device->getVideoDriver();
    smgr = device->getSceneManager();
    //PRUEBA
//    ICameraSceneNode * cam = smgr->addCameraSceneNode();
//    cam->setFOV(32);
//    cam->setNearValue(0.5f);
//    cam->setFarValue(10.0f);
    
    return true;
}

bool engineInterface::_Run(){
    return device->run();
}
void engineInterface::_deviceClose(){
    device->closeDevice();
}

void engineInterface::_createCamera(float* posicion, float* target, float* rotation){
	camera = smgr->addCameraSceneNode(0,vector3df(posicion[0],posicion[1],posicion[2]),vector3df(target[0],target[1],target[2]));
	_setCamRotation(rotation);
}

void engineInterface::_setCamPosition(float *posicion){
	camera->setPosition(vector3df(posicion[0],posicion[1],posicion[2]));
}

void engineInterface::_setCamTarget(float *target){
	camera->setTarget(vector3df(target[0],target[1],target[2]));
}

void engineInterface::_setCamRotation(float *rotation){
	camera->setRotation(vector3df(rotation[0],rotation[1],rotation[2]));
}

IMesh* engineInterface::_getMesh(char* filename){
	if(filename == NULL)
		return NULL;
    return smgr->getMesh(filename);
}

nodeMesh* engineInterface::_getNode(char *filename){
	IMesh* mesh = _getMesh(filename);
	if(mesh){
		return new nodeMesh(smgr->addMeshSceneNode(mesh));
	}
	return NULL;
}

nodeMesh* engineInterface::_getNodeFromMesh(IMesh* mesh){
	return new nodeMesh(smgr->addMeshSceneNode(mesh));
}

bool engineInterface::_setMaterialTexture(nodeMesh* nodo, char *filename){
	return nodo->_setMaterialTexture(driver->getTexture(filename));
}

void engineInterface::_setMaterialFlag(nodeMesh* node, uint32_t flag, bool value){
	switch (flag) {
		case 0:
			node->_setMaterialFlag(EMF_LIGHTING, value);
			break;
			
		default:
			break;
	}
}

bool engineInterface::loadMap(world * mundo){

//    IMesh* muro  = smgr->getMesh("../../../mapa/3d/muro.3ds");
//    IMesh* muro2 = smgr->getMesh("../../../mapa/3d/muro.3ds");
//    IMesh* suelo = smgr->getMesh("../../../mapa/3d/suelo.3ds");
	IMesh* muro  = _getMesh("../../../mapa/3d/muro.3ds");
	IMesh* muro2 = _getMesh("../../../mapa/3d/muro.3ds");
	IMesh* suelo = _getMesh("../../../mapa/3d/suelo.3ds");
    IMesh* suelo_comida = smgr->getGeometryCreator()->createCubeMesh(vector3df{1,1,1});
    IMesh* cubo_fuente = smgr->getGeometryCreator()->createCubeMesh(vector3df{1,1,1});
    IMesh* cubo_alarma = smgr->getGeometryCreator()->createCubeMesh(vector3df{1,1,1});
    IMesh* cubo_botiquin = smgr->getGeometryCreator()->createCubeMesh(vector3df{1,1,1});
    
    if(!muro){
        printf("muro no cargado\n");
        return false;
    }
    if(!suelo){
        printf("suelo no cargado\n");
        return false;
    }
	
	/////(0,-5,10)-(0,6,0)////posicion de la camra, y donde tiene q mirar
    //smgr->addCameraSceneNode(0,vector3df(60,-40,-50),vector3df(60,30,0));
    cargarMapa * map = new cargarMapa();
    
    map->leerMapa();
//    map->mostrarMatriz();
    int*** mapita;
    
    //CARGAR PLANO
    IMesh* suelo_prueba = smgr->getGeometryCreator()->createPlaneMesh(core::dimension2df(map->getHeight(),map->getWidth()));
    nodeMesh * nodo_suelo = _getNodeFromMesh(suelo_prueba);
    _setMaterialFlag(nodo_suelo, 0, false);
    _setMaterialTexture(nodo_suelo,"../../../modelos3D/colorverde.jpg");
    nodo_suelo->_setNodePosition(new float[3]{static_cast<float>((map->getHeight()/2)-0.5),static_cast<float>((map->getWidth()/2)-0.5),0.5});
    nodo_suelo->_setNodeRotation(new float [3]{90,180,180});
    
    mapita = map->getMatriz();
    nodeMesh* nodo;
    nodeMesh* nodor; //rocas
    nodeMesh* nodoc; //comida
    nodeMesh* nodof; //fuente
    nodeMesh* nodoa; //alarma
    nodeMesh* nodob; //botiquin
    //nodeMesh* nodo_suelo;
    
    if(map->getHeight() < 0 || map->getWidth() < 0)
        return false;
    
    for(int i=0; i<map->getHeight();i++){
        for(int j=0; j<map->getWidth(); j++){
            /*if(mapita[0][i][j] == 21 || mapita[0][i][j] == 9 ){
//				nodo = smgr->addMeshSceneNode(muro);
				nodo = _getNodeFromMesh(muro);
//				nodo->setMaterialFlag(EMF_LIGHTING, false);
				_setMaterialFlag(nodo, 0, false);
//                nodo->setMaterialTexture(0, driver->getTexture("../../../mapa/3d/rocas.jpg"));
				_setMaterialTexture(nodo, "../../../modelos3D/rocas.jpg");
//                nodo->setPosition(vector3df(i,j,0));
				nodo->_setNodePosition(new float[3]{static_cast<float>(i),static_cast<float>(j),-0.5});
                
                nodo = NULL;
            }*/
            if(mapita[0][i][j] == 86){ //comida
                nodoc = _getNodeFromMesh(suelo_comida);
                _setMaterialFlag(nodoc, 0, false);
                _setMaterialTexture(nodoc,"../../../modelos3D/colorComida.jpg");
                nodoc->_setNodePosition(new float[3]{static_cast<float>(i),static_cast<float>(j),0});
                comida * food = new comida(nodoc->_getNodePositionD());
                mundo->anyadirComida(food);
                
                nodoc = NULL;
            }
            if(mapita[0][i][j] == 100){ //fuente
                nodof = _getNodeFromMesh(cubo_fuente);
                _setMaterialFlag(nodof, 0, false);
                _setMaterialTexture(nodof,"../../../modelos3D/colorFuente.jpg");
                nodof->_setNodePosition(new float[3]{static_cast<float>(i),static_cast<float>(j),0});
                fuente * fuen = new fuente(nodof->_getNodePositionD(),true);
                mundo->anyadirFuente(fuen);
                nodof = NULL;
            }
            if(mapita[0][i][j] == 161){ //alarma
                nodoa = _getNodeFromMesh(cubo_alarma);
                _setMaterialFlag(nodoa, 0, false);
                _setMaterialTexture(nodoa,"../../../modelos3D/colorAlarma.jpg");
                nodoa->_setNodePosition(new float[3]{static_cast<float>(i),static_cast<float>(j),0});
                
                alarma * alarm = new alarma(nodoa->_getNodePositionD());
                mundo->anyadirAlarma(alarm);
                vector3D * p = new vector3D(20,30,40);
                
                nodoa = NULL;
            }
            if(mapita[0][i][j] == 130){ //botiquin
                nodob = _getNodeFromMesh(cubo_botiquin);
                _setMaterialFlag(nodob, 0, false);
                _setMaterialTexture(nodob,"../../../modelos3D/colorBotiquin.jpg");
                nodob->_setNodePosition(new float[3]{static_cast<float>(i),static_cast<float>(j),0});
                nodob->_getNodePositionD();
                //botiquin * boti = new botiquin(nodob->_getNodePositionD());
                //mundo->anyadirBotiquin(boti);
                altavoz * alta = new altavoz(nodob->_getNodePositionD(),1);
                mundo->anyadirAltavoz(alta);
                nodob = NULL;
            }
            /*if(mapita[0][i][j] == 86){
//                nodo_suelo = smgr->addMeshSceneNode(suelo);
				nodo_suelo = _getNodeFromMesh(suelo);
//                nodo_suelo->setMaterialFlag(EMF_LIGHTING, false);
				_setMaterialFlag(nodo_suelo, 0, false);
//                nodo_suelo->setMaterialTexture(0, driver->getTexture("../../../mapa/3d/verde.jpg"));
				_setMaterialTexture(nodo_suelo, "../../../modelos3D/verde.jpg");
//                nodo_suelo->setPosition(vector3df(i,j,0));
				nodo_suelo->_setNodePosition(new float[3]{static_cast<float>(i),static_cast<float>(j),0});
                nodo_suelo = NULL;
            }*/
        }
    }
    return true;
}

void engineInterface::_beginScene(bool backBuffer, bool zBuffer){
    driver->beginScene(backBuffer, zBuffer, SColor(255, 255, 255, 255));
}
void engineInterface::_drawAll(){
    smgr->drawAll();
}
void engineInterface::_endScene(){
    driver->endScene();
}

ISceneCollisionManager* engineInterface::getSceneCollisionManager(){
    return smgr->getSceneCollisionManager();
}

void engineInterface::setreceiver(bool active){
	
	if(active){
		device->setEventReceiver(&r);
	}else
		device->setEventReceiver(0);
}

bool engineInterface::isKeyDown(char key){
	return r.IsKeyDown(key);
}

void engineInterface::_setNearValue(float nv){
    f32 c =(f32)nv;
    camera->setNearValue(c);
}

void engineInterface::_setFarValue(float fv){
    f32 n = (f32)fv;
    camera->setFarValue(n);
}
IMesh* engineInterface::_createPlaneMesh(float height, float width, char *texture){
    IMesh * plano = smgr->getGeometryCreator()->createPlaneMesh(core::dimension2d<f32>(width,height));
    nodeMesh * nodo = _getNodeFromMesh(plano);
    _setMaterialFlag(nodo, 0, false);
    _setMaterialTexture(nodo,texture);
    return plano;
}


