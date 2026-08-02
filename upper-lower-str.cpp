// se a string for só de caracteres alfabéticos dá pra usar o bitwise

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // se a string for só de caracteres alfabéticos dá pra usar o bitwise
    string s;
    cout << "Digite uma string maiúscula: " << flush;
    cin >> s;
    for (char &c : s)
    {
        c = c | 32; // upper to lower
    }
    cout << s << '\n';

    // se tiver não alfabéticos, tem que verificar se é maiúscula antes de converter
    string s2;
    cout << "Digite uma string maiúscula: " << flush;
    cin >> s2; // o getline seria aqui
    for (char &c : s2)
    {
        if (c >= 'A' && c <= 'Z')
        {
            c |= 32;
        }
    }
    cout << s2 << '\n';

    return 0;
}

// ATENÇÃO
// Se tiver espaços faça:
// string text;
// getline(cin >> ws, text);

// getline: Lê a frase inteira, preservando os espaços.
// ws: Limpa qualquer lixo oculto no buffer antes de ler a linha, evitando bugs.