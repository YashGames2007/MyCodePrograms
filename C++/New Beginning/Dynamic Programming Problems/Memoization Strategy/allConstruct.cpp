#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

void print(vector<vector<string>> *varr)
{
    if (varr->empty())
    {
        cout << "{}" << endl;
    }
    else if ((varr->size() == 1) && varr[0].empty())
    {
        cout << "{{}}" << endl;
    }
    else
    {
        cout << "{" << endl;
        for (int i = 0; i < varr->size(); i++)
        {
            cout << "    {" << varr->at(i)[0];

            for (int j = 1; j < varr->at(i).size(); j++)
            {
                cout << ", " << varr->at(i)[j];
            }
            cout << "}," << endl;
        }
        cout << "}." << endl;
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

//* Classic Recursive allConstruct Implementation.
/*
    m = TargetSum, n = Numbers.length
    Time  Complexity: O(n^m * m)
    Space Complexity: O(m * n)
*/
vector<vector<string>> *allConstruct_Classic(string target, const string word_Bank[], int size)
{
    if (target == "")
    {
        vector<vector<string>> *vec = (new vector<vector<string>>);
        vector<string> vec_Str;

        vec->clear();
        vec_Str.clear();
        vec->push_back(vec_Str);
        return vec;
    }
    else if (size == 0)
    {
        vector<vector<string>> *vec = (new vector<vector<string>>);
        vector<string> vec_Str;
        vec->clear();
        vec_Str.clear();

        vec_Str.push_back("\0");
        vec->push_back(vec_Str);
        return vec;
    }
    else
    {
        vector<vector<string>> *current_vec(new vector<vector<string>>);
        vector<vector<string>> *main_vec = (new vector<vector<string>>);
        for (int i = 0; i < size; i++)
        {
            if (is_Prefix(target, word_Bank[i]))
            {
                current_vec = allConstruct_Classic(target.substr(word_Bank[i].length()), word_Bank, size);

                if (!((current_vec->size() == 1) && (current_vec->at(0).size() == 1) && (current_vec->at(0)[0] == "\0")))
                {
                    vector<string>::iterator iter;
                    for (int j = 0; j < current_vec->size(); j++)
                    {
                        iter = current_vec->at(j).begin();
                        current_vec->at(j).insert(iter, word_Bank[i]);
                        main_vec->push_back(current_vec->at(j));
                    }
                }
            }
        }
        return main_vec;
    }
}

//* Dynamic Recursive allConstruct Implementation.
/*
    m = TargetSum, n = Numbers.length
    Time  Complexity: O(n^m)
    Space Complexity: O(m)
*/
vector<vector<string>> *allConstruct_Dynamic(string target, const string word_Bank[], int size, bool is_First_Call = true)
{
    static map<string, vector<vector<string>>> memo = {};
    if (is_First_Call)
    {
        memo.clear();
    }

    auto result = memo.find(target);
    if (result != memo.end())
    {
        return &(result->second);
    }
    if (target == "")
    {
        vector<vector<string>> *vec = (new vector<vector<string>>);
        vector<string> vec_Str;

        vec->clear();
        vec_Str.clear();
        vec->push_back(vec_Str);
        return vec;
    }
    else if (size == 0)
    {
        vector<vector<string>> *vec = (new vector<vector<string>>);
        vector<string> vec_Str;
        vec->clear();
        vec_Str.clear();

        vec_Str.push_back("\0");
        vec->push_back(vec_Str);
        return vec;
    }
    else
    {
        vector<vector<string>> *current_vec(new vector<vector<string>>);
        vector<vector<string>> *main_vec = (new vector<vector<string>>);
        for (int i = 0; i < size; i++)
        {
            if (is_Prefix(target, word_Bank[i]))
            {
                current_vec = allConstruct_Dynamic(target.substr(word_Bank[i].length()), word_Bank, size, false);

                if (!((current_vec->size() == 1) && (current_vec->at(0).size() == 1) && (current_vec->at(0)[0] == "\0")))
                {
                    vector<string>::iterator iter;
                    for (int j = 0; j < current_vec->size(); j++)
                    {
                        iter = current_vec->at(j).begin();
                        current_vec->at(j).insert(iter, word_Bank[i]);
                        main_vec->push_back(current_vec->at(j));
                    }
                }
            }
        }
        memo[target] = *(main_vec);
        return main_vec;
    }
}

int main()
{
    string arr1[] = {"purp", "p", "ur", "le", "purpl"};
    string arr2[] = {"ab", "abc", "cd", "def", "abcd", "ef", "c"};
    string arr3[] = {"bo", "rd", "ate", "t", "ska", "sk", "boar"};
    string arr4[] = {"a", "aa", "aaa", "aaaa", "aaaaa"};

    vector<vector<string>> *vec;

    vec = allConstruct_Dynamic("purple", arr1, 5);
    print(vec);
    vec = allConstruct_Dynamic("abcdef", arr2, 7);
    print(vec);
    vec = allConstruct_Dynamic("skateboard", arr3, 7);
    print(vec);
    vec = allConstruct_Dynamic("aaaaaaaaaaaaaaaaaaaaaaaaaaz", arr4, 5);
    print(vec);

    return 0;
}