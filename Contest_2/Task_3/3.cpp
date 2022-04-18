#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

vector<int>::iterator partition(vector<int>::iterator begin, vector<int>::iterator end)
{
    int pivot = *(begin + (end - begin) / 2);
    // cout << pivot << endl;

    int temp = *(end - 1);
    *(end - 1) = pivot;
    *(begin + (end - begin) / 2) = temp;

    int i = 0;
    int j = 0;

    while (begin + j + i < end)
    {
        int curr_el = *(begin + i + j);
        // cout << i << " " << j << " " << curr_el << endl;
        if (curr_el >= pivot)
            j++;
        else
        {
            int tmp = curr_el;
            *(begin + i + j) = *(begin + i);
            *(begin + i) = curr_el;
            ++i;
        }
    }
    int curr_el = *(begin + i + j - 1);
    int tmp = curr_el;
    *(begin + i + j - 1) = *(begin + i);
    *(begin + i) = curr_el;

    return begin + i;
}

void QS(vector<int>::iterator begin, vector<int>::iterator end)
{
    vector<int>::iterator mid;
    mid = partition(begin, end);
    if (begin != mid)
        QS(begin, mid);
    if ((mid + 1) != end)
        QS(mid + 1, end);
}

int main()
{
    vector<int> array;
    int k, n;
    cin >> n >> k;
    array.resize(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> array[i];
    }

    //    for (auto el : array)
    //        cout << el << " ";
    //    cout << endl;

    QS(array.begin(), array.end());
    //    for (auto el : array)
    //        cout << el << " ";
    //    cout << endl;

    cout << array[k] << endl;
    return 0;
}
