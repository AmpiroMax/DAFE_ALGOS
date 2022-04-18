#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Times
{
    int in;
    int out;
};

int count(vector<Times> &time_line)
{
    int conter = 0;
    int left = -1;
    int right = -1;

    for (int i = 0; i < time_line.size(); ++i)
    {
        if (time_line[i].in > right)
        {
            conter += 2;
            left = time_line[i].out - 1;
            right = time_line[i].out;
        }
        else if (time_line[i].in == right)
        {
            conter++;
            left = right;
            right = time_line[i].out;
        }
        else if (time_line[i].in > left && time_line[i].out > right)
        {
            conter++;
            left = right;
            right = time_line[i].out;
        }
        else if (time_line[i].in > left && time_line[i].in < right)
        {
            conter++;
            left = time_line[i].out;
        }
    }

    return conter;
}

int main()
{
    vector<Times> table;
    int n;
    cin >> n;
    table.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> table[i].in >> table[i].out;
    }
    sort(table.begin(), table.end(), [](Times a, Times b) {
        if (a.in < b.in)
            return true;
        else if (a.in == b.in)
            if (a.out < b.out)
                return true;

        return false;
    });

    int rez = count(table);
    cout << rez << endl;
    return 0;
}
