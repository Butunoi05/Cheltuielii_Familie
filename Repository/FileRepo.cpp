//
// Created by butun on 3/8/2024.
//

#include "FileRepo.h"
#include "../Domeniu/cheltuiala.h"

void FileRepo::saveToFile() {

    ofstream f(fileName);
    cout<<Repository::getSize();
    for(int i=1;i<Repository::getSize();i++){
        f<<Repository::getPoz(i).getCod()<<","<<Repository::getPoz(i).getTip()<<','<<Repository::getPoz(i).getSuma()<<','<<Repository::getPoz(i).getNume()<<','<<Repository::getPoz(i).getData()<<'\n';
    }
    f.close();
}
void FileRepo::sterge(int data) {
    Repository::sterge(data);
    saveToFile();
}
void FileRepo::adaugare(const Cheltuiala &a1) {
    Repository::adaugare(a1);
    saveToFile();
}
void FileRepo::loadFromFile() {
    //if(!f_description.is_open())throw Exception;
    std::string line;
    while(!this->f_description.eof()){
        getline(this->f_description,line);
        std::stringstream iss(line);
        string tip;
        string suma;
        string nume;
        string data;
        string id;
        Cheltuiala cheltuiala;
        if(getline(iss,id,',') && getline(iss,tip,',') && getline(iss,suma,',') && getline(iss,nume,',') && getline(iss,data,',')){
        int parsed_suma=stoi(suma);
        int parsed_data=stoi(data);
        int parsed_id= stoi(id);
        char *parsed_tip= new char[tip.length()+1];
        strcpy(parsed_tip,tip.c_str());
        char *parsed_nume= new char[nume.length()+1];
        strcpy(parsed_nume,nume.c_str());
        cheltuiala=Cheltuiala(parsed_id,parsed_suma,parsed_tip,parsed_data,parsed_nume);
        Repository::adaugare(cheltuiala);
        }

    }
}

FileRepo::~FileRepo() {
    if(this->f_description.is_open())this->f_description.close();
}

FileRepo::FileRepo(const std::string& Filename) {
    this->fileName=Filename;
    this->f_description.open(Filename,std::ios::in | std::ios::out);
    this->loadFromFile();
}

