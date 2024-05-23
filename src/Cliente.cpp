//Clase cliente con sus atributos y métodos:
#include <iostream>
#include "../Include/Cliente.h"

using namespace std;

Cliente:: Cliente(string _tipoCliente,int _numero): tipoCliente(_tipoCliente),numero(_numero){}
string Cliente:: getTipoCliente() const {return tipoCliente;}
int Cliente:: getNumero() const {return numero;}