#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    string word;
    struct Node *left, *right, *father;
};
class tree
{
  private:
    Node *root;

  public:
    tree(string word)
    {
        root = newNode(word);
        root->left = root->right = NULL;
    }
    Node *getRoot() { return root; }

    struct Node *newNode(string word)
    {
        Node *node = new Node;
        node->word = word;
        node->left = node->right = NULL;
    }
    void insert(Node *node, string word)
    {
        queue<Node *> unique;
        unique.push(node);
        while (unique.empty() == 0)
        {
            Node *node = unique.front();
            unique.pop();

            if (node->left == NULL)
            {
                node->left = newNode(word);
                break;
            }
            else
                unique.push(node->left);

            if (node->right == NULL)
            {
                node->right = newNode(word);
                break;
            }
            else
                unique.push(node->right);
        }
    }
    void PreOrder(struct Node *node)
    {
        if (node != NULL)
        {
            cout << node->word << endl;
            PreOrder(node->left);
            PreOrder(node->right);
        }
    }
    void PostOrder(struct Node *node)
    {
        if (node != NULL)
        {
            PostOrder(node->left);
            PostOrder(node->right);
            cout << node->word << endl;
        }
    }
    void InOrder(struct Node *node)
    {
        if (node != NULL)
        {
            InOrder(node->left);
            cout << node->word << endl;
            InOrder(node->right);
        }
    }
    void NoChild(struct Node *node)
    {
        if (node == NULL)
            return;

        if (node->left != NULL && node->right != NULL)
        {
            NoChild(node->left);
            NoChild(node->right);
        }
        else if (node->left != NULL)
        {
            NoChild(node->left);
        }
        else if (node->right != NULL)
        {
            NoChild(node->right);
        }
        else if (node->left == NULL && node->right == NULL)
            cout << node->word << endl;
    }
};
int main()
{
    int func;
    string word;
    cin >> word;
    tree tUgur(word);
    while (true)
    {
        cin >> word;
        if (word == "end")
            break;
        tUgur.insert(tUgur.getRoot(), word);
    }
    if (cin >> func)
    {
        while (func != -1)
        {
            cout << "*****" << endl;
            switch (func)
            {
            case 1:
                tUgur.PreOrder(tUgur.getRoot());
                break;
            case 2:
                tUgur.PostOrder(tUgur.getRoot());
                break;
            case 3:
                tUgur.InOrder(tUgur.getRoot());
                break;
            case 4:
                tUgur.NoChild(tUgur.getRoot());
                break;
            default:
                break;
            }
            cin >> func;
        }
    }
    cout << "Done!";
    return 0;
}
