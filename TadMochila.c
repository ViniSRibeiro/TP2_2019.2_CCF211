//
// Created by vinicius on 31/10/2019.
//

#include "TadMochila.h"
#include <string.h>
void print(const int *v, const int size)
{
    if (v != 0) {
        for (int i = 0; i < size; i++) {
            printf("%4d", v[i] );
        }
        printf("\n");
    }
} // print


void visit(int *Value, int N, int k)
{
    static int level = -1;
    level = level+1; Value[k] = level;

    if (level == N)
        print(Value, N);
    else
        for (int i = 0; i < N; i++)
            if (Value[i] == 0)
                visit(Value, N, i);

    level = level-1; Value[k] = 0;
}