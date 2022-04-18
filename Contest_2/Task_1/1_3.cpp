#include <iostream>
#include <vector>
using namespace std;

void print(const vector<pair<pair<int, int>, double>> &array)
{
    for (auto el : array)
    {
        cout << el.first.first << " " << el.first.second << " " << el.second << endl;
    }
}

auto &isert_sort(vector<pair<pair<int, int>, double>> &array)
{

    for (int i = 1; i < array.size(); ++i)
    {
        pair<pair<int, int>, double> tmp = array[i];
        int j = i - 1;
        for (; j >= 0 && tmp.first.second < array[j].first.second; --j)
            array[j + 1] = array[j];

        array[j + 1] = tmp;
    }

    for (int i = 1; i < array.size(); ++i)
    {
        pair<pair<int, int>, double> tmp = array[i];
        int j = i - 1;
        for (; j >= 0 && tmp.first.first < array[j].first.first; --j)
            array[j + 1] = array[j];

        array[j + 1] = tmp;
    }

    array[0].second = 100002;
    for (int i = 1; i < array.size(); ++i)
    {
        int x1 = array[0].first.first, y1 = array[0].first.second;
        int x2 = array[i].first.first, y2 = array[i].first.second;
        double tan_alpha;
        if (x2 == x1)
            tan_alpha = 100001;
        else
            tan_alpha = 1.0 * (y2 - y1) / (x2 - x1);

        array[i].second = tan_alpha;
    }

    for (int i = 1; i < array.size(); ++i)
    {
        pair<pair<int, int>, double> tmp = array[i];
        int j = i - 1;
        for (; j >= 0 && tmp.second > array[j].second; --j)
            array[j + 1] = array[j];

        array[j + 1] = tmp;
    }

    return array;
}

int main()
{
    vector<pair<pair<int, int>, double>> line;
    int n;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        line.push_back({{x, y}, 0});
    }

    line = isert_sort(line);

    print(line);
    return 0;
}

//-------------------
/*pair<pair<int, int>, double>
 *
 5
 2 1
 3 0
 2 5
 1 1
 1 2

 6
 3 5
 5 4
 8 3
 6 2
 9 1
 1 3

  */
