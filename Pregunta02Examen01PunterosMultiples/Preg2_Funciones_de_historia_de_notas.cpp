/* 
 * File:   Preg2_Funciones_de_historia_de_notas.h
 * Author: Crystallyzer
 *
 * Created on 10 de mayo de 2024, 12:28 AM
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include "Preg1_Funciones_de_cursos_y_alumnos.h"
#include "Preg2_Funciones_de_historia_de_notas.h"
#include "AperturaDeArchivos.h"

#define NUM_LINEA 100

using namespace std;

void cargarNotas(char ***&cursos_cod,int ***&cursos_nota_sem_veces,double **&costos,int **alumnos,char ***alumnos_nom_mod,double *escalas,char ***cursos,double *cursos_cred,const char *nombArch){
    int codAlu,semestre,nota,posAlu,i;
    char *codCur,c;
    
    ifstream archHistNotas;
    AperturaDeUnArchivoDeTextosParaLeer(archHistNotas,nombArch);
    
    for(i=0;alumnos[i];i++);
    cursos_cod=new char**[i+1];
    cursos_nota_sem_veces=new int**[i];
    costos=new double*[i];
    cursos_cod[i]=nullptr;
    
    int cantCurxAlu[i]={};
    
    while(1){
        archHistNotas>>codAlu;
        if(archHistNotas.eof())break;
        archHistNotas>>c;
        codCur=leerCadenaComa(archHistNotas);
        archHistNotas>>semestre>>c>>nota;
        archHistNotas>>ws;
        
        posAlu=buscarAlumno(alumnos,codAlu);
        if(posAlu!=-1){
            agregarNotaCursoYCosto(cursos_cod[posAlu],cursos_nota_sem_veces[posAlu],costos[posAlu],alumnos[posAlu],alumnos_nom_mod[posAlu],escalas,cursos,cursos_cred,codCur,semestre,nota,cantCurxAlu[posAlu]);
        }
    }
    cargarArreglos(cursos_cod,cursos_nota_sem_veces,costos,cantCurxAlu);
}

int buscarAlumno(int **alumnos,int codAlu){
    for(int i=0;alumnos[i];i++){
        if(codAluIguales(alumnos[i],codAlu))return i;
    }
    return -1;
}

int codAluIguales(int *alumnos,int codAlu){
    return alumnos[0]==codAlu;
}

void agregarNotaCursoYCosto(char **&cursos_cod,int **&cursos_nota_sem_veces,double *&costos,int *alumnos,char **alumnos_nom_mod,double *escalas,char ***cursos,double *cursos_cred,char *codCur,int semestre,int nota,int &cantCur){
    int posBika=-1;
    
    if(cantCur==0){
        cursos_cod=new char*[20];
        cursos_nota_sem_veces=new int*[20];
        costos=new double[20];
    }
    
    if(cantCur>0)posBika=buscarBika(cursos_cod,codCur,cantCur);
    if(posBika!=-1){
        insertarCursoNota(cursos_nota_sem_veces[posBika],nota,semestre,posBika);
        //cout<<"Bika encontrada, que vruto"<<endl;
    }else{
        insertarCursoNota(cursos_nota_sem_veces[cantCur],nota,semestre,posBika);
        cursos_cod[cantCur]=codCur;
        insertarCosto(costos[cantCur],alumnos,alumnos_nom_mod,escalas,cursos,cursos_cred,codCur);
        
        cantCur++;
        //if(alumnos[0]==202123703)cout<<cantCur<<endl;
        //cout<<"Paso a la primera, que crack"<<endl;
    }
}

int buscarBika(char **cursos_cod,char *codCur,int cantCur){
    for(int i=0;i<cantCur;i++){
        if(strcmp(cursos_cod[i],codCur)==0)return i;
    }
    return -1;
}

void insertarCursoNota(int *&cursos_nota_sem_veces,int nota,int semestre,int posBika){
    if(posBika!=-1){
        cursos_nota_sem_veces[0]=nota;
        cursos_nota_sem_veces[1]=semestre;
        cursos_nota_sem_veces[2]++;
    }else{
        cursos_nota_sem_veces=new int[3];
        cursos_nota_sem_veces[0]=nota;
        cursos_nota_sem_veces[1]=semestre;
        cursos_nota_sem_veces[2]=1;
    }
}

void insertarCosto(double &costos,int *alumnos,char **alumnos_nom_mod,double *escalas,char ***cursos,double *cursos_cred,char *codCur){
    int posCur;
    
    posCur=buscarCurso(cursos,codCur);
    if(posCur!=-1){
        if(*alumnos_nom_mod[1]=='S'){
            costos=cursos_cred[posCur]*escalas[alumnos[1]-1]*(100-alumnos[2])/100;
            //cout<<"DESCUENTO: "<<cursos_cred[posCur]<<"*"<<escalas[alumnos[1]-1]<<"*"<<alumnos[2]<<"="<<costos<<endl;
        }else{
            costos=cursos_cred[posCur]*escalas[alumnos[1]-1];
            //cout<<"SIN DESCUENTO: "<<cursos_cred[posCur]<<"*"<<escalas[alumnos[1]-1]<<"="<<costos<<endl;
        }
    }
}

int buscarCurso(char ***cursos,char *codCur){
    for(int i=0;cursos[i];i++){
        if(codCurIguales(cursos[i],codCur))return i;
    }
    return -1;
}

int codCurIguales(char **cursos,char *codCur){
    return strcmp(cursos[0],codCur)==0;
}

void cargarArreglos(char ***&cursos_cod,int ***&cursos_nota_sem_veces,double **&costos,int *cantCurxAlu){
    for(int i=0;cursos_cod[i];i++){
        cargarInterno(cursos_cod[i],cursos_nota_sem_veces[i],costos[i],cantCurxAlu[i]);
    }
}

void cargarInterno(char **&cursos_cod,int **&cursos_nota_sem_veces,double *&costos,int cantCur){
    char **auxCursos_cod;
    int **auxCursos_nota_sem_veces;
    double *auxCostos,costoTotal=0;
    
    if(cantCur>0){
        for(int i=0;i<cantCur;i++){
            costoTotal+=costos[i];
        }
        auxCursos_cod=new char*[cantCur+1];
        auxCursos_nota_sem_veces=new int*[cantCur];
        auxCostos=new double[cantCur+1];
        for(int i=0;i<cantCur;i++){
            auxCursos_cod[i]=cursos_cod[i];
            auxCursos_nota_sem_veces[i]=cursos_nota_sem_veces[i];
            auxCostos[i]=costos[i];
        }
        auxCursos_cod[cantCur]=nullptr;
        auxCostos[cantCur]=costoTotal;
        
        delete cursos_cod;
        delete cursos_nota_sem_veces;
        delete costos;
        cursos_cod=auxCursos_cod;
        cursos_nota_sem_veces=auxCursos_nota_sem_veces;
        costos=auxCostos;
    }else{
        cursos_cod=new char*[1];
        cursos_cod[0]=nullptr;
    }
}

void pruebaDeCargaDeNotas(char ***cursos_cod,int ***cursos_nota_sem_veces,double **costos,int **alumnos,char ***alumnos_nom_mod,const char *nombArch){
    ofstream archPrueba;
    AperturaDeUnArchivoDeTextosParaEscribir(archPrueba,nombArch);
    
    archPrueba.precision(2);
    archPrueba<<fixed;
    
    archPrueba<<setw(75)<<"PRUEBA DE CARGA DE NOTAS DE ALUMNOS"<<endl;
    imprimeLinea(archPrueba,NUM_LINEA,'=');
    archPrueba<<left<<setw(12)<<"CODIGO"<<setw(36)<<"NOMBRE"<<setw(18)
              <<"MODALIDAD"<<setw(18)<<"ESCALA"<<"DESCUENTO (%)"<<endl;
    imprimeLinea(archPrueba,NUM_LINEA,'=');
    for(int i=0;alumnos[i];i++){
        imprimirAlumnos2(archPrueba,cursos_cod[i],cursos_nota_sem_veces[i],costos[i],alumnos[i],alumnos_nom_mod[i]);
        imprimeLinea(archPrueba,NUM_LINEA,'=');
    }
}

void imprimirAlumnos2(ofstream &archPrueba,char **cursos_cod,int **cursos_nota_sem_veces,double *costos,int *alumnos,char **alumnos_nom_mod){
    int i;
    
    //imprimeLinea(archPrueba,NUM_LINEA,'-');
    archPrueba<<left<<setw(12)<<alumnos[0]<<setw(40)<<alumnos_nom_mod[0]
              <<setw(6)<<alumnos_nom_mod[1]<<right<<setw(12)<<alumnos[1];
    if(strcmp(alumnos_nom_mod[1],"S")==0){
        archPrueba<<setw(18)<<alumnos[2];
    }
    archPrueba<<endl;
    imprimeLinea(archPrueba,NUM_LINEA,'-');
    for(i=0;cursos_cod[i];i++){
        imprimirCursos(archPrueba,i,cursos_cod[i],cursos_nota_sem_veces[i],costos[i]);
    }
    if(i==0)archPrueba<<"NO HAY CURSOS"<<endl;
    imprimeLinea(archPrueba,NUM_LINEA,'-');
    if(i!=0)archPrueba<<"COSTO TOTAL: "<<costos[i]<<endl;
    else archPrueba<<"COSTO TOTAL: 0.00"<<endl;
}

void imprimirCursos(ofstream &archPrueba,int numCur,char *cursos_cod,int *cursos_nota_sem_veces,double costos){
    archPrueba<<numCur+1<<") "<<cursos_cod<<"    Nota: "<<setw(4)<<cursos_nota_sem_veces[0]
              <<"    Vez: "<<cursos_nota_sem_veces[2]<<"   Semestre: "<<cursos_nota_sem_veces[1]
              <<setw(40)<<costos<<endl;
}
