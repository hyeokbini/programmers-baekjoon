#include <bits/stdc++.h>

using namespace std;

int n;
long long int startpoint;
vector<long long int> save;

void recur(long long int val)
{
    cout << val << " ";
    for(int i = 0; i < n; i++)
    {
        if(val % 3 == 0 && save[i] == val / 3)
        {
            recur(save[i]);
            return;
        }
        else if(save[i] % 2 == 0 && save[i] == val * 2)
        {
            recur(save[i]);
            return;
        }
    }
    return;
}

void findstart(long long int val)
{
    for(int i = 0; i < n; i++)
    {
        if(save[i] % 3 == 0 && save[i] == val * 3)
        {
            findstart(save[i]);
            return;
        }
        else if(val % 2 == 0 && save[i] == val / 2)
        {
            findstart(save[i]);
            return;
        }
    }
    startpoint = val;
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        long long int tmp;
        cin >> tmp;
        save.push_back(tmp);
    }
    findstart(save[0]);
    recur(startpoint);
    return 0;
}
