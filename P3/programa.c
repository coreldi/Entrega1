#include "paso1.h"
#include "paso2.h"
#include "paso3.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <libgen.h>


/* Variables globales */
char * num_hijos, * quantum;
int * pid_hijos, n, q, hijo_actual = 0;


/* int main ( int ac, char ** av );
 *
 * DESCRIPCIÓN:
 *   Este programa recibe varios argumentos y 
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
    /* Mostrar mensaje de ayuda si el número de argumentos es incorrecto */
    char * myself = basename(av[0]);
    if (ac != 3 && ac != 5) {
        imprimir_uso(myself);
    }

    /* Procesar argumentos de la línea de comandos */
    if (procesar_args(ac, av) == 0) {
        imprimir_uso(myself);
    }

    /* Comprueba la validez de los argumentos */
    if (es_natural(num_hijos) == 0 || es_natural(quantum) == 0) {
        fprintf(stderr, "Argumentos deben ser números mayores que 0\n");
        exit(EXIT_FAILURE);
    } else {
        n = strtol(num_hijos, NULL, 10);
        q = strtol(quantum, NULL, 10);
    }

    /* Crea la cantidad de hijos especificada y los manda parar */
    pid_hijos = (int *) malloc(n * sizeof(int));
    if (pid_hijos == NULL) {
        fprintf(stderr, "Error con malloc()\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < n; i++) {
        pid_t pid = fork();
        if (pid < 0) {
            fprintf(stderr, "Error con fork()\n");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            hijo(num_hijos, i);
        } else {
            pid_hijos[i] = pid;
            kill(pid, SIGSTOP);
        }
    }

    /* Asignamos comportamiento a la señal SIGALRM */
    if (signal(SIGALRM, my_handler) == SIG_ERR) {
        fprintf(stderr, "Error con signal()\n");
        exit(EXIT_FAILURE);
    }

    /* Continuamos el primer proceso e iniciamos temporizador de quantum segundos */
    kill(pid_hijos[hijo_actual], SIGCONT);
    alarm(q);

    /* Espera hasta recibir una señal */
    while(1) {
        pause();
    }

    /* Inalcanzable por el bucle infinito */
    exit(EXIT_SUCCESS);
}
