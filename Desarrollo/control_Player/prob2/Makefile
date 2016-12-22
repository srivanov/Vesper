# Plantilla de Makefile para Irrlicht
# Solo es necesario cambiar target, lista de fuentes, recursos y directorio de instalacion de Irrlicht

# Nombre del ejecutable que va a ser generado
Target := main2
# Lista de ficheros fuente, separados por espacios
Sources := main.cpp
# Lista de ficheros de recursos, separados por espacios
Resources := 
# Ruta del directorio donde tenemos Irrlicht instalado (donde estan los directorios lib e include)
IrrlichtHome := ../irrlicht
# Ruta del ejecutable generado
BinPath = .

# opciones generales de compilacion (might need to be set when compiling the lib, too)
# flash de preprocesamiento (defines y directorios de includes)
USERCPPFLAGS = 
# flags de optimizacion
USERCXXFLAGS = -O3 -ffast-math
#USERCXXFLAGS = -g -Wall
# flags de enlazado (librerias y rutas de librerias)
USERLDFLAGS =

####
# No es necesario hacer cambios a partir de aqui
####

CPPFLAGS = -I$(IrrlichtHome)/include -I/usr/X11R6/include $(USERCPPFLAGS)
CXXFLAGS = $(USERCXXFLAGS)
LDFLAGS = $(USERLDFLAGS)
LIBS = -lsfml-graphics -lsfml-window -lsfml-system
# Linux es el target por defecto 
all: all_macos

# opciones especificas de cada target
all_linux all_macos all_win32 static_win32: LDFLAGS += -L$(IrrlichtHome)/lib/$(SYSTEM) -lIrrlicht
all_linux: LDFLAGS += -L/usr/X11R6/lib$(LIBSELECT) -lGL -lXxf86vm -lXext -lX11 -lXcursor
all_linux clean_linux: SYSTEM=Linux
all_macos: LDFLAGS += -Xlinker -no_pie -framework OpenGL -framework Cocoa -framework Carbon -framework IOKit
#all_macos: CPPFLAGS += -arch i386 -stdlib=libstdc++
all_macos clean_macos: SYSTEM=MacOSX
all_win32 clean_win32 static_win32: SYSTEM=Win32-gcc
all_win32 clean_win32 static_win32: SUF=.exe
static_win32: CPPFLAGS += -D_IRR_STATIC_LIB_
all_win32: LDFLAGS += -lopengl32 -lm
static_win32: LDFLAGS += -lgdi32 -lwinspool -lcomdlg32 -lole32 -loleaut32 -luuid -lodbc32 -lodbccp32 -lopengl32
# nombre del binario
DESTPATH = $(BinPath)/$(Target)$(SUF)

all_linux compile_macos all_win32 static_win32:
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(Sources) -o $(DESTPATH) $(LDFLAGS) $(LIBS)

all_macos: compile_macos 
	mkdir -p $(BinPath)/${Target}.app
	mkdir -p $(BinPath)/${Target}.app/Contents
	mkdir -p $(BinPath)/${Target}.app/Contents/Resources
	mkdir -p $(BinPath)/${Target}.app/Contents/MacOS
ifdef Resources
	cp $(Resources) $(BinPath)/${Target}.app/Contents/Resources	
endif
	mv $(DESTPATH) $(BinPath)/${Target}.app/Contents/MacOS

clean: clean_linux clean_macos clean_win32

clean_linux clean_win32:
	@$(RM) $(DESTPATH)

clean_macos:
	@$(RM) -Rf $(BinPath)/${Target}.app

.PHONY: all all_win32 static_win32 clean clean_linux clean_win32

ifeq ($(HOSTTYPE), x86_64)
LIBSELECT=64
endif

ifeq ($(HOSTTYPE), sun4)
LDFLAGS += -lrt
endif

