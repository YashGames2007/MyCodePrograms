#include <iostream>
using namespace std;

int pow(int a, int b)
{
    int ans = 1;
    for (int i = 0; i < b; i++)
    {
        ans = ans * a;
    }
    return ans;
}

int main()
{
    int n, i = 0;
    cout << "Enter Value of N: ";
    cin >> n;
    cout << endl;

    /*
    Possible Notes:
    100
    50
    20
    1
     */

    int notes[] = {100, 50, 20, 1};

    for (int note : notes)
    {
        int numberOfNotes = n / note;
        n = n % note;
        cout << "Number of " << note << "Rs notes: " << numberOfNotes << endl;
    }

    return 0;
}