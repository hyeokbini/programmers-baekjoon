#include <bits/stdc++.h>

using namespace std;

string tmp;
int ans = 0;
int idxcount = 0;
int n, m;

bool possible(int idx)
{
    idxcount = 0;
    for (int i = 0; i < 2 * n + 1; i++)
    {
        idxcount++;
        if (i % 2 == 0 && tmp[idx + i] != 'I')
            return false;
        if (i % 2 == 1 && tmp[idx + i] != 'O')
            return false;
    }
    return true;
}

int main()
{
    //freopen("test.txt", "rt", stdin);
    cin >> n >> m;
    cin >> tmp;

    for (int i = 0; i <= m - 2 * n - 1; )
    {
        if (tmp[i] == 'I')
        {
            if(possible(i))
            {
                ans++;
            i += 2 * n + 1;
            while (i < m - 1 && tmp[i] == 'O' && tmp[i + 1] == 'I')
            {
                ans++;
                i += 2;
            }
            }
            else
            {
                i+= idxcount - 1;
            }
        }
        else
        {
            i += 1;
        }
    }

    cout << ans;
    return 0;
}
