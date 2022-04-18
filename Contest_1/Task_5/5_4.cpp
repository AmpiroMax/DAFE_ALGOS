#include <iostream>
#include <stack>
#include <stdlib.h>
#include <vector>

using namespace std;

int count(vector<int> arr, int k)
{
    stack<int> stack;
    int a, b;
    for (int i = 0; i < k; ++i)
    {
        if (arr[i] >= 0)
        {
            stack.push(arr[i]);
        }
        else
        {
            switch (arr[i])
            {
                case -4:
                {
                    a = stack.top();
                    stack.pop();
                    b = stack.top();
                    stack.pop();
                    stack.push(a + b);
                    break;
                }
                case -3:
                {
                    a = stack.top();
                    stack.pop();
                    b = stack.top();
                    stack.pop();
                    stack.push(b - a);
                    break;
                }
                case -2:
                {
                    a = stack.top();
                    stack.pop();
                    b = stack.top();
                    stack.pop();
                    stack.push(a * b);
                    break;
                }
                case -1:
                {
                    a = stack.top();
                    stack.pop();
                    b = stack.top();
                    stack.pop();
                    stack.push(b / a);
                    break;
                }
            }
        }
    }
    return stack.top();
}

int getPriority(int operand)
{
    switch (operand)
    {
        case -1:
        case -2: return 4;

        case -3:
        case -4: return 3;
    }
    return 0;
}

int Postfix(vector<char> arr, int length)
{
    vector<int> vector(arr.size());
    int counter{0};
    stack<int> stack;

    for (int i = 0; i < length; ++i)
    {
        int token = arr[i];
        if (isdigit(token))
        {
            char *buf = new char[7];
            int j = 0;
            while (isdigit(arr[i]))
            {
                buf[j] = arr[i];
                j++;
                i++;
            }
            --i;
            vector[counter] = atoi(buf);
            ++counter;
            delete[] buf;
        }
        if (token == '+' || token == '-' || token == '*' || token == '/')
        {
            switch (token)
            {
                case '+':
                {
                    token = -4;
                    break;
                }
                case '-':
                {
                    token = -3;
                    break;
                }
                case '*':
                {
                    token = -2;
                    break;
                }
                case '/':
                {
                    token = -1;
                    break;
                }
            }
            if (!stack.empty() && getPriority(token) <= getPriority(stack.top()))
            {
                vector[counter] = stack.top();
                ++counter;
                stack.pop();
            }
            stack.push(token);
        }
        if (token == '(')
        {
            stack.push(token);
        }
        if (token == ')')
        {
            while (stack.top() != '(')
            {
                vector[counter] = stack.top();
                ++counter;
                stack.pop();
            }
            stack.pop();
        }
    }
    while (!stack.empty())
    {
        vector[counter] = stack.top();
        stack.pop();
        ++counter;
    }
    return count(vector, counter);
}

int main()
{
    vector<char> vector;
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); ++i)
    {
        vector.push_back(str[i]);
    }
    cout << Postfix(vector, vector.size());
}
