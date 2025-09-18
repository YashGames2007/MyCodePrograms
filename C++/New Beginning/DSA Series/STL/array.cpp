#include <iostream>
#include <array>
using namespace std;

int main()
{
    array<int, 5> arr = {1, 2, 3, 4, 5};
    cout << arr.at(0) << endl;
    cout << arr.size() << endl;
    cout << arr.front() << endl;
    cout << arr.back() << endl;
    cout << arr.empty() << endl;
    return 0;
}