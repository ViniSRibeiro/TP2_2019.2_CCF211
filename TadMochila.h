#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <syscall.h>
#define CAPACIDADE  40
typedef struct{
  int peso;
  int valorImportancia;
}Ttupla;

typedef struct{
  int tamanho;
  int peso_Agregado;
  int valor_Agregado;
  Ttupla combinacao_atual[CAPACIDADE];
}Tsomatorio;

void printCombination(Ttupla arr[], int n, int r, int c, int option);
void combinationUtil(Ttupla arr[], Ttupla data[], int start, int end,int index, int r);
