#include <iostream>
using namespace std;

int main()
{
    int n;
    
    cout << "Enter Value of N: ";
    cin >> n;
    cout << endl;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= (n-i+1); j++)
        {
            cout << j << " ";
        }
        for (int j = 1; j < (i*2-1); j++)
        {
            cout << "* ";
        }
        for (int j = (n-i+1); j >= 1; j--)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}