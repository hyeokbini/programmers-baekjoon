#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n;
    cin >> n;
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        string com;
        cin >> com;
        if (com == "push")
        {
            int val;
            cin >> val;
            st.push(val);
        }
        else if (com == "top")
        {
            if (st.empty())
            {
                cout << -1 << "\n";
            }
            else
            {
                cout << st.top()<< "\n";
            }
        }
        else if (com == "pop")
        {
            if (st.empty())
            {
                cout << -1 << "\n";
            }
            else
            {
                cout << st.top()<< "\n";
                st.pop();
            }
        }
        else if(com == "size")
        {
            cout << st.size()<< "\n";
        }
        else if(com == "empty")
        {
            cout << st.empty() ? 1 : 0;
            cout << "\n";
        }
    }
    return 0;
}
