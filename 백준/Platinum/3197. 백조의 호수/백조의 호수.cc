#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int r, c;
int firswanx, firswany, secswanx, secswany;
char arr[1500][1500];
int daycount = 0;
queue<pair<int, int>> waterq, nextwaterq, swanq, nextswanq;
vector<vector<bool>> watervisit(1500, vector<bool>(1500, false));
vector<vector<bool>> swanvisit(1500, vector<bool>(1500, false));

bool canmeet()
{
    while (!swanq.empty())
    {
        pair<int, int> cur = swanq.front();
        swanq.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx == secswanx && ny == secswany)
            {
                return true;
            }
            if (nx < 0 || ny < 0 || nx >= r || ny >= c)
            {
                continue;
            }
            if (swanvisit[nx][ny])
            {
                continue;
            }
            swanvisit[nx][ny] = true;
            if (arr[nx][ny] == 'X')
            {
                nextswanq.push({nx, ny});
            }
            else
            {
                swanq.push({nx, ny});
            }
        }
    }
    swap(swanq, nextswanq);
    return false;
}

void melt()
{
    while (!waterq.empty())
    {
        pair<int, int> cur = waterq.front();
        waterq.pop();
        for (int k = 0; k < 4; k++)
        {
            int nx = cur.first + dx[k];
            int ny = cur.second + dy[k];
            if (nx < 0 || ny < 0 || nx >= r || ny >= c)
            {
                continue;
            }
            if (watervisit[nx][ny])
            {
                continue;
            }
            if (arr[nx][ny] == 'X')
            {
                arr[nx][ny] = '.';
                nextwaterq.push({nx, ny});
            }
            else if (!watervisit[nx][ny])
            {
                nextwaterq.push({nx, ny});
            }
            watervisit[nx][ny] = true;
        }
    }
    /*cout << "\n";
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            cout << arr[i][j];
        }
        cout << "\n";
    }
    cout << "=====================";*/
    swap(waterq, nextwaterq);
    return;
}

int main()
{
    //freopen("test.txt", "rt", stdin);
    cin >> r >> c;
    int swancount = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == '.')
            {
                waterq.push({i, j});
                watervisit[i][j] = true;
            }
            if (arr[i][j] == 'L')
            {
                if (!swancount)
                {
                    firswanx = i;
                    firswany = j;
                    swancount++;
                    swanvisit[i][j] = true;
                    swanq.push({i, j});
                }
                else
                {
                    secswanx = i;
                    secswany = j;
                }
                waterq.push({i, j});
                watervisit[i][j] = true; // 백조도 물로 처리
            }
        }
    }

    while (true)
    {
        if (canmeet())
        {
            cout << daycount;
            break;
        }
        melt();
        daycount++;
    }
    return 0;
}
