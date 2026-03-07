#include <iostream>
#include <cmath>


using namespace std;

int main() {
    double x,y;
    cout << "Digite um número: ";
    cin >> x;
    cout << "Digite outro número: ";
    cin >> y;
    double exp = pow(x, y);
    double sqr = sqrt(x);
    cout << "Potência de " << x << " elevado a " << y << " é: " << exp << "\n";
    cout << "Raiz quadrada de " << x << " é: " << sqr << "\n";

    return 0;
}