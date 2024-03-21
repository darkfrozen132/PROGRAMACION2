#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "overload.h"
#include "persona.h"


ostream & operator <<(ostream& out,const struct Person& p){
    out<<setw(90)<<left<<p.dni<<p.name<<p.weight;
    return out;
}