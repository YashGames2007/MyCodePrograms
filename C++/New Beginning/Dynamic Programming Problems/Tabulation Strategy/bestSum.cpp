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

//* Dynamic Iterative bestSum Implementation.
/*
    n = targetSum, m = numbers.length;
    Time  Complexity: O(n * m^2)
    Space Complexity: O(m^2)
*/
int *bestSum_Dynamic(int, int[], int, int &);

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
    arr = bestSum_Dynamic(8, arr2, 3, size);
    print(arr, size);
    arr = bestSum_Dynamic(8, arr3, 3, size);
    print(arr, size);
    arr = bestSum_Dynamic(100, arr4, 4, size);
    print(arr, size);
    return 0;
}

int *bestSum_Dynamic(int targetSum, int numbers[], int size, int &return_Size)
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
                    if (((table[i].size() + 1) < table[current].size()) || (table[current][0] == -1))
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
    }

    int *result = new int[table[targetSum].size()];
    for (int i = 0; i < table[targetSum].size(); i++)
    {
        result[i] = table[targetSum][i];
    }
    return_Size = table[targetSum].size();
    return result;
}