#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> circlecon;
vector<int> circlecolor;
vector<bool> visited;
bool success = true;

void dfs(int curcircle, int curcolor) // 1과 2로 색칠
{
    if(circlecolor[curcircle] == 0)
    {
        circlecolor[curcircle] = curcolor;
    }
    if(circlecolor[curcircle] != 0 && circlecolor[curcircle] != curcolor)
    {
        success = false;
        return;
    }
    if(visited[curcircle])
    {
        return;
    }
    visited[curcircle] = true;
    int nextcolor;
    if(curcolor == 1)
    {
        nextcolor = 2;
    }
    else if(curcolor == 2)
    {
        nextcolor = 1;
    }
    for(int i = 0; i < circlecon[curcircle].size(); i++)
    {
        dfs(circlecon[curcircle][i], nextcolor);
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        circlecon.resize(n + 1,vector<int>());
        fill(circlecon.begin(),circlecon.end(),vector<int>());
        circlecolor.resize(n + 1,0);
        fill(circlecolor.begin(),circlecolor.end(),0);
        visited.resize(n + 1,false);
        fill(visited.begin(),visited.end(),false);
        success = true;
        while(m--)
        {
            int fir,sec;
            cin >> fir >> sec;
            circlecon[fir].push_back(sec);
            circlecon[sec].push_back(fir);
        }
        for(int i = 1; i <= n; i++)
        {
            if(circlecolor[i] != 0)
            {
                dfs(i,circlecolor[i]);
            }
            else
            {
                dfs(i,1);
            }
        }
        if(success)
        {
            cout << "possible\n";
        }
        else
        {
            cout << "impossible\n";
        }
    }
}
