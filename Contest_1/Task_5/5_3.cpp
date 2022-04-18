#include <iostream>
#include <vector>

using namespace std;
struct cube
{
    int w;
    int h;
};

void print_mass(const vector<cube> &vec)
{
    for (auto x : vec)
    {
        cout << x.w << " " << x.h << endl;
    }
}
int max_s(vector<cube> &sqrs, int next_h)
{

    vector<cube> temp;
    int curr_sq = 0;
    int curr_w = 0;
    int max_sq = 0;

    // cout << "Before: " << endl;
    // print_mass(sqrs);

    for (; !sqrs.empty();)
    {
        curr_w += sqrs.back().w;
        curr_sq = sqrs.back().h * curr_w;
        if (curr_sq > max_sq)
        {
            max_sq = curr_sq;
        }
        temp.push_back(sqrs.back());
        sqrs.pop_back();
    }

    bool fst_grt_next = true;
    for (; !temp.empty();)
    {
        if (temp.back().h < next_h)
            sqrs.push_back(temp.back());
        else
        {
            if (fst_grt_next)
            {
                sqrs.push_back(temp.back());
                sqrs.back().h = next_h;
                fst_grt_next = !fst_grt_next;
            }
            else if (!sqrs.empty())
                sqrs.back().w += temp.back().w;
        }
        temp.pop_back();
    }

    // cout << "After: " << endl;
    // print_mass(sqrs);

    return max_sq;
}

int main()
{
    vector<cube> stack;
    int n;
    cin >> n;

    int prev_h = 0;
    int max_square = 0;
    int curr_square = 0;

    for (int i = 0; i < n; i++)
    {
        int w, h;
        // cout << "Input: ";
        cin >> w >> h;
        if (h < prev_h)
        {
            curr_square = max_s(stack, h);
            if (curr_square > max_square)
                max_square = curr_square;
        }
        stack.push_back({w, h});

        prev_h = h;
    }

    curr_square = max_s(stack, 0);
    if (curr_square > max_square)
        max_square = curr_square;

    // cout << endl;
    cout << max_square;
    return 0;
}
/*
5
1 1
2 5
4 0
2 1
2 4

4
1 3
3 2
1 6
10 1


*/
