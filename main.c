#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include "TadMochila.h"
//gcc -o teste main.c TadMochila.c TadMochila.h

int main() {

  clock_t tempo;
	tempo = clock();

  int N,peso,valor,i = 0,r,comp;
  Ttupla *Vetor;
  char leitorN[20];

  FILE* pArquivo;
  printf("Digite o nome do arquivo: ");
  scanf("%s",leitorN);
  strcat(leitorN,".txt");

  pArquivo = fopen(leitorN,"r");

  if((pArquivo = fopen(leitorN,"r")) == NULL){
    printf("Erro na abertura do arquivo.\n");
    return 1;
  }else{
    printf("Arquivo aberto com sucesso.\n");

    fscanf(pArquivo,"%s", leitorN);
    N = atoi(leitorN);
    Vetor = (Ttupla *)malloc(N * sizeof(Ttupla));

    while(fscanf(pArquivo,"%d %d",&peso,&valor) != EOF){
      Vetor[i].peso = peso;
      Vetor[i].valorImportancia = valor;
      i++;
    }
  }
  for(i = 0; i < N; i++){
    r = i+1;
    comp = N - (i+1);
    printCombination(Vetor, N, r,comp);
  }


    printf("Tempo:%.5f Segundos\n",(clock() - tempo) / (double)CLOCKS_PER_SEC);

      return 0;
}
