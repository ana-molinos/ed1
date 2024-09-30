#include "utils.h"

/* */
void counting_sort (FILE *f, int range) {
  int i, j, total = 0;
  int *C = (int *)malloc((range+1) * sizeof(int)); /*contador*/
  
  //enquanto não chegar ao final do arquivo...
  while(!feof(f))
  {
    char ch;

    //lê o caracter do arquivo txt e armazena ele na variável ch
    fscanf(f, "%c", &ch);
    
    //se for um caracter alfanumerico...
    if(isalpha(ch))
    {
      //transforma em letra minuscula
      tolower(ch);

      //contabiliza a ocorrencia do caracter 
      //(fazendo a correção em que 'a' = 0, utilizando os valores da tabela ascii)
      C[ch - 'a']++;
    }
  }

  //calcula o total de ocorrencias de caracteres contabilizadas
  for(i=0; i<=range; i++)
    total += C[i];

  //imprime o caracter, o numero de ocorrencias e a frequência de ocorrencia no texto
  for(i=0; i<=range; i++)
    printf("%4c %6d %.4f\n", i+'a', C[i], (double)C[i]/total);

}

/* */
int main (int argc, char *argv[]) {

  /*if (argc < 2) {
    printf("run: %s file.txt\n", argv[0]);
    exit(1);
  }*/

  //FILE *f = fopen(argv[1], "r");
  
  FILE *f = fopen("livro_pt.txt", "r");

  int range = 25; /*número de letras do alfabeto (a-z)*/

  counting_sort (f, range);
  
  fclose (f);

  return 0;
}

