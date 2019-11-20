#include "ArrayEmployees.h"

void showMenu(Employee list[], int len){
    int option;
    int retorno;
    char option_continue = 'n';
    int seCargoUnEmpleado = 0;
    initEmployees(list, len);
    initIds(list, len);
    do{
        system("cls");
        printf("******* MENU PARA ALTAS, BAJAS Y MODIFICACIONES DE EMPLEADOS *******\n");
        option = getInt("Opciones:\n1. ALTAS.\n2. MODIFICAR.\n3. BAJA.\n4. INFORMAR.\n5. SALIR.\n");
        switch(option){
        case 1:
            /**ALTAS*/
            retorno = loadEmployee(list, len);
            switch(retorno){
            case -1:
                printf("No hay lugar disponible en la lista para guardar un empleado nuevo.\n");
                break;
            case 0:
                printf("Los datos se han cargado exitosamente.\n");
                seCargoUnEmpleado = 1;
                break;
            case 1:
                printf("Error, no se pudo acceder a la opcion elegida.\n");
                break;
            case 2:
                printf("El usuario cancelo la carga.\n");
                break;
            }
            printf("\n");
            system("pause");
            break;
        case 2:
            /**MODIFICACIONES*/
            if(seCargoUnEmpleado == 1){
                retorno = modificarEmpleado(list, len);
                switch(retorno){
                case -1:
                    printf("No se encontro el dato.\n");
                    break;
                case 0:
                    printf("El usuario cancelo la accion.\n");
                    break;
                case 1:
                    printf("Se cargaron los datos nuevos.\n");
                    break;
                }
            }else{
                printf("Debe ingresar al menos un empleado.\n");
            }
            printf("\n");
            system("pause");
            break;
        case 3:
            /**BAJAS*/
            if(seCargoUnEmpleado == 1){
                retorno = deleteEmployee(list, len);
                switch(retorno){
                case -1:
                    printf("Error. No se pudo completar la accion. \n");
                    break;
                case 0:
                    printf("Se ha eliminado al empleado de la lista.\n");
                    break;
                case 1:
                    printf("El empleado no existe.\n");/**REVISAR*/
                    break;
                case 2:
                    printf("El usuario cancelo la accion.\n");
                    break;
                }
            }else{
                printf("Debe ingresar al menos un empleado.\n");
            }
            printf("\n");
            system("pause");
            break;
        case 4:
            /**INFORMES*/
            if(seCargoUnEmpleado == 1){
                retorno = informarEmpleado(list, len);
                switch(retorno){
                case -1:
                    printf("Error, no se puede acceder a informes.\n");
                    break;
                case 1:
                    printf("Error. No se pudo realizar el ordenamiento.\n");
                    break;
                }
            }else{
                printf("Debe ingresar al menos un empleado.\n");
            }
            printf("\n");
            system("pause");
            break;
        case 5:
            option_continue = getChar("Esta seguro que desea salir? Ingrese s para SI o n para NO: ");
            printf("\n");
            system("pause");
            break;
        default:
            printf("Ha ingresado una opcion incorrecta.\n");
            printf("\n");
            system("pause");
            break;
        }
    }while(option_continue=='n');
    printf("\n");
}
int initEmployees(Employee* list, int len){
    int i;
    int retorno = -1;
    if(list != NULL && len>0){
        for(i=0; i<len; i++){
            list[i].isEmpty = TRUE;
            retorno = 0;
        }
    }
    return retorno;
}
int initIds(Employee* list, int len){
    int i;
    int retorno = -1;
    if(list != NULL && len>0){
        for(i=0; i<len; i++){
            list[i].id = 0; //REALIZAR FUNCION QUE INICIALICE LOS ID
            retorno = 0;
        }
    }
    return retorno;
}
int printEmployees(Employee* list, int len){
    int retorno = -1;
    int i;
    if(list != NULL && len>0){
        printf("ID:\tNOMBRE:\t\tAPELLIDO:\t\tSALARIO:\t\tSECTOR:\n");
        for(i=0; i<len; i++)
        {
            if(list[i].isEmpty != TRUE)
            {
                retorno = 1;
                showOneEmployee(list[i]);
            }
        }
    }
    return retorno;
}
void showOneEmployee(Employee sEmployee){
    printf("\n");
    printf("%03d", sEmployee.id);
    printf("%12s", sEmployee.name);
    printf("%18s", sEmployee.lastName);
    printf("%22.2f", sEmployee.salary);
    printf("%23d\n", sEmployee.sector);
}
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector){
    int retorno = -1;
    int lugar_Disponible = getIsEmpty(list, len);
    if(lugar_Disponible!= -1){
        list[lugar_Disponible].id = id;
        strcpy(list[lugar_Disponible].name, name);
        strcpy(list[lugar_Disponible].lastName, lastName);
        list[lugar_Disponible].salary = salary;
        list[lugar_Disponible].sector = sector;
        list[lugar_Disponible].isEmpty = FALSE;
        retorno = 0;
    }
    return retorno;
}
int getNewId(Employee* list, int len){
    int retorno = -1;
    int flag = 0;
    int newId;
    if(list != NULL && len>0){
        int i;
        for(i=0;i<len;i++){
            if(flag == 0 || list[i].id>newId){
                newId = list[i].id;
                flag = 1;
            }
        }
        retorno = newId;
    }
    return retorno;
}
int loadEmployee(Employee* list, int len){
    int retorno = 1;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int id;
    char confirmacion;
    char opcion_continuar;
    if(list != NULL && len>0){
        do{
            getDataEmployee(name, lastName, &salary, &sector);
            printf("\n");
            printf("Estos son los datos ingresados:\n");
            showData(name, lastName, salary, sector);
            printf("\n");
            confirmacion = getConfirmacion("Desea cargar los datos? Ingrese s para SI o n para NO: \n");
            if(confirmacion == 's'){
                id = getNewId(list, len);
                id++;
                retorno = addEmployee(list, len, id, name, lastName, salary, sector);
            }
            else if(confirmacion == 'n'){
                retorno = 2;
            }
            printf("\n");
            opcion_continuar = getConfirmacion("Desea ingresar otro empleado? Ingrese s para SI o n para NO: ");
            printf("\n");
        }while(opcion_continuar == 's');
    }
    return retorno;
}
void showData(char name[],char lastName[],float salary,int sector){
    printf("\n");
    printf("Nombre: %s\n", name);
    printf("Apellido %s\n", lastName);
    printf("Salario: %.3f\n", salary);
    printf("Sector: %d\n", sector);
}
void getDataEmployee(char name[],char lastName[],float* salary,int* sector){
    printf("Ingrese los datos del empleado: \n");
    pedirCadena("Nombre del empleado:\n", name);
    pedirCadena("Apellido del empleado: ", lastName);
    *salary = getFloat("\nSalario del empleado: ");
    *sector = getInt("\nSector del empleado: ");
}
int findEmployeeById(Employee* list, int len,int id){
    int retorno = -1;
    int i;
    if(list != NULL && len>0){
        for(i=0;i<len;i++){
            if(list[i].isEmpty == FALSE){
                if(list[i].id == id){
                    retorno = i;
                    break;
                }
            }
        }
    }
    return retorno;
}
int deleteEmployee(Employee* list, int len){
    int retorno = -1;
    int id = 0;
    int index = 0;
    char confirmacion;
    if(list != NULL && len>0){
        printf("Estos son los empleados:\n");
        printEmployees(list, len);
        id = getInt("\nIngrese el id del empleado que desea dar de baja:");
        printf("\n");
        index = findEmployeeById(list, len, id);
        if(index == -1){
            retorno = 1;
        }else{
            showOneEmployee(list[index]);
            confirmacion = getChar("\nEsta seguro que quiere eliminar al empleado? Ingrese s para SI o n para NO:");
            if(confirmacion == 's'){
                retorno = removeEmployee(list, len, id);
            }else if(confirmacion == 'n'){
                retorno = 2;
            }
       }
    }
    return retorno;
}
int removeEmployee(Employee* list, int len, int id){
    int retorno = -1;
    int i;
    if(list != NULL && len>0){
        for(i=0;i<len;i++){
            if(list[i].isEmpty == FALSE){
                if(list[i].id == id){
                    list[i].isEmpty = TRUE;
                    retorno = 0;
                    break;
                }
            }
        }
    }
    return retorno;
}
int getIsEmpty(Employee* list, int len){
    int i;
    int retorno = -1;
    if(list != NULL && len>0){
        for(i=0; i<len; i++){
            if(list[i].isEmpty == TRUE){
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
int getIsOccupied(Employee* list, int len){
    int i;
    int retorno = -1;
    if(list != NULL && len>0){
        for(i=0; i<len; i++){
            if(list[i].isEmpty == FALSE){
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}
int modificarEmpleado(Employee* list, int len){
    int retorno = -1;
    int id;
    int indice;
    Employee aux;
    int opcion;
    char confirmacion = 's';
    char cargar = 'n';

    printEmployees(list, len);

    id = getInt("\nIngrese el id del empleado a modificar:");
    indice = findEmployeeById(list, len, id);

    if(indice != -1){
        aux = list[indice];
        do{
            system("cls");
            opcion = getInt("Ingrese una opcion:\n1. Cambiar nombre.\n2. Cambiar apellido.\n3. Cambiar salario.\n4. Cambiar sector.\n5. Salir al menu principal.\n");
            switch(opcion){
            case 1:
                pedirCadena("Ingrese un nombre: ", aux.name);
                confirmacion = getConfirmacion("\nDesea seguir ingresando datos? Ingrese s para SI o n para NO: ");
                printf("\n");
                system("pause");
                break;
            case 2:
                pedirCadena("Ingrese un apellido: ", aux.lastName);
                confirmacion = getConfirmacion("\nDesea seguir ingresando datos? Ingrese s para SI o n para NO:");
                printf("\n");
                system("pause");
                break;
            case 3:
                aux.salary = getFloat("Ingrese el salario nuevo:");
                confirmacion = getConfirmacion("\nDesea seguir ingresando datos? Ingrese s para SI o n para NO: ");
                printf("\n");
                system("pause");
                break;
            case 4:
                aux.sector = getInt("Ingrese el sector nuevo:");
                confirmacion = getConfirmacion("\nDesea seguir ingresando datos? Ingrese s para SI o n para NO: ");
                printf("\n");
                system("pause");
                break;
            case 5:
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
        }while(confirmacion == 's');

        printf("Este es el empleado:\n");
        printf("\n");
        showOneEmployee(aux);
        printf("\n");
        cargar = getConfirmacion("\nDesea cargar los datos? Ingrese s para SI o n para NO:");
        if(cargar == 's'){
            list[indice]=aux;
            retorno = 1;
        }else{
            retorno = 0;
        }
    }
    return retorno;
}
int informarEmpleado(Employee* list, int len){
    int retorno = -1;
    int opcion;
    int orden;
    int opcionContinuar = 's';
    if(list!=NULL && len>0){
        do{
            system("cls");
            opcion = getInt("Ingrese una opcion:\n1. Listado de los empleados, ordenado por sector y alfabeticamente.\n2. Informe de los salarios.\n3. Salir al menu principal.\n");
            switch(opcion){
            case 1:
                orden = getInt("\nIngrese 1 si desea ordenar de manera ascendente o 0 si desea ordenar de manera descendente:");
                if(sortEmployees(list, len, orden)!= -1){
                    printEmployees(list, len);
                }else{
                    retorno = 1;
                }
                printf("\n");
                system("pause");
                break;
            case 2:
                menuInformesSalarios(list, len);
                printf("\n");
                system("pause");
                break;
            case 3:
                opcionContinuar='n';
                retorno = 0;
                break;
            default:
                printf("Ingreso una opcion incorrecta.\n");
                printf("\n");
                system("pause");
                break;
            }
        }while(opcionContinuar == 's');
    }
    return retorno;
}
void menuInformesSalarios(Employee* list, int len){
    float salarios;
    int opcion;
    char opcionContinuar = 's';
    do{
        system("cls");
        opcion = getInt("Ingrese una opcion:\n1.Informe del salario total.\n2.Informe del promedio de salarios.\n3.Informe de los salarios mayores al promedio.\n4.Salir al menu principal.\n");
        switch(opcion){
        case 1:
            salarios = getTotalSalarios(list, len);
            if(salarios == -1){
                printf("No hay total de salarios a mostrar.\n");
            }else{
                printf("Este es el total de los salarios: %.3f\n", salarios);
            }
            printf("\n");
            system("pause");
            break;
        case 2:
            salarios = getPromedioSalarios(list, len);
            if(salarios == -1){
                printf("No hay salario promedio a mostrar.\n");
            }else{
                printf("Este es el promedio de los salarios: %.3f\n", salarios);
            }
            printf("\n");
            system("pause");
            break;
        case 3:
            salarios = getMaximoSalario(list, len);
            if(salarios == -1){
                printf("No hay empleados con salarios mayores al promedio.");
            }
            printf("\n");
            system("pause");
            break;
        case 4:
            opcionContinuar='n';
            break;
        default:
            printf("Ingreso una opcion incorrecta.\n");
            printf("\n");
            system("pause");
            break;
        }
    }while(opcionContinuar == 's');
}
int sortEmployees(Employee* list, int len, int order){
    int retorno = -1;
    Employee auxEmployee;
    int i;
    int j;
    if(list != NULL && len>0){
        if(order == 1){
            for(i=0; i<len-1; i++){
                for(j=i+1; j<len; j++){
                    if(list[i].sector > list[j].sector && list[i].isEmpty == FALSE && list[j].isEmpty == FALSE){
                        auxEmployee = list[i];
                        list[i] = list[j];  //organizo por sector
                        list[j] = auxEmployee;
                    }
                    else{
                        if(list[i].sector == list[j].sector && list[i].isEmpty == FALSE && list[j].isEmpty == FALSE){
                            if(strcmp(list[i].lastName,list[j].lastName)>0){
                                auxEmployee = list[i];
                                list[i] = list[j]; //dentro del mismo sector, organizo por apellido.
                                list[j] = auxEmployee;
                            }
                            else if(strcmp(list[i].lastName,list[j].lastName)==0){
                                if(strcmp(list[i].name,list[j].name)>0){
                                    auxEmployee = list[i];
                                    list[i] = list[j]; //dentro del mismo apellido, organizo por nombre.
                                    list[j] = auxEmployee;
                                }
                            }
                        }
                    }
                }
            }
            retorno = 0;
        }
        else if(order == 0){
            for(i=0; i<len-1; i++){
                for(j=i+1; j<len; j++){
                    if(list[i].sector < list[j].sector && list[i].isEmpty == FALSE && list[j].isEmpty == FALSE){
                        auxEmployee = list[i];
                        list[i] = list[j];  //organizo por sector
                        list[j] = auxEmployee;
                    }
                    else{
                        if(list[i].sector == list[j].sector && list[j].sector && list[i].isEmpty == FALSE && list[j].isEmpty == FALSE){
                            if(strcmp(list[i].lastName,list[j].lastName)<0){
                                auxEmployee = list[i];
                                list[i] = list[j]; //dentro del mismo sector, organizo por apellido.
                                list[j] = auxEmployee;
                            }
                            else if(strcmp(list[i].lastName,list[j].lastName)==0){
                                if(strcmp(list[i].name,list[j].name)<0){
                                    auxEmployee = list[i];
                                    list[i] = list[j]; //dentro del mismo apellido, organizo por nombre.
                                    list[j] = auxEmployee;
                                }
                            }
                        }
                    }
                }
            }
            retorno = 0;
        }
    }//else order == 0
    return retorno;
}
float getTotalSalarios(Employee* list, int len){
    float retorno = -1;
    int i;
    float acumuladorSalarios = 0;
    if(list != NULL && len>0){
        for(i=0;i<len;i++){
                if(list[i].isEmpty == FALSE){
                    acumuladorSalarios = list[i].salary + acumuladorSalarios;
                }
        }
        retorno = acumuladorSalarios;
    }
    return retorno;
}
float getPromedioSalarios(Employee* list, int len){
    float retorno = -1;
    float acumuladorSalarios = 0;
    float contadorEmpleados = 0;
    float promedioSalarios = 0;
    int i;
    acumuladorSalarios = getTotalSalarios(list, len);
    if(list != NULL && len>0 && acumuladorSalarios != -1){
        for(i=0;i<len;i++){
            if(list[i].isEmpty == FALSE){
                contadorEmpleados ++;
            }
        }
        promedioSalarios = acumuladorSalarios/contadorEmpleados;
        retorno = promedioSalarios;
    }
    return retorno;
}
int getMaximoSalario(Employee* list, int len){
    int retorno = -1;
    float salarioPromedio = getPromedioSalarios(list, len);
    int i;
    if(list != NULL && len>0){
        if(salarioPromedio != -1){
            for(i=0; i<len; i++){
                if(list[i].isEmpty == FALSE){
                    if(salarioPromedio < list[i].salary){
                        showOneEmployee(list[i]);
                        retorno = 1;
                    }
                }
            }
        }
    }
    return retorno;
}
