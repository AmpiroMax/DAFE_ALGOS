#include <iostream>
#include <string>
#include <vector>

using namespace std;

void counting_sort(vector<string> &mass, vector<int> &sizes, int num_of_colomn)
{
    vector<vector<string>> temp(256 + 1);

    for (int i = 0; i < mass.size(); i++)
    {
        if (mass[i].size() > num_of_colomn)
        {
            temp[mass[i][num_of_colomn] + 1].push_back(mass[i]);
            sizes[mass[i][num_of_colomn] + 1]++;
        }
        else
        {
            temp[0].push_back(mass[i]);
            sizes[0]++;
        }
    }
    //    for (auto x : sizes)
    //        if (x != 0)
    //            cout << x << endl;

    int k = 0;
    int sum = 0;
    for (int i = 0; i < 257; i++)
    {
        sum += sizes[i];
        sizes[i] = sum;
        for (int j = 0; j < temp[i].size(); j++, k++)
        {
            mass[k] = temp[i][j];
        }
    }
}

void MSD(vector<string> &mass, int num_of_colomn, int max_colomn)
{
    if (mass.size() <= 1)
        return;
    vector<int> sizes(257);
    counting_sort(mass, sizes, num_of_colomn);

    if (num_of_colomn < max_colomn)
    {
        for (int i = 0; i < 256; i++)
        {
            vector<string> next_mass;
            int start = sizes[i];
            int leng = sizes[i + 1];

            for (int j = start; j < leng; ++j)
                next_mass.push_back(mass[j]);
            MSD(next_mass, num_of_colomn + 1, max_colomn);
            for (int j = start; j < leng; ++j)
                mass[j] = next_mass[j - start];
        }
    }
}

int main()
{
    vector<string> lines;
    string str;
    int max_colomn{0};
    while (cin >> str)
    {
        lines.push_back(str);
        if (str.size() > max_colomn)
            max_colomn = str.size();
    }
    // cout << lines.size() << endl;
    //    for (auto x : lines)
    //        cout << x << endl;
    MSD(lines, 0, max_colomn);
    for (auto x : lines)
        cout << x << endl;
    return 0;
}
