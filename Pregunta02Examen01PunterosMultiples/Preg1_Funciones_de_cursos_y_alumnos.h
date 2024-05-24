/* 
 * File:   Preg1_Funciones_de_cursos_y_alumnos.h
 * Author: Crystallyzer
 *
 * Created on 9 de mayo de 2024, 10:01 PM
 */

#ifndef PREG1_FUNCIONES_DE_CURSOS_Y_ALUMNOS_H
#define PREG1_FUNCIONES_DE_CURSOS_Y_ALUMNOS_H

#include <fstream>
using namespace std;

void cargarCursosYEscalas(char ***&,double *&,double *,const char *,const char *);
void cargarCursos(char ***&,double *&,const char *);
void incrementarEspaciosCursos(char ***&,double *&,int &,int &);
char *leerCadenaComa(ifstream &);
char *leerCadenaEnter(ifstream &);
void insertarCursos(char **&,char *,char *,char *);
void cargarEscalas(double *,const char *);
void pruebaDeCargaDeCursos(char ***,double *,double *,const char *);
void imprimirCursos(ofstream &,char **,double);
void imprimeLinea(ofstream &,int,char);
void cargarAlumnos(int *&,int **&,char ***&,const char *);
void incrementarEspaciosAlumnos(int *&,int **&,char ***&,int &,int &);
void insertarAlumnos(int *&,int,int,int,char);
void insertarAlumnosNomb(char **&,char *,char);
void pruebaDeCargaDeAlumnos(int *,int **,char ***,const char *);
void imprimirAlumnos(ofstream &,int,int *,char **);

#endif /* PREG1_FUNCIONES_DE_CURSOS_Y_ALUMNOS_H */
