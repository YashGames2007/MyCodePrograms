#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void display(vector<T> vector_Object)
{
    cout << "Vector: {" << endl;

    for (int i = 0; i < vector_Object.size() + 1; i++)
    {
        cout << vector_Object[i] << ", ";
    }
}

int main()
{
    vector<int> vec;
    vec.push_back(2);
    vec.push_back(2);
    vec.push_back(2);

    return 0;
}