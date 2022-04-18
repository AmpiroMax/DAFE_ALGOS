#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

void LSD_sort(vector<long long> &vec, long long byte, long long mx_byte)
{
    if (byte > mx_byte)
        return;
    vector<vector<long long>> vector(10);
    int pos = 0;
    for (int i = 0; i < vec.size(); ++i)
    {
        long long del = pow(10, byte - 1);
        if (vec[i] < del)
        {
            vec[pos++] = vec[i];
        }
        else
        {
            long long copy = vec[i];
            copy = (copy / del) % 10;
            vector[copy].push_back(vec[i]);
        }
    }
    for (int i = 0; i < vector.size(); ++i)
    {
        for (int j = 0; j < vector[i].size(); ++j)
        {
            vec[pos++] = vector[i][j];
        }
    }
    vector.clear();
    LSD_sort(vec, byte + 1, mx_byte);
}

int main()
{
    long long n, mx{0}, mx_byte{0};
    cin >> n;
    vector<long long> vec(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> vec[i];
        if (vec[i] > mx)
            mx = vec[i];
    }
    while (mx >= 1)
    {
        ++mx_byte;
        mx /= 10;
    }
    LSD_sort(vec, 1, mx_byte);
    for (int i = 0; i < n; ++i)
    {
        cout << vec[i] << " ";
    }
}
