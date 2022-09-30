#include <iostream>
#include <map>
using namespace std;

//* Classic Recursive canSum Sequence Implementation.
/*
    m = TargetSum, n = Numbers.length
    Time  Complexity: O(n^m)
    Space Complexity: O(m)
*/
bool canSum_Classic(int, const int[], const int);

//* Dynamic Recursive canSum Sequence Implementation.
/*
    m = TargetSum, n = Numbers.length
    Time  Complexity: O(n * m)
    Space Complexity: O(m)
*/
bool canSum_Dynamic(int, const int[], const int, bool);

bool canSum_Classic(int targetSum, const int numbers[], const int size)
{
    if (targetSum < 0)
    {
        return false;
    }
    if (targetSum == 0)
    {
        return true;
    }
    for (int i = 0; i < size; i++)
    {
        if (canSum_Classic(targetSum - numbers[i], numbers, size))
        {
            return true;
        }
    }
    return false;
}

bool canSum_Dynamic(int targetSum, const int numbers[], const int size, bool is_First_Call = true)
{
    static map<int, bool> memo = map<int, bool>();
    if (is_First_Call)
    {
        memo.clear();
    }

    //* Condition Segment...
    auto result = memo.find(targetSum);
    if (result != memo.end())
    {
        return result->second;
    }
    if (targetSum < 0)
    {
        return false;
    }
    if (targetSum == 0)
    {
        return true;
    }
    for (int i = 0; i < size; i++)
    {
        if (canSum_Dynamic(targetSum - numbers[i], numbers, size, false))
        {
            memo[targetSum] = true;
            return true;
        }
    }
    memo[targetSum] = false;
    return false;
}

int main()
{
    cout << "Hello World!" << endl;

    int arr1[] = {2, 3};
    int arr2[] = {5, 3, 4, 7};
    int arr3[] = {2, 4};
    int arr4[] = {2, 3, 5};
    int arr5[] = {7, 14};

    cout << canSum_Dynamic(7, arr1, 2) << endl;   // true
    cout << canSum_Dynamic(7, arr2, 4) << endl;   // true
    cout << canSum_Dynamic(7, arr3, 2) << endl;   // false
    cout << canSum_Dynamic(8, arr4, 3) << endl;   // true
    cout << canSum_Dynamic(300, arr5, 2) << endl; // false
    return 0;
}