#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // PAIR
    // 1. Declarations
    pair<char, int> ascii;

    // 2. Initialization
    ascii.first = 'A';
    ascii.second = 65;
    // or
    ascii = make_pair('B', 66);

    // TUPLE
    // 1. Declarations
    tuple<string, int, double> pessoa;

    // 2. Initialization
    get<0>(pessoa) = "Fco";
    get<1>(pessoa) = 20;
    get<2>(pessoa) = 1.62;
    // or
    pessoa = make_tuple("Fco", 20, 1.62);
}