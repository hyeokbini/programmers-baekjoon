#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int s;
    cin >> s;
    int maxidx = 0;
    while (1)
    {
        bool swapcheck = false;
        int curmaxval = 0;
        int curmaxvalidx;
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i + 1] > arr[i])
            {
                swapcheck = true;
            }
        }
        if (!swapcheck)
        {
            for (auto i : arr)
            {
                cout << i << " ";
            }
            return 0;
        }
        for (int i = maxidx, j = s; i < n && j >= 0; i++,j--)
        {
            if (curmaxval < arr[i])
            {
                curmaxval = arr[i];
                curmaxvalidx = i;
            }
        }
        if(curmaxvalidx - maxidx <= s)
        {
            for (int i = curmaxvalidx; i > maxidx; i--)
            {
                swap(arr[i], arr[i - 1]);
            }
            s -= curmaxvalidx - maxidx;
            maxidx++;
        }
        else
        {
            while (s--)
            {
                swap(arr[curmaxvalidx], arr[curmaxvalidx - 1]);
                curmaxvalidx--;
            }
            for (auto i : arr)
            {
                cout << i << " ";
            }
            return 0;
        }
        if (!s)
        {
            for (auto i : arr)
            {
                cout << i << " ";
            }
            return 0;
        }
    }

    /*while (1)
    {
        bool swapcheck = false;
        if (!s)
        {
            for (auto i : arr)
            {
                cout << i << " ";
            }
            return 0;
        }
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i + 1] > arr[i])
            {
                swapcheck = true;
                swap(arr[i + 1], arr[i]);
                s--;
                break;
            }
        }
        if (!swapcheck)
        {
            for (auto i : arr)
            {
                cout << i << " ";
            }
            return 0;
        }
    }*/
    return 0;
}