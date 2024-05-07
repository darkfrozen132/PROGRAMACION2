#include <iostream>
#include <iomanip>
#include <cstring>
#include<fstream>


using namespace std;
#include "Pregunta1.h"
#include "Pregunta2.h"
#include "ColaGenerica.h"
enum COLA{CABEZA,COLA,TOTALPEDIDOS};
enum NODO{REGISTRO,SIG};
void generacola(void*&col){
    void**cola=(void**)col;
    cola=new void*[3];
    cola[CABEZA]=nullptr;
    cola[COLA]=nullptr;
    cola[TOTALPEDIDOS]=0;
    col=cola;
}
void encola(void*&col,void*reg){
    void**cola=(void**)col;
    void**nodo=new void*[2];
    nodo[REGISTRO]=reg;
    nodo[SIG]=nullptr;
    
    if(colavacia(cola)){
        cola[CABEZA]=nodo;
        cola[COLA]=nodo;
        int *reg=(int*)cola[TOTALPEDIDOS];
        *reg++;
    }
    else{
        void**nod1=(void**)cola[COLA];
        nod1[SIG]=nodo;
        cola[COLA]=nodo;
        int *reg=(int*)cola[TOTALPEDIDOS];
        *reg++;
        
        
    }
    
            
}
void* desencola(void*&col){
    void**cola=(void**)col;
    void**auxnodo=(void**)cola[CABEZA];
    cola[CABEZA]=auxnodo[SIG];
    
    int *reg=(int*)cola[TOTALPEDIDOS];
    *reg--;
    
    return auxnodo;
    
}
bool colavacia(void*col){
    void**cola=(void**)col;
    if(cola[CABEZA]==nullptr){
        return true;
    }
     return false;
}