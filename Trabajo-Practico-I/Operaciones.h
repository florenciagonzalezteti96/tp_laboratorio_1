/** \brief Esta funcion recibe dos numeros flotantes y los suma.
 *
 * \param float Primer numero flotante.
 * \param float Segundo numero flotante.
 * \return float Resultado de la suma.
 *
 */
float addNumbers (float, float);
/** \brief Esta funcion recibe dos numeros flotantes y los resta.
 *
 * \param float Primer numero flotante.
 * \param float Segundo numero flotante.
 * \return float Resultado de la resta.
 *
 */
float subtractNumbers(float, float);
/** \brief Esta funcion recibe dos numeros flotantes y los divide.
 *
 * \param float Primer numero flotante.
 * \param float Segundo numero flotante.
 * \param errorMessage char* Mensaje de error en caso que la division no se pueda realizar (si el segundo numero es un cero).
 * \return float Resultado de la division.
 *
 */
float  divideNumbers (float, float, char* errorMessage);
/** \brief Esta funcion recibe dos numeros flotantes y los multiplica.
 *
 * \param float Primer numero flotante.
 * \param float Segundo numero flotante.
 * \return float Resultado de la multiplicacion.
 *
 */
float  multiplyNumbers (float, float);
/** \brief Esta funcion recibe un numero flotante y realiza el factoreo del mismo.
 *
 * \param float Numero para factorizar.
 * \return int Resultado del factoreo.
 *
 */
int  getFactorial (float);
