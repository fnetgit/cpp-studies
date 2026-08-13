#include <bits/stdc++.h>

using namespace std;

int main()
{

    int linha = 3;
    int coluna = 3;
    int matriz[linha][coluna];

    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            cout << "MATRIX[" << i << "][" << j << "] = ";
            cin >> matriz[i][j];
        }
    }

    return 0;
}
