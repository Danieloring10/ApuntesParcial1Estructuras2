#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    void **Arreglo;
    int *Tipo;
    int nObj;
    int nMax;
}TArregloG;

TArregloG CrearArreglo(){
    TArregloG AG; 
    printf("Ingresa el tamaño del arreglo: ");
    scanf("%d", &AG.nMax);
    AG.Arreglo = (void **)malloc(sizeof(void *)*AG.nMax);
    AG.Tipo = (int *)malloc(sizeof(int));
    AG.nObj = 0;
    return AG;
}
void AgregarDato(TArregloG *AG){
    printf("Ingresa el tipo de dato a agregar:\n");
    printf("1)INT 2)FLOAT 3)CHAR 4)STRING\n");
    scanf("%d", (AG->Tipo+AG->nObj));
    switch (*(AG->Tipo+AG->nObj))
    {
    case 1:
        *(AG->Arreglo+AG->nObj) = (int *)malloc(sizeof(int));
        scanf("%d",(int*)*(AG->Arreglo+AG->nObj));
        break;
    case 2:
        *(AG->Arreglo+AG->nObj) = (float *)malloc(sizeof(float));
        scanf("%f",(float*)*(AG->Arreglo+AG->nObj));
        break;  
    case 3:
        *(AG->Arreglo+AG->nObj) = (char *)malloc(sizeof(char));
        getchar();
        scanf("%c",(char*)*(AG->Arreglo+AG->nObj));
        break;
    case 4:
        *(AG->Arreglo+AG->nObj) = (char **)malloc(sizeof(char *));
        fgetchar();
        scanf("%s",*(char**)*(AG->Arreglo+AG->nObj));
        break;
    default:
        break;
    }
    (AG->nObj)++;
}
void ImprimirDato(TArregloG AG,int index){
    switch (*(AG.Tipo+index))
    {
    case 1:
        printf("%d\n", *(int *)*(AG.Arreglo+index));
        break;
    case 2:
        printf("%.2f\n", *(float *)*(AG.Arreglo+index));
        break;
    case 3:
        printf("%c\n", *(char *)*(AG.Arreglo+index));
        break;
    case 4:
        printf("%s\n", *(char **)*(AG.Arreglo+index));
        break;
    default:
        break;
    }
}
void ImprimirTodos(TArregloG AG){
    for(int i = 0; i < AG.nObj; i++){
        ImprimirDato(AG,i);
    }
}
int main(){
    TArregloG AG;
    AG = CrearArreglo();
    int input, index;
    do
    {
        printf("1)Agregar Dato 2)Imprimir Dato 3)Imprimir Todos");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            AgregarDato(&AG);
            break;
        case 2:
            scanf("%d", &index);
            ImprimirDato(AG,index);
            break;
        case 3:
            ImprimirTodos(AG);
            break;
        default:
            break;
        }
    } while (input != 4);
}