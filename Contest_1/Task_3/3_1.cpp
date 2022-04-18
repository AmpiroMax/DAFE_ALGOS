#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;

    vector<int> a;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> b;
    b.resize(m);
    for (int i = 0; i < m; i++)
        cin >> b[i];

    for (int i = 0; i < m; i++)
    {
        int beg = 0;
        int end = n - 1;
        int mid = beg + (end - beg) / 2;
        int prev_mid = mid;
        while (beg <= end)
        {
            mid = beg + (end - beg) / 2;
            if (a[mid] >= b[i])
            {
                prev_mid = mid;
                end = mid - 1;
            }
            else if (a[mid] < b[i])
            {
                beg = mid + 1;
            }
        }
        if (a[prev_mid] < b[i])
        {
            cout << n << " ";
        }
        if (a[prev_mid] >= b[i])
        {
            cout << prev_mid << " ";
        }
    }
}
