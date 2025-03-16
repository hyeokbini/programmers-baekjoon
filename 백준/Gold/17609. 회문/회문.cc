#include <bits/stdc++.h>

using namespace std;

int ans = 0;

int check(string &str, int left, int right, int delcount)
{
    if (left >= right)
    {
        if (delcount == 0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    if (str[left] != str[right])
    {
        if (delcount == 0)
        {
            return min(check(str, left, right - 1, 1), check(str, left + 1, right, 1));
        }
        return 2;
    }
    else
    {
        return check(str, left + 1, right - 1, delcount);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n;
    cin >> n;
    while (n--)
    {
        string temp;
        cin >> temp;
        cout << check(temp, 0, temp.length() - 1, 0) << "\n";
    }
    return 0;
}
