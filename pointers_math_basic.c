/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CLEAR printf("\033[0;0H\033[2J");

void ex01(void);
int mylenght(char *str);
void uppertolower(char *ptr);
void isBinary(char *ptr);

int main()
{
  ex01();

  char texto[100];
  printf("\n\nIntroduce un texto para convertir a minusculas: ");
  scanf("%s", texto);
  uppertolower(texto);
  printf("Texto convertido: %s\n", texto);

  char binario[100];
  printf("\nIntroduce un codigo para verificar si es binario: ");
  scanf("%s", binario);
  isBinary(binario);

  return 0;
}

/* Excerice 01:
  Create an array of 10 integers, set their value (whatever you want)
  Using pointer arithmetic and a for loop traverse and print all the array

  DO NOT USE BRACKETS [ ]
  
  Print both the value and the address.
  
  ie
    int array = [ 2 , 3 , 5 , 6]

    array[0] = 2 -> addr = 0x00001
    array[1] = 3 -> addr = 0x00004
    array[2] = 5 -> addr = 0x00008
    array[3] = 6 -> addr = 0x0000B
*/
void ex01(void)
{
    int Arr[10]={1,2,3,4,5,6,7,8,9,3};
    int *ptr_arr = Arr;

    for (int i=0; i<10; i++){
        printf("El elemento numero %d = %d, se encuentra en el espacio de memoria %p\n",
               i, *(ptr_arr+i), (ptr_arr+i));
    }
}

/* Excercise 02:
  Implement a function mylenght() that returns the size of the passed 
  string (char array). DO NOT USE strlen(), use only pointer arithmetic.

  DO NOT USE BRACKETS [ ]

  TIP: all strings are array of chars, terminated by '\0' character.
*/
int mylenght(char*str){
    int count = 0;
    char *ptr = str;
    while(*ptr != '\0'){
        count++;
        ptr++;
    }
    return count;
}

/* Excercise 03
  Implementa una funcion, que reciba por referencia un arreglo,
  recorra este arreglo y cambie cualquier mayuscula a minuscula, 
  el arreglo se debe de imprimir de vuelta en el main  Tip: ASCII table

  NOTA : No utilizar arreglos o corchetes dentro de
         ninguna de las 2 funciones.
*/
void uppertolower(char *ptr){
    while (*ptr != '\0'){
      if (*ptr >= 'A' && *ptr <= 'Z'){
        *ptr = *ptr + 32;
      }
      ptr++;
    }
}

/* Exercise 04
  Implementa una función isBinary que reciba una cadena de texto de consola
  y determine si está formada exclusivamente por dígitos binarios (0, 1). 
*/
void isBinary(char *ptr){
  int esBinario = 1;
  while(*ptr != '\0'){
    if(*ptr != '1' && *ptr != '0'){
      esBinario = 0;
      break;
    }
    ptr++;
  }

  if(esBinario){
      printf("El codigo es binario\n");
  } else {
      printf("El codigo no es binario\n");
  }
}
