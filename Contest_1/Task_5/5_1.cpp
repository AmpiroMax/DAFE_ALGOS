#include <deque>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<char> str;
    vector<char> deq;
    deque<char> ans;

    string in_str;

    cin >> in_str;
    for (auto x : in_str)
    {
        str.push_back(x);
        ans.push_back(x);
    }

    for (auto x : str)
    {
        if (x == '{' || x == '(' || x == '[')
        {
            deq.push_back(x);
        }

        if (x == '}' || x == ')' || x == ']')
        {
            if (deq.size() == 0)
            {
                switch (x)
                {
                    case '}':
                    {
                        ans.push_front('{');
                        break;
                    }
                    case ')':
                    {
                        ans.push_front('(');
                        break;
                    }
                    case ']':
                    {
                        ans.push_front('[');
                        break;
                    }
                }
            }
            else
            {
                auto sim = deq.back();
                deq.pop_back();
                switch (x)
                {
                    case '}':
                    {
                        if (sim != '{')
                        {
                            cout << "IMPOSSIBLE" << endl;
                            return 0;
                        }
                        break;
                    }
                    case ')':
                    {
                        if (sim != '(')
                        {
                            cout << "IMPOSSIBLE" << endl;
                            return 0;
                        }
                        break;
                    }
                    case ']':
                    {
                        if (sim != '[')
                        {
                            cout << "IMPOSSIBLE" << endl;
                            return 0;
                        }
                        break;
                    }
                }
            }
        }
    }

    while (deq.size() != 0)
    {
        auto x = deq.back();
        deq.pop_back();
        switch (x)
        {
            case '{':
            {
                ans.push_back('}');
                break;
            }
            case '(':
            {
                ans.push_back(')');
                break;
            }
            case '[':
            {
                ans.push_back(']');
                break;
            }
        }
    }

    for (auto x : ans)
    {
        cout << x;
    }
    return 0;
}
