//
// Created by butun on 4/19/2023.
//

#ifndef UNTITLED9_REPOSITORY_H
#define UNTITLED9_REPOSITORY_H
#include "../Domeniu/cheltuiala.h"

class Repository {
private:
    int nr;

protected:
    Cheltuiala *v;///v este un pointer care adrese de elemente de tip Cheltuiala
    int poz=1;
public:
    Repository();
    ~Repository();
    virtual Cheltuiala* getAll();
    virtual void adaugare(const Cheltuiala& a1);
    virtual void sterge(int data);
    virtual void stergeInterval(int i,int j);
    virtual void stergeIn();
    virtual void stergeInSuma(int suma);
    virtual void stergeOut();
    virtual void reSize();
    virtual int getSize();
    virtual void Refresh();
    virtual Cheltuiala getPoz(int poz);
    virtual void modifica(int Data,char* tip,int Salariu);
};


#endif //UNTITLED9_REPOSITORY_H
