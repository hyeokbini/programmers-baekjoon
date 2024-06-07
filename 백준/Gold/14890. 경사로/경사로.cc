#include <bits/stdc++.h>

using namespace std;

int n, l;
int ans;
vector<vector<int>> arr;

void rowcheck(int i) // 가로획 검사
{
    bool used[100] = {
        0,
    };
    int curidx = 0;
    int curheight = arr[i][curidx];
    while (curidx != n - 1)
    {
        if (curheight == arr[i][curidx + 1]) // 평평해서 직선으로 감
        {
            curidx++;
            int curheight = arr[i][curidx];
        }
        else if (curheight > arr[i][curidx + 1]) // 내려감
        {
            for (int u = curidx + 1; u <= curidx + l; u++) // 앞에 경사로 놓을 수 있는지 체크
            {
                if (u >= n)
                {
                    return;
                }
                if (arr[i][u] != curheight - 1 || used[u])
                {
                    return;
                }
            }
            if (curidx + l == n - 1) // 내려가는 경사로 뒀는데 마지막 지점인 경우
            {
                break;
            }
            if (curidx + l + 1 >= n || arr[i][curidx + l + 1] > curheight)
            {
                return;
            }
            else if (arr[i][curidx + l + 1] < curheight)
            {
                for (int u = curidx + 1; u <= curidx + l; u++)
                {
                    used[u] = true;
                }
                curidx += l;
                curheight = arr[i][curidx];
                continue;
            }
            for (int u = curidx + 1; u <= curidx + l; u++)
            {
                used[u] = true;
            }
            curidx++;
            curheight = arr[i][curidx];
        }
        else if (curidx - l < 0 || curheight < arr[i][curidx + 1]) // 올라감
        {
            int nextheight = arr[i][curidx + 1];
            for (int u = curidx; u > curidx - l; u--) // 뒤에 경사로 놓을 수 있는지 체크
            {
                if (u < 0)
                {
                    return;
                }
                if (arr[i][u] != nextheight - 1 || used[u])
                {
                    return;
                }
            }
            if (curidx - l >= 0)
            {
                if (arr[i][curidx - l] > curheight) // 맨 앞 l자리가 경사로가 되어야 하는데, 그 뒷자리는 존재하지 않아서 예외처리해야함
                {
                    return;
                }
                else if (arr[i][curidx - l] < curheight)
                {
                    if (!used[curidx - l] || !(arr[i][curidx - l] == curheight - 1))
                    {
                        return;
                    }
                }
            }

            for (int u = curidx; u > curidx - l; u--)
            {
                used[u] = true;
            }
            curidx++;
            curheight = arr[i][curidx];
        }
    }
    ans++;
    return;
}

void colcheck(int i) // 세로획 검사
{
    bool used[100] = {
        0,
    };
    int curidx = 0;
    int curheight = arr[curidx][i];
    while (curidx != n - 1)
    {
        if (curheight == arr[curidx + 1][i]) // 평평해서 직선으로 감
        {
            curidx++;
            curheight = arr[curidx][i];
        }
        else if (curheight > arr[curidx + 1][i]) // 내려감
        {
            for (int u = curidx + 1; u <= curidx + l; u++)
            {
                if (u >= n)
                {
                    return;
                }
                if (arr[u][i] != curheight - 1 || used[u])
                {
                    return;
                }
            }
            if (curidx + l == n - 1) // 내려가는 경사로 뒀는데 마지막 지점인 경우
            {
                break;
            }
            if (curidx + l + 1 >= n || arr[curidx + l + 1][i] > curheight) // 경사로 길이 바로 다음칸이 현재 높이보다 크다
            {
                return;
            }
            // 경사로 길이 바로 다음칸이 현재높이보다 낮다.. 이런 경우에는 경사로를 사용할 수 있는지 또 체크해야함
            else if (arr[curidx + l + 1][i] < curheight)
            {
                for (int u = curidx + 1; u <= curidx + l; u++)
                {
                    used[u] = true;
                }
                curidx += l;
                curheight = arr[curidx][i]; // 2번째 경사로를 놓을 수 있는 곳으로 현재 위치 변경 후 거기서 다시 탐색
                continue;
            }
            for (int u = curidx + 1; u <= curidx + l; u++)
            {
                used[u] = true;
            }
            curidx++;
            curheight = arr[curidx][i];
        }
        else if (curheight < arr[curidx + 1][i]) // 올라감
        {
            int nextheight = arr[curidx + 1][i];
            for (int u = curidx; u > curidx - l; u--)
            {
                if (u < 0)
                {
                    return;
                }
                if (arr[u][i] != nextheight - 1 || used[u])
                {
                    return;
                }
            }
            if (curidx - l >= 0)
            {
                if (arr[curidx - l][i] > curheight) // 맨 앞 l자리가 경사로가 되어야 하는데, 그 뒷자리는 존재하지 않아서 예외처리해야함
                {
                    return;
                }
                else if (arr[curidx - l][i] < curheight)
                {
                    if (!used[curidx - l] || !(arr[curidx - l][i] == curheight - 1))
                    {
                        return;
                    }
                }
            }
            for (int u = curidx; u > curidx - l; u--)
            {
                used[u] = true;
            }
            curidx++;
            curheight = arr[curidx][i];
        }
    }
    ans++;
    return;
}

int main()
{
    cin >> n >> l;
    arr.resize(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        rowcheck(i);
        colcheck(i);
    }
    cout << ans;
}