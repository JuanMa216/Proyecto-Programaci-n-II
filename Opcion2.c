#include <stdio.h>
#include <string.h>
#include "Estructuras.h"

void Create_Activities() {
    Profesor prof;
    Acvtividad act;
    char existingNames[100][30];  // Para almacenar nombres de actividades ya ingresados
    int totalPercentage = 0, activityCount = 0;

    // Solicitar el ID del profesor
    printf("Ingrese el ID del docente: ");
    scanf("%i", &prof.idProfesor);

    // Abrir archivo de profesores para validar el ID
    FILE *professorsFile = fopen("Profesores.txt", "r");
    if (professorsFile == NULL) {
        printf("Error al abrir el archivo de profesores.\n");
        return;
    }

    char buffer[256];
    int found = 0;

    // Validar que el profesor exista
    while (fgets(buffer, sizeof(buffer), professorsFile)) {
        int idFromFile;
        sscanf(buffer, "%d", &idFromFile);
        if (idFromFile == prof.idProfesor) {
            printf("Profesor encontrado.\n");
            found = 1;
            break;
        }
    }
    fclose(professorsFile);

    if (!found) {
        printf("El profesor con ID %d no está registrado.\n", prof.idProfesor);
        return;
    }

    // Abrir archivo de actividades para escritura
    FILE *activitiesFile = fopen("Actividades.txt", "a");
    if (activitiesFile == NULL) {
        printf("Error al abrir el archivo de actividades.\n");
        return;
    }

    // Crear actividades hasta que el porcentaje alcance 100%
    while (totalPercentage < 100) {
        printf("\n=== Nueva Actividad ===\n");

        // Ingresar ID de la actividad
        printf("Ingrese el ID de la actividad (un carácter): ");
        scanf("%1s", act.IdActividad);
        getchar();  // Limpiar el buffer

        // Ingresar nombre de la actividad y validar que sea único
        int nameIsUnique = 0;
        while (!nameIsUnique) {
            printf("Ingrese el nombre de la actividad: ");
            fgets(act.Nombre_Actividad, sizeof(act.Nombre_Actividad), stdin);
            act.Nombre_Actividad[strcspn(act.Nombre_Actividad, "\n")] = '\0';  // Eliminar salto de línea

            // Verificar que el nombre no esté repetido
            nameIsUnique = 1;
            for (int i = 0; i < activityCount; i++) {
                if (strcmp(existingNames[i], act.Nombre_Actividad) == 0) {
                    printf("El nombre de la actividad ya existe. Intente con otro.\n");
                    nameIsUnique = 0;
                    break;
                }
            }
        }

        // Almacenar el nombre como ya utilizado
        strcpy(existingNames[activityCount], act.Nombre_Actividad);

        // Ingresar porcentaje de la actividad
        int porcentajeValido = 0;
        do {
            printf("Ingrese el porcentaje de la actividad (restante: %d%%): ", 100 - totalPercentage);
            scanf("%i", &act.PorcentajeActividad);

            if (act.PorcentajeActividad < 0 || act.PorcentajeActividad > (100 - totalPercentage)) {
                printf("Porcentaje inválido. Debe estar entre 0 y %d.\n", 100 - totalPercentage);
            } else {
                porcentajeValido = 1;
                totalPercentage += act.PorcentajeActividad;
            }
        } while (!porcentajeValido);

        // Escribir la actividad en el archivo
        fprintf(activitiesFile, "%d;%s;%s;%d\n", prof.idProfesor, act.IdActividad, act.Nombre_Actividad, act.PorcentajeActividad);
        printf("Actividad creada correctamente.\n");

        activityCount++;
    }

    printf("\n¡Se han creado todas las actividades! El porcentaje total es 100%%.\n");

    fclose(activitiesFile);
}

   
