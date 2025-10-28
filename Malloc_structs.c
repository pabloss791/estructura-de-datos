#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct pollito
{
    char *nombre;
    int ID;
    float peso;
    
}pollito;
int main()
{
/* Ejercicios Malloc / Free
//Ahora con estructuras 


/* Crea una estructura de tipo "Pollito" que tenga un nombre, ID, y peso.*/



/* 4, crea un pollito con ID 1*/

pollito*pollito1=(pollito*)malloc(sizeof(pollito));
    pollito1->ID=1;
    pollito1->peso=9.3;
    pollito1->nombre=(char*)malloc(20*sizeof(char));
    strcpy(pollito1->nombre,"pollo 1");



/* 4.1, crea 3 pollitos mas! no pierdas la referencia a ellos,
ponles el ID que queiras */

pollito*pollito2=(pollito*)malloc(sizeof(pollito));
    pollito2->ID=2;
    pollito2->peso=7.3;
    pollito2->nombre=(char*)malloc(20*sizeof(char));
    strcpy(pollito2->nombre,"pollo 2");

pollito*pollito3=(pollito*)malloc(sizeof(pollito));
    pollito3->ID=3;
    pollito3->peso=4.3;
    pollito3->nombre=(char*)malloc(20*sizeof(char));
    strcpy(pollito3->nombre,"pollo 3");

pollito*pollito4=(pollito*)malloc(sizeof(pollito));
    pollito4->ID=4;
    pollito4->peso=6.7;
    pollito4->nombre=(char*)malloc(20*sizeof(char));
    strcpy(pollito4->nombre,"pollo 4");




/* 4.2 crea un arreglo de para guardar estos 4 pollitos existentes ...


De que tipo de dato sera? ... tipo apuntador a pollito

*/
pollito**arregloPollitos=(pollito**)malloc(4*sizeof(pollito));
arregloPollitos[0]=pollito1;
arregloPollitos[1]=pollito2;
arregloPollitos[2]=pollito3;
arregloPollitos[3]=pollito4;

/* 4.3 imprime los pollitos usando el arreglo */

for (int i=0;i<4;i++){
    printf("Pollito %d",i+1);
    printf("Nombre %s \n",arregloPollitos[i]->nombre);
    printf("ID %d \n", arregloPollitos[i]->ID);
    printf("Peso %f \n ",arregloPollitos[i]->peso);
    printf("------\n");


}

/*ya no quiero los pollitos, liberalos en la granja (TODOS)*/

for (int i=0;i<4;i++){
    free(arregloPollitos[i]->nombre);
    free(arregloPollitos[i]);

}
return 0;
}
