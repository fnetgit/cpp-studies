#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int dire, mins;

    cin >> dire >> mins;
    cout <<( mins - dire + 1) / dire  << '\n';

    return 0;
}