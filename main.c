#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include "TadMochila.h"
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
      int zero = 0,z;
      for(z = 1; z < N + 1;z++){
        comb(Vetor, z, zero);
      }
      return 0;
}
