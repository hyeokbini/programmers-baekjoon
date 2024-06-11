#include <bits/stdc++.h>

using namespace std;

void func(string str)
{
    stack<char> st;
    for(int i = 0; i < str.length(); i++)
    {
        if(st.empty() || st.top() == ')')
        {
            st.push(str[i]);
        }
        else if(st.top() == '(')
        {
            if(str[i] == ')')
            {
                st.pop();
            }
            else
            {
                st.push(str[i]);
            }
        }
    }
    if(st.empty())
    {
        cout << "YES" << "\n";
        return;
    }
    else
    {
        cout << "NO" << "\n";
        return;
    }
}

int main()
{
    //freopen("test.txt", "rt", stdin);
    int n;
    cin >> n;
    while(n--)
    {
        string str;
        cin >> str;
        func(str);
    }
    return 0;
}
