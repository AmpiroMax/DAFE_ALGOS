#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<pair<int, int>> array;
    int max_weight = 0, max_height = 0;

    while (true)
    {
        int weight, force;
        cin >> weight >> force;

        if (cin.eof())
            break;

        array.push_back({weight, force});
    }

    sort(array.begin(), array.end(), [](pair<int, int> a, pair<int, int> b) {
        if (a.first != b.first)
            return a.first < b.first;
        else
            return a.second < b.second;
    });

    int curr_w = array[0].first;
    ++max_height;

    for (int i = 1; i < array.size(); ++i)
    {

        if (array[i].second >= curr_w)
        {

            curr_w += array[i].first;
            ++max_height;
        }
    }

    cout << max_height;
}
