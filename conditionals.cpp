#include <bits/stdc++.h>

using namespace std;

int main()
{
    string turno = "noite";
    if (turno == "manha")
    {
        cout << "Bom dia";
    }
    else if (turno == "tarde")
    {
        cout << "Boa tarde";
    }
    else
    {
        cout << "Boa noite";
    }

    string turno2 = "manha";
    string saudacao = (turno == "manha") ? "Bom dia" :
                      (turno == "tarde") ? "Boa noite": "boa noite";
}