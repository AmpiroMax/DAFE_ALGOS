#include <iostream>
#include <vector>
using namespace std;

class stack
{
  private:
    int _sz;
    int _space;
    int begin, end;
    int *arr;

  public:
    stack(int capacity) : _sz{0}, _space{capacity}, begin{0}, end{0}
    {
        arr = new int[_space];
        for (int i = 0; i < _space; i++)
        {
            arr[i] = -1;
        }
    }
    void resize(int size)
    {
        if (size < _space)
            return;
        int *new_arr = new int[size];

        for (int i = 0; i < _sz; ++i)
        {
            new_arr[i] = arr[(begin + i) % _space];
        }

        for (int i = _sz; i < size; ++i)
        {
            new_arr[i] = -1;
        }
        delete arr;
        arr = new_arr;
        _space = size;
        begin = 0;
        end = _sz;
    }
    void push_back(int val)
    {
        if (begin == end && arr[begin] != -1)
        {
            resize(_sz * 2);
        }

        arr[end] = val;
        _sz++;
        end++;
        end %= _space;
    }
    int pop_front()
    {
        if (_sz != 0)
        {
            int val;
            val = arr[begin];
            --_sz;
            arr[begin] = -1;
            begin++;
            return val;
        }
        begin = 0;
        end = 0;
        return -1;
    }
    void print_info()
    {
        cout << "------------------------" << endl;
        cout << "Size: " << _sz << endl;
        cout << begin << " " << end << endl;
        for (int i = 0; i < _space; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < _sz; i++)
        {
            int k = (begin + i) % _space;
            cout << arr[k] << " ";
        }
        cout << endl;
        cout << "------------------------" << endl;
    }
};

int main()
{
    int n;
    cin >> n;
    stack stc(n);

    int func;
    int value;
    int flag = 1;

    for (int i = 0; i < n; i++)
    {
        cin >> func >> value;
        if (flag)
            switch (func)
            {
                case 2:
                {
                    int val = stc.pop_front();
                    if (val != value)
                    {
                        flag = 0;
                    }
                    break;
                }
                case 3:
                {
                    stc.push_back(value);
                }
            }
        // cout << endl;
        // stc.print_info();
    }
    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
