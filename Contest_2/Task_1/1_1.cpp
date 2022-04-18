#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct point
{
    int x;
    int y;
    int z;
    int index;
};
std::ostream &operator<<(std::ostream &out, const point &p)
{
    out << p.index << " "; //<< " " << p.x << " " << p.y << " " << p.z << endl;
    return out;
}

std::istream &operator>>(std::istream &in, point &p)
{
    in >> p.x >> p.y >> p.z;
    vector<int> coord = {p.x, p.y, p.z};
    sort(coord.begin(), coord.end());

    p.x = coord[0];
    p.y = coord[1];
    p.z = coord[2];

    return in;
}

int main()
{
    vector<point> box;
    int n;

    cin >> n;
    box.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> box[i];
        box[i].index = i;
    }

    sort(box.begin(), box.end(), [](point a, point b) {
        if (a.x <= b.x)
            return true;
        else
            return false;
    });
    //    sort(box.begin(), box.end(), [](point a, point b) {
    //        if (a.y >= b.y)
    //            return false;
    //        return true;
    //    });
    //    sort(box.begin(), box.end(), [](point a, point b) {
    //        if (a.x >= b.x)
    //            return false;
    //        return true;
    //    });

    for (auto x : box)
    {
        cout << x;
    }

    return 0;
}
