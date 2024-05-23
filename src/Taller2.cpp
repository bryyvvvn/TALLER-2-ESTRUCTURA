
#include <iostream>
#include <string>
#include <queue>
#include <queue>
#include "../Include/Cliente.h"
#include "../Include/Producto.h"
#include "../Include/Lista.h"

#include <sstream>
#include <fstream>

using namespace std;

class Logica
{
public:

     //Crea los productos al iniciar el programa con el archivo Bodega.txt y devuelve el ultimo numero de cliente de la sesion anterior(en caso de que existe sesion anterior):
    int creacionObjetosInicio(Lista *bodega, vector<string> &categorias,queue<Cliente>& colaPreferencial, queue<Cliente>& colaNormal){
      
        ifstream archivo("ArchivosTxt/Bodega.txt");
        ifstream archivoClientes("ArchivosTxt/Clientes.txt");
        string linea;
        int ultimoNumero=0;
    
        if (archivo.is_open()) {
            while (getline(archivo, linea)) {
                stringstream ss(linea);
                string categoria, subcategoria;
                double precio;
                int id;

                
                getline(ss, categoria, ',');
                getline(ss, subcategoria, ',');
                ss >> precio;
                ss.ignore(); 
                ss >> id;

                agregarProducto(categoria, subcategoria, precio, id, bodega);
            }
            archivo.close();
        } else {
            cout << "No se pudo abrir el archivo." << endl;
        }
        
        if (archivoClientes.is_open()) {
            while (getline(archivoClientes, linea)) {
                stringstream ss(linea);
                int numero;
                string tipo;
                
                ss >> numero;
                ss.ignore(); 
                getline(ss, tipo, ','); 
                Cliente cliente(tipo,numero);
                if(tipo=="Normal"){
                    colaNormal.push(cliente);
                }else{
                    colaPreferencial.push(cliente);
                }

                if(numero>ultimoNumero){
                    ultimoNumero=numero;
                }
            }
            archivoClientes.close();
        } else {
            ofstream archivo("ArchivosTxt/Clientes.txt");
            cout<<"Se creo un archivo Clientes.txt"<<endl;
        }



    
            Lista::Nodo *temp = bodega->cabeza;
            while (temp != nullptr)
            {
                
                bool encontrada = false;
                for (const string &categoria : categorias)
                {
                    if (temp->producto.getCategoria() == categoria)
                    {
                        encontrada = true;
                        break;
                    }
                }

                
                if (!encontrada)
                {
                    categorias.push_back(temp->producto.getCategoria());
                }

                temp = temp->siguiente;
            } 
            return ultimoNumero;
    };

//Agregar producto a la bodega al inicio
void agregarProducto(string categoria,string subCategoria,double precio,int id,Lista *l){
    Producto producto(categoria,subCategoria,precio,id);
    l->agregar(producto);
}

//Permite ver si existe la categoria y la subcategoria del producto a agregar
void agregarProductoABodega(string categoria, string subCategoria, double precio, int id, Lista *l, vector<string> &listaCategoria){
    
    Lista::Nodo *temp =l->cabeza; 
    Producto producto(categoria,subCategoria,precio,id);
    l->agregar(producto);

     while(temp!=nullptr){
            bool encontrada = false;
            for (const string &categoria : listaCategoria)
            {
                if (temp->producto.getCategoria() == categoria)
                {
                    encontrada = true;
                    break;
                }
            }

           
            if (!encontrada)
            {
                listaCategoria.push_back(temp->producto.getCategoria());
            }

            temp = temp->siguiente;
    }
    
    
}


//Busca ver quien es la persona que sigue en la cola
Cliente quienSigue(queue<Cliente> clientes, queue<Cliente>preferencial){
    if(clientes.empty() && preferencial.empty())
    {
        cout<<"No queda nadie en la cola"<<endl; 
        return Cliente("",0);
    }
    else
    {
        if(preferencial.empty()&&!clientes.empty()){
            return clientes.front();
            
        }else{
            return prioridadClientesPreferencial(preferencial).front();
        }
    }

}
//Busca la prioridad de los clientes preferencial en este caso Tercera Edad > Discapacidad > Embarazada
queue<Cliente> prioridadClientesPreferencial(queue<Cliente> preferencial){
    queue<Cliente> colaOrdenada;
    queue<Cliente> aux;

    while(!preferencial.empty()) {
        Cliente cliente = preferencial.front();
        preferencial.pop();

        if(cliente.getTipoCliente() == "Tercera Edad") {
            colaOrdenada.push(cliente);
        } else {
            aux.push(cliente);
        }
    }

    while(!aux.empty()) {
        Cliente cliente = aux.front();
        aux.pop();

        if(cliente.getTipoCliente() == "Discapacidad") {
            colaOrdenada.push(cliente);
        } else {
            preferencial.push(cliente);
        }
    }

    while(!preferencial.empty()) {
        Cliente cliente = preferencial.front();
        preferencial.pop();

        if(cliente.getTipoCliente() == "Embarazada") {
            colaOrdenada.push(cliente);
        }else{
            aux.push(cliente);
        }
    }
   
    return colaOrdenada;
    }
    
    void guardarCambiosBodega(const Lista *bodega) {
    ofstream archivo("ArchivosTxt/Bodega.txt");

    if (archivo.is_open()) {
        Lista::Nodo *temp = bodega->cabeza;
        while (temp != nullptr) {
            archivo << temp->producto.getCategoria() << ","
                    << temp->producto.getSubcategoria() << ","
                    << temp->producto.getPrecio() << ","
                    << temp->producto.getId() << "\n";
            temp = temp->siguiente;
        }
        archivo.close();
        
    } else {
        cout << "No se pudo abrir el archivo 'Bodega.txt' para escribir." << endl;
    }
}

    void guardarCambiosClientes(queue<Cliente>& colaPreferencial, queue<Cliente>& colaNormal) {
        ofstream archivo("ArchivosTxt/Clientes.txt");
        if(archivo.is_open()){
            while(!colaNormal.empty()){
                archivo<<colaNormal.front().getNumero()<< ","<<colaNormal.front().getTipoCliente()<<"\n";
                colaNormal.pop();
            }
            while(!colaPreferencial.empty()){
                archivo<<colaPreferencial.front().getNumero()<< ","<<colaPreferencial.front().getTipoCliente()<<"\n";
                colaPreferencial.pop();
            }
            archivo.close();
           
         }else{
            cout<<"No se pudo abrir el abrir el archivo 'Clientes.txt' para guardar los cambios"<<endl;
         }
       
    }


//------------------------------------MENU-------------------------------------------
//Agregar un Cliente Nuevo
    void agregarClienteNuevo(queue<Cliente>& colaPreferencial, queue<Cliente>& colaNormal,int numero) {
    string esPreferencial;
    
    do {
        cout << "¿Es un cliente preferencial? (S/N): ";
        cin >> esPreferencial;
    } while (esPreferencial != "S" && esPreferencial != "N");
        cout<<"---------------------------------"<<endl;
    if (esPreferencial == "S") {
        int tipoClientePreferencial;
        do {
            cout << "¿De que tipo es?\n1. Tercera Edad.\n2. Discapacitado.\n3. Embarazada." << endl;
            cout<<"Ingrese una opcion: ";
            cin >> tipoClientePreferencial;
        } while (tipoClientePreferencial < 1 || tipoClientePreferencial > 3);

        string tipoCliente;
        switch (tipoClientePreferencial) {
            case 1:
                tipoCliente = "Tercera Edad";
                break;
            case 2:
                tipoCliente = "Discapacidad";
                break;
            case 3:
                tipoCliente = "Embarazada";
                break;
        }
        Cliente cliente(tipoCliente, numero);
        colaPreferencial.push(cliente);
        cout<<"---------------------------------"<<endl;
        cout<<"El cliente con el numero: "<<numero<<" fue agregado correctamente a la fila."<<endl;
    } else if (esPreferencial == "N") {
        Cliente cliente("Normal", numero);
        colaNormal.push(cliente);
        cout<<"El cliente con el numero "<<numero<<" fue agregado correctamente a la fila."<<endl;
    }
}
    void imprimir(queue<Cliente>cola){
        cout<<"Cola:"<<endl;
        while(!cola.empty()){
            cout<<cola.front().getTipoCliente()<<" "<<cola.front().getNumero()<<endl;
            cola.pop();
        }
        
        
    }
//Permite al usuario agregar un producto a la bodega:
    void agregarBodegaMenu(Lista* bodega,vector<string> &listaCategoria){
        string categoria;
        string subCategoria;
        double precio;
        int id;
        
        cout<<"Escriba la categoria del producto: ";
        cin>>categoria;
        cout<<"Escriba la subCategoria del producto: ";
        cin>>subCategoria;
        cout<<"Escriba el precio del producto (separar decimales con punto ):  ";
        cin>>precio;
        cout<<"Escriba el ID del producto: ";
        cin>>id;
        agregarProductoABodega(categoria,subCategoria,precio,id,bodega,listaCategoria);
        cout<<"Producto agregado con exito."<<endl;
        guardarCambiosBodega(bodega);
    }
//Permite agregar los productos que quiere comprar el cliente, para hacer la boleta al final.
    void compraCliente(vector<string> &listaCategoria,Lista *bodega,Cliente cliente,queue<Cliente>& colaPreferencial, queue<Cliente>& colaNormal){
        cout<<"Atendiendo al cliente con el numero "<<cliente.getNumero()<<endl;
        cout<<"¿Que productos va a pasar por caja el cliente?"<<endl;
        cout<<"---------------------------------"<<endl;
        int categoria;
        string opcion;
        int cantidadProductos=0;
        double precioTotal=0; 
        Lista *listaProductos=new Lista();

        do{
            cout<<"Categoria: "<<endl;
            for(int i=0;i<listaCategoria.size();i++){
                cout<<i+1<<"."<<listaCategoria[i]<<endl;
            }

            do{
                cout<<"\nSeleccione un numero: ";
                cin>>categoria;
            }while(categoria<1||categoria>listaCategoria.size());

            vector<string> subCategoriasImpresas;
            Lista::Nodo *temp =bodega->cabeza;
            int i=1;
            cout<<"---------------------------------"<<"\nSubCategoria: "<<endl;
            while(temp!=nullptr){
                
                if(temp->producto.getCategoria()==listaCategoria[categoria-1]){
                    bool seImprimio=false;
                    for (const string &subcategoria : subCategoriasImpresas) {
                    if (temp->producto.getSubcategoria() == subcategoria) {
                        seImprimio = true;
                        break;
                    }
                }
                if (!seImprimio) {

                    cout << i <<"."<< temp->producto.getSubcategoria() << endl;
                    subCategoriasImpresas.push_back(temp->producto.getSubcategoria());
                    i++;
                }
                
                }temp=temp->siguiente;
            }

            int subCategoria;
            do{
                cout<<"\nSeleccione un numero: ";
                cin>>subCategoria;
                 cout<<"---------------------------------"<<endl;}
                
            while(subCategoria<1||subCategoria>subCategoriasImpresas.size()); 
            temp =bodega->cabeza;
           
            while(temp!=nullptr){
                if(temp->producto.getSubcategoria()==subCategoriasImpresas[subCategoria-1]){
                    cout<<"Categoria: "<<temp->producto.getCategoria()<<" SubCategoria: "<<temp->producto.getSubcategoria()<<" Precio: $"<<temp->producto.getPrecio()<<" ID: " <<temp->producto.getId()<<endl;
                }
                temp=temp->siguiente;
            }
            int id;
            bool existeID=false;
            do{
                cout<<"\nDigite el ID del producto a comprar: ";
                cin>>id;
                temp =bodega->cabeza;
                while(temp!=nullptr){
                    if(temp->producto.getId()==id){
                        existeID=true;                 
                        break;
                    }
                    temp=temp->siguiente;
                    }if (existeID==false){
                        cout<<"No existe el producto."<<endl;
                    }
                }while(existeID==false);

            precioTotal+=temp->producto.getPrecio();
            cantidadProductos++;
            subCategoriasImpresas.clear();
            listaProductos->agregar(temp->producto);
            bodega->eliminar(id);
            
           do{
            cout<<"\n¿Desea agregar otro producto?(S/N):  ";
            cin>>opcion;
            cin.ignore();
           }while(opcion!=("N")&&opcion!="S");
  
        }while(opcion!="N");
        listaProductos->imprimirBoleta();
        cout<<"---------------------------------"<<endl;
        cout<<"Cantidad de Productos: "<<cantidadProductos<<"\nPrecio Total: "<<precioTotal<<endl;
        if(cliente.getTipoCliente()==("Normal")){
            colaNormal.pop();
        }else{
            colaPreferencial.pop();       
         }

        guardarCambiosBodega(bodega);
    }   
};




int main(int argc, char const *argv[])
{

//Menu
vector<string> categorias;
Lista *bodega=new Lista();
Logica *logic=new Logica();
queue<Cliente> colaNormal;
queue<Cliente> colaPreferencial;

int numeroAtencion=logic->creacionObjetosInicio(bodega,categorias,colaPreferencial,colaNormal);

int opcion=-1;

do{
cout<<"---------------Menu---------------"<<endl;
cout<<"1.Dar numero a cliente. "<<endl;
cout<<"2.Agregar producto a bodega."<<endl;
cout<<"3.Llamar a proximo cliente en la fila."<<endl;;
cout<<"0.Salir."<<endl;;
cout<<"Seleccione una opcion: ";
cin>> opcion;

cout<<"---------------------------------"<<endl;

switch(opcion){
    case 1:
        numeroAtencion++;
        logic->agregarClienteNuevo(colaPreferencial,colaNormal,numeroAtencion);
        cout<<"---------------------------------"<<endl;
        break;
    case 2:
        logic->agregarBodegaMenu(bodega, categorias);
        cout<<"---------------------------------"<<endl;
        
        break;
    case 3:
        Cliente cliente=logic->quienSigue(colaNormal,colaPreferencial);
        if(cliente.getNumero()!=0){
        logic->compraCliente(categorias,bodega,cliente,colaPreferencial,colaNormal);}
        cout<<"---------------------------------"<<endl;
        break;
   
   
}
}while(opcion!=0);
   logic->guardarCambiosClientes(colaPreferencial,colaNormal);
return 0; 
}





