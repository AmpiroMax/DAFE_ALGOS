#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int count = 0;
    size_t sq = 0;
    int j = 1;
    for (int i = 1; i <= n; i += 1)
    {

        sq += j;
        j += 2;
        cout << sq << " ";
    }
    return 0;
}
