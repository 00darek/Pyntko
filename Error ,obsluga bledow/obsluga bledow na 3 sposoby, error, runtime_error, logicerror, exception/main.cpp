#include <iostream>
#include <stdexcept>
#include <exception>
using namespace std;

class MyLogicError : public logic_error
{
public:
    MyLogicError(const string &msg) : logic_error(msg) {}
};

class MyException : public exception
{
public:
    const char *what() const noexcept override
    {
        return "liczba jest trzy lub więcej cyfrowa";
    }
};
int main()
{
    float liczba{};
    try
    {
        cout << "podaj liczbe 2 cyfrową\n";
        cin >> liczba;
        if (liczba > 0 && liczba < 10)
            throw runtime_error("liczba jest jednocyfrowa");
        if (liczba > 99)
            throw MyException();
        if (liczba < 0)
            throw MyLogicError("liczba jest ujemna");
        if (liczba - (int)liczba != 0)
            throw liczba;
        cout << liczba;
    }
    catch (const runtime_error &e)
    {
        cout << e.what() << endl;
    }
    catch (const logic_error &e)
    {
        cout << e.what() << endl;
    }
    catch (const exception &e)
    {
        cout << e.what() << endl;
    }
    catch (float)
    {
        cout << "liczba niecałkowita" << endl;
    }
    return 0;
}