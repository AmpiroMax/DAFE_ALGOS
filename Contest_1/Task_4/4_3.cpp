#include <iostream>
#include <stack>

using namespace std;

class mqueue
{
  private:
    stack<int> left;
    stack<int> right;

  public:
    void left_to_right()
    {
        while (left.size() != 0)
        {
            int btw;
            btw = left.top();
            left.pop();
            right.push(btw);
        }
    }

    void right_to_left()
    {
        while (right.size() != 0)
        {
            int btw;
            btw = right.top();
            right.pop();
            left.push(btw);
        }
    }
    void push_back(int val) { left.push(val); }

    int pop_front()
    {
        if (left.size() == 0 && right.size() == 0)
        {
            return -1;
        }

        if (right.size() == 0)
            left_to_right();
        int val = right.top();
        right.pop();
        return val;
    }
};

int main()
{
    mqueue que;
    int n;
    cin >> n;

    bool is_ok = true;
    for (int i = 0; i < n; ++i)
    {
        int com, val;
        cin >> com >> val;
        switch (com)
        {
            case 2:
            {
                int qval = que.pop_front();
                if (qval != val)
                    is_ok = false;
                break;
            }
            case 3:
            {
                que.push_back(val);
                break;
            }
        }
    }
    if (is_ok)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
