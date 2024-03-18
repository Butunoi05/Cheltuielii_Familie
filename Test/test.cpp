//
// Created by butun on 4/24/2023.
//
#include <iostream>
#include "../Service/Service.h"
#include <cassert>
#include "test.h"
#include "../Repository/repository.h"
#include<cstring>
using namespace std;
void test::testAdaugare() {
    Repository v;
    assert(v.getSize()==1);
    Cheltuiala a1(1,100,"in",1,"aaa");
    v.adaugare(a1);
    assert(v.getSize()==2);
    assert(strcmp(a1.getNume(),"aaa")==0);
}

void test::testStergereInterval() {
    Repository v;
    Cheltuiala a1(1,100,"in",1,"aaa");
    Cheltuiala a2(2,100,"in",2,"aaa");
    Cheltuiala a3(3,100,"in",3,"aaa");
    Cheltuiala a4(4,100,"in",4,"aaa");
    Cheltuiala a5(5,100,"in",5,"aaa");
    v.adaugare(a1);
    v.adaugare(a2);
    v.adaugare(a3);
    v.adaugare(a4);
    v.adaugare(a5);
    assert(v.getSize()==6);
    v.stergeInterval(2,4);
    assert(v.getSize()==3);
}

void test::testStergereIn() {
    Repository v;
    Cheltuiala a1(1,100,"in",1,"aaa");
    Cheltuiala a2(2,100,"in",2,"aaa");
    Cheltuiala a3(3,100,"in",3,"aaa");
    Cheltuiala a4(4,100,"in",4,"aaa");
    Cheltuiala a5(5,100,"in",5,"aaa");
    Cheltuiala a6(6,100,"out",5,"aaa");
    Cheltuiala a7(7,100,"out",5,"aaa");
    v.adaugare(a1);
    v.adaugare(a2);
    v.adaugare(a3);
    v.adaugare(a4);
    v.adaugare(a5);
    v.adaugare(a6);
    v.adaugare(a7);
    v.stergeIn();
    assert(v.getSize()==3);
}
void test::testAll() {
    testAdaugare();
    testStergereInterval();
    testStergereIn();
}


