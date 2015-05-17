#ifndef ELEMENTO_H
#define ELEMENTO_H
#include <iostream>
using namespace std;

class Elemento
{
public:
    Elemento();
    Elemento(int valor);
    ~Elemento();
    int valor;
    Elemento* sigCol;
    Elemento* sigFil;
};

#endif // ELEMENTO_H
