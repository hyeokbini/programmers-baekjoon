#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> arr(4, vector<int>(8));
bool visited[4];
int ans = 0;

int adjustIndex(int idx)
{
    return (idx + 8) % 8;
}

void func(vector<vector<int>> &idxarr, int curgear, int rl)
{
    visited[curgear] = true;
    bool rightmove = false, leftmove = false;
    if (curgear != 3)
    {
        if (arr[curgear][idxarr[curgear][0]] != arr[curgear + 1][idxarr[curgear + 1][1]])
        {
            rightmove = true;
        }
    }
    if (curgear != 0)
    {
        if (arr[curgear][idxarr[curgear][1]] != arr[curgear - 1][idxarr[curgear - 1][0]] && curgear >= 0)
        {
            leftmove = true;
        }
    }
    int offset = 0;
    if (rl == 1)
    {
        offset = -1;
    }
    else if (rl == -1)
    {
        offset = 1;
    }
    idxarr[curgear][0] = adjustIndex(idxarr[curgear][0] + offset);
    idxarr[curgear][1] = adjustIndex(idxarr[curgear][1] + offset);
    if (curgear == 0 && visited[1])
    {
        return;
    }
    if (curgear == 3 && visited[2])
    {
        return;
    }
    // 양 옆의 gear에 대해 값 확인하고 재귀호출하기

    // 현재 기어의 오른쪽 기어에 대해 판별(아직 기어를 돌리지 않았고, 같은 극이어서 회전하지 않는 경우)
    if (curgear != 3)
    {
        if (!rightmove && !visited[curgear + 1])
        {
            func(idxarr, curgear + 1, 0); // rl값을 0으로 줘서 기어인덱스값 변화 x
        }
        // 오른쪽기어, 다른 극이어서 회전 o
        else if (rightmove && !visited[curgear + 1])
        {
            func(idxarr, curgear + 1, rl * -1); // 기존 rl값을 부호만 바꿔서 재귀
        }
    }
    if (curgear != 0)
    {
        // 왼쪽기어, 같은극이어서 회전 x
        if (!leftmove && !visited[curgear - 1])
        {
            func(idxarr, curgear - 1, 0);
        }
        // 왼쪽기어, 다른 극이어서 회전 o
        else if (leftmove && !visited[curgear - 1])
        {
            func(idxarr, curgear - 1, rl * -1);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, num, rl;
    vector<vector<int>> idxarr(4, vector<int>(2, 0));
    for (int i = 0; i < 4; i++)
    {
        idxarr[i][0] = 2;
        idxarr[i][1] = 6;
    }
    for (int i = 0; i < 4; i++)
    {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < 8; j++)
        {
            arr[i][j] = tmp[j] - '0';
        }
    }
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num >> rl;
        func(idxarr, num - 1, rl);
        fill(visited, visited + 4, 0);
    }

    for (int i = 0; i < 4; i++)
    {
        int idx = idxarr[i][0] - 2;
        if (idx < 0)
        {
            idx += 8;
        }
        if (arr[i][idx] == 1)
        {
            ans += pow(2, i);
        }
    }
    cout << ans;
}
