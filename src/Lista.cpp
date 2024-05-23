//Creación de los metodos para la utilización de listas enlazadas:
#include "Include/Lista.h"
using namespace std;

Lista::Nodo::Nodo(Producto producto)
    : producto(producto), siguiente(nullptr) {}

Lista::Lista() : cabeza(nullptr) {}

void Lista::agregar(Producto producto)
{
    if (this->cabeza == nullptr)
    {
        this->cabeza = new Nodo(producto);
    }
    else
    {
        Nodo *temp = cabeza;
        while (temp->siguiente != nullptr)
        {
            temp = temp->siguiente;
        }
        temp->siguiente = new Nodo(producto);
    }
}

void Lista::imprimirBoleta() const
{
    cout << "\n----------BOLETA-------------" << endl;
    int i = 1;
    Nodo *temp = cabeza;
    while (temp != nullptr)
    {
        cout << i << ". "
                  << "Categoria: " << temp->producto.getCategoria()
                  << " Subcategoria: " << temp->producto.getSubcategoria()
                  << " Precio Unitario: " << temp->producto.getPrecio()
                  << " ID: " << temp->producto.getId() << endl;
        temp = temp->siguiente;
        i++;
    }
}

void Lista::eliminar(int id)
{
    if (cabeza == nullptr)
    {
        return;
    }

    if (cabeza->producto.getId() == id)
    {
        Nodo *temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
        return;
    }

    Nodo *temp = cabeza;
    while (temp->siguiente != nullptr)
    {
        if (temp->siguiente->producto.getId() == id)
        {
            Nodo *nodoAEliminar = temp->siguiente;
            temp->siguiente = temp->siguiente->siguiente;
            delete nodoAEliminar;
            return;
        }
        temp = temp->siguiente;
    }
}

Lista::~Lista()
{
    Nodo *temp = cabeza;
    while (temp != nullptr)
    {
        Nodo *next = temp->siguiente;
        delete temp;
        temp = next;
    }
}
