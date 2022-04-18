#include <iostream>
#include <vector>

std::vector<std::string> str_sort(std::vector<std::string> &vec)
{
    for (int i = 0; i < vec.size() - 1; ++i)
    {
        for (int j = i + 1; j < vec.size(); ++j)
        {
            int k{0}, mn;
            mn = std::min(vec[i].size(), vec[j].size());
            while (vec[i][k] == vec[j][k] && k < mn)
                ++k;
            if (k == mn)
            {
                if (mn == vec[j].size())
                {
                    if (mn != vec[i].size())
                    {
                        std::swap(vec[i], vec[j]);
                    }
                }
            }
            else
            {
                if (vec[i][k] > vec[j][k])
                {
                    std::swap(vec[i], vec[j]);
                }
            }
        }
    }
    return vec;
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<std::string> array(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> array[i];
    }
    str_sort(array);
    for (int i = 0; i < n; ++i)
    {
        std::cout << array[i] << std::endl;
    }
}
