#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;

    int cn = n;
    int i = 2;
    while (n % i != 0)
    {
        i++;
    }
    int max_a = n / i;
    int max_b = n - max_a;

    cout << max_a << " " << max_b << endl;
    return 0;
}
