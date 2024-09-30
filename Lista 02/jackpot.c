#include "queue.h"
#include <time.h>

void jackpot (int n, int r) {
  int i, j, max, win;
  int *array = (int*) malloc(n*sizeof(int)); //uma array com n posições (como se fosse o "visor" da maquina)

  for(i=0; i<n; i++){ //repete a lógica para cada carretel
    Queue *reel = create(r); //cria uma fila que corresponde ao carretel i

    for(j=0; j<r-1; j++) //preenche a fila com dig de 1 a 9
      enqueue(reel, j+1);

    //print(reel);

    //enfileira e desenfileira o carretel um numero aleatorio de vezes
    j=0;
    max = rand()%100;
    while(j<max){
      enqueue(reel, dequeue(reel));
      j++;
    }

    array[i] = front(reel); //retorna o primeiro elemento da fila que corresponde ao numero sorteado
    printf("%d ", array[i]);
    destroy(reel); //libera a fila correspondente ao carretel
  }

  printf("\n");

  win = 1; //testa se os valores sorteados são iguais
  for(i=1; win && i<n; i++){
    if(array[i] != array[i-1])
      win = 0;
  }

  if(win)
    printf("YOU'RE THE WINNER!!!\n");
  else
    jackpot(n, r); //recursividade
}

int main () {
  srand(time(NULL));	//semente aleatória do rand
  int n = 3;  /*número de carretéis*/ //"n filas"
  int r = 10; /*sequência de números em cada carretel*/ //"r possibilidades (nesse caso, de 1 a 9)"
  jackpot (n, r);
}
