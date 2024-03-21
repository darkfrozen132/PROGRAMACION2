/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Ricardo
 *
 * Created on 21 de marzo de 2024, 12:37 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>                
using namespace std;
#include "Persona.h"
#include "funciones.h"

/*
 * 
 */
int main(int argc, char** argv) {
    ifstream archPersonas("personas.csv",ios::in);
    if(not archPersonas.is_open()){
        cout<<"ERROR: No se pudo abrir el l archivo personas.csv"<<endl;
        exit(1);
    }
    struct Persona empleados[100];
    int n=0;
    while(true){
        archPersonas>>empleados[n];
        if(archPersonas.eof())break;
        n++;
    }
    
    return 0;
}

