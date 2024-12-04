#include <stdio.h>
#include <string.h>
#include "Estructuras.h"

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Students
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//3.

void showNotes() {
    int idEstudiante;
    printf("Ingrese su ID de estudiante: ");
    scanf("%d", &idEstudiante);

    FILE *Evaluaciones = fopen("Evaluaciones.txt", "r");
    if (Evaluaciones == NULL) {
        printf("Error al abrir el archivo Evaluaciones.txt.\n");
        return;
    }

    char line[256];
    int found = 0;
    char nombreEstudiante[40];
    char asignaturaActual[30] = "";
    float totalMateria = 0.0, totalGeneral = 0.0;
    int totalMaterias = 0;

    printf("+--------------------------------------------------------------------------------------------------------+\n");
    while (fgets(line, sizeof(line), Evaluaciones)) {
        int id;
        char asignatura[30], nombreActividad[30];
        float nota, notaPonderada;

        // Leer campos de la evaluación
        sscanf(line, "%d;%39[^;];%29[^;];%*[^;];%29[^;];%f;%f",
               &id, nombreEstudiante, asignatura, nombreActividad, &nota, &notaPonderada);

        if (id == idEstudiante) {
            if (!found) {
                // Encabezado personalizado con nombre del estudiante e ID
                printf("| %-102s |\n", nombreEstudiante);
                printf("+--------------------------------------------------------------------------------------------------------+\n");
                printf("| %-50s | %-15s  | %-10s  | %-15s |\n", 
                       "Asignatura", "Nombre Actividad", "Nota", "Nota Ponderada");
                printf("+--------------------------------------------------------------------------------------------------------+\n");
                found = 1;
            }

            // Si cambia la asignatura, mostrar el total de la anterior
            if (strcmp(asignaturaActual, asignatura) != 0) {
                if (strcmp(asignaturaActual, "") != 0) {
                    // Mostrar total de la materia
                    printf("| %-50s | %-15s   | %-10s  | Total: %-9.2f|\n", 
                           "", "", "", totalMateria);
                    printf("+--------------------------------------------------------------------------------------------------------+\n");
                }
                // Actualizar asignatura actual y contar materia
                strcpy(asignaturaActual, asignatura);
                totalMateria = 0.0;
                totalMaterias++;
            }

            // Mostrar evaluación
            printf("| %-50s | %-15s   | %-10.2f  | %-15.2f |\n", 
                   asignatura, nombreActividad, nota, notaPonderada);
            totalMateria += notaPonderada;
            totalGeneral += notaPonderada;
        }
    }
    fclose(Evaluaciones);

    // Mostrar el último total de materia
    if (found) {
        printf("| %-50s | %-15s   | %-10s  | Total: %-9.2f|\n", 
               "", "", "", totalMateria);
        printf("+--------------------------------------------------------------------------------------------------------+\n");

        // Mostrar el total general y el promedio general por materia
        if (totalMaterias > 0) {
            printf("| Promedio General: %-84.2f |\n", totalGeneral / totalMaterias);
            printf("+--------------------------------------------------------------------------------------------------------+\n");
        }
    } else {
        printf("| No se encontraron evaluaciones para el ID ingresado.                                                  |\n");
        printf("+--------------------------------------------------------------------------------------------------------+\n");
    }
}


