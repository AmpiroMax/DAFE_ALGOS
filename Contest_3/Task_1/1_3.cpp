
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

#include <queue>

class Binary_tree
{
  private:
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

    Node *root;

    void inorder_print_recursive(Node *node)
    {
        if (!node)
            return;

        inorder_print_recursive(node->left);
        cout << node->val << " ";
        inorder_print_recursive(node->right);
    }

    void preorder_print_recursive(Node *node)
    {
        if (!node)
            return;

        cout << node->val << " ";
        preorder_print_recursive(node->left);
        preorder_print_recursive(node->right);
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
    void preorder_print() { preorder_print_recursive(root); }
    void postOrder_print()
    {

        std::stack<Node *> stk;
        stk.push(root);

        std::stack<int> out;

        while (!stk.empty())
        {

            Node *curr = stk.top();
            stk.pop();

            out.push(curr->val);

            if (curr->left)
                stk.push(curr->left);

            if (curr->right)
                stk.push(curr->right);
        }

        while (!out.empty())
        {
            std::cout << out.top() << " ";
            out.pop();
        }
    }
    void levelOrder_print()
    {

        std::vector<Node *> array;
        Node *temp = root;

        array.push_back(temp);

        while (!array.empty())
        {

            std::vector<Node *> temporary;

            for (int i = 0; i < array.size(); ++i)
            {

                std::cout << array[i]->val << " ";

                if (array[i]->left)
                    temporary.push_back(array[i]->left);

                if (array[i]->right)
                    temporary.push_back(array[i]->right);
            }
            array.resize(temporary.size());

            std::copy(temporary.begin(), temporary.end(), array.begin());
        }
    }
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

    tree.postOrder_print();

    return 0;
}
