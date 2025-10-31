/* Prohibido agregar librerías adicionales a estas: */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char alumno[100] = "Pablo santamaria";

/*  

    Fecha : 31 de Octubre 2025
    Diseno de Estructura de Datos - Grupo B
    Segunda Evaluación Síncrona

  Ejercicio 1:  Mandar al Inicio          /15 pts
  Ejercicio 2:  Destinos                  /20 pts
  Ejercicio 3:  Calculadora RPN           /15 pts
                                      ________
  Calificación Final:                     /50 puntos
*/

/*Definiciones y Funciones de utilidad - NO TOCAR*/
typedef struct node
{
  int value;
  struct node * next;
} node;

void printlist(node * n)  //NO TOCAR
{
  while(n)
  {
    printf("%d ", n->value);
    n=n->next;
  }
  printf("\n");
}

node *L1, *L2;
node L1n1, L1n2, L1n3, L1n4;
node L2n1, L2n2, L2n3, L2n4, L2n5;
node *LD1, *LD2, *LD1B, *LD2B;
node LD1n1, LD1n2, LD1n3, LD1n4;
node LD2n1, LD2n2, LD2n3, LD2n4, LD2n5, LD2n6;
node LD1nuevo, LD2nuevo;

/* STACK GLOBAL */
node *stack_top = NULL;
int count = 0;

void push(int data) 
{
  node *temp = NULL;
  
  if (stack_top == NULL)
  {
    stack_top = (node *)malloc(sizeof(struct node));
    stack_top->next = NULL;
    stack_top->value = data;
  }
  else
  {
    temp = (node *)malloc(sizeof(struct node));
    temp->next = stack_top;
    temp->value = data;
    stack_top = temp;
  }
  count++;
}

int pop() 
{
  node *nptr = stack_top;

  if (nptr == NULL)
  {
      printf("\nStack Vacío\n");
      return -1;
  }
  else
  {
    nptr = nptr->next;
  }
  
  int popped = stack_top->value;
  free(stack_top);
  stack_top = nptr;
  count--;
  return popped;
}

void display() 
{

  node * nptr = stack_top;
  
  if (nptr == NULL)
  {
      printf("\nStack Vacío\n");
      return;
  }
  
  printf("The stack is \n");
  while (nptr != NULL)
  {
      printf("%d--->", nptr->value);
      nptr = nptr->next;
  }
  printf("NULL\n\n");
}

/* NO TOCAR */
/*Definiciones y Funciones de utilidad - NO TOCAR*/

/* INSTRUCCION GENERAL:
   Codifica SIEMPRE dentro de las secciones: */

   /* ----------  INICIO RESPUESTA:  --------------- */
        // tu codigo del examen
        // va en estas seccion 
   /* ----------  FIN RESPUESTA:  --------------- */

/*Inicio de Examen*/

/*  = = = = = = = Ejercicio 01: Mandar al Inicio = = = = = =
    Valor: 15 puntos
    = = = = = = = = = = = = = = = = = = = = = = = = = = = = =  
  Crea una función, que reciba el apuntador a una lista ligada simple.
  La función deberá de recorrer la lista hasta llegar al último elemento y moverlo al inicio de la lista.
  
  Te recomiendo que la función regrese el nuevo header de la lista.

  Ejemplos:
  Lista Inicial: 8 -> 45 -> 70 -> 12 -> Null
  Lista después del cambio: 12 -> 8 -> 45 -> 70 -> Null

  Lista Inicial: 1 -> 2 -> 3 -> 4 -> 5 -> Null
  Lista después del cambio: 5 -> 1 -> 2 -> 3 -> 4 -> Null

  Comprueba el funcionamiento correcto llamando tu función.
  Usa la funcion printList provista y comprueba el resultado.
  Usa las listas de ejemplo L1 y L2 creadas.

*/


/* ----------  INICIO RESPUESTA:  --------------- */
//Crea tu función aquí

node* moverUltimoAlInicio(node* head) {
    if (head == NULL || head->next == NULL)
        return head; 

    node *actual = head;
    node *anterior = NULL;

   
    while (actual->next != NULL) {
        anterior = actual;
        actual = actual->next;
    }

    
    anterior->next = NULL;     
    actual->next = head;       
    head = actual;             

    return head;
}




/* ----------  FIN RESPUESTA:  --------------- */


int ex01()
{
  /* NO TOCAR, inicalizacion de listas demo L1 y L2 */
  L1n1.value=8; L1n2.value=45; L1n3.value=70; L1n4.value=12;
  L1n1.next=&L1n2; L1n2.next = &L1n3; L1n3.next = &L1n4; L1n4.next = NULL;
  L2n1.value=1; L2n2.value=2; L2n3.value=3; L2n4.value=4; L2n5.value=5;
  L2n1.next=&L2n2; L2n2.next = &L2n3; L2n3.next = &L2n4; L2n4.next = &L2n5; L2n5.next = NULL;
  L1 = &L1n1; //Header de Lista 1
  L2 = &L2n1; //Header de Lista 2
  
  printf("Lista 1 antes del cambio:\n");
  printlist(L1);
  printf("Lista 2 antes del cambio:\n");
  printlist(L2);
  /* NO TOCAR */

/* ----------  INICIO RESPUESTA:  --------------- */
// Espacio para que mandes llamar tu función y compruebes el resultado.



/* ----------  FIN RESPUESTA:  --------------- */
  
  /* NO TOCAR */
  printf("\nLista 1 después del cambio:\n");
  printlist(L1);
  printf("Lista 2 después del cambio:\n");
  printlist(L2);
  return 0;
  /* NO TOCAR */
}


/*  = = = = = = = Ejercicio 02: Destinos  = = = = = =
    Valor: 20 puntos
    = = = = = = = = = = = = = = = = = = = = = = = = =  
   Abre y revisa el archivo de texto "destinos.txt" que viene incluido en tu examen.
   El archivo de texto tiene la siguiente estructura:
    * 1era línea = Un número que se refiere a cuantos registros tiene el archivo.
    * 2nda en adelante = Registros de vuelos que contienen 3 datos en ese orden:
      * El nombre de una ciudad
      * El Codigo del vuelo: Aerolinea 3 a 5 caracteres + 3 digitos del # de vuelo
      * El costo en dolares(después de $) del vuelo a esa ciudad.

  Ejemplo:
  4
  Mexico VOL197 $600.57
  Tokyo ANAJP874 $12159.87
  Roma ITAL789 $8000.00
  Barcelona LUFT018 $5544.33
     
  1. Contruye tres arreglos de forma DINAMICA:
    * Arreglo de nombres de ciudades
    * Arreglo de numeros de vuelo (Codigo de aerolinea se ignora)
    * Arreglo de costo exacto del vuelo (Numeros, no letras)
  2. Abre el archivo, lee cada registro de vuelo y guarda la información necesaria en tus arreglos. 
  3. Imprime tus arreglos para confirmar.
  4. Escribe tu nombre completo al inicio o al final de tu archivo destinos.txt.
    TIP, si entre ejecuciones, modificas el archivo te recomiendo regresarlo a su forma original.
  5. Libera tu memoria dinámica y cierra tu archivo.
      NOTA: Si no puedes leer el archivo, pide los datos de consola, pero solo valdra 10pts.

  Output esperado:
    Ciudades:
    Mexico Tokyo Roma Barcelona Sydney
    Vuelos:
    197 874 789 18 888
    Costos:
    600.57 12159.87 8000.00 5544.33 18157.01
*/

int ex02()
{
/* ----------  INICIO RESPUESTA:  --------------- */
  
/* ----------  FIN RESPUESTA:  --------------- */
  return 0;
}


/*  = = = = = = = Ejercicio 03: Calculadora RPN  = = = = = =
    Valor: 15 puntos
    = = = = = = = = = = = = = = = = = = = = = = = = =  
    Escribe un programa que evalúe una expresión en notación postfija (RPN) usando una pila.
    Para usar el stack, utiliza la implementación de arriba de push y pop, y las variables stack_top y count.

    Para la entrada de datos, solicita por terminal un numero u operador y ejecuta la accion.
    Asume que el usuario solo ingresara digitos (0-9) o un operador (+,-,*,=).
    El operador '=' deberá terminar la operación y mostrar el resultado. Operador de división no es necesaria.
    
    Notación postfija (calculadoras graficadoras)
    * Cuando recibas un número lo ingresas en el stack.
    * Cuando recibas un operador, ejecutas dicha operación con los 2 elementos arriba del stack, y metes el resultado.
   
    Ejemplo de entrada: 5 1 2 + 4 * + 3 - =
    Salida esperada: 14

*/

int ex03()
{
/* ----------  INICIO RESPUESTA:  --------------- */
  
/* ----------  FIN RESPUESTA:  --------------- */
  return 0;
}

int main()
{
  printf("Examen Parcial 2 de : %s\n", alumno);
  printf("=== E01: Mandar al inicio\n");
  ex01();
  printf("\n=== E02: Destinos\n");
  //ex02();
  printf("\n=== E03: Calculadora RPN\n");
  //ex03();
  return 0;
}
