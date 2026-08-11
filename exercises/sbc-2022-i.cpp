#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string n;
    getline(cin, n);
    
    cout << (n.find('9') != string::npos ? "F": "S") << '\n';

    return 0;
}