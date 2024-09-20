#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MLNombre 50
#define MLCorto 10
#define MLOracion 100
#define MLLista 5
#define MLPacientes 20
//Jueves 21 - 23
//Sabado 22- 02
//Domingo 16-17

//Total 7 horas

//EL ARCHIVO DE BASE DE DATOS ES INFORMACIÓN EXTRA PARA PROBAR EL PROGRAMA SIN INGRESAR LA INFORMACIÓN MANUALMENTTE
//SOLO COPIAR Y PEGAR AL INICIO

typedef struct 
{
    char ciudad[MLCorto];
    char calle[MLNombre];
    int Numero;
}TDireccion;

typedef struct 
{
    char Nombre[MLNombre];
    TDireccion Direccion;
    int Telefono;
    int UltimaFecha; //Formato DDMMAA
    int Privado;
    char Alergias[MLLista][MLOracion];
    char Observaciones[MLLista][MLOracion];
}TPaciente;

void BorrarSalto(char Arr[]){
    *(Arr+strlen(Arr)- 1)  == '\0';
}
void IniciaString(char *Arr, int n){
    for(int i = 0; i < n; i++){
        *(Arr+i) = '\0';
    }
}
void RegistrarPaciente(TPaciente *P, int *PaRe){
    TPaciente NuevoPaciente;

    //Inicia todos los arreglos;
    IniciaString(*NuevoPaciente.Alergias+(*PaRe), *PaRe);
    IniciaString(*NuevoPaciente.Observaciones+(*PaRe), *PaRe);
    getchar();
    printf("\nIngrese el nombre del paciente: ");
    fgets(NuevoPaciente.Nombre, 50, stdin);
    printf("Ingrese la ciudad de residencia del paciente: ");
    fgets(NuevoPaciente.Direccion.ciudad, 50, stdin);
    BorrarSalto(NuevoPaciente.Direccion.ciudad);
    printf("Ingrese la calle del paciente: ");
    fgets(NuevoPaciente.Direccion.calle, 50, stdin);
    BorrarSalto(NuevoPaciente.Direccion.calle);
    printf("Ingrese el numero de la casa del paciente: ");
    scanf("%d", &NuevoPaciente.Direccion.Numero);
    printf("Ingrese el teléfono del paciente: ");
    scanf("%d", &NuevoPaciente.Telefono);
    printf("Ingrese la fecha de hoy: ");
    scanf("%d", &NuevoPaciente.UltimaFecha);
    printf("Ingrese '1' si el paciente tiene seguro social y '0' si no: ");
    scanf("%d", &NuevoPaciente.Privado);

    fgetchar(); // Para eliminar el salto de linea del Input anterior :)
    //Obtener n Alergias
    printf("\nIngrese las alergias del paciente, al terminar solo dar 'Enter': \n");
    int n = 0;
    while(1){
        char Alergia[MLOracion];
        fgets(Alergia, 50, stdin);
        if(*Alergia == '\n'){
            break;
        }
        strcpy(*(NuevoPaciente.Alergias+n),Alergia);
        n++;
    }
    //Obtener n Observaciones
    printf("\nIngrese las observaciones del paciente, al terminar solo dar 'Enter': \n");
    int x = 0;
    while(1){
        char Observacion[MLOracion];
        fgets(Observacion,100,stdin);
        if(*Observacion == '\n'){
            break;
        }
        strcpy(*(NuevoPaciente.Observaciones+x),Observacion);
        x++;
    }
    *(P+(*PaRe)) = NuevoPaciente;
    (*PaRe)++;
}

void ImprimirPaciente(TPaciente *P, int index){
    TPaciente NP = *(P+index);
    printf("\nNomrbe: %s\n", NP.Nombre);
    printf("Direccion: %s %s %d\n", NP.Direccion.ciudad,NP.Direccion.calle,NP.Direccion.Numero);
    printf("Telefono: %i\n",NP.Telefono);
    int Fecha = (*(P+index)).UltimaFecha;
    printf("Su ultima fecha registrada fue el: %d/%d/%d\n",Fecha/10000,(Fecha%10000)/100,Fecha%100);
    printf("Tiene Seguro Social: %i\n", NP.Privado);
    printf("\nAlergias:\n");
    for(int i = 0; i < 20; i++){
        if(**(NP.Alergias+i) == '\0')
            break;
        printf("%s", *(NP.Alergias+i));
    }
    printf("\nObservaciones:\n");
    for(int i = 0; i < 20; i++){
        if(**(NP.Observaciones+i) == '\0')
            break;
        printf("%s", *(NP.Observaciones+i));
    }
    printf("\n");

}

/*
    ALGORITMO DE BUSQUEDA DE PACIENTE   
    Obtener el nombre a buscar (Nom)
    Iterar por cada paciente en la base de datos
    Buscar el Nombre
    Por cada letra en Nom comparalo por cada nombre en la base de Datos <- Ineficiente pero buen 
    Un contador llevara el registro de que tan parecido es el nombre
    Si las letras son iguales y estan en la misma posición valen 3
    Si son iguales y son consecutivas pero estan en una diferente posicion valen 2
    Si es igual pero no hay adyacentes valen 1 
    Regresa en forma de listado los nombres con valores mayores a 0
    Estos nombres saldran en minuscula con las coincidencias en mayuscula
    El usuario ingresa el número de la lista con el nombre correspondiente o 0 si no se encuentra
    La función regresa el index del paciente dentro de la base de datos
*/

typedef struct 
{
    int Valor;
    char nombre[MLNombre];
    int index;
}MostrarPaciente;

void InsertionSort(MostrarPaciente arr[], int n) {
    for (int i = 1; i < n; i++) {
        MostrarPaciente key = *(arr+i);  
        int j = i - 1;
        while (j >= 0 && (*(arr+j)).Valor > key.Valor) {
            *(arr+j+1) = *(arr+j);
            j = j - 1;
        }
        *(arr+j+1) = key;
    }
}
int BuscarPaciente(TPaciente *P, int PaC){
    char Nombre[MLNombre];
    MostrarPaciente MP[MLPacientes];
    if(PaC == 0){
        printf("No hay pacientes registrados");
        return;
    }
    printf("Ingrese el nombre del paciente: ");
    getchar();
    fgets(Nombre,MLNombre,stdin);
    
    for(int i = 0; i < PaC; i++){
        TPaciente p = *(P+i);
        char *NomAct = &p.Nombre;
        int BuscChar = 0;
        (*(MP+i)).index = i; 
        for(int j = 0; j < strlen(NomAct); j++){
            *(NomAct+j) = tolower(*(NomAct+j));
            *(Nombre+BuscChar) = tolower(*(Nombre+BuscChar));
            if(*(NomAct+j) == *(Nombre+BuscChar) && BuscChar == j){
                (*(MP+i)).Valor+=3;
                BuscChar++;
                *((MP+i)->nombre+j) = toupper(*(NomAct+j));
                continue;
            }
            if(*(NomAct+j) == *(Nombre+BuscChar) && *(NomAct+i+1) == *(Nombre+BuscChar+1)){
                (*(MP+i)).Valor+=2;
                BuscChar++;
                *((MP+i)->nombre+j) = toupper(*(NomAct+j));
                continue;
            }
            if(*(NomAct+j) == *(Nombre+BuscChar)){
                (*(MP+i)).Valor+=1;
                BuscChar++;
                *((MP+i)->nombre+j) = toupper(*(NomAct+j));
                continue;
            }
            *((MP+i)->nombre+j) = *(NomAct+j);
        }
    }
    InsertionSort(MP,PaC);
    printf("Ingrese el numero que corresponda al paciente:\n");
    int PCorrecto;
    for(int i = PaC-1; i >= 0; i--){
        if((float)(*(MP+i)).Valor < ((float)(*(MP+PaC-1)).Valor)/50)
            break;
        printf("%d.- %s",PaC-i,(*(MP+i)).nombre);
    }
    scanf("%d", &PCorrecto);
    return (*(MP+PaC-PCorrecto)).index;
}
void ImpFecha(TPaciente *P, int index){
    int Fecha = (*(P+index)).UltimaFecha;
    printf("\nSu ultima fecha registrada fue el: %d/%d/%d\n",Fecha/10000,(Fecha%10000)/100,Fecha%100);
}

void MostrarPAl(TPaciente *P, int PaC){
    for(int i = 0; i < PaC; i++){
         if(**((P+i)->Alergias) != '\0'){
            printf("%s", (P+i)->Nombre);
         }
    }
    printf("\n");
}
void ImpTodos(TPaciente *P, int PaC){
    for(int i = 0; i < PaC; i++){
        ImprimirPaciente(P,i);
    }
}
void Menu(TPaciente *P, int *PaRe){
    int input = 1;
    while(input != 0){
        printf("Ingrese la accion requerida:\n1)Registrar Nuevo Paciente\n2)Buscar Info de paciente\n3)Mostrar ultima visita de paciente\n4)Mostar pacientes con alergias\n5)Mostrar todos los pacientes\n");
        scanf("%d", &input);
        switch (input)
        {
        case 0:
            break;
        case 1:
            RegistrarPaciente(P,PaRe);
            break;
        case 2:
            ImprimirPaciente(P,BuscarPaciente(P, *PaRe));
            break;
        case 3:
            ImpFecha(P,BuscarPaciente(P,*PaRe));
            break;
        case 4:
            MostrarPAl(P,*PaRe);
            break;
        case 5:
            ImpTodos(P,*PaRe);
            break;
        default:
            printf("El dato ingresado no es valido\n");
            break;
        }
    }
}
int main(){
    TPaciente *Pa = NULL;
    int numeroPacientes = 100;
    int PacientesRegistrados = 0;
    Pa = (TPaciente *)malloc(sizeof(TPaciente)*numeroPacientes);


    Menu(Pa, &PacientesRegistrados);
}