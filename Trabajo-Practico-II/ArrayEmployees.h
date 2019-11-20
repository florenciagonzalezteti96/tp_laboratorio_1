#define TRUE 0
#define FALSE 1

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "ctype.h"
#include "inputs.h"

typedef struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
}Employee;

/** \brief Esta funcion muestra un menu de opciones para un programa de altas, bajas y modificaciones de empleados
 *
 * \param list Employee*  Recibe un puntero a un array de empleados
 * \param len int Recibe el largo del array de empleados
 * \return void
 *
 */
void showMenu(Employee* list, int len);
/** \brief Esta funcion muestra un conjunto de datos de empleado.
 *
 * \param name[] char Recibe el nombre del empleado
 * \param lastName[] char Recibe el apellido del empleado
 * \param salary float Recibe el salario del empleado
 * \param sector int Recibe el sector del empleado
 * \return void
 *
 */
void showData(char name[],char lastName[],float salary,int sector);
/** \brief Esta funcion muestra a un empleado existente dentro de la lista
 *
 * \param sEmployee Employee Recibe el empleado a mostrar
 * \return void
 *
 */
void showOneEmployee(Employee sEmployee);
/** \brief Esta funcion muestra el contenido de un array de empleados
 *
 * \param lista Employee* Recibe el puntero al array de empleados
 * \param len int Recibe el largo del array de empleados
 * \return int Devuelve 0 si realizo el mostrar o -1 (si el largo del array es invalido o el puntero al array es NULL).
 *
 */
int printEmployees(Employee* list, int len);

/** \brief Esta funcion inicializa la bandera (isEmpty) de todos los lugares del array de empleados en TRUE para indicar que todos los lugares esta vacios
 *
 * \param list Employee* Recibe un puntero a array de empleados
 * \param len int Recibe el largo del array
 * \return int Devuelve 0 si realizo la inicializacion o -1 (si el largo del array es invalido o el puntero al array es NULL).
 *
 */
int initEmployees(Employee* list, int len);
/** \brief Esta funcion inicializa los ids de todos los lugares del array de empleados en 0
 *
 * \param list Employee* Recibe un puntero a array de empleados
 * \param len int Recibe el largo del array
 * \return int Devuelve 0 si realizo la inicializacion o -1 (si el largo del array es invalido o el puntero al array es NULL).
 *
 */
int initIds(Employee* list, int len);
/** \brief Esta funcion carga datos del empleado en un lugar disponible dentro del array
 *
 * \param list Employee* Recibe un puntero a array de empleados
 * \param len int Recibe el largo del array
 * \return int Devuelve 1 (si el largo del array es invalido o el puntero al array es NULL), -1 (no hay lugar disponible), 0 (logro cargar al empleado dentro del array) o 2 (el usuario decidio cancelar la carga)
 *
 */
int loadEmployee(Employee* list, int len);
/** \brief Esta funcion agrega en una lista de empleados existente, en la primera posicion libre, los valores recibidos como parametros
 *
 * \param list Employee* Recibe un puntero a array de empleados
 * \param len int Recibe el largo del array de empleados
 * \param id int Recibe el id del empleado nuevo
 * \param name[] char Recibe el nombre del empleado nuevo
 * \param lastName[] char Recibe el apellido del empleado nuevo
 * \param salary float Recibe el salario del empleado nuevo
 * \param sector int Recibe el sector del empleado nuevo
 * \return int Devuelve 0 si logro cargar o -1 (si no hay lugar disponible, si el largo del array es invalido o si el puntero al array es NULL)
 *
 */
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);
/** \brief Esta funcion busca el primer lugar libre en un array de empleados
 *
 * \param list Employee* Recibe un puntero a array de empleados
 * \param len int Recibe el largo del array de empleados
 * \return int Devuelve el indice del primer lugar libre dentro del array de empleados o -1 (si no hay lugar disponible, si el largo del array es invalido o si el puntero al array es NULL)
 *
 */
int getIsEmpty(Employee* list, int len);
/** \brief Esta funcion busca si hay al menos un lugar ocupado en el array
 *
 * \param list Employee* Recibe un puntero a array de empleados
 * \param len int Recibe el largo del array de empleados
 * \return int Devuelve el 0 o -1 (si no hay lugar ocupado, si el largo del array es invalido o si el puntero al array es NULL)
 *
 */
int getIsOccupied(Employee* list, int len);
/** \brief Esta funcion pide los datos de un empleado y los guarda en las variables recibidas como parametro
 *
 * \param name[] char El nombre del empleado
 * \param lastName[] char El apellido del empleado
 * \param salary float* Un puntero a float que es el salario del empleado
 * \param sector int* Un puntero a int que es el sector del empleado
 * \return void
 *
 */
void getDataEmployee(char name[],char lastName[],float* salary,int* sector);
/** \brief Esta funcion busca a un empleado por id y devuelve la posicion del empleado dentro del array de empleados
 *
 * \param list Employee* Recibe un puntero a un array de empleados
 * \param len int Recibe el largo del array de empleados
 * \param id int Recibe el id del empleado a buscar
 * \return int Devuelve el indice del empleado o -1 (si no encontro al empleado, si el largo del array es invalido o si el puntero al array es NULL)
 *
 */
int findEmployeeById(Employee* list, int len,int id);
/** \brief Esta elimina un empleado por ID
 *
 * \param list Employee* Recibe un puntero a un array de empleados
 * \param len int Recibe el largo del array de empleados
 * \param id int Recibe el id del empleado a eliminar
 * \return int Devuelve 0 si realizo la eliminacion o -1 (si no encontro al empleado, si el largo del array es invalido o si el puntero al array es NULL)
 *
 */
int removeEmployee(Employee* list, int len, int id);
/** \brief  Ordena los elementos del array de empleados, el parametro order indice orden ascendente o descendente
 *
 * \param list Employee* Recibe un puntero a un array de empleados
 * \param len int Recibe el largo del array de empleados
 * \param order int 1 indica orden ascendente y 0 indica orden descendente
 * \return int Devuelve 0 si logro ordenar o -1 (si el largo del array es invalido o si el puntero al array es NULL)
 *
 */
int sortEmployees(Employee* list, int len, int order);
/** \brief Esta funcion crea un submenu de modificaciones a un empleado del array
 *
 * \param list Employee* Recibe un puntero a un array de empleados
 * \param len int Recibe el largo del array de empleados
 * \return int Devuelve 0 si logro ordenar o -1 (si el largo del array es invalido o si el puntero al array es NULL o si no encontro al empleado)
 *
 */
int modificarEmpleado(Employee* list, int len);
/** \brief Esta funcion calcula el total de los salarios
 *
 * \param list Employee* Recibe un puntero a un array de empleados
 * \param len int Recibe el largo del array de empleados
 * \return float El total de los salarios
 *
 */
float getTotalSalarios(Employee* list, int len);
/** \brief Esta funcion calcula los empleados cuyo salario es mayor al promedio y los muestra
 *
 * \param list Employee* Recibe un puntero a un array de empleados
 * \param len int Recibe el largo del array de empleados
 * \return int Devuelve 1 si encontro al menos un empleado o -1 (si el largo del array es invalido, si el puntero al array es NULL o no encontro a ningun empleado con salario mayor al promedio)
 *
 */
int getMaximoSalario(Employee* list, int len);
/** \brief Esta funcion calcula el promedio de los salarios de los empleados
 *
 * \param list Employee* Recibe un puntero a un array de empleados
 * \param len int Recibe el largo del array de empleados
 * \return float Devuelve el salario promedio o -1 (si el largo del array es invalido, si el puntero al array es NULL o no encontro a ningun empleado)
 *
 */
float getPromedioSalarios(Employee* list, int len);
/** \brief Esta funcion muestra un submenu de informes sobre salarios y opcion para ordenar la lista de empleados
 *
 * \param list Employee* Recibe un puntero a un array de empleados
 * \param len int Recibe el largo del array de empleados
 * \return int Devuelve 0 si pudo entrar al menu -1 (si el largo del array es invalido, si el puntero al array es NULL) o 1 si no pudo realizar el ordenamiento.
 *
 */
int informarEmpleado(Employee* list, int len);
/** \brief Esta funcion muestra un submenu con informes sobre los salarios de empleados
 *
 * \param list Employee* Recibe un puntero a un array de empleados
 * \param len int Recibe el largo del array de empleados
 * \return void
 *
 */
void menuInformesSalarios(Employee* list, int len);
/** \brief Esta funcion muestra la lista de empleados existentes y realiza la eliminacion de un empleado o no, dependiendo de lo que elija el usuario.
 *
 * \param list Employee* Recibe un puntero a un array de empleados
 * \param len int Recibe el largo del array de empleados
 * \return int Devuelve -1 si (si el largo del array es invalido, si el puntero al array es NULL), 1 si no encontro al empleado por ID, 0 si pudo eilminar al empleado, 2 si el usuario cancelo la accion para eliminar.
 */
int deleteEmployee(Employee* list, int len);

