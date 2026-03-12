#include <bits/stdc++.h>

using namespace std;

int main()
{
    int i = 1;
    while (i <= 3)
    {
        i++;
    }

    int soma = 0;
    for (int j = 1; j <= 3; j++)
    {
        soma += j;
    }

    int k = 0;
    do
    {
        k++;
    } while (k < 2);

    cout << "i = " << i << "\n";
    cout << "soma = " << soma << "\n";
    cout << "k = " << k << "\n";

}