/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: leoncio
 *
 * Created on 4 de abril de 2024, 01:43 PM
 */

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
#include "Estructuras.h"
#include "AperturaDeArchivos.h"
#include "sobrecargas.h"
int main(int argc, char** argv) {
    ifstream archAlumnos,archCursos,archEscalas,archMatricula;
    AperturaDeUnArchivoDeTextosParaLeer(archAlumnos,"Alumnos.txt");
    AperturaDeUnArchivoDeTextosParaLeer(archCursos,"Cursos.txt");
    AperturaDeUnArchivoDeTextosParaLeer(archEscalas,"Escalas.txt");
    AperturaDeUnArchivoDeTextosParaLeer(archMatricula,"Matricula.txt");
    struct StCurso arrCurso[1000];
    struct StAlumno arrAlumno[1000];
    struct StRegistroDeMatricula arrRegistroMatricula[1000];
    int i=0;
    while(archCursos>>arrCurso[i]){
        ++i;
    }
    cout<<arrCurso[0].nombreDelProfesor<<endl;
    return 0;
}

