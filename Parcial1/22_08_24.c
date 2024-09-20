#include <stdio.h>
#include <stdlib.h>

int *crearArreglo(int n){
    int *pa = NULL;
    pa = (int *)malloc(n*sizeof(int));
    if(pa == NULL){
        printf("No se pudo :(");
        exit(1);
    }
    return pa;
}

void capturaArreglo(int n, int *Arr){
    for(int i = 0; i < n; i++){
        scanf("%d", Arr+i);
    }
}
int main(){
    int *a;
    int n = 10;
    a = crearArreglo(n);
    capturaArreglo(n,a);
}