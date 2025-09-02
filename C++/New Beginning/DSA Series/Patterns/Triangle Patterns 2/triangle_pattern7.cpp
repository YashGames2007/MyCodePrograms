#include <iostream>
using namespace std;
/*
1 2 3 4 5
6 7 8 9
10 11 12
13 14
15
*/
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
            cout << (((i - 1) * (2 * n - i + 2)) / 2) + (j - i + 1) << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}