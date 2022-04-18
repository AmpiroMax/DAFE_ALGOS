#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    vector<int> mass;
    cin >> n;
    int k = n;
    if (k == 1)
    {
        cout << 1;
        return 0;
    }
    for (int i = 2; i <= k; i++)
    {
        while (n % i == 0)
        {
            // cout << "tyt" << endl;
            mass.push_back(i);
            n /= i;
        }
    }
    for (int i = 0; i < mass.size(); i++)
    {
        cout << mass[i] << " ";
    }
    return 0;
}
