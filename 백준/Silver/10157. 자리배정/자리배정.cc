#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int curdir = 0; // 시작은 위쪽

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int c, r;
    cin >> c >> r;
    vector<vector<int>> arr(r, vector<int>(c, -1));
    int k;
    cin >> k;
    if (c * r < k)
    {
        cout << 0;
        return 0;
    }
    int curx = r - 1;
    int cury = 0;
    for (int i = 1; i <= k; i++)
    {
        if(i == k)
        {
            cout << cury + 1 << " " << r - curx;
            return 0;
        }
        arr[curx][cury] = i; // 자리 배정

        int nextx = curx + dx[curdir];
        int nexty = cury + dy[curdir]; // 다음 자리 계산
        if (nextx >= r || nextx < 0 || nexty >= c || nexty < 0 || arr[nextx][nexty] != -1)
        {
            curdir = (curdir + 1) % 4;
            nextx = curx + dx[curdir];
            nexty = cury + dy[curdir]; // 방향 다시 세팅 후 자리 재계산
        }

        curx = nextx;
        cury = nexty; // 다음 배정할 자리 세팅
    }
}
