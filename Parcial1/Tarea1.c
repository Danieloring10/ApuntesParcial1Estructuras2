#include <stdio.h>
void Leer(int a[]){
    for(int i = 0; i < 10; i++){
        scanf("%d", (a+i));
    }
}
float promedio(int a[]){
    float sum;
    for(int i = 0; i < 10; i++){
        sum += *(a+i);
    }
    return sum/10;
    
}
void Imprimir(int a[], float prom){
    for(int i = 0; i < 10; i++){
        printf("%d\n", *(a+i));
    }
    printf("El promedio es %.2f", prom);
}
int main(){
    int a[10];
    float prom;
    Leer(a);
    prom = promedio(a);
    Imprimir(a,prom);
}