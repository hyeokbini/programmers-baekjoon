#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int a, b;
    int ans = INT_MIN;
    cin >> a >> b;
    vector<int> arr(a);
    for(int i = 0; i < a; i++)
    {
        cin >> arr[i];
    }
    for(int i = 0; i < a - 2; i++)
    {
        for(int j = i + 1; j < a - 1; j++)
        {
            for(int k = j + 1; k < a; k++)
            {
                int tmp = arr[i] + arr[j] + arr[k];
                if(tmp <= b && tmp > ans)
                {
                    ans = tmp;
                }
            }
        }
    }
    cout << ans;
    return 0;
}
