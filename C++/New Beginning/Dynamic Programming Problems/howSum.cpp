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

//* Classic Recursive howSum Implementation.
int *howSum_Classic(int, const int[], int, int &, int &);

//* Dynamic Recursive howSum Implementation.
int *howSum_Dynamic(int, const int[], int, int &, int &, bool);

int *howSum_Classic(int targetSum, const int numbers[], int size, int &return_Size, int &index = temp)
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
        for (int i = 0; i < size; i++)
        {
            int *combination = howSum_Classic(targetSum - numbers[i], numbers, size, return_Size, index);
            if (combination != NULL)
            {
                combination[index] = numbers[i];
                index++;
                return_Size = index;
                return combination;
            }
        }
        return_Size = 0;
        return NULL;
    }
}

int *howSum_Dynamic(int targetSum, const int numbers[], int size, int &return_Size, int &index = temp, bool is_First_Call = true)
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
        return result->second.second;
    }
    if (targetSum < 0)
    {
        return ((int *)NULL);
    }
    else if (targetSum == 0)
    {
        int *combination = new int[1];
        index = 0;
        return_Size = 0;
        return combination;
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            int *combination = howSum_Dynamic(targetSum - numbers[i], numbers, size, return_Size, index, false);
            if (combination != (int *)NULL)
            {
                combination[index] = numbers[i];
                index++;
                return_Size = index;
                memo[targetSum] = make_pair(return_Size, combination);
                combination = (int *)realloc(combination, return_Size);
                return combination;
            }
        }
        memo[targetSum] = make_pair(0, (int *)NULL);
        return_Size = 0;
        return ((int *)NULL);
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

    arr = howSum_Dynamic(7, arr1, 2, size);
    print(arr, size);
    cout << "" << endl;
    arr = howSum_Dynamic(7, arr2, 4, size);
    print(arr, size);
    cout << "" << endl;
    arr = howSum_Dynamic(7, arr3, 2, size);
    print(arr, size);
    cout << "" << endl;
    arr = howSum_Dynamic(8, arr4, 3, size);
    print(arr, size);
    cout << "" << endl;
    arr = howSum_Dynamic(300, arr5, 2, size);
    print(arr, size);
    cout << "" << endl;
    return 0;
}