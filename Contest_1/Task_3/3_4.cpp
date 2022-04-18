#include <iostream>
#include <vector>
using namespace std;

/*

5
3 5 8 10 13
4
4 9 11 13


*/

int main()
{
    int n;
    cin >> n;

    vector<int> a;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int m;
    cin >> m;

    vector<int> b;
    b.resize(m);
    for (int i = 0; i < m; i++)
        cin >> b[i];

    int beg = 0;
    int end = n - 1;
    int mid = beg + (end - beg) / 2;
    int dif, min_dif;

    for (int i = 0; i < m; i++)
    {
        while (beg <= end)
        {
            mid = beg + (end - beg) / 2;

            // cout << beg << " " << mid << " " << end << endl;
            // cout << a[mid] << " " << b[i] << endl;

            if (beg == end - 1)
            {
                int dif_beg = abs(a[beg] - b[i]);
                int dif_end = abs(a[end] - b[i]);

                if (dif_beg <= dif_end)
                {
                    cout << beg << endl;
                    beg = end + 1;
                }
                else
                {
                    cout << end << endl;
                    beg = end + 1;
                }
            }
            else
            {

                if (a[mid] > b[i])
                {
                    end = mid;
                }

                if (a[mid] < b[i])
                {
                    beg = mid;
                }

                if (a[mid] == b[i])
                {
                    cout << mid << endl;
                    beg = end + 1;
                }
            }
        }

        beg = 0;
        end = n - 1;
        mid = beg + (end - beg) / 2;
    }
}
