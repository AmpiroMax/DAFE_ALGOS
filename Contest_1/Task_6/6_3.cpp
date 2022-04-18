#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int curr_count = 0;
    int max_count = 0;
    // {time, int/out}
    vector<pair<int, int>> time_table;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int in, out;
        cin >> in >> out;
        time_table.push_back({in, 1});
        time_table.push_back({out, -1});
    }

    sort(time_table.begin(), time_table.end(), [](pair<int, int> l, pair<int, int> r) {
        if (l.first > r.first)
            return false;
        else if (l.first < r.first)
            return true;
        else
        {
            if (l.second < r.second)
                return false;
            else
                return true;
        }
    });

    //    for (auto x : time_table)
    //    {
    //        cout << x.first << " " << x.second << endl;
    //    }

    /*
    5
    10 20
    11 20
    12 20
    20 25
    20 23
    */
    int outer_count = 0;
    for (int i = 0; i < time_table.size(); ++i)
    {
        auto time = time_table[i].first;
        int del = 0;
        for (int j = i; j < time_table.size() && time == time_table[j].first; del++, j++)
        {
            // cout << ":" << time_table[j].first << " " << time_table[j].second << endl;
            if (time_table[j].second == 1)
            {
                // cout << time_table[j].first << " " << time_table[j].second << endl;
                curr_count++;
            }
            else
            {
                // cout << time_table[j].first << " " << time_table[j].second << endl;
                outer_count++;
            }
        }
        // cout << curr_count << " " << outer_count << endl;
        i += del - 1;
        if (max_count < curr_count)
            max_count = curr_count;

        curr_count -= outer_count;
        outer_count = 0;
    }

    cout << max_count << endl;

    return 0;
}
