/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ManejadorRelaciones.h
 * Author: dalva
 *
 * Created on December 18, 2020, 1:21 PM
 */

#ifndef MANEJADORRELACIONES_H
#define MANEJADORRELACIONES_H

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <fstream>
using std::ofstream;
using std::ifstream;

#include <iostream>
using std::cout;
using std::endl;

#include "Relacion.h"
#include "Tupla.h"

class ManejadorRelaciones {
public:
    
    ManejadorRelaciones();
    
    ManejadorRelaciones(const ManejadorRelaciones& orig);
    
    virtual ~ManejadorRelaciones();
    
    void guardarRelaciones(vector<Relacion*>&);
    
    vector<Relacion*> leerArchivos();

private:
   
};

#endif /* MANEJADORRELACIONES_H */

