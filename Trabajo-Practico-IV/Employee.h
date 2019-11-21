#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "inputs.h"

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
} Employee;

/** \brief Esta funcion crea un puntero a un tipo de dato Employee e inicializa los campos del dato
 *
 * \return Employee* Devuelve NULL si no encontro espacio en memoria para el nuevo dato, caso contrario devuelve puntero a Employee
 *
 */
Employee* employee_new();
/** \brief Esta funcion crea un puntero a un tipo de dato Employee y setea los campos del dato
 *
 * \param idStr char* el id del empleado
 * \param nombreStr char* el nombre del empleado
 * \param horasTrabajadasStr char* la cantidad de horas trabajadas del empleado
 * \param sueldoStr char* el sueldo del empleado
 * \return Employee* Devuelve NULL si los punteros de los parametros recibidos son nulos o si no se encontro espacio en memoria para el nuevo dato, caso contrario devuelve al empleado
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);

/** \brief Esta funcion muestra en pantalla a un empleado
 *
 * \param employee Employee* el empleado a mostrar
 * \return int devuelve -1 si el puntero al empleado a mostrar es nulo, caso contrario devuelve 0
 *
 */
int showOneEmployee(Employee* employee);

/** \brief Esta funcion setea el id del empleado
 *
 * \param this Employee* el empleado
 * \param id int el id del empleado
 * \return int Devuelve -1 si el puntero al empleado es nulo, caso contrario devuelve 0
 *
 */
int employee_setId(Employee* this,int id);
/** \brief Esta funcion busca y retorna el id de un empleado
 *
 * \param this Employee* el empleado
 * \param id int* el id del empleado
 * \return int Devuelve -1 si el puntero al empleado o al id son nulos, caso contrario devuelve 0
 *
 */
int employee_getId(Employee* this,int* id);

/** \brief Esta funcion setea el nombre del empleado
 *
 * \param this Employee* el empleado
 * \param nombre char* el nombre del empleado
 * \return int Devuelve -1 si el puntero al empleado es nulo, caso contrario devuelve 0
 *
 */
int employee_setNombre(Employee* this,char* nombre);
/** \brief Esta funcion busca y retorna el nombre de un empleado
 *
 * \param this Employee* el empleado
 * \param nombre char* el nombre del empleado
 * \return int Devuelve -1 si el puntero al empleado o al nombre son nulos, caso contrario devuelve 0
 *
 */
int employee_getNombre(Employee* this,char* nombre);

/** \brief Esta funcion setea la cantidad de horas trabajadas del empleado
 *
 * \param this Employee* el empleado
 * \param horasTrabajadas int la cantidad de horas trabajadas del empleado
 * \return int Devuelve -1 si el puntero al empleado es nulo, caso contrario devuelve 0
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
/** \brief Esta funcion busca y retorna la cantidad de horas trabajadas de un empleado
 *
 * \param this Employee* el empleado
 * \param horasTrabajadas int* la cantidad de horas trabajadas del empleado
 * \return int Devuelve -1 si el puntero al empleado o a las horas trabajadas son nulos, caso contrario devuelve 0
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/** \brief Esta funcion setea sueldo del empleado
 *
 * \param this Employee* el empleado
 * \param sueldo int el sueldo del empleado
 * \return int Devuelve -1 si el puntero al empleado es nulo, caso contrario devuelve 0
 *
 */
int employee_setSueldo(Employee* this,int sueldo);
/** \brief Esta funcion busca y retorna el sueldo de un empleado
 *
 * \param this Employee* el empleado
 * \param sueldo int* el sueldo del empleado
 * \return int Devuelve -1 si el puntero al empleado o al sueldo son nulos, caso contrario devuelve 0
 *
 */
int employee_getSueldo(Employee* this,int* sueldo);

/** \brief Esta funcion establece un criterio de comparacion para ordenar a una lista de empleados por ID
 *
 * \param pElementOne void* El primer empleado a comparar
 * \param pElementTwo void* El segundo empleado a comparar
 * \return int Devuelve 1 si el primero es mayor al segundo, si son iguales devuelve 0
 *
 */
int compareById(void* pElementOne, void* pElementTwo);
/** \brief Esta funcion establece un criterio de comparacion para ordenar a una lista de empleados por salario
 *
 * \param pElementOne void* El primer empleado a comparar
 * \param pElementTwo void* El segundo empleado a comparar
 * \return int Devuelve 1 si el primero es mayor al segundo, si son iguales devuelve 0
 *
 */
int compareBySalary(void* pElementOne, void* pElementTwo);
/** \brief Esta funcion establece un criterio de comparacion para ordenar a una lista de empleados por nombre
 *
 * \param pElementOne void* El primer empleado a comparar
 * \param pElementTwo void* El segundo empleado a comparar
 * \return int Devuelve 1 si el primero es mayor al segundo, si son iguales devuelve 0
 *
 */
int compareByName(void* pElementOne, void* pElementTwo);
/** \brief Esta funcion establece un criterio de comparacion para ordenar a una lista de empleados por cantidad de horas trabajadas
 *
 * \param pElementOne void* El primer empleado a comparar
 * \param pElementTwo void* El segundo empleado a comparar
 * \return int Devuelve 1 si el primero es mayor al segundo, si son iguales devuelve 0
 *
 */
int compareByHoursWorked(void* pElementOne, void* pElementTwo);

/** \brief Esta funcion elimina a un empleado
 *
 * \param employee Employee* el empleado a eliminar
 * \return void
 *
 */
void employee_delete(Employee* employee);

/** \brief Esta funcion pide los datos de un empleado
 *
 * \param nombre char* el nombre del empleado
 * \param horasTrabajadas char* la cantidad de horas trabajadas del empleado
 * \param salario char* el salario del empleado
 * \return void
 *
 */
void pedirDatosEmpleado(char* nombre, char* horasTrabajadas, char* salario);

#endif // employee_H_INCLUDED
