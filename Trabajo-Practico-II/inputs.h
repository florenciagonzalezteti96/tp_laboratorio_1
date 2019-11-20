#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "ctype.h"

/** \brief Esta funcion pide un entero y lo devuelve
 *
 * \param mensaje char* El mensaje de ingreso
 * \return int El entero ingresado
 *
 */
int getInt(char *mensaje);
/** \brief Esta funcion valida si el valor ingresado es un entero o no
 *
 * \param numero int* El valor ingresado
 * \param mensaje char* El mensaje de ingreso
 * \return int Devuelve -1 si no es un entero o es un entero mas otro valor no entero, o 0 si es todo entero
 *
 */
int getValidInt(int* numero, char *mensaje);

/** \brief Esta funcion pide un caracter y lo devuelve
 *
 * \param mensaje[] char El mensaje de ingreso
 * \return char El caracter ingresado
 *
 */
char getChar(char mensaje[]);
/** \brief Esta funcion valida que el valor ingresado sea un caracter
 *
 * \param letra char* El valor ingresado
 * \return int Devuelve 1 si no es una letra, o 0 si lo es
 *
 */
int getValidChar(char* letra);
/** \brief Esta funcion pide el ingreso de 's' o de 'n' para pedir confirmacion
 *
 * \param mensaje[] char El mensaje de ingreso
 * \return char El caracter ingresado
 *
 */
char getConfirmacion(char mensaje[]);
/** \brief Esta funcion pide un string y lo guarda en una cadena
 *
 * \param mensaje[] char El mensaje de ingreso
 * \param cadena[] char La cadena de destino del string ingresado
 * \return void
 *
 */
void getString(char mensaje[], char cadena[]);
/** \brief Esta funcion verifica que el string ingresado consista solo de letras
 *
 * \param cadena[] char La cadena a validar
 * \return int Devuelve -1 si hay otros caracteres ademas de letras, o 0 si es solo letras
 *
 */
int getStringLetras(char cadena[]);
/** \brief Esta funcion pide un string y lo valida
 *
 * \param mensaje[] char El mensaje de ingreso
 * \param cadena[] char La cadena de destino del string ingresado
 * \return void
 *
 */
void pedirCadena (char mensaje[], char cadena[]);
/** \brief Esta funcion convierte la primera letra de un string a mayuscula y las demas a minuscula
 *
 * \param cadena[] char La cadena ingresada
 * \return void
 *
 */
void firstToUpper(char cadena[]);

/** \brief Esta funcion recibe un numero flotante y lo valida
 *
 * \param numero float* El numero a validar
 * \param mensaje char* El mensaje de ingreso
 * \return int Devuelve -1 si no pudo validar que sea un flotante o 0 si pudo
 *
 */
int getValidFloat(float* numero, char* mensaje);
/** \brief Esta funcion pide un flotante y lo valida
 *
 * \param mensaje[] char El mensaje de ingreso
 * \return float El numero flotante ingresado
 *
 */
float getFloat(char mensaje[]);
