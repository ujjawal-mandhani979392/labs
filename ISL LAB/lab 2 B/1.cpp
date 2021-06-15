#include <bits/stdc++.h>
using namespace std;
#define MAX_LEN 100

int main()
{
    cout << "Enter the string: ";
    char str[MAX_LEN];
    cin.getline(str, MAX_LEN);
    int n = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        n++;
    }
    cout << str[0];
    for (int i = 1; i < n - 1; i++)
    {
        if (str[i] == ' ')
        {
            cout << str[i + 1];
        }
    }
    cout << endl;
    return 0;
}