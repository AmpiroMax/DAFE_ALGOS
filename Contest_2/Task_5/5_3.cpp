#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// template <typename T>
// void print(typename vector<T>::iterator begin, typename vector<T>::iterator end)
//{
//    for (; begin != end; ++begin)
//        cout << *begin << " ";
//    cout << endl;
//}
//    for (int i = 0; i < 10; i++)
//    {
//        int chislo;
//        cin >> chislo;
//        for (int i = 0; 1 << i <= chislo; ++i)
//            cout << get_digit(chislo, i);
//        cout << endl;
//    }
bool get_digit(long long x, int n)
{
    return (x >> n) & 1;
}

void MSD_QS_bin(vector<long long> &array, int left, int right, int bit_n)
{
    // cout << "Tut msd qs" << endl;
    if (right <= left || bit_n < 0)
        return;
    int i = left;
    int j = right;

    for (; i < j;)
    {
        for (; i != j && !get_digit(array[i], bit_n);)
            i++;
        for (; j != i && get_digit(array[j], bit_n);)
            j--;

        swap(array[i], array[j]);
    }
    if (get_digit(array[right], bit_n) == 0)
        ++j;

    MSD_QS_bin(array, left, j - 1, bit_n - 1);
    MSD_QS_bin(array, j, right, bit_n - 1);
}

void MSD(vector<vector<int>> binars, size_t curr_colomn, size_t max_colomn) {}

int main()
{
    vector<long long> numbers;
    int n;
    cin >> n;

    numbers.resize(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> numbers[i];
    }
    // cout << "Tut" << endl;
    //    for (int i = 0; i < n; i++)
    //    {
    //        size_t chislo;
    //        cin >> chislo;

    //        if (chislo != 0)
    //            for (int j = 0; 1 << j <= chislo; ++j)
    //                numbers[i].push_back((chislo >> j) % 2);
    //        else
    //            numbers[i].push_back(0);
    //        reverse(numbers[i].begin(), numbers[i].end());
    //        // print<int>(numbers[i].begin(), numbers[i].end());
    //    }
    MSD_QS_bin(numbers, 0, n - 1, 63);
    for (auto num : numbers)
        cout << num << " ";
    return 0;
}
