#pragma once

#ifndef GUI_hpp
#define GUI_hpp

#include "CEGUI/CEGUI.h"
#include "CEGUI/RendererModules/OpenGL/GL3Renderer.h"
#include "CEGUI/RendererModules/Irrlicht/Renderer.h"

#include "../MyEventReceiver.hpp"

class LayoutGUI;
enum tLayout {
    tMenuPrincipalLayout = 0,
    tCargarPartidaLayout,
    tOpcionesLayout,
    tCreditosLayout,
    tHUD,
    tPausa
};

struct vec4f{
	float x, y, z, w;
};

namespace Motor{
	class GUI {
	public:
		void init(const std::string& resourcesPath, irr::IrrlichtDevice *device);
		void destroy();
		void draw();
        ~GUI();

        void update();

		void loadScheme(const std::string& schemeFile);
		void setFont(const std::string& fontFile);

		CEGUI::Window* createWidget(const std::string& type, const vec4f& destRectPerc, const vec4f& destRectPix, const std::string& name="");

		CEGUI::Window* loadLayout(const std::string& layout);


		void showMouseCursor(bool show);

		void setMouseCursor(const std::string& mouse);

		CEGUI::Key::Scan irrlichtToCeguiKey(irr::EKEY_CODE key);

		void injectKeyDown(irr::EKEY_CODE key);

		void injectKeyUp(irr::EKEY_CODE key);

		void injectMousePosition(float x, float y);

		void injectLeftMouseButton() {
			m_context->injectMouseButtonDown(CEGUI::MouseButton::LeftButton);
		}

		void injectLeftMouseButtonUp() {
			m_context->injectMouseButtonUp(CEGUI::MouseButton::LeftButton);
		}

		void injectRightMouseButton() {
			m_context->injectMouseButtonDown(CEGUI::MouseButton::RightButton);
		}
        
        void injectMouseClick() {
            m_context->injectMouseButtonClick(CEGUI::MouseButton::LeftButton);
        }


		static void setWidgetDestRect(CEGUI::Window* widget, const vec4f& destRectPerc, const vec4f& destRectPix);
		//Getters
		CEGUI::OpenGL3Renderer* getRenderer() { return m_renderer; }
		//CEGUI::IrrlichtRenderer* getIrrlichtRenderer() { return m_rendererIrrlicht; }
		const CEGUI::GUIContext* getContext() { return m_context; }

		bool debugInput = false;
        
        virtual tLayout getLayout() = 0;
        bool mostrar();
        bool ocultar();
        void setPadre(LayoutGUI* p);
        
    protected:
        tLayout layout;
        bool activo;
        LayoutGUI* padre = NULL;
	private:
		CEGUI::OpenGL3Renderer* m_renderer;
		//CEGUI::IrrlichtRenderer* m_rendererIrrlicht;
		CEGUI::GUIContext* m_context = nullptr;

		CEGUI::Window* m_root = nullptr;

		unsigned int m_lastTime = 0;
		
	};
}

#endif

