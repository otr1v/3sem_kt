#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cout << "number: ";
    int number;
    cin >> number;
    cout << "size = ";
    int size;
    cin >> size;
    vector<int> v(size);
    for (int i = 0; i < size; i++)
    {
        cin >> v[i];
    }
    for (int i = 0; i < size; i++)
    {
        if (v[i] > number)
        {
            cout << i;
            break;
        }
        
    }

    return 0;
}