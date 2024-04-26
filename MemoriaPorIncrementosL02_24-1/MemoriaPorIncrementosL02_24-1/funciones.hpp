/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funciones.hpp
 * Author: user
 *
 * Created on 16 de abril de 2024, 09:43 AM
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include <fstream>
#include <cstring>
#include "AperturaDeArchivos.hpp"

#define AUMENTO 5

using namespace std;

void lecturaDeLibros(const char* nombre,char***& libros,int**& stock);
char** leerStrings(ifstream& arch);
int* leerInt(ifstream& arch);
void incrementoMemoria(char***& libros,int**& stock,int& capacidad,int& cant);

void pruebaDeLecturaDeLibros(const char* nombre,char*** libros,int** stock);

void atencionDePedidos(const char* nombre,char*** libros,int** stock,int**& pedidosClientes,char***& pedidosLibros,bool**& pedidosAtendidos);
void agregaDatos(int orden,int dni,int**& pedidosClientes,int& cantClientes,int& capClientes);
void reservaMemoria(int**& pedidosClientes,int& cantClientes,int& capClientes);
int buscaIndice(int** pedidosClientes,int dni,bool& nuevo);
void agregaPedido(int orden,char codigo[20],char***& pedidosLibros,bool**& pedidosAtendidos,char*** libros,int** stock,int& cantOrden,int& maxOrden);
int buscaIndice(char*** libros,char codigo[20]);
void reserveMemoria(char***& pedidosLibros,bool**& pedidosAtendidos,int orden,int maxOrden);
void reservaMemoria2(int orden, char***& pedidosLibros, bool**& pedidosAtendidos,int& n);

void reporteDeEntregaDePedidos(const char* nombre,int** pedidosClientes,char*** pedidosLibros,bool** pedidosAtendidos);
void linea(ofstream& arch,char c);

#endif /* FUNCIONES_HPP */
