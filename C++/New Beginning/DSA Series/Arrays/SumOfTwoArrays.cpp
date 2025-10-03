#include <iostream>
#include <vector>
// #include <stl>
using namespace std;

vector<int> sumArray(int arr1[], int arr2[], int m, int n)
{
    vector<int> ans;
    int carry = 0;
    int i = m - 1, j = n - 1;
    for (; i >= 0 && j >= 0; i--, j--)
    {
        int sum = arr1[i] + arr2[j] + carry;
        ans.insert(ans.begin(), sum % 10);
        carry = sum / 10;
    }
    for (; i >= 0; i--)
    {
        int sum = arr1[i] + carry;
        ans.insert(ans.begin(), sum % 10);
        carry = sum / 10;
    }
    for (; j >= 0; j--)
    {
        int sum = arr2[j] + carry;
        ans.insert(ans.begin(), sum % 10);
        carry = sum / 10;
    }
    return ans;
}

int main()
{
    int arr1[] = {2, 3, 5};
    int arr2[] = {1, 2, 2};
    vector<int> ans = sumArray(arr1, arr2, 3, 3);

    cout << endl;
    for (int n : ans)
    {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}