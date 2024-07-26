#include <bits/stdc++.h>

using namespace std;

int main()
{
	//freopen("test.txt", "rt", stdin);
    int n;
    cin >> n;
    vector<int> arr(n + 1,0);
    for(int i = 1; i * i <= n; i++)
    {
        arr[i * i] = 1;
    }
    for(int i = 1; i <= n; i++)
    {
        if(arr[i])
        {
            continue;
        }
        else
        {
            for(int j = 1; j * j <= i; j++)
            {
                if(!arr[i])
                {
                    arr[i] = arr[j * j] + arr[i - j * j];
                }
                arr[i] = min(arr[i], arr[j * j] + arr[i - j * j]);
            }
        }
    }
    cout << arr[n];
    return 0;
}
