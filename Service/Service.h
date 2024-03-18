//
// Created by butun on 4/24/2023.
//

#ifndef UNTITLED9_SERVICE_H
#define UNTITLED9_SERVICE_H
#include "../Repository/repository.h"

class Service {
private:
    Repository *repository;
public:
    Service(Repository &repository);
    ~Service();
    Repository FiltareNume(char *nume);
    Repository FiltrareNumePret(char* nume,int pret);
    Repository FiltrareNumePretEgal(char* nume,int pret);
    Repository AfisareIn();
    Cheltuiala AfisareMaxOut(int ziua);
    void StergereOut();
    void adaugare(Cheltuiala &a1);
    Cheltuiala*  getAll();
    void StergeData(int data);
    void StergereInterval(int i,int s);
    void StergereIn();
    void ModificaSuma(int data,char* tip,int suma);
    Cheltuiala getPoz(int i);
    int getSize();
};


#endif //UNTITLED9_SERVICE_H
