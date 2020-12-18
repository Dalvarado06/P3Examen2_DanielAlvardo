/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tupla.cpp
 * Author: dalva
 * 
 * Created on December 18, 2020, 1:10 PM
 */

#include "Tupla.h"

Tupla::Tupla() {
}

Tupla::Tupla(const Tupla& orig) {
}

Tupla::~Tupla() {
}

void Tupla::setIdentificacion(int id){
    this->identificacion = id;
}

void Tupla::setDatos(vector<string> data){
    datos.clear();
    datos = data;
}

vector<string> Tupla::getDatos(){
    return datos;
}

int Tupla::getId(){
    return identificacion;
}