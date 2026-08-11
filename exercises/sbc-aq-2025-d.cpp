#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int toys_count;
    int height;

    cin >> toys_count >> height;
    vector<int> toys_heights(toys_count);

    for (auto &toy_height : toys_heights)
    {
        cin >> toy_height;
    }

    int sum = 0;
    for (const auto &toy_height : toys_heights)
    {
        if (toy_height <= height)
        {
            sum++;
        }
    }
    cout << sum << '\n';

    return 0;
}
