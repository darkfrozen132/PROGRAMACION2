/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "AsignacionDinamicaMemoriaExacta.h"

void lecturaDeProductos(const char*Nombrearch,char ***&productos,int *&stock,
        double *&precios){
    ifstream arch(Nombrearch,ios::in);
    if(not arch.is_open()){
        cout<<"El archivo "<<Nombrearch<<" no se ha abierto"<<endl;
        exit(1);
    }
    int nProd=0; int buffStock[200]{}; double buffPrecio[200]{}; char **buffProductos[200];
    while(true){
        buffProductos[nProd]=leerCodDescripccion(arch);
        if(arch.eof()) break;
        arch>>buffPrecio[nProd]; arch.get();
        arch>>buffStock[nProd];
        arch.get(); //leer salto de linea
        nProd++;
    }
    productos=new char **[nProd+1]; stock=new int[nProd+1]; precios=new double[nProd+1];
    for(int i=0;i<nProd;i++){
        productos[i]=buffProductos[i];
        precios[i]=buffPrecio[i];
        stock[i]=buffStock[i];
    }
    stock[nProd]=0;
}

char **leerCodDescripccion(ifstream &arch){
    char *buff[2]; int cantCadena=0;
    char **aux;
    for(int i=0;i<2;i++){
        buff[i]=leeCadena(arch);
    }
    aux=new char*[2];
    for(int i=0;i<2;i++){
        aux[i]=buff[i];
    }
    return aux;
}

char *leeCadena(ifstream &arch){
    char cadena[70], *aux;
    arch.getline(cadena,70,',');
    aux=new char[strlen(cadena)+1];
    strcpy(aux,cadena);
    return aux;
}
void pruebaDeLecturaDeProductos(const char*Nombrearch,char ***productos,int *stock,
        double *precios){
    ofstream arch(Nombrearch,ios::out);
    if(not arch.is_open()){
        cout<<"El archivo "<<Nombrearch<<" no se ha abierto"<<endl;
        exit(1);
    }
    for(int i=0;stock[i];i++){
//        cout<<stock[i]<<"   | ";
        imprimeProductos(productos[i],arch);
        arch<<right<<setw(10)<<stock[i]<<setw(10)<<fixed<<setprecision(2)<<precios[i]<<endl;
    }
    arch.close();
}


void imprimeProductos(char **productos,ofstream &arch){
    for(int i=0;i<2;i++){
        arch<<setw(70)<<left<<productos[i];
    }
}


/////////////////////////////////////////////////////////////////////////

//Parte 2
void lecturaDePedidos(const char *NombreArch,int *&fechaPedidos,char ***&codigoPedidos,
        int ***&dniCantPedidos){
    ifstream arch(NombreArch,ios::in);
    if(not arch.is_open()){
        cout<<"El archivo "<<NombreArch<<" no se ha abierto"<<endl;
        exit(1);
    }
    int posFecha,fecha,dni,Cped;
    int buffFecha[600]{0},**buffDNICant[600]{};
    char **buffCodigo[600]{},*codigo{},c;
    int nDeDatos[600]{},nDeDatosB[600]{};
    int nPed=0;
    while(true){
        codigo=leeCadena(arch);
        if(arch.eof()) break;
        arch>>dni>>c>>Cped>>c;
        fecha=leerFecha(arch);
        posFecha=buscarFecha(buffFecha,fecha);
        if(posFecha!=-1){
            buffFecha[posFecha]=fecha;
            buffCodigo[posFecha]=colocarCodigo(buffCodigo[posFecha],nDeDatos[posFecha],codigo);
            buffDNICant[posFecha]=colocarDNICant(buffDNICant[posFecha],nDeDatosB[posFecha],dni,Cped);
        }
        else{
            buffFecha[nPed]=fecha;
            buffCodigo[nPed]=colocarCodigo(buffCodigo[nPed],nDeDatos[nPed],codigo);
            buffDNICant[nPed]=colocarDNICant(buffDNICant[nPed],nDeDatosB[nPed],dni,Cped);
            nPed++;
        } 
    }
    fechaPedidos=new int[nPed+1];
    codigoPedidos=new char**[nPed+1];
    dniCantPedidos=new int**[nPed+1];
    for(int i=0;i<nPed;i++){
        codigoPedidos[i]=buffCodigo[i];
        dniCantPedidos[i]=buffDNICant[i];
        fechaPedidos[i]=buffFecha[i];       
    }
    codigoPedidos[nPed]=nullptr;
    dniCantPedidos[nPed]=nullptr;
    fechaPedidos[nPed]=0;
}
int buscarFecha(int *buffFecha,int fecha){
    int i=0;
    while(buffFecha[i]!=0){
        if(buffFecha[i]==fecha) return i;
        i++;
    }
    return -1;
}
int leerFecha(ifstream &arch){
    char c;
    int anio,mes,dia,combinacion;
    arch>>dia>>c>>mes>>c>>anio;
    combinacion=(anio*10000)+(mes*100)+dia;
    return combinacion;
}
int **colocarDNICant(int **&buffOriginal,int &nDatos,int dni,int Cped){
    int *buff[500]{},**aux;
    if(nDatos==0){
       buff[0]=new int[2];
       agregarDNICantSegundaFase(buff[0],dni,Cped);
       nDatos++;
    }
    else{
        for(int i=0;i<nDatos;i++){
            buff[i]=buffOriginal[i];
        }
        delete buffOriginal;
        buff[nDatos]=new int[2];
        agregarDNICantSegundaFase(buff[nDatos],dni,Cped);
        nDatos++;
    }
    aux=new int*[nDatos+1];
    for(int i=0;i<nDatos;i++){
        aux[i]=buff[i];
    }
    aux[nDatos]=nullptr;
    return aux;
}
char **colocarCodigo(char **&buffOriginal,int &nDatos,char *codigo){
    char *buff[500]{},**aux;
    if(nDatos==0){
       buff[0]=new char[strlen(codigo)+1];
       strcpy(buff[0],codigo);
       nDatos++;
    }
    else{
        for(int i=0;i<nDatos;i++){
            buff[i]=buffOriginal[i];
        }
        delete buffOriginal;
        buff[nDatos]=new char[strlen(codigo)+1];
        strcpy(buff[nDatos],codigo);
        nDatos++;
    }
    aux=new char*[nDatos+1];
    for(int i=0;i<nDatos;i++){
        aux[i]=buff[i];
    }
    aux[nDatos]=nullptr;
    return aux;
}
//
//
//
//void agregarDNICant(int **&buffCodigo,int dni,int Cped){
//   int i=0;
//   while(buffCodigo[i]!=nullptr) i++;
//   buffCodigo[i]=new int[2];
//   agregarDNICantSegundaFase(buffCodigo[i],dni,Cped);
//   buffCodigo[i+1]=nullptr;
//}
//
//int **agregarDNICantSI(int dni,int Cped){
//    int **buff, *buffDos[2];
//   buffDos[0]=new int[2];
//   agregarDNICantSegundaFase(buffDos[0],dni,Cped);
//   buffDos[1]=nullptr;
//   buff=new int*[2];
//   for(int i=0;i<2;i++){
//       buff[i]=buffDos[i];
//   }
//   return buff;
//}
//
void agregarDNICantSegundaFase(int *&buff,int dni,int cant){
    buff[0]=dni;
    buff[1]=cant;
}
//
//void agregarCodigo(char **&buffDNICant,char *codigo){
//   int i=0;
//   while(buffDNICant!=nullptr) i++;
//    buffDNICant[i]=new char[strlen(codigo)+1];
//    strcpy(buffDNICant[i],codigo);
//    buffDNICant[i+1]=nullptr;
//}
//
//char** agregarCodigoSI(char *codigo){
//    char *buff[2],**aux;
//    buff[0]=new char[strlen(codigo)+1];
//    strcpy(buff[0],codigo);
//    buff[1]=nullptr;
//    aux=new char*[2];
//    for(int i=0;i<2;i++){
//       aux[i]=buff[i];
//   }
//    return aux;
//}


void pruebaDeLecturaDePedidos(const char *NombreArch,int *fechaPedidos,char ***codigoPedidos,
        int ***dniCantPedidos){
    ofstream arch(NombreArch,ios::out);
    if(not arch.is_open()){
        cout<<"El archivo "<<NombreArch<<" no se ha abierto"<<endl;
        exit(1);
    }
    for(int i=0;fechaPedidos[i];i++){
        arch<<setw(10)<<left<<fechaPedidos[i]<<": "<<endl;
        imprimeCodigosYDNICant(arch,codigoPedidos[i],dniCantPedidos[i]);
        arch<<endl;
    }
    
}

void imprimeCodigosYDNICant(ofstream &arch,char **codigoPedidos,int **dniCantPedidos){
    int i=0;
    while(codigoPedidos[i]!=nullptr){
        cout<<codigoPedidos[i]<<endl;
        arch<<setw(8)<<codigoPedidos[i];
        imprimeDNICantDatos(arch,dniCantPedidos[i]);
        arch<<endl;
        i++;
    }
}
//void imprimeDNICant(ofstream &arch,int **dniCantPedidos){
//    int i=0;
//    while(dniCantPedidos[i]!=nullptr){
//        imprimeDNICantDatos(arch,dniCantPedidos[i]);
//        i++;
//    }
//}

void imprimeDNICantDatos(ofstream &arch,int *dniCantPedidos){
    for(int i=0;i<2;i++){
        arch<<setw(9)<<dniCantPedidos[i];
    }
}