#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    unordered_map <string,long long int> arr;
    long long int a,b,c;
    cin >> a >> b >> c;
    for(int i = 0; i < b; i++)
    {
        string tmp;
        long long int val;
        cin >> tmp >> val;
        arr.insert({tmp,val});
    }
    long long int check = 0;
    for(int i = 0; i < c; i++)
    {
        string tmp;
        cin >> tmp;
        check += arr[tmp];
    }
    if(a >= check)
    {
        cout << "acceptable";
    }
    else
    {
        cout << "unacceptable";
    }
    return 0;
}