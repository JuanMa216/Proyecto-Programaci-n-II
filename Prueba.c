#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
            // Eliminar salto de línea si existe
            size_t len = strlen(idMateria);
            if (len > 0 && idMateria[len - 1] == '\n') {
                idMateria[len - 1] = '\0';
            }
        }

        // Obtener el segundo token (Nombre de la materia)
        campo = strtok(NULL, ";");
        if (campo != NULL) {
            strncpy(nombreMateria, campo, sizeof(nombreMateria));
            nombreMateria[sizeof(nombreMateria) - 1] = '\0'; // Asegurar el fin de cadena
            // Eliminar salto de línea si existe
            size_t len = strlen(nombreMateria);
            if (len > 0 && nombreMateria[len - 1] == '\n') {
                nombreMateria[len - 1] = '\0';
            }
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

        // Debugging: Imprimir las cadenas comparadas
        printf("Comparando: '%s' '%s' con '%s' '%s'\n", codeLower, nameLower, idMateriaLower, nombreMateriaLower);

        // Comparar el ID y el nombre de la materia
        if (strcmpi(idMateriaLower, codeLower) == 0 && strcmpi(nombreMateriaLower, nameLower) == 0) {
            printf("Coincidencia encontrada.\n");
            fclose(fpMaterias);
            return 1; // Coincidencia encontrada
        }
    }
    

    fclose(fpMaterias);
    return 0; // No se encontró coincidencia
}


