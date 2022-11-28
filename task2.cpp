#include <iostream>
#include <vector>

using namespace std;

vector<int> func(vector<int>& v)
{
    vector<int> k(v.size());
    int size = v.size();
    for (int i = 0; i < size; i++)
    {
        k[i] = v[size - i - 1];
    }
    return k;
}
int main()
{
    vector<int> v = {1, 2, 3};
    vector<int> res = func(v);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << endl;
    }
    return 0;
}