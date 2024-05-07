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
            if(aux[2]<= *(int*)regProducto[STOCKFINAL]   ){
                if(producto[1]==nullptr) generacola(producto[1]);
                encola(producto[1],aux);
                *(int*)regProducto[STOCKFINAL] -=aux[2];
            }
        }
    }
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
        
    }
    
}