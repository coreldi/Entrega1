#ifndef PASO3_H
#define PASO3_H


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
void imprimir_uso(char *str);


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
 *   La función devuelve 0 si no se cumple con ninguna de las condiciones
 *   para considerar que los argumentos de entrada son los exigidos o se
 *   encuentran en el orden correcto, según las especificiones del programa.
 */
int procesar_args(int ac, char **av);


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
void my_handler(int signo);


#endif
