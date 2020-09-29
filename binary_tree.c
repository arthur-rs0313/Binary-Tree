#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
  int valor;
  struct nodo *izq;
  struct nodo *der;
}Nodo;

typedef Nodo Arbol;

Nodo *CrearNodo(int valor){
  Nodo *nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
  nuevoNodo->valor = valor;
  nuevoNodo->izq=nuevoNodo->der=NULL;
  return nuevoNodo;
}

void DestruirNodo(Nodo *nodo){
  nodo->izq = nodo->der=NULL;
  free(nodo);
}

void Insertar(Nodo **arbol, int valor){
  if(*arbol==NULL){
    Nodo *nuevoNodo=CrearNodo(valor);
    *arbol=nuevoNodo;
  }else{
    int valorRaiz = (*arbol)->valor;
    if(valorRaiz > valor){
      Insertar(&(*arbol)->izq,valor); 
    }else{
      Insertar(&(*arbol)->der,valor); 
    }
  }
}

//Comprobar existencia

int Existe(Nodo *arbol, int valor){
  if(arbol == NULL){
    return 0;
  }
  else if(arbol->valor == valor){
    return 1;
  }else if (valor < arbol->valor){
    return Existe(arbol->izq,valor);
  }else{
    return Existe(arbol->der,valor);
  }
}
int main(){
    Nodo *arbol = CrearNodo(10);
        

  return 0;
}
