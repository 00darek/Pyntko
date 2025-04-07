#include <iostream>
#include <string>
using namespace std;

class Osoba
{
    private:
        int id;
        string imie;
    public:
        void setId()                                                                 //setter od id
        {
            int podaneId;
            cout << "Podaj id osoby: ";
            cin >> podaneId;
            id=podaneId;
        }
        void setImie()                                                               //setter od imienia
        {
            string podaneImie;
            cout << "Podaj imie osoby: ";
            cin >> podaneImie;
            imie=podaneImie;
        }
        int getId()                                                                 //getter od id
        {
            return id;
        }
        string getImie()                                                            //getter od imienia
        {
            return imie;
        }
};

int main()
{
    Osoba osoba1;
    osoba1.setId();
    osoba1.setImie();
    cout << "Id osoby to: " << osoba1.getId();
    cout << "Imie osoby to: " << osoba1.getImie();
    return 1;
}