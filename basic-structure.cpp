// #include <bits/stdc++.h> // includes all standard library headers
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int age;
    string name;

    cout << "Enter name and age: ";

    // 'cin' stops reading at the first whitespace (space, tab, newline)
    cin >> name >> age;

    cout << "User: " << name << " | Age: " << age << "\n";

    return 0;
}