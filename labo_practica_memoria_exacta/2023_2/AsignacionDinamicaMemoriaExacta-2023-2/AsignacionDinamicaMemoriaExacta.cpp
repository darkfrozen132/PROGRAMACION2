#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

#include "AsignacionDinamicaMemoriaExacta.h"


void lecturaDeProductos(char*nombre_archivo,char***&productos, int*&stock, 
        double*&precios){
    ifstream archProductos(nombre_archivo,ios::in);
    char**buff_productos[1000]{};
    char *cod,*nombre,aux;
    int buff_stock[1000]{},stoc;
    double buff_precios[1000]{},prec;
    
    int cant=0;
    for(int i=0;i<1000;i++){
        buff_productos[i]=new char*[2];
    }
    
    
    while(1){
        cod=leer_cadena(archProductos,',');
        if(archProductos.eof()) break;
        nombre=leer_cadena(archProductos,',');
        archProductos>>prec>>aux>>stoc>>ws;  
        
        buff_productos[cant]=dar_codigo_nombre(cod,nombre);
           
            
            
            buff_stock[cant]=stoc;
            buff_precios[cant]=prec;
            cant++;
            
                    
        
    }
    productos=new char**[cant+1]{};
    stock= new int[cant+1]{};
    precios=new double[cant+1]{};
    
    for(int i=0;i<cant;i++){
        productos[i]=buff_productos[i];
        stock[i]=buff_stock[i];
        precios[i]=buff_precios[i];
    }
    
    

}
char** dar_codigo_nombre(char*cod,char*nombre){
    char **aux;
    
    for(int i=0;i<2;i++){
        aux=new char*[2];
        
    }    
        aux[0]=cod;
        aux[1]=nombre;
    return aux;
    
}
void pruebaDeLecturaDeProductos(char*nombre_archivo,char***&productos, int*&stock, 
        double*&precios){
        ofstream archReporteProductos(nombre_archivo,ios::out);
        char **produc{};
        
        
        
        
        for(int i=0;stock[i];i++){
            produc=productos[i];
            for(int j=0;j<2;j++){
                archReporteProductos<<produc[j]<<endl;
            }
                
        }
            
        
}

char* leer_cadena(ifstream&input,char caracter){
    char aux[100],*cod;
    input.getline(aux,100,caracter);
    cod=new char[strlen(aux)+1];
    strcpy(cod,aux);
    return cod;
}



void lecturaDePedidos (char*nombre_archivo,
        int*& fechaPedidos,char***&codigoPedidos,int***& dniCantPedidos){
    ifstream archPedidos(nombre_archivo,ios::in);
    int buff_fechapedidos[1000]{};
    char **buff_codigoPedidos[1000]{};
    int **buff_dniCantPedidos[1000]{};
    char *codigo,aux;
    int dni,cantidad,fecha,dd,mm,aa;
    int pos,cant=0;
    int cant_dato_codigo[1000]{},cant_datos_dni_cantidad[1000]{};
    
    for(int i=0;i<1000;i++){
        buff_codigoPedidos[i]=new char*[1000]{};
        buff_dniCantPedidos[i]=new int*[1000]{};
    }
    while(1){
        codigo=leer_cadena(archPedidos,',');
        if(archPedidos.eof()) break;
        archPedidos>>dni>>aux>>cantidad>>aux>>dd>>aux>>mm>>aux>>aa;
        fecha=dd+mm*100+aa*10000;
        //asignar a los buffers
               
        pos=buscar_fecha(buff_fechapedidos,fecha);
        
        if(pos==-1){
            buff_fechapedidos[cant]=fecha;
            
            buff_codigoPedidos[cant]=colocar_codigo(buff_codigoPedidos[cant],
                    cant_dato_codigo[cant],codigo);
            buff_dniCantPedidos[cant]=colocar_codigo(buff_dniCantPedidos[cant],
                    cant_datos_dni_cantidad[cant],dni,cantidad);
           
           
             cant++;
        }else{
            buff_codigoPedidos[pos]=colocar_codigo(buff_codigoPedidos[pos],
                    cant_dato_codigo[pos],codigo);
            
            buff_dniCantPedidos[cant]=colocar_codigo(buff_dniCantPedidos[cant],
                    cant_datos_dni_cantidad[cant],dni,cantidad);
            
        }
        
        
       
        
        
        
               
    }
    fechaPedidos=new int[cant+1]{};
    codigoPedidos=new char**[cant+1]{};
    dniCantPedidos=new int**[cant+1]{};
    for(int i=0;i<cant;i++){
        //fechaPedidos[i]=
    }
    
    
}
int**colocar_codigo(int**buffDniCantPedidos,
                    int&cant,int dni,int cantidad){
    int *dnicant,**aux;
    dnicant=new int[2];
    dnicant[0]=dni;
    dnicant[1]=cantidad;
    
    if(cant==0){
        buffDniCantPedidos[0]=new int[2];
        buffDniCantPedidos[0]=dnicant2;
        cant++;
        
    }
    else{
        
    }
}
int buscar_fecha(int*arr_fecha,int fecha){
    for(int i=0;arr_fecha[i];i++){
        if(arr_fecha[i]==fecha) return i;
        
        return -1;
    
    }
}
char** colocar_codigo(char**&buff_codigoPedidos,int&cant,char*codigo){
    char *buff_codigo[1000],**aux;
    if(cant==0){
        buff_codigo[0]=new char[strlen(codigo)+1];
       // strcpy(buff_codigo[0],codigo);
        buff_codigo[0]=codigo;
        cant++;
       
        
    }
    else{
        for(int i=0;i<cant;i++){
            buff_codigo[i]=buff_codigoPedidos[i];
        }
        delete buff_codigoPedidos;
        buff_codigo[cant]=codigo;
        cant++;
    }
    aux=new char*[cant+1]{};
    for(int i=0;i<cant;i++){
        aux[i]=buff_codigo[i];
    }
    return aux;
    
}

