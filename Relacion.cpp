/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Relacion.cpp
 * Author: dalva
 * 
 * Created on December 18, 2020, 1:17 PM
 */

#include "Relacion.h"

Relacion::Relacion() {
}

Relacion::Relacion(string nombre){
    this->nombre = nombre;
}

Relacion::Relacion(const Relacion& orig) {
}

Relacion::~Relacion() {
    freeVector();
}

void Relacion::setHeaders(vector<string> headers){
    encabezados = headers;
}

string Relacion::getNombre(){
    return nombre;
}

vector<Tupla*> Relacion::getDatos(){
    return listaDatos;
}

vector<string> Relacion::getHeaders(){
    return encabezados;
}

void Relacion::addTupla(Tupla* temp){
    listaDatos.push_back(temp);
}

void Relacion::freeVector(){
    
    for(int i = 0; i < listaDatos.size(); i++){
        delete listaDatos[i];
    }
}

void Relacion::setNombre(string nombre){
    this->nombre = nombre;
}