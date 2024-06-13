#include <bits/stdc++.h>

using namespace std;

string tmp;
int ans = 0;
int n, m;

bool possible(int idx)
{
    if (idx % 2 == 1)
    {
        for (int i = idx; i < idx + 2 * n + 1; i++)
        {
            if(i % 2 == 1 && tmp[i] != 'I')
            {
                return false;
            }
            if(i % 2 == 0 && tmp[i] != 'O')
            {
                return false;
            }
        }
    }
    else if (idx % 2 == 0)
    {
        for (int i = idx; i < idx + 2 * n + 1; i++)
        {
            if(i % 2 == 0 && tmp[i] != 'I')
            {
                return false;
            }
            if(i % 2 == 1 && tmp[i] != 'O')
            {
                return false;
            }
        }
    }
    ans++;
    return true;
}

int main()
{
    //freopen("test.txt", "rt", stdin);
    cin >> n >> m;
    cin >> tmp;
    for (int i = 0; i <= m - 2 * n - 1; i++)
    {
        if (tmp[i] != 'I')
        {
            continue;
        }
        else
        {
            if(possible(i))
            {
                i += 1;
                continue;
            }
        }
    }
    cout << ans;
    return 0;
}