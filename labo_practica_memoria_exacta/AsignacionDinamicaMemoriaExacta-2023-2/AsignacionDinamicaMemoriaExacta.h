/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   AsignacionDinamicaMemoriaExacta.h
 * Author: USER
 *
 * Created on 8 de abril de 2024, 10:30
 */

#ifndef ASIGNACIONDINAMICAMEMORIAEXACTA_H
#define ASIGNACIONDINAMICAMEMORIAEXACTA_H

void lecturaDeProductos(const char*Nombrearch,char ***&productos,int *&stock,
        double *&precios);
char **leerCodDescripccion(ifstream &arch);
char *leeCadena(ifstream &arch);
void pruebaDeLecturaDeProductos(const char*Nombrearch,char ***productos,int *stock,
        double *precios);
void imprimeProductos(char **productos,ofstream &arch);
/////////////////////////////////////////////////////////////////////////
void lecturaDePedidos(const char *NombreArch,int *&fechaPedidos,char ***&codigoPedidos,
        int ***&dniCantPedidos);
int **colocarDNICant(int **&buffOriginal,int &nDatos,int dni,int Cped);
char **colocarCodigo(char **&buffOriginal,int &nDatos,char *codigo);
int buscarFecha(int *buffFecha,int fecha);
int leerFecha(ifstream &arch);
//void agregarDNICant(int **&buffCodigo,int dni,int Cped);
//int **agregarDNICantSI(int dni,int Cped);
void agregarDNICantSegundaFase(int *&buff,int dni,int cant);
//void agregarCodigo(char **&buffDNICant,char *codigo);
char** agregarCodigoSI(char *codigo);
void pruebaDeLecturaDePedidos(const char *NombreArch,int *fechaPedidos,char ***codigoPedidos,
        int ***dniCantPedidos);
void imprimeCodigosYDNICant(ofstream &arch,char **codigoPedidos,int **dniCantPedidos);
void imprimeDNICant(ofstream &arch,int **dniCantPedidos);
void imprimeDNICantDatos(ofstream &arch,int *dniCantPedidos);
void agregarDNICantSI(int **buffDNICant,int dni,int Cped);
void agregarCodigoSI(char **buffDNICant,char *codigo);
///////////////////////Falta Cambiar/////////////////////////////
#endif /* ASIGNACIONDINAMICAMEMORIAEXACTA_H */

