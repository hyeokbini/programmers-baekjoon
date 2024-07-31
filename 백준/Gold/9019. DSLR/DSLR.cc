#include <bits/stdc++.h>

using namespace std;

vector<int> vis(10001,false);

void func(int a,int b)
{
    queue<pair<int,string>> Q;
    Q.push({a,""});
    vis[a] = true;
    while(!Q.empty())
    {
        int val = Q.front().first;
        string com = Q.front().second;
        Q.pop();
        if(val == b)
        {
            cout << com << "\n";
            return;
        }
        if(!vis[(val * 2) % 10000])
        {
            Q.push({(val * 2) % 10000, com + "D"});
            vis[(val * 2) % 10000] = true;
        }
        if(val == 0 && !vis[9999])
        {
            Q.push({9999,com + "S"});
            vis[9999] = true;
        }
        else if(val != 0 && !vis[val - 1])
        {
            Q.push({val - 1, com + "S"});
            vis[val - 1] = true;
        }
        if(!vis[(val % 1000) * 10 + val / 1000])
        {
            Q.push({(val % 1000) * 10 + val / 1000, com + "L"});
            vis[(val % 1000) * 10 + val / 1000] = true;
        }
        if(!vis[(val % 10) * 1000 + val / 10])
        {
            Q.push({(val % 10) * 1000 + val / 10, com + "R"});
            vis[(val % 10) * 1000 + val / 10] = true;
        }
    }
    return;
} 

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n;
    cin >> n;
    while(n--)
    {
        int a,b;
        cin >> a >> b;
        func(a,b);
        fill(vis.begin(),vis.end(),false);
    }
    return 0;
}