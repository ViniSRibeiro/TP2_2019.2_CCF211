#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include "TadMochila.h"
//-gcc -o teste main.c TadMochila.c TadMochila.h
/* Tamanho máximo da entrada */
#define MAX_INPUT 100

int main() {
    unsigned MAX, MASK, NUM ;
    int i, j, r, k, total = 0,total_maior = 0 ;
    /* Armazena a string de entrada. */
    char input[MAX_INPUT] ;
    /* Armazena cada combinação. */
    char str[sizeof(input)],str_print[sizeof(input)] ;

    printf("Digite o grupo inicial: ") ;
    scanf("%s", input) ;

    printf("Digite o r: ") ;
    scanf("%d", &r) ;
    for (int l = 1; l <= r; ++l) {
        /* Manda o bit 1 para a n-ésima posição.
    * Os bits são invertidos para que a posição n
    * esteja com o bit zero, a fim de marcar
    * o final do processo.
    */
        MAX = ~(1 << strlen(input)) ;

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

                str[i]=0 ;
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
