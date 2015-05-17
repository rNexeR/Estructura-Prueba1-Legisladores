#ifndef MATRIZ_H
#define MATRIZ_H
#include "Elemento.h"

class Matriz
{
public:
    Matriz();
    Matriz(int filas, int columnas);
    void asignar(int fila, int columna, int elemento);
    Elemento* obtenerElemento(int fila, int columna);
    Matriz sumar(Matriz* sum);
    Matriz productoEscalar(int num);
    void imprimir();
    ~Matriz();
    int filas, columnas;
    Elemento* inicio;
};

#endif // MATRIZ_H
