
#include <iostream>
#include <iomanip>
#include <cstring>
#include<fstream>


using namespace std;
#include "Pregunta1.h"



void cargarPedidos(int**&fechaClienteCantidad,char**&codigoDelProducto,char*nombre_archivo){
    ifstream archPedidos(nombre_archivo,ios::in);
    char*cod;
    int num=0,cap=0;
    int dd,mm,aa;
    int dni,cantidad_sol;
    int fecha;
    char aux;
    while(1){
        cod=leer_cadena(archPedidos,',');
        if(archPedidos.eof()) break;
        archPedidos>>dni;
        archPedidos.get();
        archPedidos>>cantidad_sol;
        archPedidos.get();
        archPedidos>>dd>>aux>>mm>>aux>>aa;
        archPedidos.get();
        if(num==cap) incrementar_espacios(fechaClienteCantidad,codigoDelProducto,num,cap);
        fecha=dd+100*mm+10000*aa;
        asignar_espacios(fechaClienteCantidad,codigoDelProducto,dni,cantidad_sol,fecha,cod,num);
        
        num++;
    }
    
    ordenar(fechaClienteCantidad,codigoDelProducto,0,num-2);
    
    
}
void ordenar(int**&fechaClienteCantidad,char**&codigoDelProducto,int izq,int der){
    int limite, pos;
    if(izq>=der) return;
    pos=(izq+der)/2;
    cambiar(fechaClienteCantidad[izq],fechaClienteCantidad[pos],codigoDelProducto[izq],codigoDelProducto[pos]);
    limite=izq;
    for(int i=izq+1;i<=der;i++){
        int *aux1=fechaClienteCantidad[i];
        int *aux2=fechaClienteCantidad[izq];
        
        if(aux1[0]<aux2[0]){
            limite++;
            cambiar(fechaClienteCantidad[limite],fechaClienteCantidad[i],codigoDelProducto[limite],codigoDelProducto[i]);
        }
    }
    cambiar(fechaClienteCantidad[limite],fechaClienteCantidad[izq],codigoDelProducto[limite],codigoDelProducto[izq]);
    ordenar(fechaClienteCantidad,codigoDelProducto,izq,limite-1);;
    ordenar(fechaClienteCantidad,codigoDelProducto,limite+1,der);;
}
void cambiar(int*&val1,int*&val2,char*&var1,char*&var2){
    int *aux1=val1;
    val1=val2;
    val2=aux1;
    
    char*aux2=var1;
    var1=var2;
    var2=aux2;
}
void asignar_espacios(int**&fechaClienteCantidad,char**&codigoDelProducto,int dni,int cantidad_sol,
        int fecha,char *cod,int num){
    int *auxfechaClienteCantidad=new int[3];
    auxfechaClienteCantidad[0]=fecha;
    auxfechaClienteCantidad[1]=dni;
    auxfechaClienteCantidad[2]=cantidad_sol;
    fechaClienteCantidad[num-1]=auxfechaClienteCantidad;
    codigoDelProducto[num-1]=cod;
    
    
}
void incrementar_espacios(int**&fechaClienteCantidad,char**&codigoDelProducto,int&num,int&cap){
    int** auxfechaClienteCantidad;
    char** auxcodigoDelProducto;
    cap=cap+5;
    if(num==0){
        fechaClienteCantidad=new int*[cap]{};
        codigoDelProducto=new char*[cap]{};
        num=1;  
    }
    else{
        auxfechaClienteCantidad=new int*[cap]{};
        auxcodigoDelProducto=new char*[cap]{};
        for(int i=0;i<num;i++){
            auxfechaClienteCantidad[i]=fechaClienteCantidad[i];
            auxcodigoDelProducto[i]=codigoDelProducto[i];
        }
        delete fechaClienteCantidad,codigoDelProducto;
        fechaClienteCantidad=auxfechaClienteCantidad;
        codigoDelProducto=auxcodigoDelProducto;
                
    }
}
char*leer_cadena(ifstream&input,char c){
    char *cad,buf[100];
    input.getline(buf,100,c);
    if(input.eof()) return nullptr;
    cad=new char[strlen(buf)+1];
    strcpy(cad,buf);   
    
    return cad;
}

void pruebaDeCargaDePedidos(int**fechaClienteCantidad,char**codigoDelProducto,char*nombre_archivo){
    int*aux;
    ofstream archReportePedidos(nombre_archivo,ios::out);
    //encabezado;
    archReportePedidos<<left<<setw(22)<<"Codigo"<<setw(17)<<"DNI"<<setw(13)<<"Cantidad"<<setw(20)
            <<"Fecha"<<endl;
    
    
    for(int i=0;fechaClienteCantidad[i];i++){
        aux=fechaClienteCantidad[i];
        archReportePedidos<<left<<setw(10)<<codigoDelProducto[i];
        archReportePedidos<<right<<setw(20)<<aux[1]<<setw(10)<<aux[2]<<setw(20)<<aux[0]<<endl;
    }
    
}
