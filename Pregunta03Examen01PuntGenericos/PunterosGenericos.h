/* 
 * File:   PunterosGenericos.h
 * Author: Crystallyzer
 *
 * Created on 10 de mayo de 2024, 07:33 PM
 */

#ifndef PUNTEROSGENERICOS_H
#define PUNTEROSGENERICOS_H

#include <fstream>
using namespace std;

void CargaCursos(int *,void *&,const char *);
void inicializarAlumno(int,void *&);
void inicializarNotas(void *&);
int buscarCodigo(int *,int);
void insertarNota(void *&,char *,int *,int *);
void insertarCurso(void *&,char *,int *,int *);
void pasarInterno(void *&);
void ActualizaVeces(void *&);
void actualizarAlumno(void *&);
void actualizarCurso(void *,void *,int &,int &,int &,int &,int);
void contarCurso(void *,char *,int &);
void imprime(void *);
void imprimirAlu(void *);
void imprimirCurso(void *);

#endif /* PUNTEROSGENERICOS_H */
