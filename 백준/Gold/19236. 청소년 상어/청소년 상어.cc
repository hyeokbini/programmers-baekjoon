#include <bits/stdc++.h>
using namespace std;

int ans = 0;
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};

bool isIn(int x, int y)
{
    return (x >= 0 && x < 4 && y >= 0 && y < 4);
}

vector<vector<pair<int,int>>> moveFish(vector<vector<pair<int,int>>> arr, int sharkX, int sharkY)
{
    for (int f = 1; f <= 16; f++)
    {
        int fx = -1, fy = -1;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (arr[i][j].first == f)
                {
                    fx = i;
                    fy = j;
                }
            }
        }
        if (fx == -1 && fy == -1)
        {
            continue;
        }
            
        int dir = arr[fx][fy].second;
        for (int k = 0; k < 8; k++)
        {
            int ndir = (dir + k) % 8;
            int nx = fx + dx[ndir];
            int ny = fy + dy[ndir];
            if (!isIn(nx, ny))
                continue;
            if (nx == sharkX && ny == sharkY)
                continue;

            swap(arr[fx][fy], arr[nx][ny]);
            arr[nx][ny].second = ndir;
            break;
        }
    }
    return arr;
}

void dfs(int sharkX, int sharkY, int sum, vector<vector<pair<int,int>>> arr)
{
    sum += arr[sharkX][sharkY].first;
    int sharkDir = arr[sharkX][sharkY].second;
    arr[sharkX][sharkY].first = 0;

    arr = moveFish(arr, sharkX, sharkY);

    bool canMove = false;
    for (int step = 1; step <= 3; step++)
    {
        int nx = sharkX + dx[sharkDir] * step;
        int ny = sharkY + dy[sharkDir] * step;
        if (!isIn(nx, ny))
            break;
        if (arr[nx][ny].first == 0)
            continue;

        canMove = true;
        dfs(nx, ny, sum, arr);
    }
    if (!canMove)
    {
        ans = max(ans, sum);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    vector<vector<pair<int,int>>> arr(4, vector<pair<int,int>>(4));
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int num, dir;
            cin >> num >> dir;
            arr[i][j] = {num, dir - 1};
        }
    }

    dfs(0, 0, 0, arr);
    cout << ans << "\n";
}
