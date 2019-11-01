#include "TadMochila.h"
#include <stdio.h>

  int CAPACIDADE = 10;
Tsomatorio somatorio, somatorio_print;

void printCombination(Ttupla arr[], int n, int r)
{

  /*somatorio_print.valor_Agregado = 0;
  somatorio_print.tamanho = 0;
  somatorio_print.peso_Agregado = 0;
  somatorio_print.combinacao_atual;*/
  somatorio.peso_Agregado = 0;
  somatorio.tamanho = 0;
  somatorio.valor_Agregado = 0;

    Ttupla data[r];



    combinationUtil(arr, data, 0, n-1, 0, r);

}

void combinationUtil(Ttupla arr[], Ttupla data[], int start, int end,int index, int r)
{


  int k=0;


    if (index == r)
    {

        for (k=0; k<r; k++){
          somatorio.peso_Agregado += data[k].peso;
          somatorio.valor_Agregado += data[k].valorImportancia;
          somatorio.combinacao_atual[k] = data[k];
          somatorio.tamanho ++;
          printf("data:\n");
          printf("(%d %d)\n",data[k].peso,data[k].valorImportancia );
          printf("somatorio:\n");
          printf("(%d %d)",somatorio.combinacao_atual[k].peso,somatorio.combinacao_atual[k].valorImportancia);
          printf("\n");
          printf("valor agregado: %d\n",somatorio.valor_Agregado);
          printf("peso agregado: %d\n",somatorio.peso_Agregado);

          return;
        }

        if(somatorio.valor_Agregado > somatorio_print.valor_Agregado && r >= 1){
          if(somatorio.peso_Agregado < 40){
            somatorio_print.valor_Agregado = somatorio.valor_Agregado;
            somatorio_print.peso_Agregado = somatorio.peso_Agregado;
            somatorio_print.tamanho = somatorio.tamanho;
            for (k=0; k<r; k++){
              somatorio_print.combinacao_atual[k] = somatorio.combinacao_atual[k];
            }
          }
        }else{
          if(somatorio.valor_Agregado == somatorio_print.valor_Agregado && r > 1){
            if (somatorio.tamanho > somatorio_print.tamanho) {
              somatorio_print.valor_Agregado = somatorio.valor_Agregado;
              somatorio_print.peso_Agregado = somatorio.peso_Agregado;
              somatorio_print.tamanho = somatorio.tamanho;
              for (k=0; k<r-1; k++){
                somatorio_print.combinacao_atual[k] = somatorio.combinacao_atual[k];
              }
            }

          }
        }
        return;
    }





    for (int i=start; i<=end && end-i+1 >= r-index; i++)
    {

        data[index] = arr[i];
        combinationUtil(arr, data, i+1, end, index+1, r);
    }

    if(r > 1 && somatorio_print.tamanho < r){
      printf("O maior valor agregado de uma combinacao tamanho %d eh %d\n",r-1,somatorio_print.valor_Agregado);
      printf("O maior peso agregado de uma combinacao tamanho %d eh %d\n",r-1,somatorio_print.peso_Agregado);
      for (int m=0; m<r; m++){
        printf("(%d %d)", somatorio_print.combinacao_atual[m].peso,somatorio_print.combinacao_atual[m].valorImportancia);

      }
      printf("\n");
      return;
    }else{
      if(r == 1){
        somatorio_print.tamanho = 0;
      }
    }
}
