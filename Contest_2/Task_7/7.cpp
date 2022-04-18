#include <iostream>
#include <iterator>
#include <time.h>
#include <vector>

using namespace std;
vector<int>::iterator rand_iter(vector<int>::iterator begin, vector<int>::iterator end)
{
    int leng = end - begin;

    return begin + rand() % leng;
}

vector<int>::iterator partition(vector<int>::iterator begin, vector<int>::iterator end)
{
    int pivot = *(begin + (end - begin) / 2);
    *rand_iter(begin, end);
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
    ios_base::sync_with_stdio(false);
    vector<int> array;
    srand(time(nullptr));
    int max = 0;
    int temp;
    for (; cin >> temp;)
    {
        //        if (temp > max)
        //            max = temp;
        //        if (i == 9)
        //        {
        //            array.push_back(max);
        //            i = 0;
        //            max = 0;
        //        }
        array.push_back(temp);
    }
    size_t size = array.size();
    //    for (size_t i = 0; i < size; i++)
    //        cout << array[i] << " ";
    //    cout << endl;
    //    cout << array.size() << endl;
    QS(array.begin(), array.end());
    //    cout << array.size() << endl;
    //    for (size_t i = 0; i < size; i++)
    //        if ((i + 1) % 10 == 0)
    //        {
    //            cout << "_" << array[i] << "_ ";
    //        }
    //        else
    //            cout << array[i] << " ";
    //    cout << endl;
    for (size_t i = 9; i < size; i += 10)
        cout << array[i] << endl;

    return 0;
}
