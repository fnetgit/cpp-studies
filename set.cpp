#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // Declarations
    set<int> mySet;
    unordered_set<int> unorderedSet;

    // Insertion
    mySet.insert(5);
    mySet.insert(10);
    unorderedSet.insert(5);
    unorderedSet.insert(10);

    // Deletion
    mySet.erase(5);
    unorderedSet.erase(5);
    mySet.clear();

    // Access and Search
    unorderedSet.find(10);
    unorderedSet.count(10);
    // unorderedSet.contains(10); // C++20 feature
}