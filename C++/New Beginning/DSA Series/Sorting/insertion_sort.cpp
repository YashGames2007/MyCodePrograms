#include <iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i], j;
        for (j = i - 1; arr[j] > temp && j >= 0; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = temp;
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
    insertionSort(arr, 7);
    printArray(arr, 7);
    return 0;
}