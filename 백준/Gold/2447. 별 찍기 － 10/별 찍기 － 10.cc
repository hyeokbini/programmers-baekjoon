#include <bits/stdc++.h>

using namespace std;

void drawStars(vector<vector<char>> &arr, int xstart, int xend, int ystart, int yend)
{
    if (xend - xstart == 1 || yend - ystart == 1)
    {
        for (int i = xstart; i < xend; i++)
        {
            for (int j = ystart; j < yend; j++)
            {
                arr[i][j] = '*';
            }
        }
    }
    else
    {
        int width = (xend - xstart) / 3;
        int height = (yend - ystart) / 3;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (i != 1 || j != 1)
                {
                    drawStars(arr, xstart + i * width, xstart + (i + 1) * width, ystart + j * height, ystart + (j + 1) * height);
                }
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;

    vector<vector<char>> arr(n, vector<char>(n, ' '));
    drawStars(arr, 0, n, 0, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j];
        }
        cout << "\n";
    }

    return 0;
}
