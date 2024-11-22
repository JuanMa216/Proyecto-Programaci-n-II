#include <stdio.h>
#include <string.h>
#include "Estructuras.h"

void Mostrar_Estudiantes () {
    FILE *fpTemporal = fopen("Lista_de_Estudiantes.txt", "r");

    if (fpTemporal == NULL)
    {
        printf("No se pudo abrir correctamente.\n");
        return;
    }

    int i = 0;
    char buffer[100];
    char cad_aux[100];
    while (fgets (buffer, 100, fpTemporal) != NULL) {
    i++;
        if (!esLineaVacia(buffer))
        {
            char *puntoComa = strchr(buffer, ';');
            if (puntoComa != NULL)
            {
                *puntoComa = '\0';
            }
            strcpy(cad_aux, buffer);
            printf("%i. Estudiante: %s\n", i-1, cad_aux);
        } else {
        continue;
        }
    }
fclose(fpTemporal);
}

/*
// Función para mostrar los profesores
void Mostrar_Profesores() {
    FILE *fpTemporal = fopen("Asignaturas.txt", "r");

    if (fpTemporal == NULL) {
        printf("Error al abrir el archivo para la lectura.\n");
        return;
    }

    char buffer[100];
    int i = 0;

    printf("Listado de Profesores:\n");
    while (fgets(buffer, sizeof(buffer), fpTemporal)) {
        if (!esLineaVacia(buffer)) {
            i++;
            if (i == 1)
            {
                continue;
            }
            // Procesar los tokens
            char *campo = strtok(buffer, ";");
            if (campo != NULL) {
                printf("ID: %s ", campo);
            }

            campo = strtok(NULL, ";");
            if (campo != NULL) {
                printf("Nombre: %s ", campo);
            }

            campo = strtok(NULL, ";");
            if (campo != NULL) {
                printf("Codigo: %s ", campo);
            }

            campo = strtok(NULL, ";");
            if (campo != NULL) {
                printf("Asignatura: %s ", campo);
            }

            campo = strtok(NULL, ";");
            if (campo != NULL) {
                printf("Cantidad de grupos: %s\n", campo);
            }

        } else {
        continue;
        }
    }

    fclose(fpTemporal);
}
*/

void Mostrar_Profesores() {
    FILE *fpTemporal = fopen("Profesores.txt", "r");

    if (fpTemporal == NULL) {
        printf("Error al abrir el archivo para la lectura.\n");
        return;
    }

    char buffer[100];
    int i = 0;
    Profesor profesor;  // Declaración de la estructura

    printf("Listado de Profesores:\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("| %-5s | %-20s | %-10s | %-18s | %-10s |\n", "ID", "Nombre", "Codigo", "Asignatura", "Grupos");
    printf("-------------------------------------------------------------------------------\n");

    while (fgets(buffer, sizeof(buffer), fpTemporal)) {
        if (!esLineaVacia(buffer)) {
            i++;

            if (i == 1) {
                continue;
            }

            // Procesar los tokens
            char *campo;

            // Leer y almacenar el ID del profesor
            campo = strtok(buffer, ";");
            if (campo != NULL) {
                profesor.idProfesor = atoi(campo);  // Convertir el string a entero
            }

            // Leer y almacenar el nombre del profesor
            campo = strtok(NULL, ";");
            if (campo != NULL) {
                strncpy(profesor.nombre, campo, sizeof(profesor.nombre) - 1);
            }

            // Leer y almacenar el código de la materia
            campo = strtok(NULL, ";");
            if (campo != NULL) {
                // Aquí podrías almacenar el código de la materia en el array materias[], 
                // pero eso depende de cómo estés organizando las materias.
                strcpy(profesor.codigo_materia, campo);  // Esto es solo un ejemplo
            }

            // Leer y almacenar la asignatura
            campo = strtok(NULL, ";");
            if (campo != NULL) {
                strcpy(profesor.nombre_asignatura, campo);  // Similar al código de la materia, si se desea
            }

            // Leer y almacenar el grupo
            campo = strtok(NULL, ";");
            if (campo != NULL) {
                profesor.Grupo = atoi(campo);  // Convertir el string a entero
            }

            // Imprimir los datos del profesor en formato de tabla
            printf("| %-5d | %-20s | %-10s | %-18s | %-10d |\n", profesor.idProfesor, profesor.nombre, profesor.codigo_materia, profesor.nombre_asignatura, profesor.Grupo);
        } else {
            //printf("Línea %d está vacía.\n", i + 1);
            continue;
        }
    }

    printf("-------------------------------------------------------------------------------\n");

    fclose(fpTemporal);
}

void Crear_Grupo() {
    Materia materias[20];

    FILE *fpGrupo = fopen("Grupo.txt", "a");
    if (fpGrupo == NULL) {
        printf("Error al crear el archivo.\n");
        return;
    }

    FILE *fpDocentes = fopen("Profesores.txt", "r");
    if (fpDocentes == NULL) {
        fclose(fpGrupo);
        printf("Error al abrir el archivo de profesores.\n");
        return;
    }

    Materia nuevaMateria;
    printf("Bienvenido docente\nIngrese el nombre de la materia: ");
    getchar();
    fgets(nuevaMateria.nombre, sizeof(nuevaMateria.nombre), stdin);
    size_t len = strlen(nuevaMateria.nombre);
    if (len > 0 && nuevaMateria.nombre[len - 1] == '\n') {
        nuevaMateria.nombre[len - 1] = '\0';
    }

    int verificar_codigo = 0;
    do {
        printf("Ingrese el codigo de la materia: ");
        scanf("%5s", nuevaMateria.idMateria);
        getchar(); // Consumir el salto de línea
        printf ("%s\n", nuevaMateria.idMateria);
        printf("%s\n", nuevaMateria.nombre);
        verificar_codigo = VerificarID_Materia(nuevaMateria.idMateria, nuevaMateria.nombre);
        printf("%i\n", verificar_codigo);
        if (!verificar_codigo) {
            printf("El codigo o nombre de la materia no coincide. Intente nuevamente.\n");
        }
    } while (verificar_codigo == 0);
    

    printf("Ingrese el codigo del profesor: ");
    scanf("%5s", nuevaMateria.idProfesor);
    getchar();

    char *id_objetivo = nuevaMateria.idProfesor;
    char buffer[100];
    int profesorEncontrado = 0;

    while (fgets(buffer, sizeof(buffer), fpDocentes) != NULL) {
        char *campo = strtok(buffer, ";");
        if (campo != NULL && strcmp(campo, id_objetivo) == 0) {
            profesorEncontrado = 1;
            break;
        }
    }

    if (profesorEncontrado) {
        fprintf(fpGrupo, "%s;%s;%s\n", nuevaMateria.idMateria, nuevaMateria.nombre, nuevaMateria.idProfesor);
        printf("Grupo creado exitosamente.\n");
    } else {
        printf("La ID ingresada no ha sido encontrada.\n");
    }

    fclose(fpDocentes);
    fclose(fpGrupo);
}
