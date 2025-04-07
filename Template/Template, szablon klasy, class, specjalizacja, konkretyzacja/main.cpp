#include <iostream>
using namespace std;

template <typename T1, typename T2>
class Szablon
{
public:
  T1 m1;
  T2 m2;
  void display()
  {
    cout << "konkkretyzacja " << endl;
  }
};

template <>
class Szablon<int, float>
{
public:
  int m1;
  float m2;
  void display()
  {
    cout << " specjalizacja int float " << endl;
  }
};

template <>
void Szablon<double,float>:: display()
{
    cout << " specjalizacja double float " << endl;
};


int main()
{
  Szablon<double, float> szablon{1.1, 2.9f};
  szablon.display();
  Szablon<int, float> szablon2{1, 2.123f};
  szablon2.display();
  Szablon<int, int> szablon3{21, 23};
  szablon3.display();
  return 0;
}