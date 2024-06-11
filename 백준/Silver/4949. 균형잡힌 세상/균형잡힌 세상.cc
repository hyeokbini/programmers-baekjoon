#include <bits/stdc++.h>

using namespace std;

void check(string str)
{
    stack<char> st;
    for(auto i : str)
    {
        if(i != '(' && i != ')' && i != '[' && i != ']')
        {
            continue;
        }
        else
        {
            if(i == '(' || i == '[' || st.empty())
            {
                st.push(i);
            }
            else
            {
                if(i == ')')
                {
                    if(!st.empty() && st.top() == '(')
                    {
                        st.pop();
                    }
                    else
                    {
                        st.push(i);
                    }
                }
                else if(i == ']')
                {
                    if(!st.empty() && st.top() == '[')
                    {
                        st.pop();
                    }
                    else
                    {
                        st.push(i);
                    }
                }
            }
        }
    }
    if(st.empty())
    {
        cout << "yes\n";
    }
    else
    {
        cout << "no\n";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("test.txt","rt",stdin);
    string line;
    while(getline(cin, line))
    {
        if(line == ".")
        {
            break;
        }
        check(line);
    }
    return 0;
}
