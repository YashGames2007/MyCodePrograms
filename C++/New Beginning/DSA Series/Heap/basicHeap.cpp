#include <iostream>
using namespace std;

// Function to swap two integers
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

class MaxHeap
{
public:
    int arr[100];
    int size;

    MaxHeap()
    {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val)
    {
        size++;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index / 2;
            cout << "Indexes: " << parent << ", " << index << endl;
            cout << "Values: " << arr[parent] << ", " << arr[index] << endl;
            if (arr[parent] < arr[index])
            {
                cout << "Swapping..." << arr[parent] << ", " << arr[index] << endl;
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void deleteLast()
    {
        if (size == 0)
        {
            cout << "Nothing to Delete!" << endl;
            return;
        }

        arr[1] = arr[size];
        size--;

        int i = 1;
        while (i < size)
        {
            int leftIndex = i * 2;
            int rightIndex = i * 2 + 1;

            if (leftIndex < size && arr[i] < arr[leftIndex])
            {
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }
            else if (rightIndex < size && arr[i] < arr[rightIndex])
            {
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        cout << endl;
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    MaxHeap h;
    h.insert(5);
    h.insert(4);
    h.insert(1);
    h.insert(2);
    h.insert(10);
    h.insert(9);
    h.insert(8);
    h.print();
    return 0;
}