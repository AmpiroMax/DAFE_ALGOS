#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct line
{
    int cord;
    int type;
};

int main()
{
    vector<line> lines;
    int n;
    cin >> n;
    lines.resize(2 * n);

    for (int i = 0; i < 2 * n; i += 2)
    {
        int x, y;
        cin >> x >> y;
        lines[i].cord = x;
        lines[i].type = 1;
        lines[i + 1].cord = y;
        lines[i + 1].type = -1;
    }

    sort(lines.begin(), lines.end(), [](line a, line b) {
        if (a.cord < b.cord)
            return true;
        return false;
    });

    int depth = 0;
    int length = 0;
    for (int i = 0; i < lines.size() - 1; ++i)
    {
        auto str = lines[i];
        depth += str.type;
        if (depth == 1)
            length += lines[i + 1].cord - str.cord;
        // cout << showpos << str.cord << " " << str.type << endl;
    }
    cout << length << endl;
    return 0;
}
