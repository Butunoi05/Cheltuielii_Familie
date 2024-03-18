//
// Created by butun on 4/19/2023.
//

#include "repository.h"
#include "../Domeniu/cheltuiala.h"
#include <cstring>
Repository::Repository() {
    this->nr=1;
    this->v =new Cheltuiala[nr];///v este un pointer la un array de elemente de tip Cheltuiala
}

Repository::~Repository() {
    delete[] this->v;
    this->nr=0;
}

int Repository::getSize(){
    return this->poz;
}
void Repository::reSize() {
    auto *p=new Cheltuiala[nr*2];
    for(int i=1;i<=this->nr;i++)p[i]=this->v[i];
    delete[] this->v;
    this->nr=this->nr*2;
    this->v=p;
}

void Repository::adaugare(const Cheltuiala& a1) {///Se retine adresa elementului pe pozitia poz
    if(poz == this->nr)reSize();
    v[this->poz++]=a1;
}

Cheltuiala Repository::getPoz(int j) {
    return v[j];///Se returneaza elementul de tip Cheltuiala de la adresa v[j]
    ///return &v[j]; returneaza adresa elementului de tip cheltuiala de la adresa v[j];
}

void Repository::sterge(int data) {
    for(int i=1;i<this->poz;i++)
        if(v[i].getData()==data)
        {
            for(int j=i;j<this->poz-1;j++)
                v[j]=v[j+1];
            this->poz=this->poz-1;
            this->Refresh();
            i--;
        }
}

void Repository::stergeInterval(int i, int j) {
    for(int a=1;a<this->poz;a++)
        if(v[a].getData()>=i and v[a].getData()<=j)
        {   int k=a;
            for(;k<this->poz-1;k++)
                v[k]=v[k+1];
            this->poz--;
            a--;
        }
}

void Repository::stergeIn() {
    for(int i=1;i<this->poz;i++)
        if(strcmp(v[i].getTip(),"in")==0)
        {
            for(int j=i;j<this->poz-1;j++)
                v[j]=v[j+1];
            this->poz--;
            i--;
        }
}

void Repository::stergeOut() {
    for(int i=1;i<this->poz;i++)
        if(strcmp(v[i].getTip(),"out")==0)
        {
            for(int j=i;j<this->poz-1;j++)
                v[j]=v[j+1];
            this->poz--;
            i--;
        }
}

void Repository::modifica(int Data,char*  tip1, int Salariu) {
    for(int a=1;a<this->poz;a++)
        if(v[a].getData()==Data and strcmp(v[a].getTip(),tip1)==0)
            v[a].setSuma(Salariu);

}

Cheltuiala *Repository::getAll() {
    return this->v;
}

void Repository::stergeInSuma(int suma) {
    for(int i=1;i<this->poz;i++)
        if(strcmp(v[i].getTip(),"in")==0 and v[i].getSuma()<suma)
        {
            for(int j=i;j<this->poz-1;j++)
                v[j]=v[j+1];
            this->poz--;
            i--;
        }
}

void Repository::Refresh() {
        auto *p=new Cheltuiala[nr];
        for(int i=1;i<=this->poz;i++)p[i]=this->v[i];
        delete[] this->v;
        this->v=p;
}
