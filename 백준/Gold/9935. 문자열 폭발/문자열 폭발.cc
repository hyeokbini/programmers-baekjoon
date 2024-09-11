#include <bits/stdc++.h>

using namespace std;

string str;
string bomb;
int bomblength;
int strlength;
/*bool check(stack<char> S)
{
    for (int i = bomblength - 1; i >= 0; i--)
    {
        if (S.top() != bomb[i])
        {
            return false;
        }
        S.pop();
    }
    return true;
}*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    stack<char> S;
    cin >> str >> bomb;
    char stand = bomb.back();
    bomblength = bomb.length();
    strlength = str.length();
    for (int i = 0; i < strlength; i++)
    {
        S.push(str[i]);
        if (str[i] == stand)
        {
            if (S.size() >= bomblength)
            {
                string tmp = "";
                for (int i = 0; i < bomblength; i++)
                {
                    tmp += S.top();
                    S.pop();
                }
                reverse(tmp.begin(), tmp.end());

                if (tmp != bomb)
                {
                    for (char c : tmp)
                    {
                        S.push(c);
                    }
                }
            }
        }
    }
    if (S.empty())
    {
        cout << "FRULA";
    }
    else
    {
        string result = "";
        while (!S.empty())
        {
            result += S.top();
            S.pop();
        }
        reverse(result.begin(), result.end());
        cout << result;
    }
    return 0;
}