//
// Created by vinicius on 31/10/2019.
//

#ifndef TP220192CCF211_TADMOCHILA_H
#define TP220192CCF211_TADMOCHILA_H

#endif //TP220192CCF211_TADMOCHILA_H

#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int peso;
    int valorImportancia;
}tupla;

void print(const int *v, const int size);
void visit(int *Value, int N, int k);
long long gcd(long long a, long long b);
long long binom(long long n, long long p);
