#include "TadMochila.h"
int CAPACIDADE = 100;
Tsomatorio somatorio, somatorio_print,somatorio_final;

void printCombination(Ttupla arr[], int n, int r,int c)
{
    Ttupla data[r];
  //  int i;
    combinationUtil(arr, data, 0, n-1, 0, r);
    printf("------------------------------------------------\n");
    printf("* Peso Agregado: %d                             *\n",somatorio_print.peso_Agregado);
    printf("* Valor Agregado: %d                            *\n",somatorio_print.valor_Agregado);
    /*for(i = 0 ; i < 40; i++){
      if(somatorio_print.combinacao_atual[i].peso > 0){
          printf("(%d %d) ",somatorio_print.combinacao_atual[i].peso,somatorio_print.combinacao_atual[i].valorImportancia);
      }
    }*/
    if (c == 0) {
      printf("colocar nesse local as variaveis para o print final FINAL\n");
    }
    //printf("c = %d\n",c);
}

void combinationUtil(Ttupla arr[], Ttupla data[], int start, int end, int index, int r)
{
  int j/*count = 0*/;
  somatorio.peso_Agregado = 0;
  somatorio.tamanho = 0;
  somatorio.valor_Agregado = 0;
/*
  somatorio_print.valor_Agregado = 0;
  somatorio_print.tamanho = 0;
  somatorio_print.peso_Agregado = 0;
  for(j = 0; j < 40; j++){
      somatorio_print.combinacao_atual[j].peso = -6;
      somatorio_print.combinacao_atual[j].valorImportancia = -6;
  }
*/
    if (index == r)
    {
        for (j=0; j<r; j++){
            printf("(%d %d) ", data[j].peso,data[j].valorImportancia);
            somatorio.peso_Agregado += data[j].peso;
            somatorio.valor_Agregado += data[j].valorImportancia;
            if(somatorio.peso_Agregado <= CAPACIDADE && somatorio.valor_Agregado >somatorio_print.valor_Agregado) {
                somatorio_print.peso_Agregado = somatorio.peso_Agregado;
                somatorio_print.valor_Agregado = somatorio.valor_Agregado;
                //somatorio_print.combinacao_atual[count].peso= data[j].peso;
                //somatorio_print.combinacao_atual[count].valorImportancia= data[j].peso;
                //count +=1;
            }
        }
        printf("\n");

        return;
    }

    for (int i=start; i<=end && end-i+1 >= r-index; i++)
    {

        data[index] = arr[i];
        combinationUtil(arr, data, i+1, end, index+1, r);
    }
}
