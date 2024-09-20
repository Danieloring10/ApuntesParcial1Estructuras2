#include <stdio.h>
#include <math.h>
#include <stdlib.h>
//Capture n de terminos
//Crear arreglo dinamico de n terminos
//Capturar el polinomio
//Evaluar el polinomio según un valor x
//Liberar memoria al finalizar

//Tiempo de realizarlo 1 hr
typedef struct{
    int Coeficiente;
    int Exponente;
}Termino;

Termino *CrearArreglo(int n){
    Termino *T = NULL;
    T = (Termino *)malloc(sizeof(Termino)*n);
    return T;
}
void CapturaPolinomio(Termino *T, int n){
    for(int i = 0; i < n; i++){
        printf("Ingresa el coeficiente del termino %d: ", i+1);
        scanf("%d",&(T+i)->Coeficiente);
        printf("Ingresa el exponente del termino %d: ", i+1);
        scanf("%d",&(T+i)->Exponente);
    }
}

float EvaluaPolinomio(Termino *T, int n){
    float res = 0, x;
    printf("Ingresa el valor de x: ");
    scanf("%f", &x);
    for(int i = 0; i < n; i++){
        res += ((float)(T+i)->Coeficiente)*(float)pow(x,(T+i)->Exponente);
    }
    return res;
}
void LiberaArreglo(Termino **T){
    free(*T);
    *T = NULL;
}
int main(){
    Termino *T = NULL;
    int n;
    float res;
    printf("Ingresa la cantidad de terminos del polinomio: ");
    scanf("%d", &n);
    T = CrearArreglo(n);
    CapturaPolinomio(T,n);
    res = EvaluaPolinomio(T,n);
    printf("%.2f", res);
    LiberaArreglo(&T);
    if(T == NULL){
        printf("\nArreglo liberado con exito");
    }
}