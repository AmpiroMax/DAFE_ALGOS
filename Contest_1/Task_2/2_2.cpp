#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int px, py;
    int fx, fy;
    int x = 0, y = 0;

    double S = 0;

    cin >> px >> py;
    fx = px;
    fy = py;
    for (int i = 1; i < n; i++)
    {
        cin >> x >> y;
        double dS = 0.5 * (x - px) * (y + py);
        // cout << dS << endl;
        S += dS;
        px = x;
        py = y;
    }
    double dS = 0.5 * (fx - x) * (fy + y);
    // cout << dS << endl;
    S += dS;
    cout << S;
    return 0;
}
