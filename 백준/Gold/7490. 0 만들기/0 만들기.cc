#include <bits/stdc++.h>

using namespace std;

int a;
vector<string> ansstr;

void anscheck(string str)
{
    int ans = 0;
    int tmpnum = 0;
    char tmpop = '+';
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '+' || str[i] == '-')
        {
            if (tmpop == '+')
            {
                ans += tmpnum;
            }
            else if (tmpop == '-')
            {
                ans -= tmpnum;
            }
            tmpop = str[i];
        }
        else if (str[i] - '0' < 10 && str[i] - '0' > 0)
        {
            if (str[i - 1] == ' ')
            {
                tmpnum *= 10;
                tmpnum += str[i] - '0';
            }
            else
            {
                tmpnum = str[i] - '0';
            }
        }
    }
    if (tmpop == '+')
    {
        ans += tmpnum;
    }
    else if (tmpop == '-')
    {
        ans -= tmpnum;
    }
    if (ans == 0)
    {
        ansstr.push_back(str);
    }
    return;
}

void dfs(int level, string str)
{
    if (level == a + 1)
    {
        anscheck(str);
        return;
    }

    string tmpstr = str;
    tmpstr += '+';
    tmpstr += level + '0';
    dfs(level + 1, tmpstr);
    tmpstr = str;
    tmpstr += '-';
    tmpstr += level + '0';
    dfs(level + 1, tmpstr);
    tmpstr = str;
    tmpstr += ' ';
    tmpstr += level + '0';
    dfs(level + 1, tmpstr);
    return;
}

int main()
{
    //freopen("test.txt", "rt", stdin);
    int n;
    cin >> n;
    while (n--)
    {
        ansstr.clear();
        string str = "";
        str += '1';
        cin >> a;
        dfs(2, str);
        sort(ansstr.begin(), ansstr.end());
        for (auto i : ansstr)
        {
            cout << i << "\n";
        }
        cout << "\n";
    }
    return 0;
}
