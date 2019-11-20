#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Esta funcion carga una lista dinamica con datos de un archivo ya existente, en modo texto
 *
 * \param path char* La ruta y nombre del archivo desde donde se cargan los datos en la lista dinamica
 * \param pArrayListEmployee LinkedList* La lista dinamica
 * \return int Devuelve -1 si pudo realizar la carga de datos, 0 si logro abrir el archivo y cargar los datos, 1 si la lista o el puntero al archivo son nulos, 2 si la lista ya fue cargada.
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee);
/** \brief Esta funcion carga una lista dinamica con datos de un archivo ya existente, en modo binario
 *
 * \param path char* La ruta y nombre del archivo desde donde se cargan los datos en la lista dinamica
 * \param pArrayListEmployee LinkedList* La lista dinamica
 * \return int Devuelve -1 si pudo realizar la carga de datos, 0 si logro abrir el archivo y cargar los datos, 1 si la lista o el puntero al archivo son nulos, 2 si la lista ya fue cargada.
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee);
/** \brief Esta funcion permite la carga de un empleado a una lista dinamica
 *
 * \param pArrayListEmployee LinkedList* la lista dinamica
 * \param id int* El id del empleado a cargar
 * \return int Devuelve -1 si no pudo realizar la carga, 0 si pudo cargar al empleado, 1 si la lista es nula, 2 si el usuario cancelo la carga
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int* id);
/** \brief Esta funcion despliega un submenu que permite modificar a un empleado existente en una lista dinamica
 *
 * \param pArrayListEmployee LinkedList* la lista dinamica
 * \return int Devuelve -1 si la lista es nula, 0 si la lista esta vacia, el id del empleado no existe, 2 si se cargo al empleado con las modificaciones, 3 si el usuario cancelo la accion
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);
/** \brief Esta funcion permite eliminar a un empleado de una lista dinamica
 *
 * \param pArrayListEmployee LinkedList* la lista dinamica
 * \return int Devuelve -1 si no pudo eliminar al empleado, 0 si logro eliminar al empleado, 1 si la lista es nula, 2 si el usuario cancelo la accion, 3 si el id del empleado no existe, 4 si la lista esta vacia
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);
/** \brief Esta funcion lista los empleados cargados en una lista dinamica
 *
 * \param pArrayListEmployee LinkedList* la lista dinamica
 * \return int Devuelve -1 si la lista es nula, 0 si logro listar, 1 si la lista esta vacia,
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);
/** \brief Esta funcion despliega un submenu que permite ordenar a los empleados cargados en una lista dinamica
 *
 * \param pArrayListEmployee LinkedList* la lista dinamica
 * \return int Devuelve -1 si la lista si no pudo ordenar, 0 si logro ordenar, 1 si la lista es nula, 2 si la lista esta vacia, 3 si el usuario cancelo el ordenamiento
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);
/** \brief Esta funcion permite guardar los cambios realizados a los datos cargados en una lista dinamica en modo texto
 *
 * \param path char* La ruta y nombre del archivo desde donde se cargan los datos en la lista dinamica
 * \param pArrayListEmployee LinkedList* La lista dinamica
 * \return int Devuelve -1 si la lista o el puntero al archivo son nulos, 0 si logro guardar los datos
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee);
/** \brief Esta funcion permite guardar los cambios realizados a los datos cargados en una lista dinamica en modo binario
 *
 * \param path char* La ruta y nombre del archivo desde donde se cargan los datos en la lista dinamica
 * \param pArrayListEmployee LinkedList* La lista dinamica
 * \return int Devuelve -1 si la lista o el puntero al archivo son nulos, 0 si logro guardar los datos
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee);
/** \brief Esta funcion recorre una lista dinamica con datos de tipo empleado y busca el mayor ID
 *
 * \param pArrayListEmployee LinkedList* la lista dinamica
 * \return int Devuelve -1 si la lista es nula, caso contrario devuelve el mayor id
 *
 */
int dameMayorId(LinkedList* pArrayListEmployee);
/** \brief Esta funcion calcula el id del proximo empleado a agregar en una lista dinamica
 *
 * \param pArrayListEmployee LinkedList* la lista dinamica
 * \return int Devuelve -1 si la lista es nula, caso contrario devuelve el proximo id
 *
 */
int dameProximoId(LinkedList* pArrayListEmployee);
/** \brief Esta funcion busca a un empleado por id, dentro de una lista dinamica, y si lo encuentra, lo retorna
 *
 * \param pArrayListEmployee LinkedList* la lista dinamica
 * \param id int el id del empleado a encontrar
 * \return void* Devuelve el empleado si lo encontro, caso contrario devuelve NULL
 *
 */
void* getEmployeeById(LinkedList* pArrayListEmployee, int id);

