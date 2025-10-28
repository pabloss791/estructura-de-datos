#include<stdio.h>
#include<stdlib.h>

int main(){

   int n=5;
    int*entero=malloc(sizeof(int));
    int*arr_int=(int*)malloc(n*sizeof(int));

    typedef struct 
    {
        float altura;
        char nombre[20];
        int edad; 
        char color[20];

    } minions;

    int*minion=malloc(sizeof(minions));

   int*puntero_dinamico;

   puntero_dinamico=(int*)malloc(sizeof(int));

    int filas1=3;

    int**matriz_dinamica;

    matriz_dinamica=(int**)malloc(filas1*sizeof(int*));

    int*new_entero=(int*)realloc(entero,2*sizeof(int));

    int filas=10;
    int columnas=12;

    int**matriz;

    matriz=(int**)malloc(filas*sizeof(int*));
    for(int i=0;i<filas;i++){
        *(matriz+i)=(int*)malloc(columnas*sizeof(int));
    }

    void asignarValor(int filas,int columnas, int**matriz, int valor){
        *(*(matriz+filas)+columas)=valor;
    }
    void imprimirMatriz(int**matriz, int filas, int columnas){
        for(int i=0; i<filas;i++){
            for(int j=0; j<columnas;j++){
                printf("%d",*(*matriz+i)+j);
            }
        }
    }

    free(entero);
    free(arr_int);
    free(minion);
    free(puntero_dinamico);
    free(matriz_dinamica);
    free(matriz);







    


}