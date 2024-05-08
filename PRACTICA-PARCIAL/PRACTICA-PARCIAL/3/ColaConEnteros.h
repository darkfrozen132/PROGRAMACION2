/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   ColaConEnteros.h
 * Author: Leoncio
 *
 * Created on 6 de mayo de 2024, 06:09 PM
 */

#ifndef COLACONENTEROS_H
#define COLACONENTEROS_H

void cargaEnteros(void*&cola,void*(*leenumero)(ifstream&),char*nombre_archivo);
void* leenumero(ifstream&);
void mostrarEnteros(void*cola,void(*imprimenumero)(ofstream&,void*),char*nombre_archivo);
void imprimenumero(ofstream&,void*);

#endif /* COLACONENTEROS_H */

