#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < (n - 1); i++)
    {
        bool swap = false;
        for (int j = 0; j < (n - i - 1); j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap = true;
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        if (!swap)
        {
            return;
        }
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {5, 4, 1, 2, 6, 7, 3};

    printArray(arr, 7);
    bubbleSort(arr, 7);
    printArray(arr, 7);
    return 0;
}