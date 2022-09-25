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

//* Classic Recursive canConstruct Implementation.
/*
    m = TargetSum, n = Numbers.length
    Time  Complexity: O(n^m * m)
    Space Complexity: O(m^2)
*/
bool canConstruct_Classic(string target, const string word_Bank[], int size)
{
    if (target == "")
    {
        return true;
    }
    else if (size == 0)
    {
        return false;
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            if (is_Prefix(target, word_Bank[i]))
            {
                if (canConstruct_Classic(target.substr(word_Bank[i].length()), word_Bank, size))
                {
                    return true;
                }
            }
        }
        return false;
    }
}

//* Dynamic Recursive canConstruct Implementation.
/*
    m = TargetSum, n = Numbers.length
    Time  Complexity: O(n * m^2)
    Space Complexity: O(m^2)
*/
bool canConstruct_Dynamic(string target, const string word_Bank[], int size, bool is_First_Call = true)
{
    static map<string, bool> memo = {};

    if (is_First_Call)
    {
        memo.clear();
    }

    auto result = memo.find(target);
    if (result != memo.end())
    {
        return result->second;
    }
    if (target == "")
    {
        return true;
    }
    else if (size == 0)
    {
        return false;
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            if (is_Prefix(target, word_Bank[i]))
            {
                if (canConstruct_Dynamic(target.substr(word_Bank[i].length()), word_Bank, size, false))
                {
                    memo[target] = true;
                    return true;
                }
            }
        }
        memo[target] = false;
        return false;
    }
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