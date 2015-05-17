#include "Matriz.h"

Matriz::Matriz()
{
    filas = 0;
    columnas = 0;
}

Matriz::Matriz(int filas, int columnas){
    this->filas = filas;
    this->columnas = columnas;

    inicio = new Elemento(0);
    Elemento* temp = inicio;
    //cout<<inicio->valor<<" ";

    for(int x = 0; x<filas; x++){
        Elemento* t = temp;
        for(int x = 0; x<columnas-1; x++){
            t->sigCol = new Elemento(0);
            t = t->sigCol;
            //cout<<t->valor<<" ";
        }
        cout<<endl;
        temp->sigFil = new Elemento(0);
        temp = temp->sigFil;
        //cout<<temp->valor<<" ";
    }
    cout<<endl;

    temp = inicio;


}

void Matriz::asignar(int fila, int columna, int elemento){
    cout<<"seteando valor"<<endl;
    if(fila<filas && columna<columnas){
       obtenerElemento(fila,columna)->valor = elemento;

    }
}

Elemento* Matriz::obtenerElemento(int fila, int columna){
    cout<<"obteniendo valor"<<endl;
    if(fila<filas && columna<columnas){
        Elemento* temp = inicio;
        for(int x = 0; x<fila; x++){
            temp=temp->sigFil;
        }
        for(int x = 0; x<columna; x++){
            temp=temp->sigCol;
        }
        return temp;
    }
}

Matriz Matriz::sumar(Matriz* sum){
    if(sum->filas == filas && sum->columnas == columnas){
        Elemento* temp = inicio;
        for(int x = 0; x < filas; x++){
            Elemento* t = temp;
            for(int y = 0; y < columnas; y++){
                t->valor = t->valor + sum->obtenerElemento(x, y)->valor;
                t = t->sigCol;
            }
            temp = temp->sigFil;
        }
    }
    imprimir();
}

Matriz Matriz::productoEscalar(int num){
    Elemento* temp = inicio;
    for(int x = 0; x < filas; x++){
        Elemento* t = temp;
        for(int y = 0; y < columnas; y++){
            t->valor = t->valor *num;
            t = t->sigCol;
        }
        temp = temp->sigFil;
    }
    imprimir();
}

void Matriz::imprimir(){
    Elemento* temp = inicio;
    //cout<<inicio->valor<<" ";

    for(int x = 0; x<filas; x++){
        Elemento* t = temp;
        for(int x = 0; x<columnas; x++){
            //t->sigFil = new Elemento(0);
            cout<<t->valor<<" ";
            t = t->sigCol;

        }
        cout<<endl;
        //temp->sigCol = new Elemento(0);
        temp = temp->sigFil;
        //cout<<temp->valor<<" ";
    }
    cout<<endl;

}

Matriz::~Matriz()
{

}

