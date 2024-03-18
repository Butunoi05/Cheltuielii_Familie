//
// Created by butun on 3/8/2024.
//

#ifndef UNTITLED9_FILEREPO_H
#define UNTITLED9_FILEREPO_H
#include <iostream>
#include <fstream>
#include <cstring>
#include "repository.h"
#include <sstream>
#pragma once
using namespace std;
class FileRepo: public Repository{
private:
    string fileName;
    fstream  f_description;
public:
        FileRepo()=default;
        FileRepo(const string& filename);
        ~FileRepo();
        void loadFromFile();
        void saveToFile();
        void adaugare(const Cheltuiala &a1) override;
        void sterge(int data) override;
    }
;
#endif //UNTITLED9_FILEREPO_H
