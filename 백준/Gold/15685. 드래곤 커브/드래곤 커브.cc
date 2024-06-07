#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

int ansmap[101][101];
int ans = 0;

struct curve
{
    int curx;
    int cury; // 기준점이자 회전점이 될 좌표
    int dir;
    int gen;
};

void func(curve &obj)
{
    vector<vector<int>> dotarr;
    bool tmpmap[101][101] = { false };
    tmpmap[obj.cury][obj.curx] = true;
    dotarr.push_back({obj.cury, obj.curx});
    obj.cury += dx[obj.dir];
    obj.curx += dy[obj.dir];
    tmpmap[obj.cury][obj.curx] = true; // 0세대 밑작업 완료
    dotarr.push_back({obj.cury, obj.curx});
    while(obj.gen > 0)
    {
        int pivotY = dotarr.back()[0];
        int pivotX = dotarr.back()[1];
        int size = dotarr.size();
        for(int j = size - 2; j >= 0; j--)
        {
            int newY = pivotY + (dotarr[j][1] - pivotX);
            int newX = pivotX - (dotarr[j][0] - pivotY);

            if(newY >= 0 && newY <= 100 && newX >= 0 && newX <= 100)
            {
                tmpmap[newY][newX] = true;
                dotarr.push_back({newY, newX});
            }
        }
        obj.gen--;
    }
    for(int i = 0; i < 101; i++)
    {
        for(int j = 0; j < 101; j++)
        {
            if(ansmap[i][j] || tmpmap[i][j])
            {
                ansmap[i][j] = 1;
            }
        }
    }
    return;
}


int main()
{
    int n;
    cin >> n;
    vector<curve> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].curx >> arr[i].cury >> arr[i].dir >> arr[i].gen;
        func(arr[i]);
    }
    for(int i = 0; i <= 100; i++)
    {
        for(int j = 0; j <= 100; j++)
        {
            if(ansmap[i][j] && ansmap[i + 1][j] && ansmap[i][j + 1] && ansmap[i + 1][j + 1])
            {
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}