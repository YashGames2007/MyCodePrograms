#include <iostream>
using namespace std;

int fact(int n, int m)
{
    if (n == 0 || n == 1)
        return 1;
    return (1LL * fact(n - 1, m) * n) % m; // use 1LL to avoid overflow
}

int main()
{
    int n;
    int m = 10000009; // 10^7 + 9
    cout << "Enter Value of N: ";
    cin >> n;
    cout << "Mod Factorial = " << fact(n, m) << endl;
    return 0;
}
