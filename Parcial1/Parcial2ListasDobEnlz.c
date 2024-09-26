#include <stdio.h>
typedef struct nodD{
  int dato;
  struct nodD *sig, *ant;
}TNodoD;
typedef struct{
  TNodoD *inicio, *fin;
}TCab;

TNodoD *crear_nodoD(int info){
  TNodoD * aux;
  aux = (TNodoD *) malloc(sizeof(TNodoD));
  if(aux){
    aux->info = d;
    aux->sig = NULL;
    aux->ant = NULL;
  }
  return aux;
}
void insertar_inicio(TCab *cab, int info){
  TNodoD *aux = crear_nodoD(info);
  if(aux){
    aux->sig = cab->incio;
    if(cab->inicio){
      cab->inicio->ant = aux;
      cab->inicio = aux;
    }
  }
  else{
    cab->inicio = aux;
    cab->final = aux;
  }
}
int main(){
  
  }
