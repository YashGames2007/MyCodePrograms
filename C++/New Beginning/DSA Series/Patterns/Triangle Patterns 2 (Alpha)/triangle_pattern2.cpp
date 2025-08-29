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
        for (int j = i; j <= n; j++)
        {
            cout << char(('A' - 1) + j) << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}