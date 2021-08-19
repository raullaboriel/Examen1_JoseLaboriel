#include<iostream>
using namespace std;

struct Nodo{
  string dato;
  Nodo *siguiente;
};

//Esta funciona agrega un paquete al almacen
void agregarPila(Nodo *&, string);
//Esta funciona saca un paquete al almacen
void sacarPila(Nodo *&, string &);
//Esta funcion cuenta los paquetes disponibles en el almacen
int contarDisponibles(Nodo *);
//Esta funcion cuenta los paquetes despachados en el almacen
int contarDespachados(int);

Nodo *pila;
int despachados;

int main(){
  int opcion;
  string codigo;

  do{
    cout<<"1. Agregar paquete.\t\tPaquetes disponibles: "<<contarDisponibles(pila)<<"\n";
    cout<<"2. Sacar paquete.  \t\tPaquetes despachados: "<<contarDespachados(despachados)<<"\n";
    cout<<"3. Salir del programa.\n";
    cout<<"Digite una opcion: "; cin>>opcion;

    switch(opcion){
      case 1:
        cout<<"Ingrese el codigo del paquete: "; cin>>codigo;
        if(codigo.length() == 8){
          agregarPila(pila, codigo);
        }else{
          cout<<"\tATENCION: Codigo de paquete invalido (=8).\n\n";
        }
      break;

      case 2:
        if(pila != NULL){
          sacarPila(pila, codigo);
          cout<<"\tPaquete "<<codigo<<" sacado correctamente\n"<<endl;
          despachados++;
        }else{
          cout<<"\tATENCION: El almacen esta vacio.\n\n";
        }
      break;

      case 3:
       cout<<"MENSAJE: Fin del programa\n";
      break;

      default:
        cout<<"\tERROR: Opcion seleccionada es invalida.\n\n";
      break;
    }
  }while(opcion != 3);
}

//Esta funciona agrega un paquete al almacen
void agregarPila(Nodo *&pila, string n){
  Nodo *nuevo_nodo = new Nodo();
  nuevo_nodo->dato=n;
  nuevo_nodo->siguiente = pila;
  pila=nuevo_nodo;
  cout<<"\tPaquete "<<n<<" agregado correctamente\n"<<endl;
}

//Esta funciona saca un paquete al almacen
void sacarPila(Nodo *&pila,string &n){
  Nodo *aux=pila;
  n=aux->dato;
  pila=aux->siguiente;
  delete aux;
}

//Esta funcion cuenta los paquetes disponibles en el almacen
int contarDisponibles(Nodo *pila){
  int restantes = 0;
  Nodo *aux = pila;

  while(aux != NULL){
    restantes++;
    aux = aux -> siguiente;
  }

  return restantes;
}

//Esta funcion cuenta los paquetes despachados en el almacen
int contarDespachados(int n){
  return n;
}