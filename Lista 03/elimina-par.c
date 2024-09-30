#include "stack.h"

int main () {
  int tam = 6;
  int num;
  Stack *s = create (tam); //cria a pilha
  Stack *s_aux = create(tam); //cria a pilha reserva
  srand(time(NULL));
  int i;
  //preenche a pilha com numeros aleatorios entre 0 e 10
  for (i = 0; i < tam; i++) {
    push (s, rand()%10);
  }
  print (s); //printa a fila gerada
  
  /*TERMINAR*/

  //enquanto a fila não estiver vazia, desempilhe
  while(!empty(s)){
    num = pop(s);
    //confere se o numero desempilhado eh impar, caso seja, empilha ele na pilha aux
    if(num%2)
      push(s_aux, num);
  }

  //devolve os elementos da pilha auxiliar para a pilha original
  while (!empty(s_aux))
  {
    push(s, pop(s_aux));
  } //isso "desinverte" o sentido dos elementos
  
  print(s);

  destroy (s);
  destroy(s_aux);
}
