CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -I. -IClases -IDatatypes
TARGET = lab4

SOURCES = main.cpp \
    Clases/Administra/Administra.cpp \
    Clases/Agenda/Agenda.cpp \
    Clases/Apartamento/Apartamento.cpp \
    Clases/Casa/Casa.cpp \
    Clases/Cliente/Cliente.cpp \
    Clases/Inmobiliaria/Inmobiliaria.cpp \
    Clases/Inmueble/Inmueble.cpp \
    Clases/Propietario/Propietario.cpp \
    Clases/Publicacion/Publicacion.cpp \
    Clases/Sistema/Sistema.cpp \
    Clases/Factory/SistemaFactory.cpp \
    Clases/Usuario/Usuario.cpp \
    Datatypes/DTDetalleInmueble/DTDetalleInmueble.cpp \
    Datatypes/DTFecha/DTFecha.cpp \
    Datatypes/DTInmobiliaria/DTInmobiliaria.cpp \
    Datatypes/DTInmueble/DTInmueble.cpp \
    Datatypes/DTInmuebleAdministrado/DTInmuebleAdministrado.cpp \
    Datatypes/DTPropietario/DTPropietario.cpp \
    Datatypes/DTPublicacion/DTPublicacion.cpp \
    ICollection/Integer.cpp \
    ICollection/String.cpp \
    ICollection/collections/List.cpp \
    ICollection/collections/ListIterator.cpp \
    ICollection/collections/ListNode.cpp \
    ICollection/collections/OrderedDictionary.cpp \
    ICollection/collections/OrderedDictionaryEntry.cpp \
    ICollection/interfaces/ICollectible.cpp \
    ICollection/interfaces/ICollection.cpp \
    ICollection/interfaces/IDictionary.cpp \
    ICollection/interfaces/IIterator.cpp \
    ICollection/interfaces/IKey.cpp \
    ICollection/interfaces/OrderedKey.cpp

# Todos los .o se generan juntos en la raiz para evitar problemas de carpetas en Windows
OBJECTS = $(notdir $(SOURCES:.cpp=.o))

VPATH = Clases/Administra Clases/Agenda Clases/Apartamento Clases/Casa Clases/Cliente \
    Clases/Inmobiliaria Clases/Inmueble Clases/Propietario Clases/Publicacion \
    Clases/Sistema Clases/Factory Clases/Usuario \
    Datatypes/DTDetalleInmueble Datatypes/DTFecha Datatypes/DTInmobiliaria \
    Datatypes/DTInmueble Datatypes/DTInmuebleAdministrado Datatypes/DTPropietario \
    Datatypes/DTPublicacion \
    ICollection ICollection/collections ICollection/interfaces

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o $(TARGET) $(TARGET).exe

run: all
	@echo Ejecutando $(TARGET)...
	@./$(TARGET)

.PHONY: all clean run