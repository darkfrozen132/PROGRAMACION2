#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "funciones.h"
void CargaDeClientes (int*&cli_DNI,char**& cli_Nombre,char*& cli_Categoria){
    
    ifstream archClientes("Clientes.csv",ios::in);
    int buff_cli_DNI[1000],cli,cant=0,tele;
    char *buff_cli_Nombre[1000],*nombre,aux;
    char buff_cli_Categoria[1000],categoria;
    while(1){
        archClientes>>cli;
        if(archClientes.eof()) break;
        archClientes>>aux;
        nombre=leer_cadena(archClientes,',');
        categoria=dar_categoria(nombre);
        archClientes>>tele;
        //pasar arreglo estaticos;
        buff_cli_DNI[cant]=cli;
        buff_cli_Nombre[cant]=nombre;
        buff_cli_Categoria[cant]=categoria;
        cant++;
        
    }
    //crear espacio para arreglo dinamicos;
    cli_DNI= new int[cant+1]{};
    cli_Nombre= new char*[cant+1]{};
    cli_Categoria= new char[cant+1]{};
    //pasar datos de estaticos a dinamicos
    for(int i=0;i<cant;i++){
        cli_DNI[i]=buff_cli_DNI[i];
        cli_Nombre[i]=buff_cli_Nombre[i];
        cli_Categoria[i]=buff_cli_Categoria[i];
    }
    
    
}
char* leer_cadena(ifstream&input,char c){
    char *nombre,buff[100];
    
    input.getline(buff,100,c);
    nombre=new char[strlen(buff)+1];
    strcpy(nombre,buff);
    return nombre;
    
}
char dar_categoria(char*&nombre){
    char cate;
    int tam_nombre=strlen(nombre);
    if(nombre[tam_nombre-2]==' '){
        cate=nombre[tam_nombre-1];
        nombre[tam_nombre-1]=' ';
       
    }
    else{
        cate='-';
        
    }
        return cate;
}
void ReporteDeClientes (int*cli_DNI,char** cli_Nombre,char* cli_Categoria){
    ofstream archReporteClientes("ReporteDeClientes.txt",ios::out);
    for(int i=0;cli_Nombre[i];i++){
        archReporteClientes<<left<<setw(10)<<cli_DNI[i]<<setw(60)<<cli_Nombre[i]
                <<setw(8)<<cli_Categoria[i]<<endl;
    }
}