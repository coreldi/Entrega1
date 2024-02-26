#ifndef PASO2_H
#define PASO2_H


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
void hijo(char *str, int n);


#endif
