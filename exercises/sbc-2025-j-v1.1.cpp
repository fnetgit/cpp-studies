#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    unordered_set<int> difs;
    int d[] = {1, 2, 3, 4};
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