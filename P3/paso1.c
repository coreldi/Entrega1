#include "paso1.h"

#include <stdio.h>
#include <string.h>
#include <unistd.h>


/* int es_natural ( char * str );
 *
 * DESCRIPCIÓN:
 *   Esta función analiza una cadena de texto para comprobar si se trata
 *   de un número natural distinto de cero.
 *
 * PARÁMETROS:
 *      'str': La cadena de texto que se desea procesar.
 *
 * VALOR DEVUELTO:
 *   Se devuelve 1 si la cadena de texto representaba un número natural
 *   distinto de cero.
 *
 * ERRORES:
 *   La función devuelve 0 si la cadena de texto no había sido inicializada,
 *   si no se trataba de un número natural o si el número era cero.
 */
int es_natural(char *str) {
    if (!str) {
        return 0;
    }

    int l = strlen(str), i = 0;
    while (*str) {
        if (*str < '0' || *str > '9') {
            return 0;
        } else if (*str == '0') {
            i++;
        }
        str++;
    }

    if (l == i) {
        return 0;
    }

    return 1;
}


/* void imprimir ( int entrada );
 *
 * DESCRIPCIÓN:
 *   Esta función permite imprimir por salida estándar un bucle infinito de
 *   líneas conteniendo información relacionada con el pid del proceso en
 *   ejecución, el número pasado como entrada a la función y la iteración en
 *   la que se encuentra.
 *
 * PARÁMETROS:
 *  'entrada': Número de "+" que se quiere imprimir.
 */
void imprimir(int entrada) {
    int iter = 0;
    pid_t pid = getpid();

    while(1) {
        printf("[%d] Proceso %d ", pid, entrada);
        for(int i = 0; i < entrada; i++) {
            printf("+");
        }
        printf(" iter %d\n", iter);
        iter++;
    }
}
/*Bucle limitado a 5 iteraciones
void imprimir(int entrada) {
    int iter = 0;
    pid_t pid = getpid();

    for (int i = 0; i < 5; i++) {
        printf("[%d] Proceso %d ", pid, entrada);
        for(int j = 0; j < entrada; j++) {
            printf("+");
        }
        printf(" iter %d\n", iter);
        iter++;
    }
}*/
