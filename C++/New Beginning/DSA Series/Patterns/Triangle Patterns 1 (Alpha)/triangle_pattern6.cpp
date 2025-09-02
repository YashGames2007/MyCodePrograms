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
        for (int j = 1; j <= i; j++)
        {
            cout << char(('A' - 1) + (((i*(i-1))/2) + j)) << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}