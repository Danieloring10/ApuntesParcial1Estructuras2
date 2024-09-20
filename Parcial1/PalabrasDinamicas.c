#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MaxLenght 50

char **CapPalabras(int numP){
    int i;
    char **P;
    char *NP;
    P = (char **)malloc(sizeof(char *)*numP);
    for(i = 0; i < numP; i++){
        NP = (char *)malloc(MaxLenght);
        fgets(NP,sizeof(NP),stdin);
        *(P+i) = (char *)malloc(strlen(NP)+1);
        strcpy(*(P+i),NP);
        free(NP);
        NP = NULL;
    }
    return P;
}
void ImpPal(char**P, int numP){
    for(int i = 0; i<numP; i++){
        printf("%s",*(P+i));
    }
}
int main(){
    int numP;
    char **Palabras;
    scanf("%d", &numP);
    Palabras = CapPalabras(numP);
    ImpPal(Palabras,numP);
}