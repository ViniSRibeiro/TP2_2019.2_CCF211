#include "TadMochila.h"

void comb(tupla *arr, size_t n, size_t index){
    size_t k;
    if (index == n) {
        /* array vazio, imprime o que está "para trás" */
        printf("(%d %d) ", arr[0]);
        for (k = 1; k < n; k++) printf("(%d %d) ", arr[k]);
        puts("");
        return;
    }
    for (k = index; k < n; k++) {
        tupla tmp;
        /* mete cada um dos elementos ao principio */
        tmp = arr[k];
        arr[k] = arr[index];
        arr[index] = tmp;

        /* recursividade! */
        comb(arr, n, index + 1);

        /* repoe posicao inicial */
        tmp = arr[k];
        arr[k] = arr[index];
        arr[index] = tmp;
    }
}
