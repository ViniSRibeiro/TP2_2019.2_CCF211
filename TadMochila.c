#include "TadMochila.h"
int CAPACIDADE = 100;
Tsomatorio somatorio, somatorio_print;

void printCombination(Ttupla arr[], int n, int r,int c)
{
    Ttupla data[r];
    combinationUtil(arr, data, 0, n-1, 0, r);
    printf("------------------\n");
    printf("Peso Agregado: %d\n",somatorio_print.peso_Agregado);
    printf("Valor Agregado: %d\n",somatorio_print.valor_Agregado);
    if (c == 0) {
      printf("colocar nesse local as variaveis para o print final FINAL\n");
    }
    //printf("c = %d\n",c);
}

void combinationUtil(Ttupla arr[], Ttupla data[], int start, int end, int index, int r)
{
  int j;
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
                //somatorio_print.combinacao_atua
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
