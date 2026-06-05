# Laboratorio 4 - Implementacion

Version completada a partir del esqueleto inicial del grupo.

## Objetivo de esta version

Esta version deja una base funcional y compilable para el Laboratorio 4. La estructura
mantiene separadas las clases del dominio, los datatypes, la interfaz del sistema y el
menu de consola.

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

La implementacion interna de `ICollection` se mantiene como caja negra y no se modifica.
El codigo propio evita depender de cambios internos de esa infraestructura.

## Casos incluidos en el menu

- Carga de datos de prueba.
- Alta de cliente.
- Alta de propietario.
- Alta de inmobiliaria.
- Representacion de propietario por inmobiliaria.
- Alta de inmueble.
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

Para ejecutar:

```bash
./lab4
```

## Nota

El `main.cpp` concentra `cin` y `cout`. Las clases del sistema, dominio y datatypes
devuelven datos mediante datatypes o colecciones de datatypes.
