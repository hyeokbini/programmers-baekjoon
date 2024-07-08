#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n, k;
    cin >> n >> k;
    queue<int> Q;
    vector<int> ans;
    for(int i = 1; i <= n; i++)
    {
        Q.push(i);
    }
    int count = 0;
    while(!Q.empty())
    {
        int cur = Q.front();
        Q.pop();
        count++;
        if(count != k)
        {
            Q.push(cur);
        }
        else
        {
            ans.push_back(cur);
            count = 0;
        }
    }
    cout << "<";
    for(int i = 0; i < n; i++)
    {
        if(i == n - 1)
        {
            cout << ans[i];
            break;
        }
        cout << ans[i] << ", ";
    }
    cout << ">";
    return 0;
}
