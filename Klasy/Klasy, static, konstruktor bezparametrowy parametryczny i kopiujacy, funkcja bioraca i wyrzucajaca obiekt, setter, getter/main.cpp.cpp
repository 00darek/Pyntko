#include <iostream>
#include <string>
using namespace std;

class Ksiazka
{
    private:
        string tytul;
        string autor;
        int rokWydania;
        int static zliczanieKsiazek;                                                                                                      //deklaracja statica
    public:
        Ksiazka()  : Ksiazka("brak","brak",0000) {zliczanieKsiazek++;};                                                                   //konstruktor bezparametrowy
        Ksiazka(string TYTUL, string AUTOR, int ROK) : tytul(TYTUL), autor(AUTOR), rokWydania(ROK) {zliczanieKsiazek++;}                  //konstruktor parametryczny
        Ksiazka(const Ksiazka &copied) : tytul{copied.tytul}, autor{copied.autor}, rokWydania{copied.rokWydania} {zliczanieKsiazek++;}    //konstruktor kopiujacy
        void Wypisz()
        {
            cout << "Tytul ksiazki: " << tytul << ".\n";
            cout << "Autor ksiazki: " << autor << ".\n";
            cout << "Rok wydania ksiazki: " << rokWydania << ".\n";
        }
        void setTytul()                                                                 //setter
        {
            string tytul1;
            cout << "Podaj tytul: ";
            cin >> tytul1;
            tytul=tytul1;
        }
        void setAutor()                                                                //setter
        {
            string autor1;
            cout << "Podaj Autora: ";
            cin.ignore(256,'\n');
            getline(cin,autor1);
            autor=autor1;
        }
        void setRok()                                                                 //setter
        {
            int rok1;
            cout << "Podaj rok wydania: ";
            cin >> rok1;
            rokWydania=rok1;
        }
        string getTytul()                                                             //getter 
        {
            return tytul;
        }
        string getAutor()                                                             //getter 
        {
            return autor;
        }
        int getRok()                                                                 //getter 
        {
            return rokWydania;
        }
        friend Ksiazka bigLetters(Ksiazka a);
};

int Ksiazka::zliczanieKsiazek = 0;                                                 // static na poczatku zawsze jest rowne 0

Ksiazka bigLetters(Ksiazka a)                                                      //funkcja pobieracja obiekt i zwracajaca obiekt 
{
    int i=0;
    for (char v : a.getTytul())
    {
        a.tytul[i] = toupper(v);
        i++;
    }
    return a;
}

int main()
{
    Ksiazka ksiazka1;
    Ksiazka ksiazka3("Maly Ksiaze", "Adam", 1989);
    ksiazka1.setTytul();
    ksiazka1.setAutor();
    ksiazka1.setRok();
    cout << "=====================\n";
    Ksiazka ksiazka2=ksiazka1;
    ksiazka1.Wypisz();
    cout << "=====================\n";
    ksiazka2.Wypisz();
    cout << "=====================\n";
    ksiazka3.Wypisz();
    cout << "=====================\n";
    Ksiazka ksiazka4=bigLetters(ksiazka1);
    cout << ksiazka4.getTytul();
    return 1;
}