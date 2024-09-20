#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxPlant 150
#define MaxPal 50

//EL OTRO ARCHIVO ES UNA BASE DE DATOS PARA PROBAR EL PROGRAMA
typedef struct 
{
    char *nombre;
    int diasriego;
    int existencia;
    char tipo; // o - Ornato   a - Arbol
    void *generico;
}TPlanta;

typedef struct 
{
    char frutal; // s/n
    float altura;
}TArbol;

typedef struct{
    char sol; //  s/n
    char *color;
}TOrnato;

void LeerPlanta(TPlanta *P, int *num){
    getchar();
    int n = *num;
    printf("Ingresa el nombre de la planta: ");
    char Nombre[MaxPal];
    fgets(Nombre,MaxPal,stdin);
    if (Nombre[strlen(Nombre) - 1] == '\n') {
        Nombre[strlen(Nombre) - 1] = '\0';
    }
    (P+n)->nombre = (char *)malloc(strlen(Nombre) + 1);
    strcpy((P+n)->nombre, Nombre);

    printf("Ingrese los días de riego: ");
    scanf("%d", &(P+n)->diasriego);
    printf("Ingrese la cantidad en existencia: ");
    scanf("%d", &(P+n)->existencia);
    printf("Ingrese el tipo (o - Ornato / a - Arbol): ");
    scanf(" %c", &(P+n)->tipo);
    if((P+n)->tipo == 'o'){
        getchar();
        TOrnato *Aux;
        (P+n)->generico = (TOrnato *)malloc(sizeof(TOrnato));
        Aux = (TOrnato *)(P+n)->generico;
        
    printf("Ingresa el color de la planta: ");
    char Color[MaxPal];
    fgets(Color,MaxPal,stdin);
    if (Color[strlen(Color) - 1] == '\n') {
        Color[strlen(Color) - 1] = '\0';
    }
    Aux->color = (char *)malloc(strlen(Color) + 1);
    strcpy(Aux->color, Color);
    printf("La planta es de sol? (s/n): ");
    scanf(" %c",&Aux->sol); 
    }
    else{
        TArbol *Aux;
        (P+n)->generico = (TArbol *)malloc(sizeof(TArbol));
        Aux = (TArbol *)(P+n)->generico;
        printf("El arbol es frutal? (s/n): ");
        scanf(" %c",&Aux->frutal);
        printf("Ingresa la altura maxima de crecimiento del arbol: ");
        scanf("%f", &Aux->altura);
    }
    (*num)++;
}
int ArbFrut(TPlanta *P, int n){
    int nArb;
    for(int i = 0; i < n; i++){
        if((P+i)->tipo == 'a')
            if(((TArbol *)(P+i)->generico)->frutal == 's')
                nArb += (P+i)->existencia;
    }
    return nArb;
}
char *FlorRojo(TPlanta *P, int n){
    int slen = 0, nFl = 0, cnt = 0;
    char *nombres =NULL;
    for(int i = 0; i < n; i++){
        if((P+i)->tipo == 'o'){
            if(strcmp(((TOrnato *)(P+i)->generico)->color,"rojo") == 0){
                slen += strlen((P+i)->nombre);
                nFl++;
            }
        }
    }
    nombres = (char *)malloc(slen+nFl);
    *nombres = '\0';
    for(int i = 0; i < n; i++){
        if((P+i)->tipo == 'o'){
            if(strcmp(((TOrnato *)(P+i)->generico)->color,"rojo") == 0){
                if(cnt != 0 && cnt < nFl){
                    strcat(nombres,",");
                }
                strcat(nombres, (P+i)->nombre);
                cnt++;
            }
        }
    }
    return nombres;
}

void ImprimirTodo(TPlanta *P, int n){
    for(int i = 0; i<n; i++){
        TPlanta Aux = *(P+i);
        printf("\n\n%s\n",Aux.nombre);
        printf("Días de riego: %d\n", Aux.diasriego);
        printf("Existencia: %d\n", Aux.existencia);
        printf("Tipo: %c\n", Aux.tipo);
        if(Aux.tipo == 'o'){
            printf("Necesita sol: %c\n", ((TOrnato *)Aux.generico)->sol);
            printf("Color: %s\n", ((TOrnato *)Aux.generico)->color);
        }
        else{
            printf("Es frutal: %c\n",((TArbol *)Aux.generico)->frutal);
            printf("Altura maxima: %.2f\n\n",((TArbol *)Aux.generico)->altura);
        }
    }
}
int main(){
    TPlanta *P;
    int n = 0, act = 0, nArbol;
    char *nombres;
    P = (TPlanta *)malloc(sizeof(TPlanta)*MaxPlant);
    do{
        printf("Ingresa la acción:\n");
        printf("0)Salir\n1)Agregar nuevo producto\n2)Imprimir numero de arboles frutales \n3)Imprimir flores decolor rojo\n4)Imprimir todas las plantas\n");
        scanf("%d", &act);
        switch (act)
        {
        case 1:
            LeerPlanta(P,&n);
            break;
        case 2:
            nArbol = ArbFrut(P,n);
            printf("\nHay %d arboles frutales\n\n", nArbol);
            break;
        case 3:
            nombres = FlorRojo(P,n);
            printf("\n%s\n\n",nombres);
            free(nombres);
            nombres = NULL;
            break;
        case 4:
            ImprimirTodo(P,n);
            break;
        default:
            break;
        }
    }while(act != 0);
}