#include <iostream>
using namespace std;

int sqrt(int n)
{
    int start = 0, end = n;
    int ans = -1, mid;

    while (start < end)
    {
        mid = start + (end - start) / 2;
        cout << "Mid: " << mid << " start: " << start << " end: " << end << endl;
        if (mid == (n / mid))
        {
            return mid;
        }
        else if (mid < (n / mid))
        {
            start = mid + 1;
            ans = mid;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}

double sqrt_precision(int root, int precision, int n)
{
    double factor = 1;
    double ans = root;

    for (int i = 0; i < precision; i++)
    {
        factor = factor / 10;
        for (double j = ans; j * j <= n; j += factor)
        {
            ans = j;
        }
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter Value of N: ";
    cin >> n;
    cout << endl;

    cout << "Square Root: " << sqrt_precision(sqrt(n), 5, n) << endl;
    return 0;
}