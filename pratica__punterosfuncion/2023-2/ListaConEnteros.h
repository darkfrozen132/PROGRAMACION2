/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   ListaConEnteros.h
 * Author: Leoncio
 *
 * Created on 2 de mayo de 2024, 08:21 PM
 */

#ifndef LISTACONENTEROS_H
#define LISTACONENTEROS_H

#include <fstream>
using namespace std;
void*leenumero(ifstream&input);
double calculanumero(void*num);
int cmpnumero(const void*,const void*);
#endif /* LISTACONENTEROS_H */

