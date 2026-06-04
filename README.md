# Laboratorio 4 - Implementacion

Version mejorada a partir del esqueleto inicial del grupo.

## Objetivo de esta version

Esta version deja una base funcional y compilable para el prototipo del Laboratorio 4.
La estructura se mantiene similar a la version original, pero se ajusto el manejo de
colecciones para usar la infraestructura dada por el curso.

## Estructura

- `Clases/`: clases del dominio y clase `Sistema`.
- `Datatypes/`: objetos de transferencia usados por el menu.
- `Interfaces/`: interfaz `ISistema`.
- `ICollection/`: infraestructura dada por el curso.
- `main.cpp`: menu de consola.
- `Makefile`: compilacion del proyecto.

## Colecciones

En las clases del sistema no se usan `std::map`, `std::vector` ni `std::set`.

- Para busquedas por clave se usa `IDictionary` con `OrderedDictionary`.
- Para relaciones y listados se usa `ICollection` con `List`.
- Las clases de dominio que se guardan en colecciones heredan de `ICollectible`.
- Los datatypes que se devuelven al menu tambien heredan de `ICollectible`.

La implementacion interna de `ICollection` se mantiene como caja negra. Solo se corrigio
un caso puntual en el destructor de `OrderedDictionary` para evitar error cuando el
diccionario esta vacio.

## Casos incluidos en el menu

- Carga de datos de prueba.
- Alta de cliente.
- Alta de propietario.
- Alta de inmobiliaria.
- Alta de administracion de propiedad.
- Alta de publicacion.
- Consulta de publicacion.
- Eliminar inmueble.

## Compilacion

En Linux:

```bash
make
```

Para limpiar:

```bash
make clean
```

Tambien se verifico la compilacion directa con:

```bash
g++ -std=c++11 -Wall -Wextra -I. main.cpp Clases/*.cpp Datatypes/*.cpp ICollection/*.cpp ICollection/collections/*.cpp ICollection/interfaces/*.cpp -o lab4
```

## Nota

Esta base es funcional y esta pensada para que el grupo la revise, la pruebe en Linux
y ajuste los detalles finos de contratos, mensajes de error y datos de prueba segun la
letra final del curso.
