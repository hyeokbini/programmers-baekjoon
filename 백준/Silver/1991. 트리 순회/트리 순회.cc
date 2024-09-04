#include <bits/stdc++.h>

using namespace std;

struct node
{
    string val;
    node* left = nullptr;
    node* right = nullptr;
};

void maketree(node* curnode,string val,string left,string right)
{
    if(curnode == nullptr)
    {
        return;
    }
    if(val == curnode->val)
    {
        node *leftnode = new node;
        node *rightnode = new node;
        leftnode->val = left;
        rightnode->val = right;
        curnode->left = leftnode;
        curnode->right = rightnode;
    }
    maketree(curnode->left,val,left,right);
    maketree(curnode->right,val,left,right);
}

void pre(node* root)
{
    if(root->val == ".")
    {
        return;
    }
    cout << root->val;
    pre(root->left);
    pre(root->right);
}

void in(node* root)
{
    if(root->val == ".")
    {
        return;
    }
    in(root->left);
    cout << root->val;
    in(root->right);
}

void pos(node* root)
{
    if(root->val == ".")
    {
        return;
    }
    pos(root->left);
    pos(root->right);
    cout << root->val;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n;
    cin >> n;
    node *tree = new node;
    tree->val = "A";
    for(int i = 0; i < n; i++)
    {
        string val,left,right;
        cin >> val >> left >> right;
        maketree(tree,val,left,right);
    }
    pre(tree);
    cout << "\n";
    in(tree);
    cout << "\n";
    pos(tree);
    return 0;
}
