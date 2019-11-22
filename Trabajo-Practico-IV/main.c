#include "Controller.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado.
     4. Modificar datos de empleado.
     5. Baja de empleado.
     6. Listar empleados.
     7. Ordenar empleados.
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
     10. Salir.

*****************************************************/

int main()
{
    LinkedList* listaEmpleados = ll_newLinkedList();
    LinkedList* listaBajasEmpleados = ll_newLinkedList();
    int option;
    int retorno;
    char option_continue = 'n';
    int id = 0;
    int len;
    do
    {
        system("cls");
        printf("Menu:\n");
        option = getInt("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n3. Alta de empleado\n4. Modificar datos de empleado.\n5. Baja de empleado.\n6. Listar empleados.\n7. Ordenar empleados.\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n10. Salir.\nIngrese una opcion: ");
        switch(option)
        {
        case 1:
            /**CARGA DE TEXTO*/
            retorno = controller_loadFromText("data.csv", listaEmpleados);
            controller_loadFromText("Bajas.csv", listaBajasEmpleados);
            id = dameProximoId(listaEmpleados);
            switch(retorno)
            {
            case -1:
                printf("Error: el archivo no puede ser abierto.\n");
                break;
            case 0:
                len = ll_len(listaEmpleados);
                printf("Se cargaron un total de %d empleados.\n",len);
                printf("\n");
                printf("Los archivos se han abierto exitosamente en modo texto.\n");
                break;
            case 1:
                printf("Error: no se pudo acceder a la opcion de carga desde archivo data.csv (modo texto)");
                break;
            case 2:
                printf("Error: La lista ya esta cargada.\n");
                break;
            }
            printf("\n");
            system("pause");
            break;
        case 2:
            /**CARGA DE BINARIO*/
            retorno = controller_loadFromBinary("data.bin", listaEmpleados);
            controller_loadFromBinary("Bajas.bin", listaBajasEmpleados);
            id = dameProximoId(listaEmpleados);
            switch(retorno)
            {
            case -1:
                printf("Error: el archivo no puede ser abierto.\n");
                break;
            case 0:
                len = ll_len(listaEmpleados);
                printf("Se cargaron un total de %d empleados.\n",len);
                printf("\n");
                printf("Los archivos se han abierto exitosamente en modo binario.\n");
                break;
            case 1:
                printf("Error: no se pudo acceder a la opcion de carga desde archivo data.bin (modo binario)");
                break;
            case 2:
                printf("Error: la lista ya esta cargada.\n");
                break;
            }
            printf("\n");
            system("pause");
            break;
        case 3:
            /**ALTA DE EMPLEADO*/
            retorno = controller_addEmployee(listaEmpleados, &id);
            switch(retorno)
            {
            case -1:
                printf("Error: no se pudo agregar al empleado en la lista.\n");
                break;
            case 0:
                printf("Se ha realizado la carga en la lista.\n");
                break;
            case 1:
                printf("Error: no se pudo acceder al alta de empleados.\n");
                break;
            case 2:
                printf("El usuario cancelo la accion.\n");
                break;
            case 3:
                printf("Error: no se han agregado empleados a la lista. Agregue los empleados ya existentes antes de los nuevos.\n");
                break;
            }
            printf("\n");
            system("pause");
            break;
        case 4:
            /**MODIFICAR*/
            retorno = controller_editEmployee(listaEmpleados);
            switch(retorno)
            {
            case -1:
                printf("Error: no se ha podido acceder al menu de modificaciones.\n");
                break;
            case 0:
                printf("Error: no se han agregado empleados a la lista.\n");
                break;
            case 1:
                printf("Error: el empleado no existe.\n");
                break;
            case 2:
                printf("Se han guardado las modificaciones.\n");
                break;
            case 3:
                printf("El usuario cancelo la accion.\n");
                break;
            }
            printf("\n");
            system("pause");
            break;
        case 5:
            /**BAJAS*/
            retorno = controller_removeEmployee(listaEmpleados, listaBajasEmpleados);
            switch(retorno)
            {
            case -1:
                printf("Error: no se ha podido eliminar al empleado.\n");
                break;
            case 0:
                printf("Se ha eliminado al empleado. Se podra ver al empleado en la lista de bajas (opcion 6 del menu principal).\n");
                break;
            case 1:
                printf("Error: no se pudo acceder a la baja de empleados.\n");
                break;
            case 2:
                printf("El usuario cancelo la accion.\n");
                break;
            case 3:
                printf("Error: el empleado no existe.\n");
                break;
            case 4:
                printf("Error: no se han agregado empleados a la lista.\n");
                break;
            }
            printf("\n");
            system("pause");
            break;
        case 6:
            /**LISTAR*/
            retorno = mostrarMenuListar(listaEmpleados, listaBajasEmpleados);
            switch(retorno)
            {
            case -1:
                printf("Error: no se puede acceder al listado de empleados.\n");
                break;
            case 0:
                printf("Se han listado todos los empleados.\n");
                break;
            case 1:
                printf("Error: No se han agregado empleados a la lista.\n");
                break;
            }
            printf("\n");
            system("pause");
            break;
        case 7:
            /**ORDENAR*/
            retorno = controller_sortEmployee(listaEmpleados);
            switch(retorno)
            {
            case -1:
                printf("Error: no se pudo realizar el ordenamiento.\n");
                break;
            case 0:
                printf("Se ha ordenado a los empleados.\n");
                break;
            case 1:
                printf("Error: no se pudo acceder al ordenamiento de empleados.\n");
                break;
            case 2:
                printf("No se han agregado empleados a la lista.\n");
                break;
            case 3:
                printf("Se ha salido del submenu de ordenamiento.\n");
                break;
            }
            printf("\n");
            system("pause");
            break;
        case 8:
            /**GUARDAR TEXTO*/
            retorno = controller_saveAsText("data.csv", listaEmpleados);
            switch(retorno)
            {
            case -1:
                printf("Error: no se ha podido acceder al guardado en texto.\n");
                break;
            case 0:
                printf("Los archivos se han guardado exitosamente en modo texto.\n");
                controller_saveAsText("Bajas.csv", listaBajasEmpleados);
                break;
            }
            printf("\n");
            system("pause");
            break;
        case 9:
            /**GUARDAR BINARIO*/
            retorno = controller_saveAsBinary("data.bin", listaEmpleados);
            switch(retorno)
            {
            case -1:
                printf("Error: no se ha podido acceder al guardado en binario.\n");
                break;
            case 0:
                printf("Los archivos se han guardado exitosamente en modo binario.\n");
                controller_saveAsBinary("Bajas.bin", listaBajasEmpleados);
                break;
            }
            printf("\n");
            system("pause");
            break;
        case 10:
            /**SALIR*/
            option_continue = getConfirmacion("Esta seguro que desea salir? Ingrese s para SI o n para NO: ");
            ll_deleteLinkedList(listaEmpleados);
            ll_deleteLinkedList(listaBajasEmpleados);
            printf("\n");
            system("pause");
            break;
        default:
            printf("Ha ingresado una opcion incorrecta.\n");
            printf("\n");
            system("pause");
            break;
        }
    }
    while(option_continue=='n');
    printf("\n");

    return 0;
}
