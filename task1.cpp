#include <iostream>
#include <vector>
#include <unistd.h>
using namespace std;

int main()
{

    int N;
    cin >> N;
    double sum = 0;
    vector<double> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
        sum += v[i];
    }
    double medium = sum / N;
    for (int i = 0; i < N; i++)
    {
        if (v[i] > medium)
        {
            cout << i << endl;
        }
    }
    
    return 0;
}