#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Estructuras.h"
#include "Estructuras.c"
#include "Opcion1.c"

void MakeMenu(){

    int opc = 0; // Variable to store user's main menu selection
    char opc2[10]; // String to store sub-option selections

    do {

        printf("\n-----------------------------------------------------Menú del Proyecto-----------------------------------------------------\n");
        printf("1. Administrador\n");
        printf("   1.1 Crear perfil del profesor\n");
        printf("       1.1.1 Editar datos\n");
        printf("       1.1.2 Eliminar\n");
        printf("       1.1.3 Listar Profesores\n");
        printf("   1.2 Crear perfil de la asignatura\n");
        printf("       1.2.1 Editar datos\n");
        printf("       1.2.2 Eliminar\n");
        printf("       1.2.3 Listar Asignatura\n");
        printf("   1.3 Asignar materia al profesor\n");
        printf("       1.3.1 Editar datos\n");
        printf("       1.3.2 Eliminar asignación\n");
        printf("       1.3.3 Listar Asignatura y su profesor\n");
        printf("   1.4 Crear perfil estudiante\n");
        printf("       1.4.1 Editar datos\n");
        printf("       1.4.2 Eliminar\n");
        printf("       1.4.3 Listar estudiantes\n");
        printf("   1.5 Asignar materia al estudiante\n");
        printf("       1.5.1 Editar datos\n");
        printf("       1.5.2 Eliminar asignación\n");
        printf("       1.5.3 Listar Asignatura y sus estudiantes\n");
        printf("2. Docente\n");
        printf("   2.1 Crear actividades y sus porcentajes de la materia\n");
        printf("       2.1.1 Editar actividades\n");
        printf("       2.1.2 Eliminar actividad\n");
        printf("       2.1.3 Listar actividades\n");
        printf("   2.2 Crear notas para la actividad\n");
        printf("       2.2.1 Modificar notas\n");
        printf("       2.2.2 Eliminar notas\n");
        printf("   2.3 Listar estudiantes\n");
        printf("   2.4 Mostrar notas de todos los estudiantes\n");
        printf("3. Estudiante\n");
        printf("   3.1 Mostrar todas las notas\n");
        printf("   3.2 Mostrar notas de una materia específica\n");
        printf("\n\nTener en cuenta:\n");
        printf("- Que las notas van de 0.0 a 5.0.\n");
        printf("- Las cédulas no se repiten.\n");
        printf("- El código de la materia no se repite.\n");
        printf("\nSeleccione una opcion: ");
        scanf("%i", &opc); 
        
        if (opc == 0) {
            printf("Saliendo del programa...\n");
            system("cls"); 
        } else if (opc == 1) {
            printf("\n1. Administrador\n");
            printf("  1.1 Crear perfil del profesor\n");
            printf("  1.2 Crear perfil de la asignatura\n");
            printf("  1.3 Asignar materia al profesor\n");
            printf("  1.4 Crear perfil estudiante\n");
            printf("  1.5 Asignar materia al estudiante\n");
            printf("Selecciona una subopción: ");
            scanf("%s", opc2);

            if (strcmp(opc2, "1.1") == 0) {
                printf("1.1 Crear perfil del profesor.\n");
                makeTeacher(); //Funcion que crea los profesores
                printf("\n  1.1.1 Editar datos\n");
                printf("  1.1.2 Eliminar\n");
                printf("  1.1.3 Listar profesores\n");
                printf("Selecciona una subopción: ");
                scanf("%s", opc2);
                if (strcmp(opc2, "1.1.1") == 0) {
                    printf("1.1.1 Editar datos.\n");
                    editData();
                } else if (strcmp(opc2, "1.1.2") == 0) {
                    printf("1.1.2 Eliminar.\n");
                    deleteTeacher();
                } else if (strcmp(opc2, "1.1.3") == 0) {
                    printf("1.1.3 Listar Profesores\n");
                    showTeachers();
                }

            } else if (strcmp(opc2, "1.2") == 0) {
                printf("1.2 Crear perfil de la asignatura.\n");
                // Funcion que lo haga

                printf("  1.2.1 Editar datos\n");
                printf("  1.2.2 Eliminar\n");
                printf("  1.2.3 Lista1r asignatura\n");
                printf("Selecciona una subopción: ");
                scanf("%s", opc2);
                if (strcmp(opc2, "1.2.1") == 0) {
                    printf("1.2.1 Editar datos.\n");
                } else if (strcmp(opc2, "1.2.2") == 0) {
                    printf("1.2.2 Eliminar.\n");
                } else if (strcmp(opc2, "1.2.3") == 0) {
                    printf("1.2.3 Listar profesores");
                }
                
            } else if (strcmp(opc2, "1.3") == 0) {
                printf("1.3 Asignar materia al profesor.\n");
                // Funcion que lo haga

                printf("  1.3.1 Editar datos\n");
                printf("  1.3.2 Eliminar\n");
                printf("  1.3.3 Listar asignatura y su profesor\n");
                printf("Selecciona una subopción: ");
                scanf("%s", opc2);
                if (strcmp(opc2, "1.3.1") == 0) {
                    printf("1.3.1 Editar datos.\n");
                } else if (strcmp(opc2, "1.3.2") == 0) {
                    printf("1.3.2 Eliminar.\n");
                } else if (strcmp(opc2, "1.3.3") == 0) {
                    printf("1.3.3 Listar asignatura y su profesor");
                }

            } else if (strcmp(opc2, "1.4") == 0) {
                printf("1.4 Crear perfil estudiante.\n");
                // Funcion que lo haga

                printf("  1.4.1 Editar datos\n");
                printf("  1.4.2 Eliminar\n");
                printf("  1.4.3 Listar estudiantes\n");
                printf("Selecciona una subopción: ");
                scanf("%s", opc2);
                if (strcmp(opc2, "1.4.1") == 0) {
                    printf("1.4.1 Editar datos.\n");
                } else if (strcmp(opc2, "1.4.2") == 0) {
                    printf("1.4.2 Eliminar.\n");
                } else if (strcmp(opc2, "1.4.3") == 0) {
                    printf("1.4.3 Listar estudiantes");
                }

            } else if (strcmp(opc2, "1.5") == 0) {
                printf("1.5 Asignar materia al estudiante.\n");
                //Funcion que lo haga
                
                printf("  1.5.1 Editar datos\n");
                printf("  1.5.2 Eliminar\n");
                printf("  1.5.3 Listar asignatura y sus estudiantes\n");
                printf("Selecciona una subopción: ");
                scanf("%s", opc2);
                if (strcmp(opc2, "1.5.1") == 0) {
                    printf("1.5.1 Editar datos.\n");
                } else if (strcmp(opc2, "1.5.2") == 0) {
                    printf("1.5.2 Eliminar.\n");
                } else if (strcmp(opc2, "1.5.3") == 0) {
                    printf("1.5.3 Listar asignatura y sus estudiantes");
                }

            } else {
                printf("Subopción inválida.\n");
            }
        } else if (opc == 2) {
            printf("\n2. Docente\n");
            printf("  2.1 Crear actividades y sus porcentajes de la materia\n");
            printf("  2.2 Crear notas para la actividad\n");
            printf("  2.3 Listar estudiantes\n");
            printf("  2.4 Mostrar notas de todos los estudiantes\n");
            printf("Selecciona una subopción: ");
            scanf("%s", opc2);

            if (strcmp(opc2, "2.1") == 0) {
                printf("2.1 Crear actividades.\n");
                // Funcion que lo haga
            } else if (strcmp(opc2, "2.2") == 0) {
                printf("2.2 Crear notas para la actividad.\n");
                // Funcion que lo haga
            } else if (strcmp(opc2, "2.3") == 0) {
                printf("2.3 Listar estudiantes seleccionado.\n");
                // Funcion que lo haga
            } else if (strcmp(opc2, "2.4") == 0) {
                printf("2.4 Mostrar notas de todos los estudiantes.\n");
                // Funcion que lo haga
            } else {
                printf("Subopción inválida.\n");
            }
        } else if (opc == 3) {
            printf("\n3. Estudiante\n");
            printf("  3.1 Mostrar todas las notas\n");
            printf("  3.2 Mostrar notas de una materia específica\n");
            printf("Selecciona una subopción: ");
            scanf("%s", opc2);

            if (strcmp(opc2, "3.1") == 0) {
                printf("3.1 Mostrar todas las notas.\n");
                // Funcion que lo haga
            } else if (strcmp(opc2, "3.2") == 0) {
                printf("3.2 Mostrar notas de una materia específica.\n");
                // Funcion que lo haga
            } else {
                printf("Subopción inválida.\n");
            }
        } else {
            printf("¡Opción incorrecta!\n");
        }
    } while (opc != 0);

}

//Main.
int main(){

    MakeMenu();
    
}