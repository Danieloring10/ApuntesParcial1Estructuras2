#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PM 50
//Arreglo de Datos genericos

typedef struct 
{
    void *P;
    int Tipo;
    int nObj;
    int MaxObj;
}TArregloGenerico;

typedef struct 
{
    int clave;
    char *nombre;

}TAlumno;

TArregloGenerico GenerarArreglo(){
    TArregloGenerico AG;
    printf("Escribe que tipo de variable sera el arreglo:\n");
    printf("1)INT 2)FLOAT 3)CHAR\n");
    scanf("%d", &AG.Tipo);
    printf("Escribe el tamaño del arreglo: ");
    scanf("%d", &AG.MaxObj);
    switch (AG.Tipo)
    {
    case 1:
        AG.P = malloc(sizeof(int)*AG.MaxObj);
        break;
    case 2:
        AG.P = malloc(sizeof(float)*AG.MaxObj);
        break;
    case 3:
        AG.P = malloc(AG.MaxObj);
        break;
    case 4:
        AG.P = malloc(sizeof(char *)*AG.MaxObj);
        break;
    case 5:
        AG.P = malloc(sizeof(TAlumno)*AG.MaxObj);
        break;
    default:
        printf("Tipo no valido");
        break;
    }
    AG.nObj = 0;
    return AG;
}
void AgregarDato(TArregloGenerico *AG){
    switch ((*AG).Tipo)
    {
    case 1:
        scanf("%d", (int *)(*AG).P+(*AG).nObj);
        (*AG).nObj += 1;
        break;
    case 2:
        scanf("%f", (float *)(*AG).P+(*AG).nObj);
        (*AG).nObj += 1;
        break;
    case 3:
        getchar();
        scanf("%c", (char *)(*AG).P+(*AG).nObj);
        (*AG).nObj += 1;
        break;
    case 4:
        //getchar();
        scanf(" %s", ((char**)AG->P+AG->nObj));
        (*AG).nObj += 1;
    case 5:
        scanf("%d", &((TAlumno*)AG->P+AG->nObj)->clave);
        ((TAlumno*)AG->P+AG->nObj)->nombre = malloc(PM);
        scanf(" %s", ((TAlumno *)AG->P+AG->nObj)->nombre);
        (*AG).nObj += 1;
        break;
    default:
        break;
    }
}
int BuscarDato(TArregloGenerico AG){
    printf("Escribe el Objeto a buscar: ");
    int ObjI;
    float ObjF;
    char ObjC;
    char ObjS[PM];
    switch (AG.Tipo)
        {
        case 1:
            scanf("%d", &ObjI);
            break;
        case 2:
            scanf("%f", &ObjF);
            break;
        case 3:
            getchar();
            scanf(" %c", &ObjC);
            break;
        case 4:
            getchar();
            scanf(" %s", ObjS);
        case 5:
            printf("Clave del Alumno: ");
            scanf("%d", &ObjI);
            break;
        }
    for(int i = 0; i < AG.nObj; i++){
        switch (AG.Tipo)
        {
        case 1:
            if(*((int *)AG.P+i) == ObjI){
                return i;
            }
            break;
        case 2:
            if(*((float *)AG.P+i) == ObjF){
                return i;
            }
            break;
        case 3:
            if(*((char *)AG.P+i) == ObjC){
                return i;
            }
            break;
        case 4:
            if(strcmp(ObjS,((char **)AG.P+i)) == 0){
                return i;
            }
            break;
        case 5:
            if(((TAlumno *)AG.P+i)->clave,ObjI){
                return i;
            }
            break;
        }
    }
    return -1;
}
void ImprimeArr(TArregloGenerico AG){
    for(int i = 0; i < AG.nObj; i++){
        switch (AG.Tipo)
        {
        case 1:
            printf("%d - %d\n",i, *((int *)AG.P+i));
            break;
        case 2:
            printf("%d - %.2f\n",i, *((float *)AG.P+i));
            break;
        case 3:
            printf("%d - %c\n",i, *((char *)AG.P+i));
            break;
        case 4:
            printf("%d - %s\n",i, (((char **)AG.P)+i));
            break;
        case 5:
            printf("%d -\t%d\n\t%s\n",i, ((TAlumno *)AG.P+i)->clave,((TAlumno *)AG.P+i)->nombre);
            break;
        }
    }
}
int main(){
    TArregloGenerico AG;
    AG = GenerarArreglo();  
    int Acc, index;
    do
    {
        printf("Imprime la accion a realizar:\n");
        printf("1) Agregar Dato 2) Buscar Dato 3) Imprimir Arreglo\n");
        scanf("%d", &Acc);
        switch (Acc)
        {
        case -1:
            break;
        case 1:
            AgregarDato(&AG);
            break;
        case 2:
            index = BuscarDato(AG);
            if(index == -1){
                printf("El objeto no fue encontrado\n");
            }
            else{
                printf("Index en la lista = %d\n",index);
            }
            break;
        case 3:
            ImprimeArr(AG);
            break;
        default:
            printf("Input no valido\n");
            break;
        }
        printf("\n");
    } while (Acc != -1);
    
    
}