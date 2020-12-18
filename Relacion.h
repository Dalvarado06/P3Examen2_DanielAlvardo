/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Relacion.h
 * Author: dalva
 *
 * Created on December 18, 2020, 1:17 PM
 */

#ifndef RELACION_H
#define RELACION_H

#include <vector>
using std::vector;

#include <string>
using std::string;

#include "Tupla.h"

class ManejadorRelaciones;

class Relacion {
public:
    
    Relacion();
    
    Relacion(string);
    
    Relacion(const Relacion& orig);
    
    virtual ~Relacion();
    
    //gets y sets
    
    

private:
    
    vector<string> encabezados;
    string nombre;
    vector<Tupla*> listaDatos;
    friend class ManejadorRelaciones;
};

#endif /* RELACION_H */

