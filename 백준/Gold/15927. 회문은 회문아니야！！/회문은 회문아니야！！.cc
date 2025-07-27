#include <bits/stdc++.h>
using namespace std;


int func(string tmp)
{
    char checkchar = tmp[0];
    bool isonecharword = true;
    for(int i = 0; i < tmp.length(); i++)
    {
        if(tmp[i] != tmp[tmp.length() - (i + 1)]) // 팰린드롬이 아님
        {
            return tmp.length();
        }
        if(tmp[i] != checkchar)
        {
            isonecharword = false;
        }
    }
    return isonecharword ? -1 : tmp.length() - 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    string tmp;
    cin >> tmp;
    cout << func(tmp);
    return 0;
}
