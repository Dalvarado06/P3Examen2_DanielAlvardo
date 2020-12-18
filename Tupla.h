/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tupla.h
 * Author: dalva
 *
 * Created on December 18, 2020, 1:10 PM
 */

#ifndef TUPLA_H
#define TUPLA_H

#include <vector>
using std::vector;

#include <string>
using std::string;

class ManejadorRelaciones;

class Tupla {

public:

    Tupla();

    Tupla(const Tupla& orig);

    virtual ~Tupla();
    
    //gets y sets
    
    void setIdentificacion(int);
    
    vector<string> getDatos();
    
    void setDatos(vector<string>);
    
    int getId();
    
    void addDato(string);
    

private:
    
    int identificacion;
    vector<string> datos;
    friend class ManejadorRelaciones;
};

#endif /* TUPLA_H */

