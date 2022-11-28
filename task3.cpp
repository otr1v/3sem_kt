#include <iostream>
#include <vector>

using namespace std;

vector<int> func(vector<int>& v)
{
    int size = v.size();
    for (int i = 0; i < size; i++)
    {
        for(int j = 0; j < size - i - 1; j++)
        {
            if (v[j] < v[j + 1])
            {
                int tmp = v[j + 1];
                v[j + 1] = v[j];
                v[j] = tmp;
            }
        }
    }
    return v;
}

int main()
{
    vector<int> v = {1, 8, 5};
    vector<int> res = func(v);
    for (int k = 0; k < res.size(); k++)
    {
        cout << res[k] << endl;
    }
    return 0;
}