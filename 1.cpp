#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <exception>
#include <stdexcept>
#include <set>

using namespace std;

int func(string str1, string str2)
{
    map<char, int> first = {};
    map<char, int> second = {};

    const int size = 27; // кол-во букв.
    int number = 97; // код первой буквы.
    char letter;
 
    for (int i = 0; i < size; i++) {
        letter=(char) number;
        first[letter] = 0;
        second[letter] = 0;
        for (int j = 0; j < str1.size(); j++)
        {
            if (str1[j] == letter)
            {
                first[letter] += 1;
            }
        }
        for (int i = 0; i < str2.size(); i++)
        {
            if (str2[i] == letter)
            {
                second[letter] += 1;
            }
        }
        
        number++;
    }
    if (first == second)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    map<string, string> m = {{"str", "rst"}, {"ay", "yyy"}};
    //cout << i.first.size;
    for (auto i : m)
    {
        int res = func(i.first, i.second);
        if (res == 1)
        {
            cout <<"YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}