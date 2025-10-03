#include <iostream>
using namespace std;

int getStringLength(char str[])
{
    int len = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        len++;
    }
    return len;
}

void reverseString(char str[])
{
    int length = getStringLength(str);

    for (int i = 0; i < (length / 2); i++)
    {
        swap(str[i], str[length - i - 1]);
    }
}

int main()
{
    // char name[20];
    // cout << "Enter Your Name: ";
    // cin >> name;
    // cout << endl;

    // cout << "Original Name: " << name << endl;
    // reverseString(name);
    // cout << "Reversed Name: " << name << endl;

    string a = "Yash";
    char b[] = "Yash";
    b[2] = '\0';
    a[2] = '\0';

    cout << a << endl;
    cout << b << endl;

    return 0;
}