#include "paso1.h"

#include <stdio.h>
#include <stdlib.h>


/* int main ( int ac, char ** av );
 *
 * DESCRIPCIÓN:
 *   Este programa recibe un argumento y comprueba que sea un número
 *   natural distinto de cero. Seguidamente imprime en un bucle infinto
 *   una línea con la siguiente información:
 *   [%MiPID] Proceso %ARG_ENTRADA [+] iter %NUM_ITERACION
 *
 * PARÁMETROS:
 *   'ac': Número de parámetros pasados al programa por la línea de
 *           comandos, incluyendo el propio nombre del programa.
 *   'av': Array con los parámetros pasado al programa por línea de
 *           comandos.
 *           El primer parámetro (argv[0]) es el nombre del programa.
 *
 * VALOR DEVUELTO:
 *   Código de salida del programa.
 */
int main (int ac, char **av) {
    /* Comprueba que el programa reciba exactamente 1 argumento */
	if (ac != 2) {
        fprintf(stderr, "Nº de argumentos incorrecto\n");
        exit(EXIT_FAILURE);
	}

    /* Procesar argumento de la línea de comandos */
    char * input = av[1];
    int n = strtol(input, NULL, 10);

    /* Comprueba el argumento e imprime el mensaje */
    if (es_natural(input) == 0) {
        fprintf(stderr, "Argumento no entero o menor que 1\n");
        exit(EXIT_FAILURE);
    } else {
        imprimir(n);
    }
    
    /* Inalcanzable por el bucle infinito */
    exit(EXIT_SUCCESS);
}
