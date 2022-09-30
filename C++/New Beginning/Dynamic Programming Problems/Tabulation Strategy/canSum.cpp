#include <iostream>
using namespace std;

void print(bool arr[], int size)
{
    cout << "{" << arr[0];
    for (int i = 1; i < size; i++)
    {
        cout << ", " << arr[i];
    }
   cout << "}" << endl;
}

//* Dynamic Iterative canSum Implementation.
/*
    n = targetSum, m = numbers.length;
    Time  Complexity: O(n * m)
    Space Complexity: O(m)
*/
bool canSum_Dynamic(int, int[], int);

int main()
{
    cout << "Hello World!" << endl;

    int arr1[] = {2, 3};
    int arr2[] = {5, 3, 4, 7};
    int arr3[] = {2, 4};
    int arr4[] = {2, 3, 5};
    int arr5[] = {7, 14};
    cout << canSum_Dynamic(7, arr1, 2) << endl;
    cout << canSum_Dynamic(7, arr2, 4) << endl;
    cout << canSum_Dynamic(7, arr3, 2) << endl;
    cout << canSum_Dynamic(8, arr4, 3) << endl;
    cout << canSum_Dynamic(300, arr5, 2) << endl;

    return 0;
}

bool canSum_Dynamic(int targetSum, int numbers[], int size)
{
    bool table[targetSum + 1];

    for (int i = 0; i <= targetSum; i++)
    {
        table[i] = false;
    }
    table[0] = true;

    // print(table, targetSum + 1);
    for (int i = 0; i <= targetSum; i++)
    {
        if ((table[i]) == true)
        {
            for (int j = 0; j < size; j++)
            {
                if ((i + numbers[j]) <= targetSum)
                {
                    table[i + numbers[j]] = true;
                }
            }
        }
    }
    return table[targetSum];
}