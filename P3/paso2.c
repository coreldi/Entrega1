#include "paso2.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


/* void hijo ( char * str, int n );
 *
 * DESCRIPCIÓN:
 *   Esta función tiene una funcionalidad muy concreta que consiste en 
 *   lanzar el código de proceso.c (o de cualquier código especificado
 *   en execlp()) pasandole como argumento un número convertido a cade-
 *   na de texto.
 *
 * PARÁMETROS:
 *      'str': Cadena de texto usada para saber el tamaño del argumento de
 *             entrada usado en execlp().
 *        'n': Número que será el argumento de entrada usado en execlp().
 */
void hijo(char *str, int n) {
    char n_hijo[strlen(str)];
    sprintf(n_hijo, "%d", n + 1);
    execlp("./proceso", "proceso", n_hijo, NULL);
    fprintf(stderr,"Error con execlp()\n");
    _exit(EXIT_FAILURE);
}
