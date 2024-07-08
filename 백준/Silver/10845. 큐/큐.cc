#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n;
    cin >> n;
    queue<int> Q;
    for (int i = 0; i < n; i++)
    {
        string com;
        cin >> com;
        if (com == "push")
        {
            int val;
            cin >> val;
            Q.push(val);
        }
        else if (com == "front")
        {
            if (Q.empty())
            {
                cout << -1 << "\n";
            }
            else
            {
                cout << Q.front()<< "\n";
            }
        }
        else if (com == "back")
        {
            if (Q.empty())
            {
                cout << -1 << "\n";
            }
            else
            {
                cout << Q.back()<< "\n";
            }
        }
        else if (com == "pop")
        {
            if (Q.empty())
            {
                cout << -1 << "\n";
            }
            else
            {
                cout << Q.front()<< "\n";
                Q.pop();
            }
        }
        else if(com == "size")
        {
            cout << Q.size()<< "\n";
        }
        else if(com == "empty")
        {
            cout << Q.empty() ? 1 : 0;
            cout << "\n";
        }
    }
    return 0;
}
