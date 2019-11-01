#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include "TadMochila.h"
//gcc -o teste main.c TadMochila.c TadMochila.h

int main() {

  int N,peso,valor,i = 0,r,arr[4];;
  Ttupla *Vetor;
  char leitorN[20];


  FILE* pArquivo;
  printf("Digite o nome do arquivo: ");
  scanf("%s",leitorN);
  strcat(leitorN,".txt");

  pArquivo = fopen(leitorN,"r");

  if((pArquivo = fopen(leitorN,"r")) == NULL){
    printf("Erro na abertura do arquivo.\n");
  }else{
    printf("Arquivo aberto com sucesso.\n");

    fscanf(pArquivo,"%s", leitorN);
    N = atoi(leitorN);
    Vetor = (Ttupla *)malloc(N * sizeof(Ttupla));
  //printf("%d\n",N);

    while(fscanf(pArquivo,"%d %d",&peso,&valor) != EOF){
      Vetor[i].peso = peso;
      Vetor[i].valorImportancia = valor;
      i++;
  //printf("%d %d\n",peso,valor);
    }
  }

  for(i = 0; i < N; i++){
    r = i+1;
    printCombination(Vetor, N, r);
  }


      return 0;
}
