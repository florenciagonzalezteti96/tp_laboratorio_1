/** \brief Esta funcion muestra en la pantalla de la consola un menu para realizar el ingreso de operandos y operaciones matematicas sobre los mismos.
 *
 * \param void No recibe ningun parametro.
 * \return void No devuelve ningun valor.
 *
 */
void showOptionMenu(void);
/** \brief Esta funcion pide y devuelve un entero.
 *
 * \param message char* Mensaje de ingreso de un numero.
 * \return int El numero ingresado.
 *
 */
int getInt(char* message);
/** \brief Esta funcion pide y devuelve un numero flotante.
 *
 * \param message char* Mensaje de ingreso de un numero.
 * \return float El numero ingresado.
 *
 */
float getFloat(char* message);
/** \brief Esta funcion verifica que el numero ingresado sea un entero o no.
 *
 * \param float number Numero que recibe para validar.
 * \return int Devuelve uno [1] si el numero ingresado es un entero o cero [0] si no lo es.
 *
 */
int isInt (float number);
