#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> mass;
    mass.resize(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> mass[i];
    }

    for (int i = 0; i < n / 2; i++)
    {
        int swap = mass[i];
        mass[i] = mass[n - i - 1];
        mass[n - i - 1] = swap;
    }

    for (int i = 0; i < n; ++i)
    {
        cout << mass[i] << " ";
    }
    return 0;
}
