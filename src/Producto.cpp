//Clase producto con sus atributos y métodos:
#include "Include/Producto.h"
using namespace std; 

Producto:: Producto(string _categoria, string _subcategoria, double _precio, int _id)
    : categoria(_categoria), subcategoria(_subcategoria), precio(_precio), id(_id) {}

string Producto::getCategoria() const { return categoria; }
string Producto::getSubcategoria() const { return subcategoria; }
double Producto::getPrecio() const { return precio; }
int Producto::getId() const { return id; }
