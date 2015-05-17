#include "Elemento.h"

Elemento::Elemento()
{
    valor = 0;
    sigCol = NULL;
    sigFil = NULL;
}

Elemento::Elemento(int valor)
{
    this->valor = valor;
    sigCol = NULL;
    sigFil = NULL;
}

Elemento::~Elemento()
{

}

