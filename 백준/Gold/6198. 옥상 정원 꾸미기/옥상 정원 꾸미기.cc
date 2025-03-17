#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    long long int ans = 0;
    stack <int> S;
    int n;
    cin >> n;
    while(n--)
    {
        int curheight;
        cin >> curheight;
        if(S.empty())
        {
            S.push(curheight);
        }
        else
        {
            while(!S.empty() && S.top() <= curheight)
            {
                S.pop();
            }
            ans += S.size();
            S.push(curheight);
        }
    }
    cout << ans;
    return 0;
}
