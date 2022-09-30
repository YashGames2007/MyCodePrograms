#include <iostream>
#include <string>
#include <vector>
using namespace std;

void print(vector<vector<string>> vec)
{
    if (vec.size() == 0)
    {
        cout << "[]" << endl;
    }
    else if (vec.size() == 1 && vec[0].size() == 0)
    {
        cout << "[ [] ]" << endl;
    }
    else
    {
        cout << "[" << endl;
        for (int i = 0; i < vec.size(); i++)
        {
            cout << "  [ " << vec[i][0];
            for (int j = 1; j < vec[i].size(); j++)
            {
                cout << ", " << vec[i][j];
            }
            cout << " }" << endl;
        }
       cout << "]" << endl;
    }
}

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

//* Dynamic Iterative allConstruct Implementation.
/*
    m = Target, n = word_Bank.size
    Time  Complexity: O(n^m)
    Space Complexity: O(n^m)
*/
vector<vector<string>> allConstruct_Dynamic(string target, const string word_Bank[], int size)
{
    vector<vector<string>> table[target.length() + 1];
    vector<vector<string>> current;
    string sub_String;

    for (int i = 0; i <= target.length(); i++)
    {
        table[i] = *(new vector<vector<string>>);
    }
    table[0].push_back(*(new vector<string>));

    for (int i = 0; i <= target.length(); i++)
    {
        sub_String = target.substr(i);
        if (table[i].size() != 0)
        {
            for (int j = 0; j < size; j++)
            {
                if (is_Prefix(sub_String, word_Bank[j]))
                {
                    current = table[i];

                    for (int k = 0; k < current.size(); k++)
                    {
                        current[k].push_back(word_Bank[j]);
                        table[i + word_Bank[j].size()].push_back(current[k]);
                    }
                }
            }
        }
    }
    return table[target.length()];
}

int main()
{
    string arr1[] = {"purp", "p", "ur", "le", "purpl"};
    string arr2[] = {"ab", "abc", "cd", "def", "abcd", "ef", "c"};
    string arr3[] = {"bo", "rd", "ate", "t", "ska", "sk", "boar"};
    string arr4[] = {"a", "aa", "aaa", "aaaa", "aaaaa"};

    cout << "Hello World!" << endl;

    print(allConstruct_Dynamic("purple", arr1, 5));    
    print(allConstruct_Dynamic("abcdef", arr2, 7));
    print(allConstruct_Dynamic("skateboard", arr3, 7));
    print(allConstruct_Dynamic("aaaaaaaaaaz", arr4, 5));

    return 0;
}