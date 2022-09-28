#include <iostream>
#include <map>
using namespace std;

int temp = 0;

void print(int array[], int size)
{
    if (array == NULL || size == 0)
    {
        cout << "{}";
    }
    else
    {
        cout << "{" << array[0];
        for (int i = 1; i < size; i++)
        {
            cout << ", " << array[i];
        }
        cout << "}";
    }
}

//* Classic Recursive bestSum Implementation.
/*
    m = TargetSum, n = Numbers.length
    Time  Complexity: O(n^m)
    Space Complexity: O(m)
*/
int *bestSum_Classic(int, const int[], int, int &, int &);

//* Dynamic Recursive bestSum Implementation.
/*
    m = TargetSum, n = Numbers.length
    Time  Complexity: O(n * m^2)
    Space Complexity: O(m^2)
*/
int *bestSum_Dynamic(int, const int[], int, int &, int &, bool);

int *bestSum_Classic(int targetSum, const int numbers[], int size, int &return_Size, int &index = temp)
{
    if (targetSum < 0)
    {
        return NULL;
    }
    else if (targetSum == 0)
    {
        int *combination = new int[size];
        index = 0;
        return combination;
    }
    else
    {
        int *lowest_Combination;
        int *combination;
        int lowest_Index = INT_MAX;

        for (int i = 0; i < size; i++)
        {
            combination = bestSum_Classic(targetSum - numbers[i], numbers, size, return_Size, index);
            if (combination != NULL)
            {
                combination[index] = numbers[i];
                index++;

                if (index < lowest_Index)
                {
                    lowest_Index = index;
                    lowest_Combination = combination;
                }
            }
        }
        if (lowest_Index == INT_MAX)
        {
            return_Size = 0;
            return NULL;
        }
        else
        {
            return_Size = lowest_Index;
            return lowest_Combination;
        }
    }
}

int *bestSum_Dynamic(int targetSum, const int numbers[], int size, int &return_Size, int &index = temp, bool is_First_Call = true)
{
    static map<int, pair<int, int *>> memo = {};

    if (is_First_Call)
    {
        memo.clear();
    }

    auto result = memo.find(targetSum);
    if (result != memo.end())
    {
        return_Size = result->second.first;
        if (return_Size != 0)
        {
            int *lowest_Combination = result->second.second;
            int *combination = new int[return_Size];

            for (int i = 0; i < return_Size; i++)
            {
                combination[i] = lowest_Combination[i];
            }
            index = return_Size;
            return combination;
        }
        return (int *)NULL;
    }
    if (targetSum < 0)
    {
        return NULL;
    }
    else if (targetSum == 0)
    {
        int *combination = new int[size];
        index = 0;
        return_Size = 0;
        return combination;
    }
    else
    {
        int *lowest_Combination;
        int *combination;
        int lowest_Index = INT_MAX;

        for (int i = 0; i < size; i++)
        {
            combination = bestSum_Dynamic(targetSum - numbers[i], numbers, size, return_Size, index, false);
            if (combination != NULL)
            {
                combination[index] = numbers[i];
                index++;

                if (index < lowest_Index)
                {
                    lowest_Index = index;
                    lowest_Combination = combination;
                }
            }
        }
        if (lowest_Index == INT_MAX)
        {
            return_Size = 0;
            memo[targetSum] = make_pair(return_Size, (int *)NULL);
            return (int *)NULL;
        }
        else
        {
            return_Size = lowest_Index;
            memo[targetSum] = make_pair(return_Size, lowest_Combination);
            return lowest_Combination;
        }
    }
}

int main()
{
    cout << "Hello World!" << endl;

    int arr1[] = {5, 3, 4, 7};
    int arr2[] = {2, 3, 5};
    int arr3[] = {1, 4, 5};
    int arr4[] = {1, 2, 5, 25};

    int size;
    int *arr;

    arr = bestSum_Dynamic(7, arr1, 4, size);
    print(arr, size);
    cout << "" << endl;
    arr = bestSum_Dynamic(8, arr2, 3, size);
    print(arr, size);
    cout << "" << endl;
    arr = bestSum_Dynamic(8, arr3, 3, size);
    print(arr, size);
    cout << "" << endl;
    arr = bestSum_Dynamic(100, arr4, 4, size);
    print(arr, size);
    cout << "" << endl;
    return 0;
}