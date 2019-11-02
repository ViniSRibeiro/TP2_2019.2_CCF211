#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int peso;
  int valorImportancia;
}Ttupla;

typedef struct{
  int tamanho;
  int peso_Agregado;
  int valor_Agregado;
  Ttupla combinacao_atual[40];
}Tsomatorio;

int fatorial(int n);
int comparacao(int n,int p);
void printCombination(Ttupla arr[], int n, int r,int c);
void combinationUtil(Ttupla arr[], Ttupla data[], int start, int end,int index, int r);
