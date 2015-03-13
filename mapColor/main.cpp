#include <iostream>

using namespace std;

int main()
{   char nombre[10];
    int valores = 990;
    int R;//max 255
    int G;//max 255
    int B;//max 255

    cin >> nombre;
    map(valores)
    cout << "Hello world!" << nombre << endl;
    return 0;
}
long map(long x, long in_min, long in_max, long out_min, long out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
