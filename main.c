#include <stdio.h>
#include <string.h>
#include "TadMochila.h"
#include "combinador.h"
//gcc -o teste main.c TadMochila.c TadMochila.h

int main() {

  int N,peso,valor,i = 0;

      tupla *Vetor;
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
        Vetor = (tupla *)malloc(N * sizeof(tupla));
        //printf("%d\n",N);

        while(fscanf(pArquivo,"%d %d",&peso,&valor) != EOF){
            Vetor[i].peso = peso;
            Vetor[i].valorImportancia = valor;
            i++;
            //printf("%d %d\n",peso,valor);
        }
      }

    //  for(i = 0; i < N;i++){
    //    printf("%d %d\n",Vetor[i].peso,Vetor[i].valorImportancia );
    //  }
    //////////////////////////////////////////////////////////////////////////////////////////////////////
    int j = 0;
    while (j < sizeof(N) ){
        int arr[sizeof(N)] ;
        int r = j;
        int n = sizeof(arr)/sizeof(arr[0]);
        printCombination(Vetor, n, r);
        i++;
    }

    return 0;

}
