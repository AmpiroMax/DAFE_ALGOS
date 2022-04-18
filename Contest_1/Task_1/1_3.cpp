#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int cs = a * d + b * c;
    int zn = b * d;

    int cs_o = cs;
    int zn_o = zn;

    while (cs != zn)
    {
        if (cs > zn)
            cs = cs - zn;
        else
            zn = zn - cs;
    }
    cout << cs_o / cs << " " << zn_o / cs << endl;
    return 0;
}
