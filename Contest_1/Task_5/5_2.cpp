#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    stack<char> anogram;
    string str_in, str_out;
    cin >> str_in >> str_out;

    int i = 0, j = 0;
    for (int i = 0; i < str_in.size(); ++i)
    {
        if (str_in[i] != str_out[j])
        {
            if (anogram.empty())
                anogram.push(str_in[i]);
            else
            {
                char c = anogram.top();
                anogram.pop();
                if (str_out[j] == c)
                {
                    ++j;
                    --i;
                }
                else
                {
                    anogram.push(c);
                    anogram.push(str_in[i]);
                }
            }
        }
        else
        {
            ++j;
        }
    }
    while (!anogram.empty())
    {
        if (str_out[j] != anogram.top())
        {
            cout << "NO";
            return 0;
        }
        else
        {
            anogram.pop();
            ++j;
        }
    }
    cout << "YES";

    return 0;
}
