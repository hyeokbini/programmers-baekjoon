#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("test.txt", "rt", stdin);
    int n, maxsize = 0;
    vector<int> used(10,0);
    cin >> n;
    queue<int> Q;
    while(n--)
    {
        int tmp;
        cin >> tmp;
        used[tmp]++;
        Q.push(tmp);
        int usecount = 0;
        for(int i = 0; i < 10; i++)
        {
            if(used[i])
            {
                usecount++;
            }
        }
        if(usecount > 2)
        {
            int deleteval = Q.front();
            while(Q.front() == deleteval)
            {
                Q.pop();
                used[deleteval]--;
            }
        }
        maxsize = max((int)Q.size(),maxsize);
    }
    cout << maxsize;
}