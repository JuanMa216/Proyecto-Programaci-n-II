#include <stdio.h>
#include <string.h>
#include "Estructuras.h"

void makeTeacher()
{
    int n; 

    printf("\n¿Cuántos profesores desea ingresar? ");
    scanf("%i", &n);

    for (int i = 0; i < n; i++) {

        Profesor prof;
        int NumAsig;

        printf("\nIngrese el ID del docente: ");
        scanf("%i", &prof.idProfesor);

        FILE *Professor = fopen("C:\\Users\\julia\\OneDrive\\Documentos\\GitHub\\Proyecto-Programaci-n-II\\output\\Profesores.txt", "a+");
        if (Professor == NULL) {
            printf("Error al abrir el archivo.\n");
            return;
        }

        char line[256];
        int found = 0;

        rewind(Professor); // Empezar desde el inicio 
        while (fgets(line, sizeof(line), Professor)) {
            int idRegistrado;
            sscanf(line, "%d", &idRegistrado);
            if (idRegistrado == prof.idProfesor) {
                printf("El profesor con ID %d ya se encuentra registrado.\n", prof.idProfesor);
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("Ingrese el nombre del profesor: ");
            getchar(); 
            fgets(prof.nombre, sizeof(prof.nombre), stdin);
            prof.nombre[strcspn(prof.nombre, "\n")] = '\0'; 

            printf("Número de asignaturas que dicta el profesor: ");
            scanf("%i", &NumAsig);
            getchar();

            for (int j = 1; j <= NumAsig; j++) {

                printf("Ingrese el nombre de la asignatura %i: ", j);
                fgets(prof.nombre_asignatura, sizeof(prof.nombre_asignatura), stdin);
                prof.nombre_asignatura[strcspn(prof.nombre_asignatura, "\n")] = '\0';

                fprintf(Professor, "%d;%s;%s\n", 
                    prof.idProfesor, prof.nombre, prof.nombre_asignatura);
                printf("Registrado correctamente.\n\n", j);

            }
        }

        fclose(Professor); // Cerrar el archivo
    }
}

void editData() {

    int ID, NumAsig;
    Profesor prof;

    printf("\nIngrese el ID del docente que desea editar: ");
    scanf("%i", &ID);

    FILE *Professor = fopen("C:\\Users\\julia\\OneDrive\\Documentos\\GitHub\\Proyecto-Programaci-n-II\\output\\Profesores.txt", "r");
    if (Professor == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    FILE *TempFile = fopen("C:\\Users\\julia\\OneDrive\\Documentos\\GitHub\\Proyecto-Programaci-n-II\\output\\Temp.txt", "w");
    if (TempFile == NULL) {
        printf("Error al crear el archivo temporal.\n");
        fclose(Professor);
        return;
    }

    char line[256];
    int found = 0;

    while (fgets(line, sizeof(line), Professor)) {

        int idRegistrado;
        sscanf(line, "%d", &idRegistrado);

        if (idRegistrado == ID) {

            found = 1;

            printf("Ingrese el nuevo nombre del profesor: ");
            getchar(); 
            fgets(prof.nombre, sizeof(prof.nombre), stdin);
            prof.nombre[strcspn(prof.nombre, "\n")] = '\0';

            printf("Número de asignaturas que dicta el profesor: ");
            scanf("%i", &NumAsig);

            for (int j = 1; j <= NumAsig; j++) {
                getchar();
                printf("Ingrese el nombre de la asignatura %i: ", j);
                fgets(prof.nombre_asignatura, sizeof(prof.nombre_asignatura), stdin);
                prof.nombre_asignatura[strcspn(prof.nombre_asignatura, "\n")] = '\0';

                fprintf(TempFile, "%d;%s;%s\n", 
                    ID, prof.nombre, prof.nombre_asignatura);
            }
        } else {
            fputs(line, TempFile);
        }
    }

    fclose(Professor);
    fclose(TempFile);

    remove("C:\\Users\\julia\\OneDrive\\Documentos\\GitHub\\Proyecto-Programaci-n-II\\output\\Profesores.txt");
    rename("C:\\Users\\julia\\OneDrive\\Documentos\\GitHub\\Proyecto-Programaci-n-II\\output\\Temp.txt", 
           "C:\\Users\\julia\\OneDrive\\Documentos\\GitHub\\Proyecto-Programaci-n-II\\output\\Profesores.txt");

    if (found) {
        printf("Los datos del profesor con ID %d han sido actualizados.\n", ID);
    } else {
        printf("No se encontró un profesor con el ID %d.\n", ID);
    }
}

void deleteTeacher() {

    int ID;
    int found = 0;

    printf("\nIngrese el ID del profesor que desea eliminar: ");
    scanf("%d", &ID);

    FILE *Professor = fopen("C:\\Users\\julia\\OneDrive\\Documentos\\GitHub\\Proyecto-Programaci-n-II\\output\\Profesores.txt", "r");
    if (Professor == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    FILE *TempFile = fopen("C:\\Users\\julia\\OneDrive\\Documentos\\GitHub\\Proyecto-Programaci-n-II\\output\\Temp.txt", "w");
    if (TempFile == NULL) {
        printf("Error al crear el archivo temporal.\n");
        fclose(Professor);
        return;
    }

    char line[256];

    while (fgets(line, sizeof(line), Professor)) {
        
        int idRegistrado;
        sscanf(line, "%d", &idRegistrado); 

        if (idRegistrado == ID) {
            found = 1; 
            printf("Eliminando al profesor con ID %d.\n", ID);
            continue; 
        }

        fputs(line, TempFile);
    }

    fclose(Professor);
    fclose(TempFile);

    remove("C:\\Users\\julia\\OneDrive\\Documentos\\GitHub\\Proyecto-Programaci-n-II\\output\\Profesores.txt");
    rename("C:\\Users\\julia\\OneDrive\\Documentos\\GitHub\\Proyecto-Programaci-n-II\\output\\Temp.txt", 
                "C:\\Users\\julia\\OneDrive\\Documentos\\GitHub\\Proyecto-Programaci-n-II\\output\\Profesores.txt");

    if (found) {
        printf("El profesor con ID %d ha sido eliminado exitosamente.\n", ID);
    } else {
        printf("No se encontró un profesor con el ID %d.\n", ID);
    }

}


void showTeachers() {

    FILE *fpTemporal = fopen("C:\\Users\\julia\\OneDrive\\Documentos\\GitHub\\Proyecto-Programaci-n-II\\output\\Profesores.txt", "r");
    if (fpTemporal == NULL) {
        printf("Error al abrir el archivo para la lectura.\n");
        return;
    }

    char buffer[256];
    Profesor prof;

    printf("Listado de Profesores:\n");
    printf("+-------+----------------------+---------------------------+\n");
    printf("| %-5s | %-20s | %-25s |\n", "ID", "Nombre", "Asignatura");
    printf("+-------+----------------------+---------------------------+\n");

    while (fgets(buffer, sizeof(buffer), fpTemporal)) {
        if (!esLineaVacia(buffer)) {
            char *campo;

            // Leer y almacenar el ID del profesor
            campo = strtok(buffer, ";");
            if (campo != NULL) {
                prof.idProfesor = atoi(campo); // Convertir a entero
            }

            // Leer y almacenar el nombre del profesor
            campo = strtok(NULL, ";");
            if (campo != NULL) {
                strncpy(prof.nombre, campo, sizeof(prof.nombre) - 1);
                prof.nombre[sizeof(prof.nombre) - 1] = '\0';
                prof.nombre[strcspn(prof.nombre, "\n")] = '\0'; // Remover salto de línea
            }

            // Leer y almacenar la asignatura
            campo = strtok(NULL, ";");
            if (campo != NULL) {
                strncpy(prof.nombre_asignatura, campo, sizeof(prof.nombre_asignatura) - 1);
                prof.nombre_asignatura[sizeof(prof.nombre_asignatura) - 1] = '\0';
                prof.nombre_asignatura[strcspn(prof.nombre_asignatura, "\n")] = '\0'; // Remover salto de línea
            }

            // Imprimir los datos del profesor en formato de tabla
            printf("| %-5d | %-20s | %-25s |\n", prof.idProfesor, prof.nombre, prof.nombre_asignatura);
        }
    }

    printf("+-------+----------------------+---------------------------+\n");

    fclose(fpTemporal);
}

void makeSubject() {

    int n;
    printf("Ingrese el numero de materias que desea ingresar: ");
    scanf("%i", &n);
    getchar();

    for (int i = 0; i < n; i++) {

        Asignatura Asign;

        printf("\nIngrese el codigo de la asignatura: ");
        fgets(Asign.idAsignatura, sizeof(Asign.idAsignatura), stdin);
        Asign.idAsignatura[strcspn(Asign.idAsignatura, "\n")] = '\0'; 

        FILE *Asignaturas = fopen("C:\\Users\\julia\\OneDrive\\Documentos\\GitHub\\Proyecto-Programaci-n-II\\output\\Asignaturas.txt", "r+");
        if (Asignaturas == NULL) {
            printf("Error al abrir el archivo.\n");
            return;
        }

        char line[256];
        int found = 0;

        rewind(Asignaturas); 
        while (fgets(line, sizeof(line), Asignaturas)) {
            char idRegistrado[20];
            sscanf(line, "%[^;]", idRegistrado); 
            if (strcmp(idRegistrado, Asign.idAsignatura) == 0) {
                printf("La asignatura con el codigo %s ya se encuentra registrada.\n\n", Asign.idAsignatura);
                found = 1;
                break;
            }

        }

        if (!found) {
            
            getchar(); 
            printf("Ingrese el nombre de la asignatura: ");
            fgets(Asign.nombre, sizeof(Asign.nombre), stdin);
            Asign.nombre[strcspn(Asign.nombre, "\n")] = '\0'; 

            printf("Ingrese la cantidad de creditos que tiene la asignatura: ");
            scanf("%i", &Asign.creditos);
            getchar(); 

            if (Asign.creditos <= 0 || Asign.creditos > 5) {
                printf("La cantidad de créditos debe ser mayor a 0 y menor o igual a 4. Registro cancelado.\n");
                fclose(Asignaturas);
                continue;
            }

            fprintf(Asignaturas, "%s;%s;%i\n", Asign.idAsignatura, Asign.nombre, Asign.creditos);
            printf("Asignatura registrada correctamente.\n\n");

        }

        fclose(Asignaturas);
    }
}

/*
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

*/