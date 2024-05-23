#pragma once
#include <iostream>
using namespace std;

class Cliente
{
private:
    string tipoCliente;
    int numero;

public:
    Cliente(string tipoCliente,int numero);
    string getTipoCliente() const;
    int getNumero() const;
};