#include <iostream>
#include <map>
using namespace std;

//* Classic Recursive gridTraveler Sequence Implementation.
/*
    m = Rows, n = Columns
    Time  Complexity: O(2^(m + n))
    Space Complexity: O(m + n)
*/
long long gridTraveler_Classic(int, int);

//* Dynamic Recursive gridTraveler Sequence Implementation.
/*
    m = Rows, n = Columns
    Time  Complexity: O(m * n)
    Space Complexity: O(m + n)
*/
long long gridTraveler_Dynamic(int, int);

int main()
{
    cout << "Hello World!" << endl;

    cout << gridTraveler_Dynamic(1, 1) << endl;   // 1
    cout << gridTraveler_Dynamic(2, 3) << endl;   // 3
    cout << gridTraveler_Dynamic(3, 2) << endl;   // 3
    cout << gridTraveler_Dynamic(3, 3) << endl;   // 6
    cout << gridTraveler_Dynamic(18, 18) << endl; // 2333606220

    return 0;
}

long long gridTraveler_Classic(int m, int n)
{
    if (m == 0 || n == 0)
    {
        return 0;
    }
    else if (m == 1 && n == 1)
    {
        return 1;
    }
    else
    {
        return (gridTraveler_Classic(m - 1, n) + gridTraveler_Classic(m, n - 1));
    }
}

long long gridTraveler_Dynamic(int m, int n)
{
    static map<pair<int, int>, long long> memo = {};
 
    // auto result1 = memo.find();
    auto result1 = memo.find(make_pair(m, n));

    if (result1 != memo.end())
    {
        return result1->second;
    }
    auto result2 = memo.find(make_pair(n, m));

    if (result2 != memo.end())
    {
        return result2->second;
    }

    if (m == 0 || n == 0)
    {
        return 0;
    }
    else if (m == 1 && n == 1)
    {
        return 1;
    }
    else
    {
        memo[make_pair(m, n)] = (gridTraveler_Dynamic(m - 1, n) + gridTraveler_Dynamic(m, n - 1));
        return memo[make_pair(m ,n)];
    }
}