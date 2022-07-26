#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
    return;
}

void swap(int &a, int &b)
{
    return;
}

int main()
{
    // 6! = 6*5*4*3*2*1
    int a = 45;
    int &b = a;
    // scanf("%d", &a);
    cout <<endl<<"Before Swap: "<<a<<", "<<b;
    swap(a, b);
    cout <<endl<<"After Swap: "<<a<<", "<<b;
    return 0;
}