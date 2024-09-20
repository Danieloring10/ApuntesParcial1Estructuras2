#include <stdio.h>
#include <malloc.h>

int **CreeColumnas( int nc, int nr){
    int r; // Variable de apollo
    int **P = NULL; // Puntero que se regresara
    //Se crea toda la memoria del puntero en base a los renglones
    P = (int **)malloc(sizeof(int*)*nr); 
    if(P != NULL){ // Si se creo correctamente
        for(r = 0; r < nr; r++){ // Por cada renglon
            //Crea el espacio de cada lugar de la columna
            *(P+r) = (int *)malloc(sizeof(int)*nc); 
            if(*(P+r) == NULL) //Si no jala termina
                break;
        }
        if(r < nr){ //Checa si no termino el bucle
                while(r>=0){ // Entonces itera desde que fallo
                    free(*(P+r)); //Libera el espacio
                    *(P+r) == NULL; 
                    r--;
                }
            }
        if(r<0){ // Si no funciono
            free(P); //Libera y anula
            P = NULL;
        }
    }
    return P;
}
void LlenarArr(int **P, int r, int c){
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
        scanf("%d",*(P+i)+j);
        }
    }
}
void ImprimirArr(int **P, int r, int c){
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
        printf("%d ",*(*(P+i)+j));
        }
        printf("\n");
    }
}
int main(){
    int **Arr;
    int nc = 4;
    int nr = 4;
    Arr = CreeColumnas(nc,nr);
    printf("Hola");
    LlenarArr(Arr,nr,nc);
    ImprimirArr(Arr,nr,nc);
}