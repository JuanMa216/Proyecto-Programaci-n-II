#ifndef Estructuras_h
#define Estructuras_h

#include <stdio.h>
//#include "Estructuras.c"


// Estructura para las notas
typedef struct {
    char idMateria[6];         
    float calificacion;   
    int porcentaje;  
} Nota;

// Estructura para las materias
typedef struct {
    char idAsignatura[6];         
    char nombre[40];       
    int creditos;   
} Asignatura;

// Estructura para los estudiantes
typedef struct {
    int idEstudiante;      
    char nombre[30];       
    Nota notas[12];
    int numNotas;          
} Estudiante;

// Estructura para los profesores
typedef struct {
    int idProfesor;        
    char nombre[30];    
    char nombre_asignatura[30];     
} Profesor;

// Funciones declaradas
int esLineaVacia (const char *linea);

#endif
