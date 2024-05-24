/* 
 * File:   Pregunta02Examen01PunterosMultiples.cpp
 * Author: Crystallyzer
 *
 * Created on 10 de mayo de 2024, 00:23 AM
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include "Preg1_Funciones_de_cursos_y_alumnos.h"
#include "Preg2_Funciones_de_historia_de_notas.h"

using namespace std;

int main(int argc, char** argv) {
    char ***cursos,***alumnos_nom_mod;
    double *cursos_cred,escalas[5];
    int *alumnos_cod,**alumnos;
    
    cargarCursosYEscalas(cursos,cursos_cred,escalas,"Cursos.csv","Escalas.csv");
    pruebaDeCargaDeCursos(cursos,cursos_cred,escalas,"PruebaCursos.txt");
    
    cargarAlumnos(alumnos_cod,alumnos,alumnos_nom_mod,"Alumnos.csv");
    pruebaDeCargaDeAlumnos(alumnos_cod,alumnos,alumnos_nom_mod,"PruebaAlumnos.txt");
    
    int ***cursos_nota_sem_veces;
    double **costos;
    char ***cursos_cod;
    
    cargarNotas(cursos_cod,cursos_nota_sem_veces,costos,alumnos,alumnos_nom_mod,escalas,cursos,cursos_cred,"HistoriaDeNotas.csv");
    pruebaDeCargaDeNotas(cursos_cod,cursos_nota_sem_veces,costos,alumnos,alumnos_nom_mod,"PruebaDeNotas.txt");
    
    return 0;
}
