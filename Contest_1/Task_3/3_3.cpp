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
    b.resize(n);
    for (int i = 0; i < m; i++)
        cin >> b[i];

    int beg = 0;
    int end = n - 1;
    int mid = beg + (end - beg) / 2;

    for (int i = 0; i < m; ++i, mid = beg + (end - beg) / 2)
    {
        // cout << beg << " " << mid << " " << end << endl;
        while (beg <= end)
        {
            // cout << beg << " " << mid << " " << end << endl;
            // cout << a[mid] << " " << b[i] << endl;
            if (a[mid] > b[i])
            {
                end = mid - 1;
                mid = beg + (end - beg) / 2;
            }
            else if (a[mid] < b[i])
            {
                beg = mid + 1;
                mid = beg + (end - beg) / 2;
            }
            else if (a[mid] == b[i])
            {
                cout << a[mid] << endl;
                beg = end + 1;
            }
        }
        beg = mid;
        end = n - 1;
    }
}
