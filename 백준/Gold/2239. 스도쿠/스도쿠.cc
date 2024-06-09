#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> arr(9, vector<int>(9));

bool check(int x, int y, int val)
{
    bool caninsert[9];
    fill(begin(caninsert), end(caninsert), true);
    for (int i = 0; i < 9; i++)
    {
        if (arr[x][i] != 0)
        {
            caninsert[arr[x][i] - 1] = false;
        }
    }
    for (int i = 0; i < 9; i++)
    {
        if (arr[i][y] != 0)
        {
            caninsert[arr[i][y] - 1] = false;
        }
    }
    int startx = (x / 3) * 3;
    int starty = (y / 3) * 3;
    for (int i = startx; i < startx + 3; i++)
    {
        for (int j = starty; j < starty + 3; j++)
        {
            if (arr[i][j] != 0)
            {
                caninsert[arr[i][j] - 1] = false;
            }
        }
    }
    return caninsert[val - 1];
}

void func(int xidx, int yidx)
{
    if (xidx == 9)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << arr[i][j];
            }
            cout << "\n";
        }
        exit(0);
    }
    if(yidx == 9)
    {
        func(xidx + 1,0);
        return;
    }
    if(arr[xidx][yidx] != 0)
    {
        func(xidx, yidx + 1);
        return;
    }
    else
    {
        for(int i = 1; i <= 9; i++)
        {
            if(check(xidx,yidx,i))
            {
                arr[xidx][yidx] = i;
                func(xidx,yidx + 1);
                arr[xidx][yidx] = 0;
            }
        }
    }
}

int main()
{
    for (int i = 0; i < 9; i++)
    {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < 9; j++)
        {
            arr[i][j] = tmp[j] - '0';
        }
    }
    func(0,0);
    return 0;
}