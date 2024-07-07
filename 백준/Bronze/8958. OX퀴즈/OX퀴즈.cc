#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n;
    cin >> n;
    while(n--)
    {
        string tmp;
        cin >> tmp;
        vector<int> arr(tmp.length(),0);
        for(int i = 0; i < tmp.length(); i++)
        {
            if(tmp[i] == 'O')
            {
                if(i == 0 || tmp[i - 1] == 'X')
                {
                    arr[i] = 1;
                }
                else
                {
                    arr[i] = arr[i - 1] + 1;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < tmp.length(); i++)
        {
            ans += arr[i];
        }
        cout << ans << "\n";
    }
    return 0;
}
