#include <iostream>
#include <vector>
using namespace std;

template <typename T, typename Iter>
void merge(const vector<T> &lft, const vector<T> &rht, Iter begin)
{
    size_t i = 0;
    size_t j = 0;

    for (; i < lft.size() && j < rht.size();)
        *(begin++) = lft[i] > rht[j] ? rht.at(j++) : lft.at(i++);

    for (; i < lft.size(); ++i)
        *(begin++) = lft[i];

    for (; j < rht.size(); ++j)
        *(begin++) = rht[j];
}
template <typename T, typename Iter>
void merge_sort(Iter begin, Iter end)
{
    if (end - begin == 1)
        return;

    auto mid = begin + (end - begin) / 2;
    merge_sort<T>(begin, mid);
    merge_sort<T>(mid, end);

    vector<T> left(begin, mid);
    vector<T> right(mid, end);

    merge<T>(left, right, begin);
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

    merge_sort<int>(array.begin(), array.end());

    for (auto el : array)
        cout << el << " ";
    cout << endl;

    // cout << array[k] << endl;
    return 0;
}
