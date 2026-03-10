// #include <bits/stdc++.h> // includes all standard library headers
#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); // untie C++ streams from C streams for faster I/O
    cin.tie(0);                   // untie cin from cout for faster input

    int age;
    string name;

    cout << "Enter name and age: ";

    // 'cin' stops reading at the first whitespace (space, tab, newline)
    cin >> name >> age;

    cout << "User: " << name << " | Age: " << age << "\n";

    return 0; // optional in C++ main function, as reaching the end of main implies return 0
}