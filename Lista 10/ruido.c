#include "ruido.h"
#include "utils.h"

void selection_sort (int *A, int n) {
  int min;
  
  for(int i=0; i<n-1; i++)
  {
    min = i;
    for(int j=i+1; j<n; j++)
    {
      if (A[j] < A[min]) 
      {
        min = j;
      }
      //printf("menor = %d pos = %d\n", menor, pos);
    }
    swap(A, i, min);
  }
}

/* */
Image* create (int nrows, int ncols) {
  int i;
  Image *img = (Image *)malloc(sizeof(Image)); 
  img->nrows = nrows;
  img->ncols = ncols;
  img->m = (int **)malloc(ncols * sizeof(int *));
  for (i = 0; i < ncols; i++) {
    img->m[i] = (int *)malloc(nrows * sizeof(int)); 
  }
  return img;
}

/* */
void destroy (Image *img) {
  int i;
  for (i = 0; i < img->ncols; i++) {
    free(img->m[i]);
  }
  free(img->m);
  free(img);
}

/* */
Image* read_image (FILE *file_in, int *nrows, int *ncols) {
  int nlevels;
  char *type = (char *)malloc(sizeof(char));
  fscanf(file_in, "%s", type);   
  fscanf(file_in, "%d %d %d", ncols, nrows, &nlevels);   
  Image *in = create (*nrows, *ncols);
  int i, j;
  for (j = 0; j < in->nrows; j++) {
    for (i = 0; i < in->ncols; i++) {
      fscanf(file_in, "%d", &(in->m[i][j]));
    }
  } 
  free(type);
  return in;
}

/* */
void write_image (FILE *file_out, Image *out, int nrows, int ncols) {
  int i, j;	
  fprintf(file_out, "P2\n%d %d\n255\n", out->ncols, out->nrows);
  for (j = 0; j < out->nrows; j++) {
    for (i = 0; i < out->ncols; i++) {
      fprintf(file_out, "%d ", out->m[i][j]);
      if ( (j != 0) && ((j % 12) == 0) ) {
        fprintf(file_out, "\n");
      }
    }
  }
}  

/* */
Image* process (Image *in, int wsize) {
  //Image* in: ponteiro da imagem q vai ser processada
  //Int wsize: tamanho da vizinhança que sera usada para o calculo da mediana (M wsize x wsize)

  int i, j, k, l, p;
  Image *out = create (in->nrows, in->ncols);
  /*Array {A} é usado para armazenar os pixels da janela*/
  /*O array {A} deve ser ordenado e utilizado para mediana*/
  int *A = (int *)malloc(wsize * wsize * sizeof(int));

  //zera a matriz de saída
  for(i=0; i<in->nrows; i++)
  {
    for(j=0; j<in->ncols; j++)
      out->m[i][j]= 0;
  }

  //laços que percorrem a imagem desconsiderando as bordas(não entendi por que desconsidera wsize 
  //linhas/colunas das bordas...)
  for (i = wsize; i < (in->ncols - wsize); i++) {
    for (j = wsize; j < (in->nrows - wsize); j++) {
      
      p=0;
      //laços que percorrem a vizinhança wsize x wsize de do elemento ij
      for(k=i-wsize/2; k<=i+wsize/2; k++)
      {
        for(l=j-wsize/2; l<=j+wsize/2; l++)
        {
          //preenche o vetor com os valores dos vizinhos
          A[p] = in->m[k][l];
          p++;
        } 
      }

      //ordena os valores e substitui o valor do elemento i,j pela mediana
      selection_sort(A, wsize);
      out->m[i][j] = A[wsize/2];
    }
  }
  free(A); 
  return out;
}

/* */

/*Observações com relação ao tamanho da mascára: quanto maior a janela, menor o numero de ruido
  no resultado final, porém a qualidade da imagem decai bastante. Imagino que seja porque, quanto
  maior a vizinhança, mais longe a mediana fica de representar o pixel em questão.*/
int main ( ) {
  int nrows, ncols;
  FILE *file_in  = fopen("lena.pgm", "r");//ponteiro pra imagem q vai ser processada
  FILE *file_out = fopen("saida.pgm", "w");//ponteiro pra imagem apos ser processada
  /*tamanho da janela de remoção de ruído: */
  int wsize = 5; /*teste com ímpares 5, 7, 9, ...*/
  Image *in = read_image (file_in, &nrows, &ncols);//le a imagem original
  Image *out = process (in, wsize);//processa a imagem original
  write_image (file_out, out, nrows, ncols);//grava a imagem processada
  destroy (in); 
  destroy (out);
  fclose(file_in);
  fclose(file_out);
  return 0;
} 


