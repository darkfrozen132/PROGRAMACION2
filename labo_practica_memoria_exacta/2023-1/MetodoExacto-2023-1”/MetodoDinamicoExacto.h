/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   MetodoDinamicoExacto.h
 * Author: Leoncio
 *
 * Created on 11 de abril de 2024, 05:04 PM
 */

#ifndef METODODINAMICOEXACTO_H
#define METODODINAMICOEXACTO_H

#include<fstream>


void lecturaAlumnos (char*nombre_archivo,int*&alumno_Codigo, char**& alumno_Nombre,
                char*&alumno_Modalidad, int*&alumno_Porcentaje, int*&alumno_Escala);
void pruebaLecturaAlumnos (char*nombre_archivo,int*&alumno_Codigo, char**& alumno_Nombre,
                char*&alumno_Modalidad, int*&alumno_Porcentaje, int*&alumno_Escala);
void lecturaCursos (char*,int*& alumno_Codigo,int*& alumno_Escala,char**& curso_Nombre,
                double*&curso_Credito,int**& curso_Alumnos,int*& alumno_Escala);







void pasar_a_arreglos(int*&alumno_Codigo, char**&alumno_Nombre,  char*&  alumno_Modalidad,  int*&  alumno_Porcentaje, int*&   alumno_Escala,
                   int*  buff_alumno_Codigo   ,char**buff_alumno_Nombre,char*buff_alumno_Modalidad,int*buff_alumno_porcentaje,
            int*buff_alumno_escala,int cant);
char* leer_cadena(ifstream&input,char c);
void leer_valores(ifstream&input,int&porcentaje,int&escala,char&modalidad);
/*
 
        char **alumno_Nombre,**curso_Nombre, *alumno_Modalidad;
        int *alumno_Codigo, *alumno_Porcentaje,*alumno_Escala;
        int **curso_Alumnos;
        double *curso_Credito;
 */
#endif /* METODODINAMICOEXACTO_H */

