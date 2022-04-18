#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> mass1;
    vector<int> mass2;
    mass1.resize(n);
    mass2.resize(n);
    //---------------------------
    for (int i = 0; i < n; ++i)
    {
        cin >> mass1[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> mass2[i];
    }
    //---------------------------
    int i0 = 0, j0 = 0, i0_max = 0;
    int sum = mass1[i0] + mass2[j0];
    for (int i = 0; i < n; i++)
    {
        if (mass1[i] > mass1[i0_max])
        {
            i0_max = i;
        }
        if (mass1[i0_max] + mass2[i] > sum)
        {
            i0 = i0_max;
            j0 = i;
            sum = mass1[i0_max] + mass2[i];
        }
    }
    cout << i0 << " " << j0 << endl;
    return 0;
}
