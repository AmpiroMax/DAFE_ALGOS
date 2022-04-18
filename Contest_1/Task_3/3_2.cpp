#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int beg = 0;
    int end = n - 1;
    int mid = beg + (end - beg) / 2;

    int priority = 1;
    while (priority)
    {
        int e1;
        if (mid - 1 >= 0)
            e1 = a[mid - 1];
        else
            e1 = -1;
        int e2 = a[mid];
        int e3;
        if (mid + 1 < n)
            e3 = a[mid + 1];
        else
            e3 = -1;
        // cout << e1 << " " << e2 << " " << e3 << endl;
        if (e2 > e1 && e2 > e3)
        {
            cout << mid << endl;
            priority = 0;
        }
        else if (e2 > e1 && e2 < e3)
        {
            beg = mid + 1;
        }
        else if (e2 < e1 && e2 > e3)
        {
            end = mid - 1;
        }
        mid = beg + (end - beg) / 2;
    }
}
