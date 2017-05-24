
#include "GUI.h"
#include "../Dvector.hpp"

void GUI::init(CEGUI::RenderTarget* target){
	CEGUI::Logger::getSingleton().setLoggingLevel(CEGUI::Informative);
	m_context = &CEGUI::System::getSingleton().createGUIContext(*target);
	m_root = CEGUI::WindowManager::getSingleton().createWindow("DefaultWindow", "root");
	m_context->setRootWindow(m_root);
	m_renderer = (CEGUI::OpenGL3Renderer*)states::Instance()->renderer;
}

GUI::~GUI(){
    
}

void GUI::update(){
    injectMousePosition(eventManager->mousePos);
    if(eventManager->isPressed(SKY_MOUSE_BUTTON_LEFT)) {
        injectLeftMouseButton();
    } else {
        injectLeftMouseButtonUp();
    }
}

void GUI::render(){
    m_context->draw();
}

void GUI::destroy() {
	CEGUI::System::getSingleton().destroyGUIContext(*m_context);
}

void GUI::draw() {
//	m_context->draw();
	//glDisable(GL_SCISSOR_TEST);
}

/*void GUI::update() {
	unsigned int elapsed;
	Time time;
	if (m_lastTime == 0) {
		elapsed = 0;
		m_lastTime = time.asSeconds();
	} else {
		unsigned int nextTime = time.asSeconds();
		elapsed = nextTime - m_lastTime;
		m_lastTime = nextTime;
	}
	m_context->injectTimePulse(elapsed);
}*/

void GUI::loadScheme(const std::string& schemeFile){
	CEGUI::SchemeManager::getSingleton().createFromFile(schemeFile);
}

void GUI::setFont(const std::string& fontFile) {
	CEGUI::FontManager::getSingleton().createFromFile(fontFile + ".font");
	m_context->setDefaultFont(fontFile);
}

CEGUI::Window* GUI::createWidget(const std::string& type, const vec4f& destRectPerc, const vec4f& destRectPix, const std::string& name) {
	CEGUI::Window *newWindow = CEGUI::WindowManager::getSingleton().createWindow(type, name);
	m_root->addChild(newWindow);
	setWidgetDestRect(newWindow, destRectPerc, destRectPix);
	return newWindow;
}

CEGUI::Window * GUI::loadLayout(const std::string & layout) {
    CEGUI::Window *newWindow = CEGUI::WindowManager::getSingleton().loadLayoutFromFile(layout);
	m_root->addChild(newWindow);
	return newWindow;
}

void GUI::showMouseCursor(bool show) {
	if (show) {
		m_context->getMouseCursor().show();
	} else {
		m_context->getMouseCursor().hide();
	}
}

void GUI::setMouseCursor(const std::string & mouse) {
	m_context->getMouseCursor().setDefaultImage(mouse);
}

//void GUI::injectKeyDown(irr::EKEY_CODE key) {
////	m_context->injectKeyDown(irrlichtToCeguiKey(key));
//}
//
//void GUI::injectKeyUp(irr::EKEY_CODE key) {
////	m_context->injectKeyUp(irrlichtToCeguiKey(key));
//}

void GUI::injectMousePosition(dvector2D pos) {
	m_context->injectMousePosition(pos.x, pos.y);
}

void GUI::setWidgetDestRect(CEGUI::Window* widget, const vec4f& destRectPerc, const vec4f& destRectPix) {
	widget->setPosition(CEGUI::UVector2(CEGUI::UDim(destRectPerc.x, destRectPix.x), CEGUI::UDim(destRectPerc.y, destRectPix.y)));
	widget->setSize(CEGUI::USize(CEGUI::UDim(destRectPerc.z, destRectPix.w), CEGUI::UDim(destRectPerc.z, destRectPix.w)));
}



