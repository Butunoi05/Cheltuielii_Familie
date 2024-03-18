//
// Created by butun on 4/24/2023.
//
#include <iostream>
#include "Service.h"
#include "../Repository/repository.h"
#include <cstring>
using namespace std;
Service::Service(Repository &repository) {
    this->repository=&repository;
}

Service::~Service() {
    delete[] this->repository;
}

Repository Service::FiltareNume(char *nume) {
    Repository rez;
    for(int i=1;i<this->repository->getSize();++i)
        if(strcmp(this->repository->getPoz(i).getNume(),nume)==0)
            rez.adaugare(this->repository->getPoz(i));

    //for(int i=1;i<rez.getSize();i++)cout<<rez.getPoz(i).getTip()<<" "<<rez.getPoz(i).getData()<<" "<<rez.getPoz(i).getSuma()<<" "<<rez.getPoz(i).getNume()<<'\n';
    return rez;

}

Repository Service::FiltrareNumePret(char *nume, int pret) {
    Repository rez;
    for(int i=1;i<this->repository->getSize();++i)
        if(strcmp(this->repository->getPoz(i).getNume(),nume)==0 and this->repository->getPoz(i).getSuma()>=pret)
            rez.adaugare(this->repository->getPoz(i));

    //for(int i=1;i<rez.getSize();i++)cout<<rez.getPoz(i).getTip()<<" "<<rez.getPoz(i).getData()<<" "<<rez.getPoz(i).getSuma()<<" "<<rez.getPoz(i).getNume()<<'\n';
    return rez;
}

Repository Service::FiltrareNumePretEgal(char *nume, int pret)
    {
        Repository rez;
        for(int i=1;i<this->repository->getSize();++i)
            if(strcmp(this->repository->getPoz(i).getNume(),nume)==0 and this->repository->getPoz(i).getSuma()==pret)
                rez.adaugare(this->repository->getPoz(i));

        //for(int i=1;i<rez.getSize();i++)cout<<rez.getPoz(i).getTip()<<" "<<rez.getPoz(i).getData()<<" "<<rez.getPoz(i).getSuma()<<" "<<rez.getPoz(i).getNume()<<'\n';
        return rez;
    }

Repository Service::AfisareIn() {
    Repository rez;
    for(int i=1;i<this->repository->getSize();++i)
        if(strcmp(this->repository->getPoz(i).getTip(),"in")==0)
            rez.adaugare(this->repository->getPoz(i));
    return rez;
}

Cheltuiala Service::AfisareMaxOut(int ziua) {
    Cheltuiala rez;
    int max=0;
    for(int i=1;i<this->repository->getSize();++i)
        if(strcmp(this->repository->getPoz(i).getTip(),"out")==0 and max<this->repository->getPoz(i).getSuma())
            rez=this->repository->getPoz(i),max=this->repository->getPoz(i).getSuma();
    return rez;
}

void Service::StergereOut() {
    this->repository->stergeOut();
    }

void Service::adaugare(Cheltuiala &a1) {
    this->repository->adaugare(a1);

}

Cheltuiala* Service::getAll() {
    return this->repository->getAll();
}

void Service::StergeData(int data) {
    this->repository->sterge(data);
}

void Service::StergereInterval(int i, int s) {
    this->repository->stergeInterval(i,s);
}
void Service::StergereIn(){
    this->repository->stergeIn();
}

void Service::ModificaSuma(int data, char *tip, int suma) {
    this->repository->modifica(data,tip,suma);

}

Cheltuiala Service::getPoz(int i) {
    return this->repository->getPoz(i);
}

int Service::getSize() {
    return this->repository->getSize();
}


