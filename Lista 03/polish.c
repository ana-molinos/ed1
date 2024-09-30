#include "stack.h"
#include <stdio.h>

void reversed_polish_notation (char *c) {
  Stack *s = create(strlen(c));
  int i = 0;
  
  //percorre a string empilhando apenas operadores
  while (c[i] != '\0') {
    
    //se for um numero, apenas imprime na tela
    if(c[i] >= '0' && c[i] <= '9')
    {
      printf("%c ", c[i]);
    }
    //se for um operador, empilha
    else if(!full(s) && (c[i] == '+' || c[i] == '-' || c[i] == '*' || c[i] == '/'))
    {
      push(s, c[i]);
    }
    //se for um fecha parenteses, desempilha, o que faz respeitar a precedencia
    else if(!empty(s) && c[i] == ')')
    {
      printf("%c ", pop(s));
    }

    i++;

  }

  //faz com que desempilhe quando nao tiver parenteses
  while(!empty(s))
  {
    printf("%c ", pop(s));
  }

  printf("\n");
  destroy(s);
}

int main () {
  char *c = "( 9 + ( ( 0 + 1 ) * ( 2 * 3 ) ) )";
  //char *c = "1*(2+(3*(4+(5*(6+7)))))";
  //char *c = "1+2*(3-4*(5-6)-7*8)-9*0"; //nao funciona para esse caso
  reversed_polish_notation (c);
  return 0;
}
