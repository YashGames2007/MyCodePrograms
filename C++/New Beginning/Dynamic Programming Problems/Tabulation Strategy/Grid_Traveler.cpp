#include <iostream>
using namespace std;

void print(long long *arr, int m, int n)
{
    cout << "{" << endl;
    for (int i = 0; i < m; i++)
    {
        cout << "  {" << arr[i * n];
        for (int j = 1; j < n; j++)
        {
            cout << ", " << arr[(n * i) + j];
        }
        cout << "}" << endl;
    }
    cout << "}" << endl;
}

//* Dynamic Iterative gridTraveler Implementation.
/*
    n = rows, m = columns;
    Time  Complexity: O(n * m)
    Space Complexity: O(n * m)
*/
long long gridTraveler_Dynamic(int, int);

int main()
{
    cout << "Hello World!" << endl;
    cout << gridTraveler_Dynamic(1, 1) << endl;
    cout << gridTraveler_Dynamic(2, 3) << endl;
    cout << gridTraveler_Dynamic(3, 2) << endl;
    cout << gridTraveler_Dynamic(3, 3) << endl;
    cout << gridTraveler_Dynamic(18, 18) << endl;

    return 0;
}

long long gridTraveler_Dynamic(int m, int n)
{
    long long table[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            table[i][j] = 0;
        }
    }
    table[1][1] = 1;

    print(table[0], m + 1, n + 1);

    long long count = 0;
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i != m)
            {
                table[i + 1][j] += table[i][j];
            }
            if (j != n)
            {
                table[i][j + 1] += table[i][j];
            }
        }
    }

    // print(table[0], m + 1, n + 1);
    return table[m][n];
}