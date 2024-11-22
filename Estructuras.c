#include "Estructuras.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


//Funcion que verifica si una linea esta vacia.
int esLineaVacia(const char *linea) {
    // Recorre la línea para verificar si hay caracteres visibles
    while (*linea) {
        if (!isspace(*linea)) {
            return 0; // No está vacía (tiene algún carácter visible)
        }
        linea++;
    }
    return 1; // Está vacía (solo contiene espacios o está completamente vacía)
}

void Pause_Menu(){
    system("pause");
    system("cls");
}
//Asignar Materia al profesor (Mostrar Listado de Profesores con: ID, Nombre, Materias, Codigo de la asignatura, Grupo)

//Funcion que verifica si el codigo ingresado coincide con el nombre de la materia.
int VerificarID_Materia(const char *code, const char *name) {
    char buffer[100];
    char *campo;
    FILE *fpMaterias = fopen("Lista_Asignaturas.txt", "r");
    if (fpMaterias == NULL) {
        printf("Error al abrir el archivo de materias.\n");
        return 0;
    }

    // Convertir el código y el nombre de la materia a minúsculas
    char codeLower[10];
    char nameLower[40];
    
    // Convertir código a minúsculas
    for (int i = 0; code[i]; i++) {
        codeLower[i] = tolower(code[i]);
    }
    codeLower[strlen(code)] = '\0'; // Asegurar que la cadena esté terminada correctamente

    // Convertir nombre de la materia a minúsculas
    for (int i = 0; name[i]; i++) {
        nameLower[i] = tolower(name[i]);
    }
    nameLower[strlen(name)] = '\0'; // Asegurar que la cadena esté terminada correctamente

    // Leer línea por línea del archivo de materias
    while (fgets(buffer, sizeof(buffer), fpMaterias) != NULL) {
        char idMateria[10];
        char nombreMateria[40];
        
        // Obtener el primer token (ID de la materia)
        campo = strtok(buffer, ";");
        if (campo != NULL) {
            strncpy(idMateria, campo, sizeof(idMateria));
            idMateria[sizeof(idMateria) - 1] = '\0'; // Asegurar el fin de cadena
        }

        // Obtener el segundo token (Nombre de la materia)
        campo = strtok(NULL, ";");
        if (campo != NULL) {
            strncpy(nombreMateria, campo, sizeof(nombreMateria));
            nombreMateria[sizeof(nombreMateria) - 1] = '\0'; // Asegurar el fin de cadena
        }

        // Convertir la materia leída del archivo a minúsculas
        char idMateriaLower[10];
        char nombreMateriaLower[40];
        
        for (int i = 0; idMateria[i]; i++) {
            idMateriaLower[i] = tolower(idMateria[i]);
        }
        idMateriaLower[strlen(idMateria)] = '\0'; // Asegurar que la cadena esté terminada correctamente

        for (int i = 0; nombreMateria[i]; i++) {
            nombreMateriaLower[i] = tolower(nombreMateria[i]);
        }
        nombreMateriaLower[strlen(nombreMateria)] = '\0'; // Asegurar que la cadena esté terminada correctamente
        
        // Comparar el código de la materia
        int matchCodigo = 1;
        for (int i = 0; idMateriaLower[i] != '\0'; i++) {
            if (idMateriaLower[i] != codeLower[i]) {
                matchCodigo = 0;
                printf("%i ", i);
                break;
            }
        }
        
        // Comparar el nombre de la materia
        int matchNombre = 1;
        for (int i = 0; nombreMateriaLower[i] != '\0'; i++) {
            if (nombreMateriaLower[i] != nameLower[i]) {
                matchNombre = 0;
                break;
            }
        }

        // Si ambos coinciden, devolver 1
        if (matchCodigo && matchNombre) {
            fclose(fpMaterias);
            return 1; // Coincidencia encontrada
        }
    }

    fclose(fpMaterias);
    return 0; // No se encontró coincidencia
}