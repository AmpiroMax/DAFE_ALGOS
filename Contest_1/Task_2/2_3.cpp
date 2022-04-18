#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;

    cin >> n;
    vector<int> a;
    a.resize(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    cin >> m;
    vector<int> b;
    b.resize(m);
    for (int i = 0; i < m; ++i)
    {
        cin >> b[i];
    }

    int k;
    cin >> k;

    int counter = 0;
    int i = 0, j = m - 1;

    while (i < n && j >= 0)
    {
        if (a[i] + b[j] < k)
        {
            i++;
        }
        else if (a[i] + b[j] > k)
        {
            j--;
        }
        else if (a[i] + b[j] == k)
        {
            counter++;
            i++;
        }
    }
    cout << counter;
}
