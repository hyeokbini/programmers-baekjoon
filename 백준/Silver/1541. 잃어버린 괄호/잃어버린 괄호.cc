#include <bits/stdc++.h>

using namespace std;

vector<int> stairs;
vector<int> score;
int n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    
    string tmp;
    cin >> tmp;
    int ans = stoi(tmp);
    int firstopidx;
    int secondopidx;
    bool bracket = false; // 괄호 안에있는지 여부
    for(int i = 0; i < tmp.length(); i++)
    {
        if(tmp[i] == '+' || tmp[i] == '-')
        {
            firstopidx = i;
            break;
        }
    }
    int tmpnum = 0;
    while(1)
    {
        for(int i = firstopidx + 1; i <= tmp.length(); i++)
        {
            if(tmp[i] == '+' || tmp[i] == '-' || i == tmp.length())
            {
                secondopidx = i;
                break;
            }
        }
        if(tmp[firstopidx] == '-')
        {
            bracket = true;
            tmpnum += abs(stoi(tmp.substr(firstopidx,secondopidx)));
        }
        else if(tmp[firstopidx] == '+')
        {
            if(bracket)
            {
                tmpnum += abs(stoi(tmp.substr(firstopidx,secondopidx)));
            }
            else
            {
                ans += abs(stoi(tmp.substr(firstopidx,secondopidx)));
            }
        }
        if(tmp[secondopidx] == '-')
        {
            bracket = false;
            ans -= tmpnum;
            tmpnum = 0;
        }
        firstopidx = secondopidx;
        if(secondopidx == tmp.length())
        {
            if(tmpnum != 0)
            {
                ans -= tmpnum;
                break;
            }
            break;
        }
    }
    cout << ans;
    return 0;
}