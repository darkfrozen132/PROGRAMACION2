#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include <fstream>
#include "Estructuras.h"
bool operator>>(ifstream& input,struct StCurso& curso){
    input>>curso.codigoDelCurso;
    if(input.eof()) return false;
    input>>curso.nombreDelCurso>>curso.creditos>>curso.codigoDelProfesor>>
            curso.nombreDelProfesor;
    return true;
    
}