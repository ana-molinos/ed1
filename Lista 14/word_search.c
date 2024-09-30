#include <string.h>
#include <math.h>
#include "utils.h"

/* */
//char** words: uma matriz ou um vetor de strings
//char* key: uma string (ou seja, a palavra procurada)
int linear_search (char **words, int n, char *key) {
  for(int i=0; i<n;i++)
  {
    //se a string atual for igual a string procurada...
    if(strcmp(words[i], key)==0)
      return i;//retorna a posição
  }

  return NOT_FOUND;
}

/* */
int binary_search_iterative (char **words, int n, char *key) {
  int l, r, m;
  l = 0;
  r = n-1;

  //enquanto a esquerda for menor ou igual a direita...
  while(l<=r)
  {
    m = (l+r)/2;
    //se a palavra procurada for igual a palavra do meio do intervalo do dicionario...
    if(strcmp(key, words[m]) == 0)
      return m; //...retorne a posição da palavra no dicionario
    //se a palavra procurada vir antes da palavra atual no dicionario (em relação a ordem alfabetica)...
    else if(strcmp(key, words[m])<0)
      r = m - 1; //atualize o valor da direita para considerar o intervalo da esquerda
    else//caso contrario...
      l = m + 1;//...atualize o valor da esquerda para considerar o intervalo da direita
  }

  return NOT_FOUND;
}

/* */
int binary_search_recursive (char **words, int l, int r, char *key) {
  int m;
  
  if (l<=r) 
  {
    m = (r+l)/2;
    if(strcmp(key, words[m])<0)
      m = binary_search_recursive(words, l, m-1, key);
    else if(strcmp(key, words[m])>0)
      m = binary_search_recursive(words, m+1, r, key);
    else
      return m;
  }
  else
    return NOT_FOUND;
  
}

/* */
int get_number_of_lines (FILE *f) {
  int n = 0;
  if (f == NULL) 
    return n; 
  while (!feof(f)) {
    char c;
    fscanf(f, "%c", &c);
    if (c == '\n') 
      n++;
  }
  rewind(f);
  return (n-1);
}

/* */
int main (int argc, char *argv[]) {
  /*if (argc < 2) { 
    printf("run: %s [word_to_search]\n", argv[0]);
    exit(1);
  }*/  
  clock_t start, end;
  double elapsed_time;
  //char *key = argv[1];
  char *key = "ZOOLOGIA";
  FILE *f = fopen("palavras.txt", "r"); 
  int n = get_number_of_lines(f);
  char **words = (char **)malloc(n * sizeof(char *));
  int i, index;
  for (i = 0; i < n; i++) 
    words[i] = (char *)malloc(256 * sizeof(char));
  i = 0;
  while (!feof(f)) {
    fscanf(f, "%s", words[i]);     
    i++;
  }

  /*Busca linear*/
  start = clock();
  index = linear_search (words, n, key);
  end = clock();
  elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
  printf("Running time (linear): %.2f\n", elapsed_time);
  if (index >= 0) {
    printf("Key %s, found at %d\n", key, index);
  }
  else {
    printf("Element not found.\n");
  }
 
  /*Busca binária iterativa*/
  start = clock();
  index = binary_search_iterative (words, n, key);
  end = clock();
  elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
  printf("Running time (binary): %.2f\n", elapsed_time);
  if (index >= 0) {
    printf("Key %s, found at %d\n", key, index);
  }
  else {
    printf("Element not found.\n");
  }
  
  /*Busca binária recursiva*/
  start = clock();
  index = binary_search_recursive (words, 0, n-1, key);
  end = clock();
  elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
  printf("Running time (binary): %.2f\n", elapsed_time);
  if (index >= 0) {
    printf("Key %s, found at %d\n", key, index);
  }
  else {
    printf("Element not found.\n");
  }
 
  /*Desalocando estruturas*/ 
  for (i = 0; i < n; i++) 
    free(words[i]);
  free(words);
  fclose(f);
  return 0;
}  
