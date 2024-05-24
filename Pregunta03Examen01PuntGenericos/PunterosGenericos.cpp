/* 
 * File:   PunterosGenericos.cpp
 * Author: Crystallyzer
 *
 * Created on 10 de mayo de 2024, 07:33 PM
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include "PunterosGenericos.h"
#include "Preg1_Funciones_de_cursos_y_alumnos.h"
#include "FuncionesAuxiliares.h"
#include "AperturaDeArchivos.h"

using namespace std;

void CargaCursos(int *alumnos_cod,void *&alumnoveces,const char *nombArch){
    void **alu;
    int codAlu,*ciclo,*nota,i,posAlu;
    char *codCur,c;
    
    ifstream archHistNotas;
    AperturaDeUnArchivoDeTextosParaLeer(archHistNotas,nombArch);
    
    //Reservar memoria
    for(i=0;alumnos_cod[i]!=-1;i++);
    alu=new void*[i+1];
    alu[i]=nullptr;
    
    //Inicializar arreglos
    for(i=0;alumnos_cod[i]!=-1;i++){
        inicializarAlumno(alumnos_cod[i],alu[i]);
    }
    
    while(1){
        archHistNotas>>codAlu;
        if(archHistNotas.eof())break;
        archHistNotas>>c;
        codCur=leerCadenaComa(archHistNotas);
        ciclo=new int;
        nota=new int;
        archHistNotas>>*ciclo>>c>>*nota;
        archHistNotas>>ws;
        
        posAlu=buscarCodigo(alumnos_cod,codAlu);
        if(posAlu!=-1){
            insertarNota(alu[posAlu],codCur,ciclo,nota);
        }
    }
    for(int i=0;alu[i];i++){
        pasarInterno(alu[i]);
    }
    
    alumnoveces=alu;
}

void inicializarAlumno(int alumnoCod,void *&alumno){
    void **alu;
    int *codAlu,*numCur,*curApro,*curAproPrim,*curAproSeg,*curAproTer;
    alu=new void*[7];
    codAlu=new int;
    *codAlu=alumnoCod;
    alu[0]=codAlu;
    numCur=new int;
    *numCur=0;
    alu[1]=numCur;
    curApro=new int;
    *curApro=0;
    alu[2]=curApro;
    curAproPrim=new int;
    *curAproPrim=0;
    alu[3]=curAproPrim;
    curAproSeg=new int;
    *curAproSeg=0;
    alu[4]=curAproSeg;
    curAproTer=new int;
    *curAproTer=0;
    alu[5]=curAproTer;
    inicializarNotas(alu[6]);
    
    alumno=alu;
}

void inicializarNotas(void *&notas){
    void **nota;
    nota=new void*[20];
    //Ya lleva un contador de cursos. Si no llevara, usaría nullptr
    //alu[0]=nullptr;
    
    notas=nota;
}

int buscarCodigo(int *alumnos_cod,int codigo){
    for(int i=0;alumnos_cod[i];i++){
        if(alumnos_cod[i]==codigo)return i;
    }
    return -1;
}

void insertarNota(void *&alumno,char *codCur,int *ciclo,int *nota){
    void **alu=(void **)alumno;
    void **curso=(void **)alu[6];
    int *numCur=(int *)alu[1];
    
    insertarCurso(curso[(*numCur)],codCur,ciclo,nota);
    
    (*numCur)++;
}

void insertarCurso(void *&curso,char *codCur,int *ciclo,int *nota){
    void **cur;
    
    cur=new void*[3];
    cur[0]=codCur;
    cur[1]=ciclo;
    cur[2]=nota;
    
    curso=cur;
}

void pasarInterno(void *&alumno){
    void **alu=(void **)alumno;
    void **aux;
    int *numCur=(int *)alu[1];
    void **cursos=(void **)alu[6];
    
    if(*numCur>0){
        aux=new void*[*numCur];
        for(int i=0;i<*numCur;i++){
            aux[i]=cursos[i];
        }
        delete []cursos;
        alu[6]=aux;
    }else{
        delete []cursos;
        cursos=nullptr;
    }    
}

void ActualizaVeces(void *&alumnoveces){
    void **alumno=(void **)alumnoveces;

    for(int i=0;alumno[i];i++){
        actualizarAlumno(alumno[i]);
    }
}

void actualizarAlumno(void *&alumno){
    void **alu=(void **)alumno;
    int *numCur=(int *)alu[1];
    int *numApro=(int *)alu[2];
    int *numPri=(int *)alu[3];
    int *numSeg=(int *)alu[4];
    int *numTer=(int *)alu[5];
    void **curso=(void **)alu[6];
    
    for(int i=0;i<(*numCur);i++){
        actualizarCurso(curso,curso[i],*numApro,*numPri,*numSeg,*numTer,i);
    }
    
}

void actualizarCurso(void *cursos,void *curso,int &numApro,int &numPri,int &numSeg,int &numTer,int numCur){
    void **arrCurso=(void **)cursos;
    void **cur=(void **)curso;
    char *codCur=(char *)cur[0];
    int *nota=(int *)cur[2];
    int cantCursado;
    
    if(*nota>10){
        cantCursado=0;
        numApro++;
        for(int i=0;i<=numCur;i++){
            contarCurso(arrCurso[i],codCur,cantCursado);
        }
        if(cantCursado==1)numPri++;
        if(cantCursado==2)numSeg++;
        if(cantCursado==3)numTer++;
    }
}

void contarCurso(void *curso,char *codCur,int &cantCursado){
    void **cur=(void **)curso;
    char *codigo=(char *)cur[0];
    if(strcmp(codigo,codCur)==0)cantCursado++;
}
