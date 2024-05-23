#pragma once

#include "Producto.h"
#include <iostream>
using namespace std;

class Lista
{
public:
    class Nodo
    {
    public:
        Producto producto;
        Nodo *siguiente;
        Nodo(Producto producto);
    };

    Nodo *cabeza;

    Lista();

    void agregar(Producto producto);
    void imprimirBoleta() const;
    void eliminar(int id);
    ~Lista();
};
