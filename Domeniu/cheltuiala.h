//
// Created by butun on 4/19/2023.
//

#ifndef UNTITLED9_CHELTUIALA_H
#define UNTITLED9_CHELTUIALA_H


class Cheltuiala {
private:
    char *tip,*nume;
    int cod,suma,data;
public:
    Cheltuiala();
    ~Cheltuiala();
    Cheltuiala(int Cod,int Suma, char *Tip,int Data,char *Nume);
    int getCod();
    void setCod(int id);
    int getSuma();
    char* getTip();
    int getData();
    char* getNume();
    void setSuma(int suma);
    void setTip(char *Tip);
    void setData(int data);
    void setNume(char *Nume);
    Cheltuiala& operator=(const Cheltuiala &c);

};


#endif //UNTITLED9_CHELTUIALA_H
