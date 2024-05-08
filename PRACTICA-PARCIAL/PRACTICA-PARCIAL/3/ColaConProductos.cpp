#include <iostream>
#include <iomanip>
#include <cstring>
#include<fstream>


using namespace std;
#include "Pregunta1.h"
#include "Pregunta2.h"

#include "ColaConEnteros.h"
#include "ColaConProductos.h"
#include "ColaGenerica.h"
enum regProductos{CODIGO,DESCRIPCION,PRECIO,STOCKFINAL};
void procesarPedidos(int**&fechaClienteCantidad,char**&codigoDelProducto,void*&prod){
    int pos;
    int *aux;
    void**productos=(void**)prod;
    for(int i=0;codigoDelProducto[i];i++){  
        aux=fechaClienteCantidad[i];
        pos=buscar(codigoDelProducto[i],prod);
        
        
        if(pos!=-1){
            void**producto=(void**)productos[pos];
             void**regProducto=(void**)producto[0];
             void*regProductoCola=producto[1];
             if(regProductoCola==nullptr) generacola(regProductoCola);
            if(aux[2]<= *(int*)regProducto[STOCKFINAL]   ){
                
                void**arr=new void*[3];
                int *a=new int;
                *a=aux[0];
                arr[0]=a;
                int *b=new int;
                *b=aux[1];
                arr[1]=b;
                int *c=new int;
                *c=aux[2];
                arr[2]=c;
                
                
                encola(regProductoCola,arr);
              
                
            
                *(int*)regProducto[STOCKFINAL]= *(int*)regProducto[STOCKFINAL]-aux[2];
                
            }
             producto[0]=regProducto;
             producto[1]=regProductoCola;
             productos[pos]=producto;
        }
        
        
        
    }
    prod=productos;
}
int buscar(char*codigo,void*prod){
    void**productos=(void**)prod;
    
    
    for(int i=0;productos[i];i++){
        void**producto=(void**)productos[i];
        void**regproducto=(void**)producto[0];
        if(strcmp(codigo,(char*)regproducto[CODIGO])==0) return i;
    }
    return -1;
}

void reporteDePedidos(void*prod,char*nombre_archivo){
    ofstream archreportePedidos(nombre_archivo,ios::out);
    void**productos=(void**)prod;
    
    for(int i=0;productos[i];i++){
        void**producto=(void**)productos[i];
        void**reg_producto=(void**)producto[0];
        
      
        archreportePedidos<<"Producto "<<i+1<<endl;
        archreportePedidos<<left<<setw(10)<<(char*)reg_producto[CODIGO]<<setw(20)
                <<(char*)reg_producto[DESCRIPCION]<<endl;
        archreportePedidos<<right<<"Precio: "<<*(double*)reg_producto[PRECIO]<<
                " "<<setw(10)<<"Stock: "<<*(int*)reg_producto[STOCKFINAL]<<endl;
        archreportePedidos<<"Pedidos aceptados: "<<endl;
        void*reg_cola=producto[1];
        
       
         archreportePedidos<<left<<setw(10)<<"FECHA"<<setw(15)<<"DNI"<<setw(15)<<"Cantidad"<<endl;
         if(reg_cola!=nullptr){
             
            while(1){
                if(colavacia(reg_cola)==true) break;
                void*reg;

                reg=desencola(reg_cola);
                void**registro=(void**)reg;
                void**registro_cola=(void**)registro[0];

                archreportePedidos<<left<<setw(10)<<*(int*)registro_cola[0]<<setw(15)<<
                        *(int*)registro_cola[1]<<setw(15)<<*(int*)registro_cola[2]<<endl;
            }
        }
         archreportePedidos<<endl;
        
    }
    
}