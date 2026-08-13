#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    unordered_set<int> difs;
    vector<int> d = {1, 2, 3, 4}; //ver depois se com array dá certo
    int count = 0;

    for (int i = 0; i < 10; i++)
    {
        int x;
        cin >> x;
        difs.insert(x);
    }

    for (int x : d)
    {
        if (!difs.count(x))
        {
            count++;
        }
    }
    cout << count << "\n";
    return 0;
}