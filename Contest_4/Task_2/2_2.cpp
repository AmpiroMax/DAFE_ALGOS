#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<pair<int, int>> array;
    int max_am = 0, curr_end;

    while (true)
    {
        int begin, end;
        cin >> begin >> end;

        if (cin.eof())
            break;

        array.push_back({begin, end});
    }

    sort(array.begin(), array.end(), [](pair<int, int> a, pair<int, int> b) {
        if (a.second != b.second)
            return a.second < b.second;
        else
            return a.first < b.first;
    });

    curr_end = array[0].second;
    ++max_am;

    for (int i = 1; i < array.size(); ++i)
    {

        if (array[i].first >= curr_end)
        {

            curr_end = array[i].second;
            ++max_am;
        }
    }

    cout << max_am;
}
