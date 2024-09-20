#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int clave;
    char Nombre[50];
}TAlumno;
void*CrearVariable(int *tipo){
    void * var;
    printf("Que tipo de variable?\n");
    printf("1.Int 2.Float 3.Char 4.Cadena 5.TAlumno\n");
    scanf("%d", tipo);
    switch (*tipo)
    {
    case 1:
        var = malloc(sizeof(int));
        break;
    case 2:
        var = malloc(sizeof(float));
        break;
    case 3:
        var = malloc(sizeof(char));
        break;
    case 4:
        var = malloc(sizeof(char *));
        break;
    case 5:
        var = malloc(sizeof(TAlumno));
        break;
    default:
        break;
    }
    return var;
}
void LeerVariable(void *var, int tipo){
    printf("Ingrese el valor: ");
    switch (tipo)
    {
    case 1:
        scanf("%d", (int*)var);
        break;
    case 2:
        scanf("%f", (float*)var);
        break;
    case 3:
        scanf(" %c", (char*)var);
        break;
    case 4:
        scanf(" %s", (char**)var);
        break;
    case 5:
        scanf("%d", &(((TAlumno*)var)->clave));
        scanf(" %s", (((TAlumno*)var)->Nombre));
        break;
    default:
        break;
    }
}
void ImprimirVariable(void *var, int tipo){
    switch (tipo)
    {
    case 1:
        printf("%d", *((int*)var));
        break;
    case 2:
        printf("%f", *((float*)var));
        break;
    case 3:
        printf("%c", *((char*)var));
        break;
    case 4:
        printf("%s", ((char**)var));
        break;
    case 5:
        printf("%d - %s", (((TAlumno*)var)->clave),(((TAlumno*)var)->Nombre));
        break;
    default:
        break;
    }
}
int main(){
    void * var;
    int tipo;
    var = CrearVariable(&tipo);
    LeerVariable(var,tipo);
    ImprimirVariable(var,tipo);
}
