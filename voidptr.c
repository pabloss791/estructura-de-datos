#include <stdio.h>
/* Teoria, un VOID pointer es un apuntador GENERICO
que no tiene (todavia) un tipo de dato al que va apuntar.
sintaxis:
void * ptr;
reglas:
no se puede desreferenciar un apuntador void, ya que no sabemos
de que tipo son.
para poder usarse, se tienen que "castear" que es el proceso de
especificarle al compilador el tipo de dato al que realmente
apunta.
ES RESPONSABILIDAD DEL PROGRAMADOR hacer el casting correcto.
La aritmetica de punteros de un void ptr es byte por byte
(como el char)
References:
https://www.geeksforgeeks.org/void-pointer-c-cpp/
*/
void myprint(void *, int);
#define CHAR 1
#define INTEGER 2
#define FLOAT 3
typedef int TYPE;
int main()
{
//Ejemplo de por qué es importante inicializar en NULL
/*
int * null_ptr;
null_ptr = NULL;
if(null_ptr == NULL){
printf("Error\n");
}
else{
printf("Direccion de null_ptr es: %p y tiene el valor de: %d \n", null_ptr,
*null_ptr);
}
*/
int a = 10;
void * vptr = &a;
/*vptr es un apuntador generico, que tiene guardado la direccion de a.
no podemos usarlo sin castear: */
//printf("valor de a = %d", *vptr); // <-- no compila
//argument void type is incomplete
/* 2 formas de usarlo */
//1) casting directo:
printf("el valor de a = %d \n", *(int *)vptr);
//2) restaurando su puntero en un puntero del tipo correcto:
int * iptr = vptr;
printf("Ahora el valor de a = %d \n", *iptr);
printf("Dir de int ptr: %p con valor de: %d \n\n",iptr,*iptr);
getchar();
char l = 'A';
vptr = &l;
printf("Por ultimo %d\n", *(int*)vptr);
//uso practico;
//crear 1 sola funcion que imprima y reciba cualquier
//cosa, dependiendo del tipo, dentro hara cosas especiales.
//nos ahorra crear 3 funciones y duplicar codigo.
int z = 150;
char b = 'R';
float f = 999.99;
int * intptr = &z;
myprint((void*)&z, INTEGER);
void * gen_ptr = &b;
myprint(gen_ptr, CHAR);
gen_ptr = &f;
myprint(gen_ptr, FLOAT);
getchar();
void * new_ptr = NULL;
myprint(new_ptr, FLOAT);
}
void myprint(void * ptr, TYPE t)
{
if(ptr == NULL)
{
// another sintax .... if(!ptr) if not valid ...
printf("Error, NULL pointer, it is dangerous to go alone\n");
return;
}
if(t == INTEGER)
printf("NUM: %d",*(int *)ptr);
if(t == CHAR)
printf("Letter [%c] ", *(char *)ptr);
if(t == FLOAT)
printf("Float %f ", *(float *)ptr);
printf("\n");
}