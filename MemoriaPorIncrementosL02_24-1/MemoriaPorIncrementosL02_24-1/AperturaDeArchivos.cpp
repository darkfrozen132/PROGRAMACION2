/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "AperturaDeArchivos.hpp"

void AperturaDeUnArchivoDeTextosParaLeer(ifstream &archivo, 
                                         const char*nombreDelArchivo){
    archivo.open(nombreDelArchivo,ios::in);
}

void AperturaDeUnArchivoDeTextosParaEscribir(ofstream &archivo, 
                                             const char*nombreDelArchivo){
    archivo.open(nombreDelArchivo,ios::out);
}