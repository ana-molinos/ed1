#include "list.h"

/* */
List* merge (List *A, List *B) {
  List* C;

  //se nenhuma das listas está vazia...
  if(A!=NULL && B!=NULL)
  {
    //atualiza C com o menor elemento das duas listas e recursividade...
    if(A->data <= B->data)
    {
      //define a cabeça de C
      C = A;
      //atualiza a cabeça de A
      A = A->next;
      //conecta a cabeça atual com o resultado do novo merge (feito entre A atualizado e B)
      C->next = merge(A, B);
    }
    else
    {
      C = B;
      B = B->next;
      C->next = merge(A, B);
    }
  }
  else //se uma das duas listas está vazia...
  {
    //retorna aquela que não está.
    if (A == NULL)  
      return B;

    return A;
    //(ou seja, conecta a lista restante a cabeça "anterior")
  }

  return C;
}

/* */
int main () {
  /*int k;
  List *A = NULL;
  for (k = 0; k <= 14; k += 2) {
    A = insert_back (A, k);
  }
  printf("Lista = ");
  print (A);
  printf("\n");

  List *B = NULL;
  for (k = 1; k <= 9; k += 2) {
    B = insert_back (B, k);
  }
  printf("Lista = ");
  print (B);
  printf("\n");*/

  List* A = NULL;
  A = insert_back(A, 2);
  printf("oi\n");
  A = insert_back(A, 3);
  print(A);
  printf("oi\n");

  List* B = NULL;
  B = insert_back(B, 0);
  B = insert_back(B, 1);
  B = insert_back(B, 4);
  print(B);
  printf("oi\n");

  List *C = merge (A, B);
  printf("Lista = ");
  print (C);
  printf("\n");

  printf("tchau\n");

  destroy (C);
  return 0;
}


