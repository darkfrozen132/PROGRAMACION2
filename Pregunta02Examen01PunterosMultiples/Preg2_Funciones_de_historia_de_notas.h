/* 
 * File:   Preg2_Funciones_de_historia_de_notas.h
 * Author: Crystallyzer
 *
 * Created on 10 de mayo de 2024, 12:28 AM
 */

#ifndef PREG2_FUNCIONES_DE_HISTORIA_DE_NOTAS_H
#define PREG2_FUNCIONES_DE_HISTORIA_DE_NOTAS_H

#include <fstream>
using namespace std;

void cargarNotas(char ***&,int ***&,double **&,int **,char ***,double *,char ***,double *,const char *);
int buscarAlumno(int **,int);
int codAluIguales(int *,int);
void agregarNotaCursoYCosto(char **&,int **&,double *&,int *,char **,double *,char ***,double *,char *,int,int,int &);
int buscarBika(char **,char *,int);
void insertarCursoNota(int *&,int,int,int);
void insertarCosto(double &,int *,char **,double *,char ***,double *,char *);
int buscarCurso(char ***,char *);
int codCurIguales(char **,char *);
void cargarArreglos(char ***&,int ***&,double **&,int *);
void cargarInterno(char **&,int **&,double *&,int);
void pruebaDeCargaDeNotas(char ***,int ***,double **,int **,char ***,const char *);
void imprimirAlumnos2(ofstream &,char **,int **,double *,int *,char **);
void imprimirCursos(ofstream &,int,char *,int *,double);

#endif /* PREG2_FUNCIONES_DE_HISTORIA_DE_NOTAS_H */
