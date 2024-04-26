/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>
/* 
 * File:   funciones.h
 * Author: Administrador
 *
 * Created on 18 de abril de 2024, 13:51
 */
using namespace std;
#ifndef FUNCIONES_H
#define FUNCIONES_H
char *obtenerCadena(ifstream &arch,char delimitador);
void incrementarLibros(char ***&libros,int **&stock,int &numeroLibros,int &capacidadLibros);
void agregarLibro(char *codigo,char *nombre,char *autor,char **&libroActual,int *&stockActual,int stock);
void lecturaDeLibros(char *nombreArch,char ***&libros,int **&stock);
void pruebaDeLecturaDeLibros(char *nombreArch,char ***libros,int **stock);
void atencionDePedidos(char *nombreArch,char ***libros,int **&stock,int **&pedidosClientes,char ***&pedidosLibros,bool **&pedidosAtendidos);
#endif /* FUNCIONES_H */
