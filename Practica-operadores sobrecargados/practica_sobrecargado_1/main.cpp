/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: leoncio
 *
 * Created on 21 de marzo de 2024, 08:18 AM
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

#include "persona.h"
#include "overload.h"
/*
 * 
 */
int main(int argc, char** argv) {
    struct Person p;
    p.dni=123456;
    p.weight=166.5;
    strcpy(p.name,"leoncio");
    cout<<p;
    return 0;
}

