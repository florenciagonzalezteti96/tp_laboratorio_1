#include "Employee.h"

Employee* employee_new()
{
    Employee* this = (Employee*) malloc(sizeof(Employee));

    if(this != NULL)
    {
        this->id = 0;
        strcpy(this->nombre,"");
        this->horasTrabajadas = 0;
        this->sueldo = 0;
    }

    return this;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* this = employee_new();

    if(idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
    {
        if(this != NULL)
        {
            employee_setId(this, atoi(idStr));
            employee_setNombre(this, nombreStr);
            employee_setHorasTrabajadas(this, atoi(horasTrabajadasStr));
            employee_setSueldo(this, atoi(sueldoStr));
        }
    }

    return this;
}

void employee_delete(Employee* employee)
{
    free(employee);
    employee = NULL;
}

int showOneEmployee(Employee* employee)
{
    int retorno = -1;

    if(employee != NULL)
    {
        printf("%4d %18s %20d %20d\n", employee->id, employee->nombre, employee->horasTrabajadas, employee->sueldo);
        retorno = 0;
    }

    return retorno;
}

int employee_setId(Employee* this,int id)
{
    int retorno = -1;

    if(this != NULL)
    {
        this->id = id;
        retorno = 0;
    }

    return retorno;
}

int employee_getId(Employee* this,int* id)
{
    int retorno = -1;

    if(this != NULL && id != NULL)
    {
        *id = this->id;
        retorno = 0;
    }

    return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int retorno = -1;

    if(this != NULL && nombre != NULL)
    {
        strcpy(this->nombre, nombre);
        retorno = 0;
    }

    return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int retorno = -1;

    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        retorno = 0;
    }

    return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno = -1;

    if(this != NULL)
    {
        this->horasTrabajadas = horasTrabajadas;
        retorno = 0;
    }

    return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno = -1;

    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno = 0;
    }

    return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno = -1;

    if(this != NULL)
    {
        this->sueldo = sueldo;
        retorno = 0;
    }

    return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno = -1;

    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        retorno = 0;
    }

    return retorno;
}

int compareById(void* pElementOne, void* pElementTwo)
{
    int retorno = -1;
    int id_Uno;
    int id_Dos;

    Employee* empleado_Uno = (Employee*) pElementOne;
    Employee* empleado_Dos = (Employee*) pElementTwo;

    employee_getId(empleado_Uno, &id_Uno);
    employee_getId(empleado_Dos, &id_Dos);

    if(id_Uno > id_Dos)
    {
        retorno = 1;
    }
    else
    {
        if(id_Uno == id_Dos)
        {
            retorno = 0;
        }
    }

    return retorno;
}

int compareBySalary(void* pElementOne, void* pElementTwo)
{
    int retorno = -1;
    int sueldo_Uno;
    int sueldo_Dos;

    Employee* empleado_Uno = (Employee*) pElementOne;
    Employee* empleado_Dos = (Employee*) pElementTwo;

    employee_getSueldo(empleado_Uno, &sueldo_Uno);
    employee_getSueldo(empleado_Dos, &sueldo_Dos);

    if(sueldo_Uno > sueldo_Dos)
    {
        retorno = 1;
    }
    else
    {
        if(sueldo_Uno == sueldo_Dos)
        {
            retorno = 0;
        }
    }

    return retorno;
}

int compareByName(void* pElementOne, void* pElementTwo)
{
    int retorno;
    char nombre_Uno[50];
    char nombre_Dos[50];

    Employee* empleado_Uno = (Employee*) pElementOne;
    Employee* empleado_Dos = (Employee*) pElementTwo;

    employee_getNombre(empleado_Uno, nombre_Uno);
    employee_getNombre(empleado_Dos, nombre_Dos);

    retorno = strcmp(nombre_Uno, nombre_Dos);

    return retorno;
}

int compareByHoursWorked(void* pElementOne, void* pElementTwo)
{
    int retorno = -1;
    int horasTrabajadas_Uno;
    int horasTrabajadas_Dos;

    Employee* empleado_Uno = (Employee*) pElementOne;
    Employee* empleado_Dos = (Employee*) pElementTwo;

    employee_getHorasTrabajadas(empleado_Uno, &horasTrabajadas_Uno);
    employee_getHorasTrabajadas(empleado_Dos, &horasTrabajadas_Dos);

    if(horasTrabajadas_Uno > horasTrabajadas_Dos)
    {
        retorno = 1;
    }
    else
    {
        if(horasTrabajadas_Uno == horasTrabajadas_Dos)
        {
            retorno = 0;
        }
    }

    return retorno;
}

void pedirDatosEmpleado(char* nombre, char* horasTrabajadas, char* salario)
{
    pedirCadena("Ingrese el nombre del empleado: ", nombre);
    pedirCadenaSoloNumeros("Ingrese las horas trabajadas del empleado: ", horasTrabajadas);
    pedirCadenaSoloNumeros("Ingrese el salario del empleado: ", salario);
}
