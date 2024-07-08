#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    while (1)
    {
        string tmp;
        cin >> tmp;
        if (tmp == "0")
        {
            break;
        }
        int leng = tmp.length();
        bool check = true;
        for (int i = 0; i < leng / 2; i++)
        {
            if (tmp[i] != tmp[leng - i - 1])
            {
                check = false;
                break;
            }
        }
        if (check)
        {
            cout << "yes\n";
        }
        else
        {
            cout << "no\n";
        }
    }
    return 0;
}
