#include "paso1.h"
#include "paso2.h"

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>


/* int main ( int ac, char ** av );
 *
 * DESCRIPCIÓN:
 *   Este programa recibe un argumento y comprueba que sea un número
 *   natural distinto de cero. Después crea el número de hijos que ha
 *   sido introducido como argumento y carga el código del paso
 *   anterior mediante un execlp(). El proceso padre manda parar a
 *   todos los procesos hijos  mediante una señal.
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

    /* Compruebala validez del argumento */
    if (es_natural(input) == 0) {
        fprintf(stderr, "Argumento no entero o menor que 1\n");
        exit(EXIT_FAILURE);
    }
    
    /* Crea los hijos y ejecutan la función hijo() */
    int pid_hijos[n], i;
    for (i = 0; i < n; i++) {
        pid_t pid = fork();
        if (pid < 0) {
            fprintf(stderr, "Error con fork()\n");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            hijo(input, i);
        } else {
            pid_hijos[i] = pid;
        }
    }

    /* Comprueba la creación de los hijos y los manda parar */
    if(i != n) {
        fprintf(stderr, "No todos los hijos creados (%d/%d)\n", i, n);
        kill(-getpid(), SIGKILL);
    } else {
        for(int j = 0; j < n; j++) {
            printf("Mando parar a mi hijo [%d]\n", pid_hijos[j]);
            kill(pid_hijos[j], SIGSTOP);
        }
    }

    /* Terminación del programa */
    printf("Con mis hijos parados yo, [%d], termino\n", getpid());
    exit(EXIT_SUCCESS);
}
