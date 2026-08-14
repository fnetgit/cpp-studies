#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    bool difs[5] = {false};
    int count = 0;

    for (int i = 0; i < 10; i++)
    {
        int x;
        cin >> x;
        difs[x] = true;
    }

    for (int i = 1; i < 5; i++)
    {
        if (!difs[i])
        {
            count++;
        }
    }
    cout << count;

    return 0;
}