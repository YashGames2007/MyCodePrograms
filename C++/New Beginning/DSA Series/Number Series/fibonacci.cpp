#include <iostream>
using namespace std;

int fib(int n)
{
    if (n == 0 || n == 1)
        return n;
    return fib(n - 2) + fib(n - 1);
}

int main()
{
    int n;
    cout << "Enter Value of N: ";
    cin >> n;
    cout << endl;
    cout << "Fibonacci Number at index " << n << " is: " << fib(n) << endl;
    return 0;
}