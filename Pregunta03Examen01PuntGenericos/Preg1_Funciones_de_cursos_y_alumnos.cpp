/* 
 * File:   Preg1_Funciones_de_cursos_y_alumnos.cpp
 * Author: Crystallyzer
 *
 * Created on 9 de mayo de 2024, 10:01 PM
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include "Preg1_Funciones_de_cursos_y_alumnos.h"
#include "AperturaDeArchivos.h"

#define INCREMENTO 5
#define NUM_LINEA 120

using namespace std;

void cargarCursosYEscalas(char ***&cursos,double *&cursos_cred,double *escalas,const char *nombArchCursos,const char *nombArchEscalas){
    cargarCursos(cursos,cursos_cred,nombArchCursos);
    cargarEscalas(escalas,nombArchEscalas);
}

void cargarCursos(char ***&cursos,double *&cursos_cred,const char *nombArch){
    int codProf,numCur=0,capCur=0;
    char *codCur,*nombCur,*profCur,c;
    
    ifstream archCursos;
    AperturaDeUnArchivoDeTextosParaLeer(archCursos,nombArch);
    
    cursos=nullptr;
    
    while(1){
        codCur=leerCadenaComa(archCursos);
        if(codCur==nullptr)break;
        if(numCur==capCur)incrementarEspaciosCursos(cursos,cursos_cred,numCur,capCur);
        nombCur=leerCadenaComa(archCursos);
        archCursos>>cursos_cred[numCur-1]>>c>>codProf>>c;
        profCur=leerCadenaEnter(archCursos);
        archCursos>>ws;
        
        insertarCursos(cursos[numCur-1],codCur,nombCur,profCur);
        
        cursos[numCur]=nullptr;
        numCur++;
    }
}

void incrementarEspaciosCursos(char ***&cursos,double *&cursos_cred,int &numCur,int &capCur){
    char ***auxCursos;
    double *auxCursosCred;
    
    capCur+=INCREMENTO;
    
    if(cursos==nullptr){
        cursos=new char **[capCur];
        cursos_cred=new double [capCur];
        cursos[0]=nullptr;
        numCur++;
    }else{
        auxCursos=new char **[capCur];
        auxCursosCred=new double [capCur];
        for(int i=0;i<numCur;i++){
            auxCursos[i]=cursos[i];
            auxCursosCred[i]=cursos_cred[i];
        }
        delete cursos;
        delete cursos_cred;
        cursos=auxCursos;
        cursos_cred=auxCursosCred;
    }
}

void insertarCursos(char **&cursos,char *codCur,char *nombCur,char *profCur){
    cursos=new char*[3];
    cursos[0]=codCur;
    cursos[1]=nombCur;
    cursos[2]=profCur;
}

char *leerCadenaComa(ifstream &arch){
    char cadena[100],*cad;
    arch.getline(cadena,100,',');
    if(arch.eof())return nullptr;
    cad=new char[strlen(cadena)+1];
    strcpy(cad,cadena);
    return cad;
}

char *leerCadenaEnter(ifstream &arch){
    char cadena[100],*cad;
    arch.getline(cadena,100,'\n');
    cad=new char[strlen(cadena)+1];
    strcpy(cad,cadena);
    return cad;
}

void cargarEscalas(double *escalas,const char *nombArch){
    int grupoEsc;
    char G,c;
    double precEsc;
    
    ifstream archEscalas;
    AperturaDeUnArchivoDeTextosParaLeer(archEscalas,nombArch);
    
    while(1){
        archEscalas>>G;
        if(archEscalas.eof())break;
        archEscalas>>grupoEsc>>c;
        archEscalas>>precEsc;
        
        escalas[grupoEsc-1]=precEsc; //Escala5->Espacio 4 - Escala4->Espacio 3 - ...
    }
}

void pruebaDeCargaDeCursos(char ***cursos,double *cursos_cred,double *escalas,const char *nombArch){
    ofstream archPrueba;
    AperturaDeUnArchivoDeTextosParaEscribir(archPrueba,nombArch);
    
    archPrueba.precision(2);
    archPrueba<<fixed;
    
    archPrueba<<setw(75)<<"PRUEBA DE LECTURA DE CURSOS"<<endl;
    imprimeLinea(archPrueba,NUM_LINEA,'=');
    archPrueba<<left<<setw(10)<<"CODIGO"<<setw(60)<<"NOMBRE DEL CURSO"<<setw(40)<<"PROFESOR"
              <<right<<"CREDITOS"<<endl;
    imprimeLinea(archPrueba,NUM_LINEA,'=');
    for(int i=0;cursos[i];i++){
        imprimirCursos(archPrueba,cursos[i],cursos_cred[i]);
    }
    imprimeLinea(archPrueba,NUM_LINEA,'-');
    for(int i=0;i<5;i++){
        archPrueba<<"G"<<i+1<<" "<<escalas[i]<<endl;
    }
    imprimeLinea(archPrueba,NUM_LINEA,'-');
}

void imprimirCursos(ofstream &archPrueba,char **cursos,double cursos_cred){
    archPrueba<<left<<setw(10)<<cursos[0]<<setw(60)<<cursos[1]<<setw(40)<<cursos[2]
              <<right<<setw(6)<<cursos_cred<<endl;
}

void imprimeLinea(ofstream &arch,int cantidad,char simbolo){
    for(int i=0;i<cantidad;i++)arch<<simbolo;
    arch<<endl;
}

void cargarAlumnos(int *&alumnos_cod,int **&alumnos,char ***&alumnos_nom_mod,const char *nombArch){
    int codAlu,porcentaje,escala,numAlu=0,capAlu=0;
    char *nombAlu,modalidad,c;
    
    ifstream archAlumnos;
    AperturaDeUnArchivoDeTextosParaLeer(archAlumnos,nombArch);
    
    alumnos=nullptr;
    
    while(1){
        archAlumnos>>codAlu;
        if(archAlumnos.eof())break;
        if(numAlu==capAlu)incrementarEspaciosAlumnos(alumnos_cod,alumnos,alumnos_nom_mod,numAlu,capAlu);
        archAlumnos>>c;
        nombAlu=leerCadenaComa(archAlumnos);
        archAlumnos>>modalidad;
        if(modalidad=='S'){
            archAlumnos>>c>>porcentaje>>c>>c;
        }
        if(modalidad=='V'){
            archAlumnos>>c>>c;
        }
        archAlumnos>>escala;
        archAlumnos>>ws;
        
        alumnos_cod[numAlu-1]=codAlu;
        insertarAlumnos(alumnos[numAlu-1],codAlu,escala,porcentaje,modalidad);
        insertarAlumnosNomb(alumnos_nom_mod[numAlu-1],nombAlu,modalidad);
        
        alumnos[numAlu]=nullptr;
        alumnos_cod[numAlu]=-1;
        numAlu++;
    }
}

void incrementarEspaciosAlumnos(int *&alumnos_cod,int **&alumnos,char ***&alumnos_nom_mod,int &numAlu,int &capAlu){
    int *auxAlumnosCod;
    int **auxAlumnos;
    char ***auxAlumnosNombMod;
    
    capAlu+=INCREMENTO;
    
    if(alumnos==nullptr){
        alumnos_cod=new int [capAlu];
        alumnos=new int *[capAlu];
        alumnos_nom_mod=new char **[capAlu];
        alumnos[0]=nullptr;
        alumnos_cod[0]=-1;
        numAlu++;
    }else{
        auxAlumnosCod=new int [capAlu];
        auxAlumnos=new int *[capAlu];
        auxAlumnosNombMod=new char **[capAlu];
        for(int i=0;i<numAlu;i++){
            auxAlumnosCod[i]=alumnos_cod[i];
            auxAlumnos[i]=alumnos[i];
            auxAlumnosNombMod[i]=alumnos_nom_mod[i];
        }
        delete alumnos_cod;
        delete alumnos;
        delete alumnos_nom_mod;
        alumnos_cod=auxAlumnosCod;
        alumnos=auxAlumnos;
        alumnos_nom_mod=auxAlumnosNombMod;
    }
}

void insertarAlumnos(int *&alumnos,int codAlu,int escala,int porcentaje,char modalidad){
    if(modalidad=='S'){
        alumnos=new int[3];
        alumnos[2]=porcentaje;
    }else{
        alumnos=new int[2];
    }
    alumnos[0]=codAlu;
    alumnos[1]=escala;
}

void insertarAlumnosNomb(char **&alumnos_nom_mod,char *nombAlu,char modalidad){
    char *mod;
    
    alumnos_nom_mod=new char*[2];
    alumnos_nom_mod[0]=nombAlu;
    mod=new char;
    if(modalidad=='G')*mod='P';
    else *mod=modalidad;
    alumnos_nom_mod[1]=mod;
}

void pruebaDeCargaDeAlumnos(int *alumnos_cod,int **alumnos,char ***alumnos_nom_mod,const char *nombArch){
    ofstream archPrueba;
    AperturaDeUnArchivoDeTextosParaEscribir(archPrueba,nombArch);
    
    archPrueba.precision(2);
    archPrueba<<fixed;
    
    archPrueba<<setw(75)<<"PRUEBA DE LECTURA DE ALUMNOS"<<endl;
    imprimeLinea(archPrueba,NUM_LINEA,'=');
    archPrueba<<left<<setw(12)<<"CODIGO"<<setw(36)<<"NOMBRE"<<setw(18)
              <<"MODALIDAD"<<setw(18)<<"ESCALA"<<"DESCUENTO (%)"<<endl;
    imprimeLinea(archPrueba,NUM_LINEA,'=');
    for(int i=0;alumnos[i];i++){
        imprimirAlumnos(archPrueba,alumnos_cod[i],alumnos[i],alumnos_nom_mod[i]);
    }
    imprimeLinea(archPrueba,NUM_LINEA,'-');
}

void imprimirAlumnos(ofstream &archPrueba,int alumnos_cod,int *alumnos,char **alumnos_nom_mod){
    archPrueba<<left<<setw(12)<<alumnos_cod<<setw(40)<<alumnos_nom_mod[0]
              <<setw(6)<<alumnos_nom_mod[1]<<right<<setw(12)<<alumnos[1];
    if(strcmp(alumnos_nom_mod[1],"S")==0){
        archPrueba<<setw(18)<<alumnos[2];
    }
    archPrueba<<endl;
}
