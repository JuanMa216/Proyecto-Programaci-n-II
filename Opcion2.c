#include <stdio.h>
#include <string.h>
#include "Estructuras.h"

void createActivities() {
    Profesor prof;
    int n;

    // Solicitar el ID del profesor
    printf("\nIngrese el ID del profesor: ");
    scanf("%d", &prof.idProfesor);
    getchar();

    // Verificar si el profesor existe en Profesores.txt
    FILE *Profesores = fopen("Profesores.txt", "r");
    if (Profesores == NULL) {
        printf("Error al abrir el archivo Profesores.txt.\n");
        return;
    }

    char line[256];
    int found = 0;

    while (fgets(line, sizeof(line), Profesores)) {
        int idRegistrado;
        char nombreProfesor[50];
        sscanf(line, "%d;%49[^\n]", &idRegistrado, nombreProfesor);

        if (idRegistrado == prof.idProfesor) {
            found = 1;
            strcpy(prof.nombre, nombreProfesor);
            break;
        }
    }
    fclose(Profesores);

    if (!found) {
        printf("El profesor con ID %d no está registrado.\n", prof.idProfesor);
        return;
    }

    printf("Profesor encontrado: %s (ID: %d)\n", prof.nombre, prof.idProfesor);

    // Solicitar el número de actividades que desea crear
    printf("\nIngrese el número de actividades que desea ingresar: ");
    scanf("%d", &n);
    getchar();

    FILE *Actividades = fopen("Actividades.txt", "a+");
    if (Actividades == NULL) {
        printf("Error al abrir el archivo Actividades.txt.\n");
        return;
    }

    for (int i = 0; i < n; i++) {

        Acvtividad Activ;
        int foundActividad = 0;

        printf("\nIngrese el código de la actividad: ");
        fgets(Activ.IdActividad, sizeof(Activ.IdActividad), stdin);
        Activ.IdActividad[strcspn(Activ.IdActividad, "\n")] = '\0';

        rewind(Actividades);
        while (fgets(line, sizeof(line), Actividades)) {
            char idRegistrado[20];
            sscanf(line, "%[^;]", idRegistrado);

            if (strcmp(idRegistrado, Activ.IdActividad) == 0) {
                printf("La actividad con el código %s ya está registrada.\n\n", Activ.IdActividad);
                foundActividad = 1;
                break;
            }
        }

        if (foundActividad) {
            continue;
        }

        printf("Ingrese el nombre de la actividad: ");
        fgets(Activ.nombre, sizeof(Activ.nombre), stdin);
        Activ.nombre[strcspn(Activ.nombre, "\n")] = '\0';

        printf("Ingrese el porcentaje de la actividad: ");
        scanf("%d", &Activ.PorcentajeActividad);
        getchar();

        if (Activ.PorcentajeActividad <= 0 || Activ.PorcentajeActividad > 100) {
            printf("El porcentaje debe ser mayor a 0 y menor o igual a 100. Registro cancelado.\n");
            continue;
        }

        // Registrar la actividad asociada al profesor
        fprintf(Actividades, "%s;%s;%d;%d;%s\n",
                Activ.IdActividad, Activ.nombre,
                Activ.PorcentajeActividad, prof.idProfesor, prof.nombre);

        printf("Actividad '%s' (código: %s) registrada correctamente para el profesor '%s' (ID: %d).\n",
               Activ.nombre, Activ.IdActividad, prof.nombre, prof.idProfesor);
    }

    fclose(Actividades);
}
