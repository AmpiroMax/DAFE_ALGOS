#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, K, M, L;
    size_t sum{0};

    cin >> N >> K >> M >> L;

    vector<long long> array;
    array.push_back(K);

    for (int i = 1; i < N; ++i)
    {

        K = ((K * M) & 0xFFFFFFFFU) % L;
        array.push_back(K);
    }

    sort(array.begin(), array.end());

    for (int i = 0; i < N; ++i)
    {

        if (i % 2 == 0)
        {

            sum += array[i];
        }
    }

    cout << sum % L;
}
