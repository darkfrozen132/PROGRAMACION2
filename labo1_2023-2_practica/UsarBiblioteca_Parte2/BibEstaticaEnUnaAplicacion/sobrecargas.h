/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   sobrecargas.h
 * Author: leoncio
 *
 * Created on 26 de marzo de 2024, 01:23 PM
 */

#ifndef SOBRECARGAS_H
#define SOBRECARGAS_H

#include "AperturaDeArchivos.h"
#include "Estructuras.h"
//Lectura
bool  operator >> (ifstream&,struct Cliente&);
bool  operator >> (ifstream&,struct Producto&);
bool  operator >> (ifstream&,struct Pedido&);

//Agregacion

void operator +=(struct Cliente*,struct Pedido&);
void operator +=(struct Producto*,struct Pedido&);

//Impresion
ofstream& operator <<(ofstream&,const struct Cliente&);
ofstream& operator<<(ofstream&,const struct Producto&);

#endif /* SOBRECARGAS_H */

