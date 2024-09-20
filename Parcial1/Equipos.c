#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ML 100 
typedef struct 
{
   char *Nombre;
   int Victorias;
   int Derrotas;
   int tipo;
   void *InfExtra;
}TEquipo;
typedef struct
{
    int BolasBatExito;
    int Carreras;
    int Errores;
    int JuegosExtra;
}TBaseball;
typedef struct
{
   int Empates;
   int Tantos;
   int GolpesCampo;
   int ContraAtaques;
   int YardasGanads;
   int YardasCedidas;
}TFutball;

TEquipo *GenerarArreglo(int *n){
    TEquipo *E;
    printf("Ingresa el numero de equipos en la liga: ");
    scanf("%d", n);
    E = (TEquipo *)malloc(sizeof(TEquipo)*(*n));
    return E;
}
void IngresarDatos(TEquipo *E, int *nE){
    int nEquipos = *nE;
    char *Nombre = NULL;
    Nombre = (char*)malloc(ML);
    //Nombre 
    printf("Ingresa el Nombre del equipo + La ciudad: ");
    getchar();
    fgets(Nombre,ML,stdin);
    printf("A");
    (E+nEquipos)->Nombre = (char*)malloc(strlen(Nombre)+1);
    strcpy((E+nEquipos)->Nombre,Nombre);
    
    printf("Ingresa el numero de victorias: ");
    scanf("%d", &(E+nEquipos)->Victorias);
    printf("Ingresa el numero de Derrotas: ");
    scanf("%d", &(E+nEquipos)->Derrotas);

    printf("Ingresa el tipo de Equipo: 1)Baseball 2)Futbol");
    scanf("%d", &(E+nEquipos)->tipo);
    if((E+nEquipos)->tipo == 1){
        //Baseball

        (E+nEquipos)->InfExtra = (TBaseball *)malloc(sizeof(TBaseball));
        TBaseball *EB = (TBaseball *)(E+nEquipos)->InfExtra;
        printf("Ingresa las bolas bateadas con exito: ");
        scanf("%d",&EB->BolasBatExito);
        printf("Ingresa las carreras: ");
        scanf("%d",&EB->Carreras);
        printf("Ingresa los errores: ");
        scanf("%d",&EB->Errores);
        printf("Ingresa los juegos extra: ");
        scanf("%d",&EB->JuegosExtra);
    }
    else{
        //Futball

        (E+nEquipos)->InfExtra = (TFutball *)malloc(sizeof(TFutball));
        TFutball *EF = (TFutball *)(E+nEquipos)->InfExtra;
        printf("Ingresa numero de empates: ");
        scanf("%d",&EF->Empates);
        printf("Ingresa numero de tantos: ");
        scanf("%d",&EF->Tantos);
        printf("Ingresa numero de golpes de campo: ");
        scanf("%d",&EF->GolpesCampo);
        printf("Ingresa numero de contrataques: ");
        scanf("%d",&EF->ContraAtaques);
        printf("Ingresa total de yardas ganadas: ");
        scanf("%d",&EF->YardasGanads);
        printf("Ingresa total de yardas cedidas: ");
        scanf("%d",&EF->YardasCedidas);
    }
    (*nE)++;
}
void ImprimirDatos(TEquipo *E, int nEquipos){
    for(int i = 0; i <  nEquipos; i++){
        printf("\n\n\t----------%s",(E+i)->Nombre);
        printf("Victorias: %d\n",(E+i)->Victorias);
        printf("Derrotas: %d\n",(E+i)->Derrotas);
        if((E+i)->tipo == 1){
            TBaseball * EB = (TBaseball *)(E+i)->InfExtra;
            printf("\n\t----- Baseball -----\n");
            printf("Bolas bateadas con exito: %d\n",EB->BolasBatExito);
            printf("Numero de carreras: %d\n",EB->Carreras);
            printf("Numero de errores: %d\n",EB->Errores);
            printf("Numero de juegos extra: %d\n",EB->JuegosExtra);
        }
        else{
            TFutball * EF = (TFutball *)(E+i)->InfExtra;
            printf("\n\t----- Futball -----\n");
            printf("Numero de empates: %d\n",EF->Empates);
            printf("Numero de tantos: %d\n",EF->Tantos);
            printf("Numero de golpes de campo: %d\n",EF->GolpesCampo);
            printf("Numero de contraataques: %d\n",EF->ContraAtaques);
            printf("Total de yardas ganadas: %d\n",EF->YardasGanads);
            printf("Total de yardas cedidas: %d\n",EF->YardasCedidas);
        }
    }
}
int main(){
    TEquipo *E;
    int n, nEquipos = 0, input;
    E = GenerarArreglo(&n);
    do{
        printf("Ingrese la accion a realizar: 1) Agregar equipo 2) Imprimir lista 3) Salir\n");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            IngresarDatos(E,&nEquipos);
            break;
        case 2:
            ImprimirDatos(E,nEquipos);
        case 3:
            break;
        default:
            break;
        }
    }while(input !=  3);
    
}
