#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n, moveval;
    cin >> n;
    deque<pair<int,int>> D;
    for(int i = 1; i <= n; i++)
    {
        int tmp;
        cin >> tmp;
        D.push_back({i,tmp});
    }
    while(!D.empty())
    {
        cout << D.front().first << " ";
        moveval = D.front().second;
        D.pop_front();
        if(D.empty())
        {
            break;
        }
        if(moveval > 0)
        {
            moveval--;
            for(int i = 0; i < moveval; i++)
            {
                D.push_back(D.front());
                D.pop_front();
            }
        }
        else
        {
            moveval *= -1;
            for(int i = 0; i < moveval; i++)
            {
                D.push_front(D.back());
                D.pop_back();
            }
        }
    }
    return 0;
}