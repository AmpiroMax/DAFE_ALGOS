#include <iostream>
#include <vector>

using namespace std;

#include <queue>

struct Node
{
    Node *left;
    Node *right;
    int val;

    Node(int _val) : val{_val}
    {
        left = nullptr;
        right = nullptr;
    }
};

class Binary_tree
{
  private:
    Node *root;

    void inorder_print_recursive(Node *node)
    {
        if (!node)
            return;

        inorder_print_recursive(node->left);
        cout << node->val << " ";
        inorder_print_recursive(node->right);
    }

  public:
    Binary_tree() { root = nullptr; }

    void insert(int val)
    {
        if (!root)
        {
            root = new Node{val};
            // cout << root << endl;
            // cout << root->val << endl;
            return;
        }

        Node *tmp = root;
        Node *parent = tmp;

        while (tmp)
        {
            parent = tmp;
            if (tmp->val > val)
                tmp = tmp->left;
            else
                tmp = tmp->right;
        }
        Node *new_node = new Node{val};

        if (parent->val > val)
            parent->left = new_node;
        else
            parent->right = new_node;
    }

    void inorder_print() { inorder_print_recursive(root); }

    void delete_node(int val) {}
};

int main()
{
    Binary_tree tree;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int value;
        cin >> value;
        tree.insert(value);
    }

    tree.inorder_print();

    return 0;
}
