#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> arr(9, vector<int>(9));

/*bool checkrow(int x, int y)
{
    int zerocount = 0;
    int tmp = 45;
    for (int i = 0; i < 9; i++)
    {
        if (arr[x][i] == 0)
        {
            zerocount++;
        }
        else
        {
            tmp -= arr[x][i];
        }
    }
    if(zerocount != 1)
    {
        return false;
    }
    else
    {
        arr[x][y] = tmp;
        return true;
    }
}

bool checkcol(int x, int y)
{
    int zerocount = 0;
    int tmp = 45;
    for (int i = 0; i < 9; i++)
    {
        if (arr[i][y] == 0)
        {
            zerocount++;
        }
        else
        {
            tmp -= arr[i][y];
        }
    }
    if(zerocount != 1)
    {
        return false;
    }
    else
    {
        arr[x][y] = tmp;
        return true;
    }
}

bool checkbox(int x, int y)
{
    int zerocount = 0;
    int tmp = 45;
    int startx = (x / 3) * 3;
    int starty = (y / 3) * 3;
    for (int i = startx; i < startx + 3; i++)
    {
        for (int j = starty; j < starty + 3; j++)
        {
            if (arr[i][j] == 0)
            {
                zerocount++;
            }
            else
            {
                tmp -= arr[i][j];
            }
        }
    }
    if(zerocount != 1)
    {
        return false;
    }
    else
    {
        arr[x][y] = tmp;
        return true;
    }
}

void func()
{

    int curx, cury;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (arr[i][j] == 0)
            {
                curx = i;
                cury = j;
                if(checkrow(curx, cury))
                {
                    continue;
                }
                if(checkcol(curx, cury))
                {
                    continue;
                }
                if(checkbox(curx,cury))
                {
                    continue;
                }
            }
        }
    }
    return;
}*/

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
                cout << arr[i][j] << " ";
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
    //freopen("test.txt", "rt", stdin);
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> arr[i][j];
        }
    }
    func(0,0);
    return 0;
}