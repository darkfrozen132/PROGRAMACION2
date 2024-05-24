/* 
 * File:   Pregunta02Examen01PuntGenericos.cpp
 * Author: Crystallyzer
 *
 * Created on 10 de mayo de 2024, 07:25 PM
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include "PunterosGenericos.h"
#include "Preg1_Funciones_de_cursos_y_alumnos.h"
#include "FuncionesAuxiliares.h"

using namespace std;

int main(int argc, char** argv) {
    int *alumnos_cod,**alumnos;
    void *alumnoveces;
    char ***alumnos_nom_mod;
    
    cargarAlumnos(alumnos_cod,alumnos,alumnos_nom_mod,"Alumnos.csv");
    CargaCursos(alumnos_cod,alumnoveces,"HistoriaDeNotas.csv");
    ActualizaVeces(alumnoveces);
    ImprimeAlumno(alumnoveces);
    
    return 0;
}
