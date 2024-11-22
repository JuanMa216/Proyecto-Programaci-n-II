#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Estructuras.h"
#include "Estructuras.c"
#include "Opcion1.c"

//Menus.
void Menu_Profesores();
void ShowMenu();

//Main.
int main () {

    int option = 0;
    do
    {
        ShowMenu();  
        scanf("%i", &option);
        getchar();
        switch (option)
        {
        case 0:
            printf("Hasta pronto...");
            return 1;
            break;
        case 1:
            Menu_Profesores();
            break;
        
        default:
            while (option < 0 || option > 1)
            {
                printf("Opcion invalida, ingrese su opcion de nuevo: ");
                scanf("%i", &option);
            }
            break;
        }
    } while (option != 0);
    
}


//Funciones de Menus.
void ShowMenu() {
    system("cls");
    printf("\nBienvenido al portal de notas de la UTP\n");
    printf("Seleccione su opcion\n");
    printf("0. Salir del Programa.\n");
    printf("1. Menu de Profesores.\n");
}

//Funcion que muestra el menu de profesores.
void Menu_Profesores() {
    int option = 0;
    system("cls");
    printf("\nMenu de Profesores.\nBienvenido, seleccione su opcion deseada:\n");
    do
    {   
        printf("0. Volver al menu principal.\n");
        printf("1. Mostrar listado de profesores.\n");
        printf("2. Crear grupo.\n");
        printf("3. Listado de estudiantes.\n");
        
        scanf("%i", &option);
        switch (option)
        {
        case 0:
            ShowMenu();
            break;
        
        case 1:
            Mostrar_Profesores();
            break;

        case 2:
            Crear_Grupo();
            break;

        case 3:
            Mostrar_Estudiantes();
            Pause_Menu();
            break;
        
        default:
            while (option < 0 || option > 3)
            {
                printf("Opcion invalida, ingrese su opcion de nuevo: ");
                scanf("%i", &option);
            }
            break;
        }
    } while (option != 0);
    
}   

