#include <iostream>
using namespace std;

//* Dynamic Iterative Fibonacci Sequence Implementation.
/*
    n = index
    Time  Complexity: O(n)
    Space Complexity: O(n)
*/
long long fib_Dynamic(int);

int main()
{
    cout << "Hello World!" << endl;
    cout << fib_Dynamic(6) << endl;
    cout << fib_Dynamic(7) << endl;
    cout << fib_Dynamic(8) << endl;
    cout << fib_Dynamic(50) << endl;

    return 0;
}

long long fib_Dynamic(int index)
{
    long long *table = new long long [index + 1];

    for (int i = 0; i <= index; i++)
    {
        table[i] = 0;
    }
    table[1] = 1;

    for (int i = 0; i <= index; i++)
    {
        table[i + 1] += table[i];
        if (i != index)
        {
            table[i + 2] += table[i];
        }
    }
    long long result = table[index];
    delete table;
    return result;
}