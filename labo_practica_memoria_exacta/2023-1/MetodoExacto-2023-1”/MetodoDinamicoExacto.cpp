#include<fstream>
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;
#include "MetodoDinamicoExacto.h"

void lecturaAlumnos (char*nombre_archivo,int*&alumno_Codigo, char**& alumno_Nombre,
                char*&alumno_Modalidad, int*&alumno_Porcentaje, int*&alumno_Escala){
    
    ifstream archAlumnos(nombre_archivo,ios::in);
    if(not archAlumnos.is_open()){
        cout<<"El archivo "<<nombre_archivo<<" no se pudo abrir"<<endl;
        exit(1);
    }
    int buff_alumno_Codigo[1000],buff_alumno_porcentaje[1000],buff_alumno_escala[1000];
    char *buff_alumno_Nombre[1000];
    char buff_alumno_Modalidad[1000];
    int cant=0;
    int codigo,porcentaje,escala;
    char *nombre,modalidad;
    
    while(1){
        archAlumnos>>codigo;
        if(archAlumnos.eof()) break;
        archAlumnos.get();
        nombre=leer_cadena(archAlumnos,',');
        leer_valores(archAlumnos,porcentaje,escala,modalidad);
        
        buff_alumno_Codigo[cant]=codigo;
        buff_alumno_porcentaje[cant]=porcentaje;
        buff_alumno_escala[cant]=escala;
        buff_alumno_Nombre[cant]=nombre;
        buff_alumno_Modalidad[cant]=modalidad;
        
        cant++;
        
    }
    pasar_a_arreglos(alumno_Codigo, alumno_Nombre,    alumno_Modalidad,    alumno_Porcentaje,    alumno_Escala,
                     buff_alumno_Codigo   ,buff_alumno_Nombre,buff_alumno_Modalidad,buff_alumno_porcentaje,
            buff_alumno_escala,cant);
}
void pruebaLecturaAlumnos (char*nombre_archivo,int*&alumno_Codigo, char**& alumno_Nombre,
                char*&alumno_Modalidad, int*&alumno_Porcentaje, int*&alumno_Escala){
    ofstream archReporteAlumno(nombre_archivo,ios::out);
    
    
    for(int i=0;alumno_Codigo[i];i++){
        archReporteAlumno<<left<<setw(20)<<alumno_Codigo[i]<<setw(60)<<alumno_Nombre[i]<<
                setw(5)<<alumno_Modalidad[i]<<setw(20)<<alumno_Porcentaje[i]<<
                setw(5)<<alumno_Escala[i]<<endl;
    }


}
void lecturaCursos (char*archivo_nombre,int*& alumno_Codigo,int*& alumno_Escala,char**& curso_Nombre,
                double*&curso_Credito,int**& curso_Alumnos,int*& alumno_Escala){
    ifstream archCursos(archivo_nombre,ios::out);
    
}


void pasar_a_arreglos(int*& alumno_Codigo, char**&alumno_Nombre,  char*&  alumno_Modalidad,  int*&  alumno_Porcentaje, int*&   alumno_Escala,
                   int*  buff_alumno_Codigo   ,char**buff_alumno_Nombre,char*buff_alumno_Modalidad,int*buff_alumno_porcentaje,
            int*buff_alumno_escala,int cant){
    
    alumno_Codigo=new int[cant+1]{};
    alumno_Nombre=new char*[cant+1]{};
    alumno_Modalidad=new char[cant+1]{};
    alumno_Porcentaje=new int[cant+1]{};
    alumno_Escala=new int[cant+1]{};
    for(int i=0;i<cant;i++){
        alumno_Codigo[i]=buff_alumno_Codigo[i];
        alumno_Nombre[i]=buff_alumno_Nombre[i];
        alumno_Modalidad[i]=buff_alumno_Modalidad[i];
        alumno_Porcentaje[i]=buff_alumno_porcentaje[i];
        alumno_Escala[i]=buff_alumno_escala[i];
        
    }
}

void leer_valores(ifstream&input,int&porcentaje,int&escala,char&modalidad){
    int porcen,esc;
    char modali,aux;
    
    input>>modalidad;
    switch (modalidad) {
        case 'V'://modalidad virtual
            input >> aux >> escala; //leemos la escala
            porcentaje = 0;
            break;
        case 'S'://modalidad semi-presencial
            input >> aux >> porcentaje >> aux >> escala;
            break;
        default://modalidad presencial
            escala = modalidad - '0'; //conseguimos el numero
            modalidad = 'P';
            porcentaje = 0;
            break;
    }
    
}

char* leer_cadena(ifstream&input,char c){
    char cad[60],*cadena;
    input.getline(cad,60,c);
    cadena=new char[strlen(cad)+1];
    strcpy(cadena,cad);
    return cadena;
           
}