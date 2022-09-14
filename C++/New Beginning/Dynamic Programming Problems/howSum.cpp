#include <iostream>
#include <map>
using namespace std;

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

//* Classic Recursive howSum Sequence Implementation.
int *howSum_Classic(int, const int[], int &, bool);

//* Dynamic Recursive howSum Sequence Implementation.
int *howSum_Dynamic(int, const int[], int &, bool);

int *howSum_Classic(int targetSum, const int numbers[], int &size, bool is_First_Call = true)
{
    static int index = 0;
    if (is_First_Call)
    {
        index = 0;
    }

    if (targetSum < 0)
    {
        return NULL;
    }
    else if (targetSum == 0)
    {
        int *combination = new int[size];
        return combination;
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            int *combination = howSum_Dynamic(targetSum - numbers[i], numbers, size, false);
            if (combination != NULL)
            {
                combination[index] = numbers[i];
                index++;
                if (is_First_Call)
                {
                    size = index;
                }
                return combination;
            }
        }
        if (is_First_Call)
        {
            size = 0;
        }
        return NULL;
    }
}

int *howSum_Dynamic(int targetSum, const int numbers[], int &size, bool is_First_Call = true)
{
    static int index = 0;
    static map<int, int*> memo = {};

    auto result = memo.find(targetSum);
    if (result != memo.end())
    {
        return result->second;
    }
    
    if (is_First_Call)
    {
        index = 0;
    }

    if (targetSum < 0)
    {
        return NULL;
    }
    else if (targetSum == 0)
    {
        int *combination = new int[size];
        return combination;
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            int *combination = howSum_Dynamic(targetSum - numbers[i], numbers, size, false);
            if (combination != NULL)
            {
                combination[index] = numbers[i];
                index++;
                // if (is_First_Call)
                // {
                    size = index;
                // }
                memo[targetSum] = combination;
                return combination;
            }
        }
        if (is_First_Call)
        {
            size = 0;
        }
        memo[targetSum] = NULL;
        return NULL;
    }
}

int main()
{
    cout << "Hello World!" << endl;

    int arr1[] = {2, 3};
    int arr2[] = {5, 3, 4, 7};
    int arr3[] = {2, 4};
    int arr4[] = {2, 3, 5};
    int arr5[] = {7, 14};

    int size;
    int *arr;

    size = 2;
    arr = howSum_Dynamic(7, arr1, size);
    print(arr, size);
    cout << "" << endl;
    size = 4;
    arr = howSum_Dynamic(7, arr2, size);
    print(arr, size);
    cout << "" << endl;
    size = 2;
    arr = howSum_Dynamic(7, arr3, size);
    print(arr, size);
    cout << "" << endl;
    size = 3;
    arr = howSum_Dynamic(8, arr4, size);
    print(arr, size);
    cout << "" << endl;
    size = 2;
    arr = howSum_Dynamic(300, arr5, size);
    print(arr, size);
    cout << "" << endl;
    return 0;
}