#include <bits/stdc++.h>

using namespace std;

int ans = 0;
vector<vector<int>> peoplemap;
vector<bool> knowpeople; // true면 진실을 아는 사람, false면 모름

void makegraph(vector<int> &arr)
{
    int size = arr.size();
    for(int i = 0; i < size - 1; i++)
    {
        for(int j = i; j < size; j++)
        {
            peoplemap[arr[i]].push_back(arr[j]);
            peoplemap[arr[j]].push_back(arr[i]);
        }
    }
    return;
}

void dfs(int curidx)
{
    for(int i = 0; i < peoplemap[curidx].size(); i++)
    {
        if(knowpeople[peoplemap[curidx][i]] == true)
        {
            continue;
        }
        else
        {
            knowpeople[peoplemap[curidx][i]] = true;
            dfs(peoplemap[curidx][i]);
        }
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n,m,truecount;
    cin >> n >> m >> truecount;
    knowpeople.resize(n + 1,false);
    peoplemap.resize(n + 1, vector<int>());
    for(int i = 0; i < truecount; i++)
    {
        int trueidx;
        cin >> trueidx;
        knowpeople[trueidx] = true;
    }
    vector<vector<int>> tmplist(m); // 각 파티의 사람 임시리스트(검사용)
    for(int i = 0; i < m; i++)
    {
        int partypeoplenum;
        cin >> partypeoplenum;
        for(int j = 0; j < partypeoplenum; j++)
        {
            int tmp;
            cin >> tmp;
            tmplist[i].push_back(tmp);
        }
        makegraph(tmplist[i]);
    }
    for(int i = 1; i <= knowpeople.size(); i++)
    {
        if(knowpeople[i])
        {
            dfs(i);
        }
    }
    for(int i = 0; i < m; i++)
    {
        bool flag = false;
        for(int j = 0; j < tmplist[i].size(); j++)
        {
            if(knowpeople[tmplist[i][j]] == true)
            {
                flag = true;
                break;
            }
        }
        if(!flag)
        {
            ans++;
        }
    }
    cout << ans;
}
