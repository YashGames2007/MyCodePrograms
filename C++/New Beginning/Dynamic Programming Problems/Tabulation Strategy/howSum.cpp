#include <iostream>
#include <vector>
using namespace std;

void print(int arr[], int size)
{
    if (size == 1 && arr[0] == -1)
    {
        cout << "NULL" << endl;
        return;
    }
    
    cout << "[ " << arr[0];
    for (int i = 1; i < size; i++)
    {
        cout << ", " << arr[i];
    }
    cout << " ]" << endl;
}

//* Dynamic Iterative howSum Implementation.
/*
    n = targetSum, m = numbers.length;
    Time  Complexity: O(n * m^2)
    Space Complexity: O(m^2)
*/
int *howSum_Dynamic(int, int[], int, int &);

int main()
{
    cout << "Hello World!" << endl;

    int arr1[] = {2, 3};
    int arr2[] = {5, 3, 4, 7};
    int arr3[] = {2, 4};
    int arr4[] = {2, 3, 5};
    int arr5[] = {7, 14};
    int *arr;
    int size = 0;

    arr = howSum_Dynamic(7, arr1, 2, size);
    print(arr, size);
    arr = howSum_Dynamic(7, arr2, 4, size);
    print(arr, size);
    arr = howSum_Dynamic(7, arr3, 2, size);
    print(arr, size);
    arr = howSum_Dynamic(8, arr4, 3, size);
    print(arr, size);
    arr = howSum_Dynamic(300, arr5, 2, size);
    print(arr, size);

    return 0;
}

int *howSum_Dynamic(int targetSum, int numbers[], int size, int &return_Size)
{
    vector<vector<int>> table = {};
    int current = 0;

    for (int i = 0; i <= targetSum; i++)
    {
        table.push_back(*(new vector<int>));
        table[i].push_back(-1);
    }
    table[0][0] = 0;

    for (int i = 0; i <= targetSum; i++)
    {
        if (table[i][0] != -1)
        {
            for (int j = 0; j < size; j++)
            {
                current = i + numbers[j];
                if (current <= targetSum)
                {
                    table[current].clear();

                    if (!(table[i].size() == 1 && table[i][0] == 0))
                    {
                        for (int k = 0; k < table[i].size(); k++)
                        {
                            table[current].push_back(table[i][k]);
                        }
                    }
                    table[current].push_back(numbers[j]);
                }
            }
        }
    }

    int *result = new int[table[targetSum].size()];
    for (int i = 0; i < table[targetSum].size(); i++)
    {
        result[i] = table[targetSum][i];
    }
    return_Size = table[targetSum].size();
    return result;
}