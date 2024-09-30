#include "list.h"

List* merge (List *A, List *B){
  List *C, *t;
  //entender A, B e C como cabeça da lista

  while ((A!=NULL) && (B!=NULL))
  {
    if(A->data <= B->data) //se o numero em A for menor ou igual ao numero em B
    {
      if(C == NULL) //caso c esteja vazia
      {
        C = A; //C passa a apontar para A
        t = A; //o ptr temporario passa a apontar para A
        A = A->next; //a cabeça da lista A passa a ser o próximo elemento
      }
      else
      {
        //o elemento atual de C (referenciado pelo ptr temp) passa a apontar para o elemento que é cabeça da lista A
        t->next = A;
        t = A; //o ponteiro temporario passa a apontar para esse mesmo elemento
        A = A->next; //a cabeça de A é atualizada 
      }
    }
    else if(B->data <= A->data)//se o numero em B for menor ou igual ao numero em A
    {
      if(C == NULL) 
      {
        C = B; 
        t = A;
        B = B->next;
      }
      else
      {
        t->next = B;
        t = B;
        B = B->next;

      }
    }
  }

  //quando uma das listas é NULL, entao o restante da outra precisa ser "conectado" com a lista merge
  if(A==NULL)
  {
    t->next = B;
  }
  else if(B==NULL)
  {
    t->next = A;
  }
  
  return C;
}

/**/
int main () {
  int k;
  List *A = NULL, *B = NULL;
  for (k = 10; k >= 0; k -= 2) 
    A = insert (A, k);
  for (k = 19; k >= 0; k -= 2) 
    B = insert (B, k);
  print (A);
  print (B);
  List *C = merge (A, B);
  print (C);
  destroy (C);
  return 0;
}
