#include <iostream>
#include <map>
using namespace std;

//* Classic Recursive Fibonacci Sequence Implementation.
/*
    n = index
    Time  Complexity: O(2^n)
    Space Complexity: O(n)
*/
int fib_Classic(int);

//* Dynamic Recursive Fibonacci Sequence Implementation.
/*
    n = index
    Time  Complexity: O(n)
    Space Complexity: O(n)
*/
long long fib_Dynamic(int);

int main()
{
    int a, b, c;
    a = 1;
    b = 2;
    c = 50;

    cout << "Hello World!" << endl;
    cout << "Fib(" << a << "): " << fib_Dynamic(a) << endl;
    cout << "Fib(" << b << "): " << fib_Dynamic(b) << endl;
    cout << "Fib(" << c << "): " << fib_Dynamic(c) << endl;

    return 0;
}

int fib_Classic(int index)
{
    if (index <= 2)
    {
        return 1;
    }
    else
    {
        return (fib_Classic(index - 1) + fib_Classic(index - 2));
    }
}

long long fib_Dynamic(int index)
{
    static map<int, long long> memo = {};

    auto result = memo.find(index);
    if (result != memo.end())
    {
        // cout << "Found!" << endl;
        return result->second;
    }
    else if (index <= 2)
    {
        return 1;
    }
    else
    {
        memo[index] = (fib_Dynamic(index - 1) + fib_Dynamic(index - 2));
        return memo[index];
    }
}