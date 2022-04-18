#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef pair<string, vector<int>> Type;

void sort_by_n_colomn(vector<Type> &lists, int n)
{
    //    sort(lists.begin(), lists.end(), [n](Type a, Type b) {
    //        //        cout << n + 1 << " "
    //        //             << " " << a.first << " " << a.second[n] << " "
    //        //             << " " << b.first << " " << b.second[n] << endl;

    //        if (a.second[n] > b.second[n])
    //            return true;
    //        return false;
    //    });

    for (int i = 1; i < lists.size(); ++i)
    {
        Type tmp = lists[i];
        int j = i - 1;
        for (; j >= 0 && tmp.second[n] > lists[j].second[n]; --j)
            lists[j + 1] = lists[j];

        lists[j + 1] = tmp;
    }
}

int main()
{
    vector<int> pri;
    vector<Type> lists;
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < k; ++i)
    {
        int tmp;
        cin >> tmp;
        pri.push_back(tmp);
    }

    for (int i = 0; i < n; ++i)
    {
        string str;
        cin >> str;
        Type tmp;
        for (int j = 0; j < k; ++j)
        {
            int el;
            cin >> el;
            tmp.second.push_back(el);
        }
        tmp.first = str;
        lists.push_back(tmp);
    }

    for (int i = k - 1; i >= 0; --i)
    {
        sort_by_n_colomn(lists, pri[i] - 1);
        //        cout << endl;
        //        for (auto x : lists)
        //        {
        //            cout << x.first << " ";
        //            for (auto y : x.second)
        //                cout << y << " ";
        //            cout << endl;
        //        }
    }

    for (auto x : lists)
    {
        cout << x.first << " ";
        cout << endl;
    }
    return 0;
}
/*

 4
 3
 3 2 1
 A 1 0 2
 B 8 2 3
 C 9 9 9
 D 5 4 7

 4
 4
 4 1 2 3
 A 0 5 9 101
 B 99 7 11 10
 C 2 100 10 11
 D 98 99 100 100

 4
 4
 4 3 2 1
 A 4 5 3 2
 B 7 5 3 2
 C 0 2 8 2
 D 3 0 7 2

 4
 1
 1
 A 9
 B 100
 str 13
 asdasd 4

 1
 4
 3 2 4 1
 only_one 4 5 2 3

  */
