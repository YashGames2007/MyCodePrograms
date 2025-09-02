#include <iostream>
using namespace std;

int pow(int a, int b);

int main()
{
    int n;
    cout << "Enter Value of N: ";
    cin >> n;
    cout << endl;

    int ans = 0;
    int bit;
    int i = 0;

    while (n > 0)
    {
        bit = n % 10;                  // Extracting last bit
        ans = (bit * pow(2, i)) + ans; // Adding to the answer
        n /= 10;
        i++;
    }
    cout << "Binary Representation: " << ans << endl;
    return 0;
}

int pow(int a, int b)
{
    int ans = 1;
    for (int i = 0; i < b; i++)
    {
        ans = ans * a;
    }
    return ans;
}