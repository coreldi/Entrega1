#ifndef PASO1_H
#define PASO1_H


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
int es_natural(char *str);


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
void imprimir(int entrada);


#endif
