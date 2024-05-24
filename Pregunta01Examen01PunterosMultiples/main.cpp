/* 
 * File:   Pregunta01Examen01PunterosMultiples.cpp
 * Author: Crystallyzer
 *
 * Created on 9 de mayo de 2024, 09:55 PM
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include "Preg1_Funciones_de_cursos_y_alumnos.h"

using namespace std;

int main(int argc, char** argv) {
    char ***cursos,***alumnos_nom_mod;
    double *cursos_cred,escalas[5];
    int *alumnos_cod,**alumnos;
    
    cargarCursosYEscalas(cursos,cursos_cred,escalas,"Cursos.csv","Escalas.csv");
    pruebaDeCargaDeCursos(cursos,cursos_cred,escalas,"PruebaCursos.txt");
    
    cargarAlumnos(alumnos_cod,alumnos,alumnos_nom_mod,"Alumnos.csv");
    pruebaDeCargaDeAlumnos(alumnos_cod,alumnos,alumnos_nom_mod,"PruebaAlumnos.txt");
    
    return 0;
}
