#include <iostream>
using namespace std;

int binary_search(int arr[], int size, int key)
{
    int start = 0;
    int end = size - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2; // To avoid overflow

        if (arr[mid] == key)
            return mid; // Key found
        else if (arr[mid] < key)
            start = mid + 1; // Search in the right half
        else
            end = mid - 1; // Search in the left half
    }
    return -1; // Key not found
}

int main()
{
    int n;
    cout << "Enter Value of N: ";
    cin >> n;
    cout << endl;

    int arr[] = {2, 3, 4, 10, 40};

    int index = binary_search(arr, 5, n);
    if (index != -1)
        cout << "Element is present at index " << index << endl;
    else
        cout << "Element is not present in array" << endl;

    return 0;
}