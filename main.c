#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include "TadMochila.h"
//gcc -o teste main.c TadMochila.c TadMochila.h
/* Tamanho máximo da entrada */
#define MAX_INPUT 100

int main() {

    int N,peso,valor,i = 0, j, r, k;
    tupla *Vetor;
    char leitorN[20];
    unsigned MAX, MASK, NUM ;

    FILE* pArquivo;
    printf("Digite o nome do arquivo com a extensao .txt: ");
    scanf("%s",leitorN);


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
    printf("ATUALIZOU\n");
    for(i = 0; i < N;i++){
      printf("%d %d\n",Vetor[i].peso,Vetor[i].valorImportancia );
    }
    /* Armazena a string de entrada. */
    tupla *input;
    /* Armazena cada combinação. */
    tupla str[sizeof(input)] ;

    input = (tupla *)malloc(N * sizeof(tupla));
    input = Vetor;
    //  printf("Digite o grupo inicial: ") ;
    //  scanf("%s", input) ;

    i = 0;
    printf("Digite o r: ") ;
    scanf("%d", &r) ;
    for (int l = 1; l <= r; ++l) {
        /* Manda o bit 1 para a n-ésima posição.
    * Os bits são invertidos para que a posição n
    * esteja com o bit zero, a fim de marcar
    * o final do processo.
    */
      MAX = ~(1 << N) ;

      /* Primeiro número é o 1. */
      NUM = 1;

      putchar('\n') ;

      /* Quando o número alcançar MAX, o loop
       * será encerrado.
       */
      while ( MAX & NUM ) {
          /* Conta os bits 1's. */
          MASK = 1 ;
          k = 0 ;
          while ( MAX & MASK ) {
              if ( NUM & MASK ) k++ ;
              MASK = MASK << 1 ;
          }

          /* Monta o resultado somente se
           * a quantidade de bits k é igual
           * a r. */
          if ( k == l ) {
              MASK = 1 ;
              i = j = 0 ;

              while ( MAX & MASK ) {
                  /* Verdadeiro se NUM tem um bit 1
                   * na posição indicada por MASK. */
                  if ( NUM & MASK ) {
                      /* Gera a combinação em str */
                      str[i] = input[j] ;
                      i++ ;
                  }
                  j++ ;
                  /* Desloca a máscara */
                  MASK = MASK << 1 ;
              }

              printf("%s\n", str) ;
          }

          NUM++ ;
      }

  }

  return 0;
}
/*
 * o codigo so lida com vetor ja ordenado,
 * um problema da combinaçao binaria,
 * tratar somente os indices
 * */
