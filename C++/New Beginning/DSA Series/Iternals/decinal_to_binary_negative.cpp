#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    long long int n;
    cout << "Enter Value of N: " << endl;
    cin >> n;

    unsigned long long int i = 0, ans = 0;
    if (n < 0)
    {
        n = pow(2, 16) + n;
    }

    while (n)
    {
        int last_bit = (n & 1);
        ans = (last_bit * pow(10, i)) + ans;
        n >>= 1;
        i++;
    }
    cout << "Binary Representation: " << ans << endl;
    return 0;
}