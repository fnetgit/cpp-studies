// As letras maiúsculas (A a Z) ocupam as posições de 65 a 90.
// As letras minúsculas (a a z) ocupam as posições de 97 a 122.
// 97(a) - 32 = 65(A)
// 65(A) + 32 = 97(a)

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // SIMPLE SUM or SUBTRACTION
    // char c;
    // cout << "Digite uma letra Maiúscula: " << flush;
    // cin >> c;

    // char lower = c + 32;
    // cout << "Minúscula: " << lower << '\n';

    // Function
    // char c;
    // cout << "Digite uma letra Maiúscula: " << flush;
    // cin >> c;
    // char lower = tolower(c);
    // cout << lower << '\n';

    // BITWISE
    char c;
    cout << "Digite uma letra Maiúscula: " << flush;
    cin >> c;
    c = c | 32;
    // c = c & ~32; //lower to upper
    // c = c ^ 32; //toggle case
    cout << c << '\n';

    return 0;
}