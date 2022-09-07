#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int number[5], restart, length, digits[5], iteration;
    do
    {
        restart = 0;

        cout << endl
             << "How Many Tables Do You Want To Be Printed Side-by-Side? (MAX: 5): ";
        cin >> iteration;

        if (iteration > 5)
        {
            iteration = 5;
        }
        else if (iteration < 1)
        {
            iteration = 1;
        }

        for (int i = 1; i <= iteration; i++)
        {
            cout << "\nType Number " << i << ": ";
            cin >> number[i - 1];
        }

        for (int i = 0; i < iteration; i++)
        {
            length = number[i];
            digits[i] = 0;

            while (length > 0)
            {
                length /= 10;
                digits[i]++;
            }
        }

        for (int i = 1; i <= 10; i++)
        {
            cout << endl;

            for (int j = 0; j < iteration; j++)
            {
                cout << number[j] << " X " << setw(2) << i << " = " << setw(digits[j] + 1) << number[j] * i;
                cout << "    ";
            }
        }

        cout << "\n\n\nDo You Want To Restart?\n\n    <*> Type '1' For Yes.\n    <*> Type '0' For No.\n\n:::(0/1)::: ";
        cin >> restart;

        if (restart != 1)
        {
            restart = 0;
        }
    } while (restart);
    return 0;
}