#include "TadMochila.h"
int CAPACIDADE = 40;
Tsomatorio somatorio, somatorio_print,somatorio_final;

void printCombination(Ttupla arr[], int n, int r,int c)
{
    Ttupla data[r];
    int i;
    combinationUtil(arr, data, 0, n-1, 0, r);

    //  printf("------------------------------------------------\n");
    //  printf("* Peso Agregado: %d                             *\n",somatorio_print.peso_Agregado);
    //  printf("* Valor Agregado: %d                            *\n",somatorio_print.valor_Agregado);

    if (c == 0) {
      printf("\n");
      printf("Peso agregado da melhor combinacao: %d\n",somatorio_final.peso_Agregado );
      printf("Valor agregado da melhor combinacao: %d\n",somatorio_final.valor_Agregado );
      printf("Tamanho da combinação: %d\n", somatorio_final.tamanho);
      for (i = 0; i < somatorio_final.tamanho; i++) {
        printf("(%d %d) ", somatorio_final.combinacao_atual[i].peso,somatorio_final.combinacao_atual[i].valorImportancia);
      }
      printf("\n");
    }
}

void combinationUtil(Ttupla arr[], Ttupla data[], int start, int end, int index, int r)
{
  int j,count;
  somatorio.peso_Agregado = 0;
  somatorio.tamanho = 0;
  somatorio.valor_Agregado = 0;

    if (index == r)
    {
        for (j=0; j<r; j++){
            //printf("(%d %d) ", data[j].peso,data[j].valorImportancia);
            somatorio.peso_Agregado += data[j].peso;
            somatorio.valor_Agregado += data[j].valorImportancia;
            if(somatorio.peso_Agregado <= CAPACIDADE && somatorio.valor_Agregado >somatorio_print.valor_Agregado) {
                somatorio_print.peso_Agregado = somatorio.peso_Agregado;
                somatorio_print.valor_Agregado = somatorio.valor_Agregado;
                if(somatorio_print.valor_Agregado > somatorio_final.valor_Agregado && somatorio_print.peso_Agregado <= CAPACIDADE){
                    somatorio_final.peso_Agregado = somatorio_print.peso_Agregado;
                    somatorio_final.valor_Agregado = somatorio_print.valor_Agregado;
                    somatorio_final.tamanho = r;
                    for (count = 0; count < r ;count++ ) {
                        somatorio_final.combinacao_atual[count].peso = data[count].peso;
                        somatorio_final.combinacao_atual[count].valorImportancia = data[count].valorImportancia;

                    }
                }
            }
        }
        //printf("\n");

        return;
    }

    for (int i=start; i<=end && end-i+1 >= r-index; i++)
    {

        data[index] = arr[i];
        combinationUtil(arr, data, i+1, end, index+1, r);
    }
}
