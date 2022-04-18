// 3
// 1 1 2000 1 1 2100
// 1 1 2000 1 1 2100
// 1 1 2000 1 1 2100
// ans: 3

// 3
// 1 1 2000 1 1 2100
// 1 1 2080 1 1 2100
// 2 3 2080 1 1 2110
// ans: 2

// 3
// 1 1 2000 1 1 2100
// 1 1 2080 1 1 2100
// 2 3 2080 1 1 2098
// ans: 1

// 5
// 2 1 1930 1 1 1948
// 1 2 1945 1 1 1963
// 2 2 1960 2 3 2040
// 1 1 2000 1 1 2017
// 1 1 2000 1 1 2020
// ans: 2

// */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Date
{

    int d;
    int m;
    int y;
    bool is_birth;

    Date() : d{0}, m{0}, y{0} {}
    Date(int day, int month, int year) : d{day}, m{month}, y{year} {}

    bool operator==(const Date &a) const { return d == a.d && m == a.m && y == a.y; }

    bool operator<(const Date &a) const
    {

        if (y == a.y)
        {
            if (m == a.m)
                return d < a.d;
            return m < a.m;
        }
        return y < a.y;
    }

    bool operator<=(const Date &a) const
    {

        if (y == a.y)
        {
            if (m == a.m)
                return d <= a.d;
            return m <= a.m;
        }
        return y <= a.y;
    }

    Date operator-(const Date &a)
    {

        Date tmp(d - a.d, m - a.m, y - a.y);
        return tmp;
    }
};

std::istream &operator>>(std::istream &is, Date &a)
{

    is >> a.d >> a.m >> a.y;
    return is;
}

int contemporaries(const std::vector<Date> &v)
{

    int sum = 0;
    int max = 0;
    for (auto &x : v)
    {

        if (x.is_birth)
            ++sum;
        else
            --sum;

        if (sum > max)
            max = sum;
    }

    return max == 0 ? 1 : max;
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<Date> dates;

    for (int i = 0; i < n; ++i)
    {

        Date birth, death;
        birth.is_birth = 1;
        death.is_birth = 0;

        std::cin >> birth >> death;

        if (death.y - birth.y < 18 || (death.y - birth.y == 18 && birth.m == death.m && birth.d == death.d))
            continue;

        if (death.y - birth.y > 80)
        {

            death.y = birth.y + 80;
            death.m = birth.m;
            death.d = birth.d;
        }
        else if (death.y - birth.y == 80)
        {

            if (death.m > birth.m)
            {

                death.m = birth.m;
                death.d = birth.d;
            }
            else if (death.m == birth.m && death.d > birth.d)
                death.d = birth.d;
        }

        birth.y += 18;
        dates.push_back(birth);
        dates.push_back(death);
    }

    std::sort(dates.begin(), dates.end(), [](Date a, Date b) { return a < b; });

    std::cout << contemporaries(dates);
}
