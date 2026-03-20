#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "arraylist.h"
#include "stack.h"

//#include "exercises.h"

//Funciones auxiliares que puedes utilizar para debuggear tus ejercicios
//NO MODIFICAR
void imprime_lista(List *L) {
   int *dato;
   dato = (int*)first(L);
   printf("[");
   while(dato != NULL) {
      printf("%d ", *dato);
      dato = (int*)next(L);
   }
   printf("]\n");

}

//Ojo que la pila se vacía al imprimir y se imprime en orden inverso
//NO MODIFICAR
void imprime_y_vacia_pila(Stack *P) {
   void *dato;
   printf("[");
   while((dato = pop(P)) != NULL) {
      printf("%d ", *(int*)dato);
   }
   printf("]\n");
}

/* 
Ejercicio 1.
Crea una Lista y agrega punteros a elementos del 1 al 10.
Recuerda que la lista almacena punteros, por lo que
debes reservar memoria para cada elemento que agregues.
Al finalizar retorna la lista creada.
*/

List* crea_lista() {
   List* L = create_list();
   for(int i = 1; i <= 10 ; i++)
      {
         int* elemento = malloc(sizeof(int));
         *elemento = i;
         pushCurrent(L,elemento);
      }
   return L;
}

/*
Ejercicio 2.
Crea una función que reciba una lista de enteros (int*) y 
retorne la suma de sus elementos.
*/
int sumaLista(List *L) {

   int suma = 0;
   void* actual= first(L);

   while(actual != NULL)
      {
         suma += *(int *)actual;
         actual = next(L);
      }
   return suma;
}

/*
Ejercicio 3.
Crea una función que reciba una lista de punteros a int (int*) y
un entero elem. La función debe eliminar todos los elementos 
de la lista que sean iguales a elem.
Asume que popCurrent luego de eliminar un elemento se
posiciona en el elemento anterior.
*/

void eliminaElementos(List*L, int elem)
{
   void* actual = first(L);
   
   
   while(actual != NULL)
      {
         if( *((int *)actual) == elem)
         {
             actual = popCurrent(L);
         }
         actual= next(L);
      }
}

/*
Ejercicio 4.
La función copia los punteros de la pila P1 en la pila P2.
El orden de ambas pilas se debe mantener.
Puedes usar una pila auxiliar.
*/

void copia_pila(Stack* P1, Stack* P2) 
{
   //PASAR LOS ELEMENTOS DE PILA 1 A PILA 2 EN BUEN ORDEN
   /*
   1. PASAR LA PILA 1 A LAS OTRAS DOS(QUEDAN INVERTIDAS) PILA 1 VACIA
   2. LUEGO PASAMOS LO DE LA PILA 2 A LA PILA 1(QUEDA BIEN) 
   3. MISMO PROCEDIMIENTO CON LA AUXILIAR A LA 2
   */
   Stack* pilaAux= create_stack();

   void* elementoSup;
   while(top(P1) != NULL)
      {
         //PUSHEAMOS A AUXILIAR Y P2
         elementoSup = top(P1);
         push(P2,elementoSup);
         push(pilaAux,elementoSup);
         elementoSup= pop(P1);
      }
   //VACIAMOS P2
   void* elementoSup1;
   while(top(P2) != NULL)
      {
         elementoSup1 = top(P2);
         push(P1,elementoSup1);
         elementoSup1= pop(P2);
      }
   //VACIAMOS pilaAuX
   void* elementoSup2;
   while(top(pilaAux) != NULL)
      {
         elementoSup2= top(pilaAux);
         push(P2,elementoSup2);
         elementoSup2= pop(pilaAux);
      }
}

/*
Ejercicio 5.
La función verifica si la cadena de entrada tiene sus 
paraéntesis balanceados. Retorna 1 si están balanceados,
0 en caso contrario.
*/

int parentesisBalanceados(char *cadena) 
{
   //USAR UNA PILA PARA GUARDAR LOS PARENTESIS ABIERTOS
   //AL ENCONTRAR UN PAR DE CIERRE:
   // VERIFICAR SI ESTA VACIA, SI NO, COOMPARAR CON EL TOP PILA
   // SI SON IGUALES USAR UN POP AL TOP
   // EN CASO DE NO SERLO O QUE ESTE VACIA LA PILA, LA CADENA ESTA DESBALANCEADA. 
   //AL TERMINAR DE RECORRER SI LA PILA ESTA VACIA ESTA BALANCEADA, SI NO, ESTA DESBALANCEADA..

   Stack* pila= create_stack();

   for(int i = 0; cadena[i] != '\0';i++)
      {
         if(cadena[i] == '(' || cadena[i] == '[' || cadena[i] == '{')
         {
            push(pila,(void *)&cadena[i]);
         }
         if(cadena[i] == ')' || cadena[i] == ']' || cadena[i] == '}')
         {

            if(top(pila) == NULL) return 0;
            
            char apertura= *(char *)top(pila);           
            if((apertura == '(') && cadena[i] == ')' || (apertura == '[') && cadena[i] == ']' || (apertura == '{') && cadena[i] == '}')
            {
               pop(pila);
            }   
            else return 0;
         }
      }
      
   if(top(pila) != NULL) return 0;
   return 1;
}

