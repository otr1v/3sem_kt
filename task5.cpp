#include <iostream>
#include <vector>
#include <string>

using namespace std;
vector<string> func(vector<string>& v)
{
    int k = 0;
    for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3 - i - 1; j++)
            {
                if (v[j] > v[j + 1])
                {
                    string tmp = v[j];
                    v[j] = v[j + 1];
                    v[j + 1] = tmp;
                    
                }
                else
                {

                } 
            }
        }
    return v;
}
int main()
{
    vector<string> v(3);
    for (int i = 0; i < 3; i++)
    {
        cin >> v[i];
    }
    vector<string> res = func(v);
    for (int i = 0; i < 3; i++)
    {
        cout << v[i] << endl;
    }
    return 0;
}