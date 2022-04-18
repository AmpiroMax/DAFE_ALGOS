#include <iostream>
#include <vector>
using namespace std;

template <typename T, typename Iter>
void merge(const vector<T> &lft, const vector<T> &rht, Iter begin, size_t &counter)
{
    size_t i = 0;
    size_t j = 0;

    for (; i < lft.size() && j < rht.size();)
    {
        if (lft[i] > rht[j])
        {
            *(begin++) = rht.at(j++);
            counter += lft.size() - i;
        }
        else
        {
            *(begin++) = lft.at(i++);
        }
    }

    for (; i < lft.size(); ++i)
    {
        *(begin++) = lft[i];
        // counter += j;
    }

    for (; j < rht.size(); ++j)
        *(begin++) = rht[j];
}
template <typename T, typename Iter>
void merge_sort_counter(Iter begin, Iter end, size_t &counter)
{
    if (end - begin == 1)
        return;

    auto mid = begin + (end - begin) / 2;
    merge_sort_counter<T>(begin, mid, counter);
    merge_sort_counter<T>(mid, end, counter);

    vector<T> left(begin, mid);
    vector<T> right(mid, end);

    merge<T>(left, right, begin, counter);
}

int main()
{
    vector<int> array;
    int el;
    for (; cin >> el;)
    {
        array.push_back(el);
    }
    size_t count = 0;
    merge_sort_counter<int>(array.begin(), array.end(), count);
    //    for (auto el : array)
    //    {
    //        cout << el << " ";
    //    }
    cout << endl;
    cout << count << endl;
    return 0;
}
