#include <iostream>

using namespace std;

int main()
{
    int n;
    int count = 0, count5 = 0;
    cin >> n;
    for (int i = 1; i < n + 1; i++)
    {
        int k = i;
        while (k % 5 == 0)
        {
            count++;
            k /= 5;
        }
    }

    count += count5;
    cout << count;
    return 0;
}
