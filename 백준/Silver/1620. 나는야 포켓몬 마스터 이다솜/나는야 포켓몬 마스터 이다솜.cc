#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n,m,num = 1;
    cin >> n >> m;
    unordered_map <string,int> stringarr;
    unordered_map <int,string> intarr;
    while(n--)
    {
        string tmp;
        cin >> tmp;
        stringarr.insert({tmp,num});
        intarr.insert({num,tmp});
        num++;
    }
    while(m--)
    {
        string tmp;
        cin >> tmp;
        if(atoi(tmp.c_str()) != 0)
        {
            cout << intarr[atoi(tmp.c_str())] << "\n";
        }
        else
        {
            cout << stringarr[tmp] << "\n";
        }
    }
    return 0;
}