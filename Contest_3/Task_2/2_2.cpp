#include <iostream>
#include <vector>
using namespace std;

template <typename V, typename P>
class Treap
{
  private:
    struct Node
    {
        V val{};
        P priority{};
        Node *left{nullptr};
        Node *right{nullptr};
        explicit Node(const std::pair<V, P> &el) : val{el.first}, priority{el.second} {}
    };

    Node *root{nullptr};

    //---------------------Split--------------------------
    pair<Node *, Node *> split(Node *node, const V &val)
    {
        if (!node)
        {
            return {nullptr, nullptr};
        }

        if (val > node->val)
        {
            pair<Node *, Node *> par = split(node->right, val);
            node->right = par.first;
            return {node, par.second};
        }
        else
        {
            pair<Node *, Node *> par = split(node->left, val);
            node->left = par.second;
            return {par.first, node};
        }
    }

    //---------------------Merge--------------------------
    Node *merge(Node *left, Node *right)
    {
        if (!right)
            return left;

        if (!left)
            return right;

        if (left->priority > right->priority)
        {
            left->right = merge(left->right, right);
            return left;
        }
        else
        {
            right->left = merge(left, right->left);
            return right;
        }
    }
    //---------------------Insert--------------------------
    void insert(Node *&node, const pair<V, P> &elem)
    {
        if (!node)
        {
            node = new Node(elem);
            return;
        }

        if (node->priority >= elem.second)
        {
            if (elem.first >= node->val)
                insert(node->right, elem);
            else
                insert(node->left, elem);
        }
        else
        {
            pair<Node *, Node *> para;
            para = split(node, elem.first);

            Node *ins_node = new Node(elem);
            ins_node->left = para.first;
            ins_node->right = para.second;

            node = ins_node;
        }
    }
    //---------------_DFS---------------------
    void _DFS(Node *node, vector<int> &numOfNodesOnLevel, int curr_depth)
    {
        if (!node)
            return;

        ++numOfNodesOnLevel[curr_depth];

        _DFS(node->left, numOfNodesOnLevel, curr_depth + 1);
        _DFS(node->right, numOfNodesOnLevel, curr_depth + 1);
    }

    //---------------_Width-------------------
    int _width(Node *node)
    {
        int depth = this->depth();
        vector<int> widths(depth, 0);
        _DFS(root, widths, 0);

        int max_width{0};
        // cout << "-----------" << endl;
        // cout << "DEC: Widths" << endl;
        for (auto w : widths)
        {
            // cout << w << endl;
            if (w > max_width)
                max_width = w;
        }
        // cout << "-----------" << endl;
        // cout << endl;
        return max_width;
    }

    //---------------------Insert second--------------------------
    void insert_2(Node *&node, const pair<V, P> &elem)
    {
        pair<Node *, Node *> para = split(node, elem.first);
        Node *elem_node = new Node(elem);
        para.first = merge(para.first, elem_node);
        merge(para.first, para.second);
    }
    void inorder_print_recursive(Node *node)
    {
        if (!node)
            return;

        inorder_print_recursive(node->left);
        cout << node->val << " " << node->priority << endl;
        inorder_print_recursive(node->right);
    }
    int depth_root(Node *node) { return (node ? max(depth_root(node->left), depth_root(node->right)) + 1 : 0); }

  public:
    void add(const pair<V, P> &elem) { insert(root, elem); }
    void add_2(const pair<V, P> &elem) { insert_2(root, elem); }
    void inorder_print()
    {
        cout << "Inorder print DEC" << endl;
        inorder_print_recursive(root);
    }

    int depth() { return depth_root(root); }
    int width() { return _width(root); }
};
/*
 10
 1 1
 2 1
 3 1
 4 1
 5 1
 6 1
 7 1
 8 1
 9 1
 0 1

 5
 1 1
 1 2
 1 3
 1 4
 1 5

 6
 1 1
 4 5
 5 5
 6 5
 7 3
 6 2

*/

class Binary_tree
{
  private:
    struct Node
    {
        Node *left{nullptr};
        Node *right{nullptr};
        int val;
        explicit Node(int _val) : val{_val} {}
    };

    Node *root{nullptr};

    //-------------In order-----------------
    void inorder_print_recursive(Node *node)
    {
        if (!node)
            return;

        inorder_print_recursive(node->left);
        cout << node->val << " ";
        inorder_print_recursive(node->right);
    }

    //-------------Pre order-----------------
    void preorder_print_recursive(Node *node)
    {
        if (!node)
            return;

        cout << node->val << " ";
        preorder_print_recursive(node->left);
        preorder_print_recursive(node->right);
    }

    //---------------Depth-------------------
    int _depth(Node *node) { return (node ? max(_depth(node->left), _depth(node->right)) + 1 : 0); }

    //---------------_DFS---------------------
    void _DFS(Node *node, vector<int> &numOfNodesOnLevel, int curr_depth)
    {
        if (!node)
            return;

        ++numOfNodesOnLevel[curr_depth];

        _DFS(node->left, numOfNodesOnLevel, curr_depth + 1);
        _DFS(node->right, numOfNodesOnLevel, curr_depth + 1);
    }

    //---------------_Width-------------------
    int _width(Node *node)
    {
        int depth = this->depth();
        vector<int> widths(depth, 0);
        _DFS(node, widths, 0);

        int max_width{0};
        for (auto width : widths)
            if (width > max_width)
                max_width = width;

        return max_width;
    }

  public:
    void insert(int val)
    {
        if (!root)
        {
            root = new Node{val};
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

    void inorder_print()
    {
        cout << "Inoreder print Bi" << endl;
        inorder_print_recursive(root);
    }
    void preorder_print() { preorder_print_recursive(root); }
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

    int depth() { return _depth(root); }
    int width() { return _width(root); }
};

int main()
{
    Treap<int, int> dec_tree;
    Binary_tree bi_tree;
    int n = 0;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int v, p;
        cin >> v >> p;
        dec_tree.add({v, p});
        bi_tree.insert(v);
    }
    /*
    int dd = dec_tree.depth();
    int bd = bi_tree.depth();

    cout << "Dec depth: " << dd << endl;
    cout << "Bi depth: " << bd << endl;
    cout << (dd > bd ? dd - bd : bd - dd) << endl;
    */

    int dw = dec_tree.width();
    int bw = bi_tree.width();
    // cout << "Difference btw DW and BW" << endl;
    cout << dw - bw << endl;
    //    cout << endl;
    //    bi_tree.inorder_print();
    //    cout << endl;
    //    cout << endl;
    //    dec_tree.inorder_print();

    return 0;
}
