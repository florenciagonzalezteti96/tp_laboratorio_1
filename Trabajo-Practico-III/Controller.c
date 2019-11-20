#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "Employee.h"
#include "parser.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = 1;
    int isEmpty = 0;
    FILE* pFile;

    pFile = fopen(path,"r");

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        isEmpty = ll_isEmpty(pArrayListEmployee);
        if(isEmpty == 1)
        {
            retorno = parser_EmployeeFromText(pFile, pArrayListEmployee);
            fclose(pFile);
        }
        else
        {
            retorno = 2;
        }
    }
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = 1;
    int isEmpty = 0;
    FILE* pFile = NULL;

    pFile = fopen(path,"rb");

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        isEmpty = ll_isEmpty(pArrayListEmployee);
        if(isEmpty == 1)
        {
            retorno = parser_EmployeeFromBinary(pFile, pArrayListEmployee);
        }
        else
        {
            retorno = 2;
        }
    }
    fclose(pFile);
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int* id)
{
    int retorno = 1;
    char nombre[51];
    char salario[51];
    char horasTrabajadas[51];
    char idEmpleado[51];
    int proximoID;
    char confirmacion;
    char opcion_continuar;

    if(pArrayListEmployee != NULL)
    {
        do
        {
            Employee* nuevo_Empleado;

            sprintf(idEmpleado, "%d", *id);
            pedirDatosEmpleado(nombre, horasTrabajadas, salario);
            nuevo_Empleado = employee_newParametros(idEmpleado, nombre, horasTrabajadas, salario);
            printf("\n");

            printf("Estos son los datos ingresados:\n");//muestro el empleado a cargar
            printf("%4s %18s %20s %20s\n", "ID:", "Nombre:", "Horas trabajadas:", "Salario:");
            showOneEmployee(nuevo_Empleado);
            printf("\n");

            confirmacion = getConfirmacion("Desea cargar al empleado? Ingrese s para SI o n para NO: ");//pido confirmacion para cargar o cancelar la accion
            if(confirmacion == 's')
            {
                retorno = ll_add(pArrayListEmployee, nuevo_Empleado);
            }
            else if(confirmacion == 'n')
            {
                retorno = 2;
            }
            printf("\n");

            proximoID = *id;
            proximoID++;
            *id = proximoID;

            opcion_continuar = getConfirmacion("Desea ingresar otro empleado? Ingrese s para SI o n para NO: ");
            printf("\n");
        }
        while(opcion_continuar == 's');
    }
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int isEmpty = 0;
    int id;
    int opcion;
    char confirmacion = 's';
    char cargar = 'n';
    Employee* empleadoAModificar;
    Employee* auxEmpleado;

    if(pArrayListEmployee != NULL)
    {
        isEmpty = ll_isEmpty(pArrayListEmployee);
        if(isEmpty!= 1)
        {
            printf("Estos son los empleados: \n");
            controller_ListEmployee(pArrayListEmployee);
            id = getInt("Ingrese el id del empleado a modificar: \n");
            printf("\n");

            empleadoAModificar = getEmployeeById(pArrayListEmployee, id);
            auxEmpleado = empleadoAModificar;
            if(auxEmpleado != NULL)
            {
                printf("\n");
                printf("Este es el empleado a modificar: \n");
                printf("%4s %18s %20s %20s\n", "ID:", "Nombre:", "Horas trabajadas:", "Salario:");
                showOneEmployee(auxEmpleado);
                system("pause");
                do
                {
                    system("cls");
                    opcion = getInt("Ingrese una opcion:\n1. Cambiar nombre.\n2. Cambiar cantidad de horas trabajadas.\n3. Cambiar salario.\n4. Salir al menu principal.\n");
                    switch(opcion)
                    {
                    case 1:
                        pedirCadena("Ingrese un nuevo nombre: ", auxEmpleado->nombre);
                        confirmacion = getConfirmacion("\nDesea seguir ingresando datos? Ingrese s para SI o n para NO: ");
                        printf("\n");
                        system("pause");
                        break;
                    case 2:
                        auxEmpleado->horasTrabajadas = getInt("Ingrese una nueva cantidad de horas trabajadas: ");
                        confirmacion = getConfirmacion("\nDesea seguir ingresando datos? Ingrese s para SI o n para NO:");
                        printf("\n");
                        system("pause");
                        break;
                    case 3:
                        auxEmpleado->sueldo = getInt("Ingrese el nuevo salario: ");
                        confirmacion = getConfirmacion("\nDesea seguir ingresando datos? Ingrese s para SI o n para NO: ");
                        printf("\n");
                        system("pause");
                        break;
                    case 4:
                        confirmacion='n';
                        printf("\n");
                        system("pause");
                        break;
                    default:
                        printf("Ingreso una opcion incorrecta.\n");
                        printf("\n");
                        system("pause");
                        break;
                    }
                }
                while(confirmacion == 's');
            }
            else
            {
                retorno = 1;
            }
            printf("\n");
            printf("Este es el empleado con los cambios realizados:\n");
            printf("\n");
            printf("%4s %18s %20s %20s\n", "ID:", "Nombre:", "Horas trabajadas:", "Salario:");
            showOneEmployee(auxEmpleado);
            printf("\n");
            cargar = getConfirmacion("\nDesea cargar los datos? Ingrese s para SI o n para NO:");
            if(cargar == 's')
            {
                empleadoAModificar = auxEmpleado;
                retorno = 2;
            }
            else
            {
                retorno = 3;
            }
        }
        else
        {
            retorno = 0;
        }
    }
    return retorno;
}


/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 1;
    int id;
    int isEmpty = 0;
    char confirmacion;
    Employee* auxEmpleado;
    int indiceEmpleado;

    if(pArrayListEmployee != NULL)
    {
        isEmpty = ll_isEmpty(pArrayListEmployee);
        if(isEmpty != 1)
        {
            printf("Estos son los empleados:\n");
            controller_ListEmployee(pArrayListEmployee);
            id = getInt("\nIngrese el id del empleado que desea dar de baja: ");
            printf("\n");

            auxEmpleado = getEmployeeById(pArrayListEmployee, id);

            if(auxEmpleado != NULL)
            {
                printf("%4s %18s %20s %20s\n", "ID:", "Nombre:", "Horas trabajadas:", "Salario:");
                showOneEmployee(auxEmpleado);
                confirmacion = getConfirmacion("\nEsta seguro que quiere eliminar al empleado? Ingrese s para SI o n para NO:");
                if(confirmacion == 's')
                {
                    indiceEmpleado = ll_indexOf(pArrayListEmployee, auxEmpleado);
                    retorno = ll_remove(pArrayListEmployee, indiceEmpleado);
                }
                else if(confirmacion == 'n')
                {
                    retorno = 2;
                }
            }
            else
            {
                retorno = 3;
            }
        }
        else
        {
            retorno = 4;
        }
    }
    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int i;
    int len;
    int isEmpty = 0;

    if(pArrayListEmployee != NULL)
    {
        retorno = 0;
        isEmpty = ll_isEmpty(pArrayListEmployee);
        if(isEmpty != 1)
        {
            len = ll_len(pArrayListEmployee);
            Employee* auxEmpleado;
            printf("%4s%22s%32s%32s\n","Id:","Nombre:","Horas Trabajadas:","Sueldo:");
            for(i=0; i<len; i++)
            {
                auxEmpleado = (Employee*) ll_get(pArrayListEmployee, i);
                showOneEmployee(auxEmpleado);
                if(i!=0 && i%150==0)
                {
                    system("pause");
                }
            }
        }
        else
        {
            retorno = 1;
        }
    }
    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 1;
    int opcion;
    char option_continue = 'n';
    int orden;
    int isEmpty = 0;

    if(pArrayListEmployee != NULL)
    {
        isEmpty = ll_isEmpty(pArrayListEmployee);
        retorno = 2;
        if(isEmpty != 1)
        {
            do
            {
                system("cls");
                opcion = getInt("Estos son los campos por los cuales puede ordenar a los empleados:\n1.Por ID.\n2.Por nombre.\n3.Por horas trabajadas.\n4.Por salario.\nIngrese el campo por el cual ordenar a los empleados o 5 para salir del subMenu de ordenamiento: ");
                switch(opcion)
                {
                case 1:
                    orden = getDosEstados("Ingrese 1 si desea ordenar de forma ascendente o 0 si desea ordenar de forma descendente: ", 1, 0);
                    printf("Ordenando, por favor espere...\n");
                    retorno = ll_sort(pArrayListEmployee, compareById, orden);
                    option_continue = 's';
                    printf("\n");
                    system("pause");
                    break;
                case 2:
                    orden = getDosEstados("Ingrese 1 si desea ordenar de forma ascendente o 0 si desea ordenar de forma descendente: ", 1, 0);
                    printf("Ordenando, por favor espere...\n");
                    retorno = ll_sort(pArrayListEmployee, compareByName, orden);
                    option_continue = 's';
                    printf("\n");
                    system("pause");
                    break;
                case 3:
                    orden = getDosEstados("Ingrese 1 si desea ordenar de forma ascendente o 0 si desea ordenar de forma descendente: ", 1, 0);
                    printf("Ordenando, por favor espere...\n");
                    retorno = ll_sort(pArrayListEmployee, compareByHoursWorked, orden);
                    option_continue = 's';
                    printf("\n");
                    system("pause");
                    break;
                case 4:
                    orden = getDosEstados("Ingrese 1 si desea ordenar de forma ascendente o 0 si desea ordenar de forma descendente: ", 1, 0);
                    printf("Ordenando, por favor espere...\n");
                    retorno = ll_sort(pArrayListEmployee, compareBySalary, orden);
                    option_continue = 's';
                    printf("\n");
                    system("pause");
                    break;
                case 5:
                    option_continue = getConfirmacion("Esta seguro que desea salir? Ingrese s para SI o n para NO: ");
                    retorno = 3;
                    break;
                default:
                    printf("Ha ingresado una opcion incorrecta.\n");
                    printf("\n");
                    system("pause");
                    break;
                }
            }
            while(option_continue == 'n');
        }
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int len;
    int i;
    FILE* pFile;
    Employee* auxEmployee = NULL;

    int idStr;
    char nombreStr[51];
    int horasTrabajadasStr;
    int sueldoStr;

    if(pArrayListEmployee != NULL && path != NULL)
    {
        pFile = fopen(path, "w");//abro el archivo en modo escritura
        len = ll_len(pArrayListEmployee);

        if(pFile != NULL)
        {
            fprintf(pFile, "Id,Nombre,Horas trabajadas,Salario\n");
            for(i=0; i<len; i++)
            {
                auxEmployee = (Employee*) ll_get(pArrayListEmployee, i);
                employee_getId(auxEmployee, &idStr);
                employee_getNombre(auxEmployee, nombreStr);
                employee_getHorasTrabajadas(auxEmployee, &horasTrabajadasStr);
                employee_getSueldo(auxEmployee, &sueldoStr);

                fprintf(pFile, "%d,%s,%d,%d\n", idStr, nombreStr, horasTrabajadasStr, sueldoStr);
            }
        }
        fclose(pFile);
        retorno = 0;
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int len;
    int i;
    FILE* pFile;
    Employee* auxEmployee = NULL;

    if(pArrayListEmployee != NULL && path != NULL)
    {
        pFile = fopen(path, "wb");//abro el archivo en modo escritura
        len = ll_len(pArrayListEmployee);

        if(pFile != NULL)
        {
            for(i=0; i<len; i++)
            {
                auxEmployee = (Employee*) ll_get(pArrayListEmployee, i);
                fwrite(auxEmployee, sizeof(Employee), 1, pFile);
            }
        }
        fclose(pFile);
        retorno = 0;
    }

    return retorno;
}

int dameMayorId(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    if(pArrayListEmployee != NULL)
    {
        int len;
        int flag = 0;
        int i;
        Employee* auxEmployee;

        len = ll_len(pArrayListEmployee);

        for(i=0; i<len; i++)
        {
            auxEmployee = (Employee*) ll_get(pArrayListEmployee, i);
            if(flag == 0 || retorno < auxEmployee->id)
            {
                retorno = auxEmployee->id;
                flag = -1;
            }
        }
    }
    return retorno;
}

int dameProximoId(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    if(pArrayListEmployee != NULL)
    {
        retorno = dameMayorId(pArrayListEmployee);
        retorno++;
    }
    return retorno;
}

void* getEmployeeById(LinkedList* pArrayListEmployee, int id)
{
    int len;
    int i;
    Employee* auxEmployee = NULL;
    if(pArrayListEmployee != NULL)
    {
        len = ll_len(pArrayListEmployee);

        for(i=0; i<len; i++)
        {
            auxEmployee = (Employee* ) ll_get(pArrayListEmployee, i);
            if(id == auxEmployee->id)
            {
                return auxEmployee;
                break;
            }
        }
    }
    return auxEmployee;
}
