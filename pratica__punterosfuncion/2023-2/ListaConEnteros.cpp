#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cstdlib>

#include "ListaConEnteros.h"
#include "ListaConRegistros.h"
#include "FlotaGenerica.h"
using namespace std;


void*leenumero(ifstream&input){
    
    double*num=new double;
    
    input>>*num;
    if(input.eof())return nullptr;
    return (void*)num;
    
}
double calculanumero(void*num){
    double*peso=(double*)num;
    return *peso;
}
int cmpnumero(const void*ptr1,const void*ptr2){
    void**p1=(void**)ptr1;
    void**p2=(void**)ptr2;
    double pp1=calcula_peso_camion(*p1);
    double pp2=calcula_peso_camion(*p2);
    
    return pp2-pp1;
    
}
