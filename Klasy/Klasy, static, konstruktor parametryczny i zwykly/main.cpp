#include <iostream>
#include <string>
using namespace std;

class Osoba
{
    public:
    string imie;
    string nazwisko;
    int id;
    static int zliczanie;                                                                                       //deklaracja statica
    Osoba() : Osoba("Jan","Cieslar",01) {zliczanie++;}                                                          //konstruktor bezparametryczny
    Osoba(string IMIE, string NAZWISKO, int ID) : imie(IMIE), nazwisko(NAZWISKO), id(ID) {zliczanie++;}         //konstruktor parametryczny
};

int Osoba::zliczanie = 0;                                                                                      //ustawienie statica na 0 na poczatku kodu

int main()
{
    Osoba osoba1("Adam","Kowalski",02);                                                                         //wywolanie konstruktora bezparametrycznego
    return 1;
}