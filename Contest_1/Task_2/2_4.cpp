#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int val;
    Node *next;

    Node(int i) { val = i; }
};
Node *add(Node *current, int i)
{
    Node *tmp = new Node{i};
    current->next = tmp;
    tmp->next = nullptr;
    return tmp;
}

Node *init(Node *head, int n)
{
    Node *cur = head;
    for (int i = 2; i <= n; ++i)
    {
        cur = add(cur, i);
    }
    cur->next = head;
    return head;
}

int main()
{
    int n = 0, step = 0;
    cin >> n >> step;
    Node *head = new Node{1};
    Node *cur = init(head, n);

    //    for (int i = 0; i < n; i++)
    //    {
    //        cout << cur->val << endl;
    //        cur = cur->next;
    //    }
    Node *prev = head;
    cur = head->next;

    for (int i = 2; cur != cur->next; i++)
    {
        if (i % step == 0)
        {
            prev->next = cur->next;
        }
        prev = cur;
        cur = cur->next;
    }
    cout << cur->val << endl;
}
