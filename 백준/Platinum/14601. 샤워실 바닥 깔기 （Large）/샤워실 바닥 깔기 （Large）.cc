#include <bits/stdc++.h>

using namespace std;

int tile[130][130];
int tilecount = 1;
int holex, holey;

bool notnumarea(int x, int y, int len)
{
    for(int i = x; i < x + len; i++)
    {
        for(int j = y; j < y + len; j++)
        {
            if(tile[i][j] != 0)
            {
                return false;
            }
        }
    }
    return true;
}
void func(int xstart, int ystart, int len)
{
    len /= 2;
    /*
    if (!(xstart <= holex && holex < xstart + len
    && ystart <= holey && holey < ystart + len)
    && tile[xstart + len - 1][ystart + len - 1] == 0)
    {
        tile[xstart + len - 1][ystart + len - 1] = tilecount;
    }
    if (!(xstart <= holex && holex < xstart + len
    && ystart + len <= holey && holey < ystart + len * 2)
    && tile[xstart + len - 1][ystart + len] == 0)
    {
        tile[xstart + len - 1][ystart + len] = tilecount;
    }
    if (!(ystart <= holey && holey < ystart + len
    && xstart + len <= holex && holex < xstart + len * 2)
    && tile[xstart + len][ystart + len - 1] == 0)
    {
        tile[xstart + len][ystart + len - 1] = tilecount;
    }
    if (!(xstart + len <= holex && holex < xstart + len * 2
    && ystart + len <= holey && holey < ystart + len * 2)
    && tile[xstart + len][ystart + len] == 0)
    {
        tile[xstart + len][ystart + len] = tilecount;
    }
    */
    if(notnumarea(xstart,ystart,len))
    {
        tile[xstart + len - 1][ystart + len - 1] = tilecount;
    }
    if(notnumarea(xstart,ystart + len,len))
    {
        tile[xstart + len - 1][ystart + len] = tilecount;
    }
    if(notnumarea(xstart + len,ystart,len))
    {
        tile[xstart + len][ystart + len - 1] = tilecount;
    }
    if(notnumarea(xstart + len,ystart + len,len))
    {
        tile[xstart + len][ystart + len] = tilecount;
    }
    tilecount++;
    /*
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << tile[i][j];
        }
        cout << "\n";
    }
    */
    if (len < 2)
    {
        return;
    }

    func(xstart, ystart, len);
    func(xstart, ystart + len, len);
    func(xstart + len, ystart, len);
    func(xstart + len, ystart + len, len);
}

int main()
{
    //freopen("test.txt", "rt", stdin);
    int k;
    cin >> k;
    k = pow(2, k);
    int x, y;
    cin >> x >> y;
    holex = k - y;
    holey = x - 1;
    tile[holex][holey] = -1;
    func(0, 0, k);
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            cout << tile[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}