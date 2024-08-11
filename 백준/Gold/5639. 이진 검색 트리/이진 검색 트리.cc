#include <bits/stdc++.h>

using namespace std;

struct node
{
    int val = -1;
    node *left = nullptr;
    node *right = nullptr;
};

void maketree(int val, node& curnode)
{
    if(curnode.val == -1)
    {
        curnode.val = val;
        return;
    }
    else if(curnode.val > val)
    {
        if(curnode.left == nullptr)
        {
            curnode.left = new node;
        }
        maketree(val,*curnode.left);
    }
    else
    {
        if(curnode.right == nullptr)
        {
            curnode.right = new node;
        }
        maketree(val,*curnode.right);
    }
}

void porder(node* curnode)
{
    if(curnode == nullptr)
    {
        return;
    }
    porder(curnode->left);
    porder(curnode->right);
    cout << curnode->val << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n;
    node root;
    while(cin >> n)
    {
        maketree(n,root);
    }
    porder(&root);
    return 0;
}
