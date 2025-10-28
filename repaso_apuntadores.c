#include <stdio.h>

void aplicar_funcion(int *ptr,int n,int(*fx)(int)){
    for(int i=0;i<n;i++){
        int resultado=fx(*(ptr+i));
        printf("%d",resultado);
    }
}

void comparar_cubos(int*arr1eje2,float*arr2eje2,int n){
  (int*)arr1eje2;
  (float*)arr2eje2;



    for (int i;i<n;i++){
        if ( (*((float *)arr2eje2)) * (*((float *)arr2eje2)) * (*((float *)arr2eje2)) 
     == *((int *)arr1eje2) ) {
        printf("TRUE");
        }else{
            printf("FALSE");
        }
    }
}

void imprimir(int *s);
void incrementar(int*s);
void poner_ceros(int*s);

typedef void (*puntero_void)(int);

int suma(int a,int b);
int producto(int a,int b);

typedef int (*puntero_int)(int, int);

float dividir(float a, float b);
float promedio(float a, float b);

typedef float (*puntero_float)(float,float);




int main(){
    puntero_void ptvd;
    puntero_int ptint;
    puntero_float ptfloat;


    ptvd = imprimir;
    printf("La funcion imprimir con sus parametros",(2));

    ptint= suma;
    printf("La funcion con suma ",ptint(2,6));

    ptfloat=dividir;
    printf("La funcion con division",ptfloat(4.7,9.3));
        
}
