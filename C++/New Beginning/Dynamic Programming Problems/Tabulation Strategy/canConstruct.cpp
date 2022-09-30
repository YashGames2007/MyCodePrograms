#include <iostream>
#include <string>
#include <map>
using namespace std;

bool is_Prefix(string _main, string _subStr)
{
    if (_subStr.length() > _main.length())
    {
        return false;
    }
    string prefix = _main.substr(0, (_subStr.length()));

    if (prefix != _subStr)
    {
        return false;
    }
    return true;
}

//* Dynamic Iterative canConstruct Implementation.
/*
    m = Target, n = word_Bank.size
    Time  Complexity: O(n * m^2)
    Space Complexity: O(m)
*/
bool canConstruct_Dynamic(string target, const string word_Bank[], int size)
{
    bool table[target.length() + 1];
    string subString, prefix;

    for (int i = 0; i <= target.length(); i++)
    {
        table[i] = false;
    }
    table[0] = true;

    for (int i = 0; i <= target.length(); i++)
    {
        subString = target.substr(0, i);
        subString = target.substr(subString.length());
        if (table[i])
        {
            for (int j = 0; j < size; j++)
            {
                if (is_Prefix(subString, word_Bank[j]))
                {
                    if ((i + word_Bank[j].length()) <= target.length())
                    {
                        table[i + word_Bank[j].length()] = true;
                    }
                }
            }
        }
    }
    return table[target.length()];
}

int main()
{
    string arr1[] = {"ab", "abc", "cd", "def", "abcd"};
    string arr2[] = {"bo", "rd", "ate", "t", "ska", "sk", "boar"};
    string arr3[] = {"a", "p", "ent", "enter", "ot", "o", "t"};
    string arr4[] = {"e", "ee", "eee", "eeee", "eeeee", "eeeeee"};

    cout << canConstruct_Dynamic("abcdef", arr1, 5) << endl;
    cout << canConstruct_Dynamic("skateboard", arr2, 7) << endl;
    cout << canConstruct_Dynamic("enterapotentpot", arr3, 7) << endl;
    cout << canConstruct_Dynamic("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", arr4, 6) << endl;
    return 0;
}