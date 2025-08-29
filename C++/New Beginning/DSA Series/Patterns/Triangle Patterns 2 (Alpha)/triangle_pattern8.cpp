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
            cout << char(('A' - 1) + (n * (n + 1)) / 2 - ( ((i - 1) * (2 * n - i + 2)) / 2 + (j - i + 1) ) + 1) << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}