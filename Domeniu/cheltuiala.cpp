//
// Created by butun on 4/19/2023.
//
#include <iostream>
#include "cheltuiala.h"
Cheltuiala::Cheltuiala() {
    this->cod=1;
    this->tip= nullptr;
    this->nume= nullptr;
    this->data=0;
    this->suma=0;
}
Cheltuiala::~Cheltuiala() {
    this->tip= nullptr;
    this->nume= nullptr;
    this->data=0;
    this->suma=0;
    this->cod=1;
}

int Cheltuiala::getSuma() {
    return this->suma;
}
char* Cheltuiala::getTip() {
    return this->tip;
}
void Cheltuiala::setTip(char *Tip) {
    this->tip=Tip;
}
void Cheltuiala::setSuma(int Suma) {
    this->suma=Suma;
}

Cheltuiala::Cheltuiala(int Cod,int Suma, char *Tip,int Data,char *Nume) {
    this->cod=Cod;
    this->suma=Suma;
    this->data=Data;
    this->tip=Tip;
    this->nume=Nume;
}

int Cheltuiala::getData() {
    return this->data;
}

Cheltuiala &Cheltuiala::operator=(const Cheltuiala &c) {
    if(this!=&c){
    this->setTip(c.tip);
    this->setSuma(c.suma);
    this->setNume(c.nume);
    this->setData(c.data);
    this->setCod(c.cod);
    }
    else std::cout<<"Cheltuielile sunt identice";
}

void Cheltuiala::setData(int Data) {
   this->data=Data;
}
void Cheltuiala::setNume(char *Nume) {
    this->nume=Nume;
}

char *Cheltuiala::getNume() {
    return this->nume;
}

int Cheltuiala::getCod() {
    return this->cod;
}
void Cheltuiala::setCod(int id) {
    this->cod=id;
}
