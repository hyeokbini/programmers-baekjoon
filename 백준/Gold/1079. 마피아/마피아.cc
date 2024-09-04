#include <bits/stdc++.h>

using namespace std;

int n;
int mafia;
int ans = 0;
vector<bool> alive;
vector<int> guiltyrate;
vector<vector<int>> R;

void func( int alivecount, int nightcount, int turn)
{
    if (alivecount == 1)
    {
        ans = max(ans, nightcount);
        return;
    }
    if (turn == 1) // 마피아 턴
    {
        for (int i = 0; i < n; i++) // 죽일사람 선택
        {
            if (!alive[i] || i == mafia)
            {
                continue;
            }
            alive[i] = false; // i를 선택해서 죽임
            for (int j = 0; j < n; j++)
            {
                if (j == i)
                {
                    continue;
                }
                guiltyrate[j] += R[i][j];
            }
            func(alivecount - 1, nightcount + 1, turn * -1);
            alive[i] = true;
            for (int j = 0; j < n; j++)
            {
                if (j == i)
                {
                    continue;
                }
                guiltyrate[j] -= R[i][j];
            }
        }
    }
    else // 시민 턴
    {
        int maxguiltyval = 0;
        int deathidx;
        for (int i = 0; i < n; i++)
        {
            if (!alive[i])
            {
                continue;
            }
            if (maxguiltyval < guiltyrate[i])
            {
                maxguiltyval = guiltyrate[i];
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (!alive[i])
            {
                continue;
            }
            if (maxguiltyval == guiltyrate[i])
            {
                alive[i] = false;
                if (i == mafia)
                {
                    ans = max(ans, nightcount);
                    alive[i] = true;
                    return;
                }
                deathidx = i;
                break;
            }
        }
        func(alivecount - 1, nightcount, turn * -1);
        alive[deathidx] = true;
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    cin >> n;
    alive.resize(n, true);
    guiltyrate.resize(n);
    R.resize(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        cin >> guiltyrate[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> R[i][j];
        }
    }
    cin >> mafia;
    if (n % 2 == 0)
    {
        func(n, 0, 1);
    }
    else
    {
        func(n, 0, -1);
    }
    cout << ans;
    return 0;
}
