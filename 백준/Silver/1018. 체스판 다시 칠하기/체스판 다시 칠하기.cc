#include <bits/stdc++.h>

using namespace std;

vector<vector<char>> chess;
int ans = INT_MAX;

void checkw(int i,int j) // 맨 왼쪽위 흰색
{
    int count = 0;
    for(int x = i; x < i + 8; x++)
    {
        for(int y = j; y < j + 8; y++)
        {
            if((x + y) % 2 == 0 && chess[x][y] != 'W')
            {
                count++;
            }
            if((x + y) % 2 == 1 && chess[x][y] != 'B')
            {
                count++;
            }
        }
    }
    ans = min(count,ans);
    return;
}

void checkb(int i,int j) // 맨 왼쪽위 검은색
{
    int count = 0;
    for(int x = i; x < i + 8; x++)
    {
        for(int y = j; y < j + 8; y++)
        {
            if((x + y) % 2 == 0 && chess[x][y] != 'B')
            {
                count++;
            }
            if((x + y) % 2 == 1 && chess[x][y] != 'W')
            {
                count++;
            }
        }
    }
    ans = min(count,ans);
    return;
}

int main()
{
    //freopen("test.txt", "rt", stdin);
    int n,m;
    cin >> n >> m;
    chess.resize(n,vector<char>(m));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> chess[i][j];
        }
    }
    for(int i = 0; i <= n - 8; i++)
    {
        for(int j = 0; j <= m - 8; j++)
        {
            checkw(i,j);
            checkb(i,j);
        }
    }
    cout << ans;
}
