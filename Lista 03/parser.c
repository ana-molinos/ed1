#include "stack.h"

int parser (char *c) {
  /*cria uma stack do tamanho da string, pois há a possibilidade de todos os caracteres
    serem do tipo abre*/
  Stack *s = create(strlen(c));
  int i = 0;
  while (c[i] != '\0') {
    if(c[i] == '(' || c[i] == '[') //se o caracter atual for "abre", empilhe!
    {
      push(s, c[i]);
      //print(s);
    }
    else if(c[i] == ')')//se o caracter atual for )...
    {
      //teste se a pilha não esta vazia e se o caracter anterior é diferente de ( 
      if(!empty(s) && (pop(s) != '('))
      {
        //print(s);
        return 0; //se sim, retorna falso pois é mal formada
      }
    }
    else if(c[i] == ']')//nesse caso a alternativa restante é ser ]
    {
      
      //teste se a pilha não esta vazia e se o caracter anterior é diferente [
      if(!empty(s) && (pop(s) != '['))//teste se o caracter anterior é diferente [ 
      {
        //print(s);
        return 0; //se sim, retorna falso pois é mal formada
      }
    }

    i++;

  }

  /*se no final, a pilha não esta vazia, significa que algum "abre" ficou sem "fecha",
    logo, a sequencia é mal formada tambem.*/
  if(!empty(s))
    return 0;

  return 1;
}

int main () {
  //declaração de strings com caracteres
  
  char *c = "( ( ) [ ( ) ] )";
  //char *c = "( [ ) ]";
  //char *c = "( ) [ ]";
  //char *c = "( [ ]";
  //char *c = ") (";
  if (parser(c)) 
    printf("true  (bem formada)\n");
  else  
    printf("false (mal formada)\n");
  return 0;
}