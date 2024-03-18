#include <iostream>
#include <stack>
using namespace std;
#include "Service/Service.h"
#include "Repository/repository.h"
#include "Test/test.h"
#include "Repository/FileRepo.h"

void meniu()
{
    cout<<"1.Inserare tranzactie\n";
    cout<<"2.Afisare tranzactii\n";
    cout<<"3.Eliminare tranzactii dintr-o zi\n";
    cout<<"4.Stergere tranzactii dintr-un interval\n";
    cout<<"5.Elimina toate tranzactiile de tip in\n";
    cout<<"6.Modifica tranzactie de tip in\n";
    cout<<"7.Filtrare dupa nume\n";
    cout<<"8.Filtrare dupa nume si pret mai mare decat cel dat\n";
    cout<<"9.Filtrare dupa nume si pret egal cu cel dat\n";
    cout<<"10.Afisare cheltuielii de tip in\n";
    cout<<"11.Afisare cea mai mare cheltuiala de tip out dintr o zi data\n";
    cout<<"12.Stergere cheltuieli de tip out\n";
    cout<<"13.Stergere cheltuieli mai mici decat o suma data\n";
    cout<<"14.Iesire program\n";
}

int main() {
    //test a;
    //stack<Repository> Undo;
    //a.testAll();
    FileRepo v=FileRepo("C:\\Users\\butun\\OneDrive\\Desktop\\POO c++\\untitled9\\cmake-build-debug\\ch.txt");
    Service s= Service(v);
    int x;
    while (true) {
        meniu();
        cout << "Dati varianta \n";
        cin >> x;
        if (x == 1)
        {
            char *tip = new char[100], *nume = new char[100];
            int suma,data,cod;
            cout<<"Dati id-ul tranzactiei\n";
            cin>>cod;
            cout << "Dati tip ul tranzactiei\n";
            cin >> tip;
            cout << "Dati suma tranzactiei\n";
            cin >> suma;
            cout << "Dati numele bunului tranzactionat\n";
            cin >> nume;
            cout << "Dati data tranzactiei\n";
            cin >> data;

            Cheltuiala a1=Cheltuiala(cod,suma, tip, data, nume);
            s.adaugare(a1);
        }
        if (x == 2)
            for (int i = 1; i < s.getSize(); i++)
                cout<<"Codul cheltuielii este :"<<s.getPoz(i).getCod() << ",tipul ei este:" << s.getPoz(i).getTip() << ",in data de:" << s.getPoz(i).getData() << ",in valoare de:" << s.getPoz(i).getSuma() << "lei,numele ei fiind:" << s.getPoz(i).getNume() << '\n';

        if (x == 3) {
            int data;
            cout << "Dati data \n";
            cin >> data;
            s.StergeData(data);
        }
        if (x == 4) {
            int i, j;
            cout << "Dati intervalul \n";
            cin >> i >> j;

            if (i <= j)v.stergeInterval(i, j);
            else cout << "Dati in interval valid \n";
        }
        if (x == 5) { v.stergeIn(); }
        if (x == 6) {
            int id, salar;
            char *tip1=new char[100];
            cout << "Dati data in care trebuie modificata cheltuiala:\n";
            cin >> id;
            cout << "Dati tipul cheltuielii care trebuie modificata:\n";
            cin>>tip1;
            cout << "Dati noua suma:\n";
            cin>>salar;
            v.modifica(id, tip1,salar);
        }
        if (x == 7) {
            char *nume = new char[100];
            cout << "Dati numele bunului\n";
            cin >> nume;
            Repository rez = s.FiltareNume(nume);
            for (int i = 1; i < rez.getSize(); i++)
                cout << rez.getPoz(i).getTip() << " " << rez.getPoz(i).getData() << " " << rez.getPoz(i).getSuma()
                     << " " << rez.getPoz(i).getNume() << '\n';
        }
        if (x == 8) {
            char *nume = new char[100];
            int n;
            cout << "Dati numele bunului\n";
            cin >> nume;
            cout << "Dati pretul\n";
            cin >> n;
            Repository rez = s.FiltrareNumePret(nume, n);
            for (int i = 1; i < rez.getSize(); i++)
                cout << rez.getPoz(i).getTip() << " " << rez.getPoz(i).getData() << " " << rez.getPoz(i).getSuma()
                     << " " << rez.getPoz(i).getNume() << '\n';
        }
        if (x == 9) {
            char *nume = new char[100];
            int n;
            cout << "Dati numele bunului\n";
            cin >> nume;
            cout << "Dati pretul\n";
            cin >> n;
            Repository rez = s.FiltrareNumePretEgal(nume, n);
            for (int i = 1; i < rez.getSize(); i++)
                cout << rez.getPoz(i).getTip() << " " << rez.getPoz(i).getData() << " " << rez.getPoz(i).getSuma()
                     << " " << rez.getPoz(i).getNume() << '\n';
        }
        if (x == 10) {
            Repository rez = s.AfisareIn();
            for (int i = 1; i < rez.getSize(); i++)
                cout << rez.getPoz(i).getTip() << " " << rez.getPoz(i).getData() << " " << rez.getPoz(i).getSuma()
                     << " " << rez.getPoz(i).getNume() << '\n';
        }
        if (x == 11) {
            int n;
            cout << "Dati ziua\n";
            cin >> n;
            Cheltuiala rez = s.AfisareMaxOut(n);
            cout << rez.getTip() << " " << rez.getNume() << " " << rez.getData() << " " << rez.getSuma() << '\n';
        }
        if (x == 12)v.stergeOut();
        if (x == 13) {
            int n;
            cout << "Dati suma\n";
            cin >> n;

            v.stergeInSuma(n);
        }
        if(x==14)break;
    }
}