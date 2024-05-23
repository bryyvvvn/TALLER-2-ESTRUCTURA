#pragma once

#include <iostream>
using namespace std;

class Producto 
{
private:
    string categoria;
    string subcategoria;
    double precio;
    int id;
    
public:
    Producto(string _categoria,string _subcategoria, double _precio, int _id);
    string getCategoria() const;
    string getSubcategoria() const;
    double getPrecio() const;
    int getId() const;
};

