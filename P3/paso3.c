#include "paso3.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>


/* Variables globales */
extern char * num_hijos, * quantum;
extern int * pid_hijos, n, q, hijo_actual;


/* void imprimir_uso ( char * str );
 *
 * DESCRIPCIÓN:
 *   Esta función imprime por la salida de error estándar un mensaje de ayuda
 *   indicando la forma de introducir los argumentos por la línea de comandos,
 *   para después finalizar el programa.
 *
 * PARÁMETROS:
 *      'str': Cadena de texto que indica el nombre del programa (av[0]).
 */
void imprimir_uso(char *str) {
    fprintf(stderr, "Uso: %s -n <num_hijos> -q [<quantum>]\n", str);
    fprintf(stderr, "   <num_hijos>: Número de hijos que deberá crear el programa\n");
    fprintf(stderr, "     <quantum>: Longitud de la ranura temporal\n");
    fprintf(stderr, "                (1 segundo por defecto)\n\n");
    exit(EXIT_FAILURE);
}


/* int procesar_args ( int ac, char ** av );
 *
 * DESCRIPCIÓN:
 *   Esta función analiza los argumentos introducidos para verificar si coinciden
 *   con las especificaciones del programa.
 *
 * PARÁMETROS:
 *       'ac': Número de argumentos totales introducidos por la línea de comandos.
 *       'av': Array de cadenas de texto conteniendo los argumentos introducidos
 *             por la línea de comandos.
 *
 * VALOR DEVUELTO:
 *   Se devuelve 1 si la lectura de los argumentos de entrada ha sido correcta.
 *
 * ERRORES:
 *   La función devuelve 0 si no se cumple con las condiciones para considerar
 *   que los argumentos de entrada son los exigidos o se encuentran en el orden
 *   correcto, según las especificiones del programa.
 */
int procesar_args(int ac, char **av) {
    if (ac == 3 && strcmp(av[1], "-n") == 0) {
        num_hijos = av[2];
        quantum = "1";
    } else if (ac == 5 && strcmp(av[1], "-n") == 0 && strcmp(av[3], "-q") == 0) {
        num_hijos = av[2];
        quantum = av[4];
    } else if (ac == 5 && strcmp(av[1], "-q") == 0 && strcmp(av[3], "-n") == 0) {
        num_hijos = av[4];
        quantum = av[2];
    } else {
        return 0;
    }

    return 1;
}


/* void my_handler ( int signo );
 *
 * DESCRIPCIÓN:
 *   Esta función hace de manejador de señales, en el caso de este programa,
 *   su funcionalidad consiste en mandar parar a un proceso de una lista, mandar
 *   continuar al siguiente y relanzar la función alarm().
 *  
 * PARÁMETROS:
 *    'signo': Recibe el número asociado a la señal atrapada.
 */
void my_handler(int signo) {
    if (signo == SIGALRM) {
        kill(pid_hijos[hijo_actual], SIGSTOP);
        hijo_actual = (hijo_actual + 1) % n;
        kill(pid_hijos[hijo_actual], SIGCONT);
        alarm(q);
    }
}
