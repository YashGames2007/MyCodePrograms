#include <iostream>
using namespace std;

int get_pivot_index(int arr[], int size)
{
    int start = 0;
    int end = size - 1;

    while (start < end)
    {
        int mid = start + (end - start) / 2; // To avoid overflow

        if (arr[0] > arr[mid])
        {
            end = mid;
        }
        else
        {
            start = mid + 1;
        }
    }
    return start; // Key not found
}

int main()
{
    // Condition: Array should be strictly increasing and rotated
    int arr[] = {5, 10, 40, 2, 3, 4};

    int index = get_pivot_index(arr, 5);
    cout << "Pivot Element Index: " << index << endl;

    return 0;
}