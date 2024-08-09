#include <bits/stdc++.h>

using namespace std;

int n;

void func(string &ans, int count, int val)
{
    for(int i = count - 1; i >= 0; i--)
    {
        int div = pow(2,i);
        if(val / div == 0)
        {
            ans += '4';
        }
        else if(val / div == 1)
        {
            ans += '7';
        }
        val %= div;
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int num = 0, powcount = 1, prenum;
    cin >> n; // 8
    while(1)
    {
        prenum = num;
        num += pow(2,powcount);
        if(n <= num)
        {
            break;
        }
        powcount++;
    }
    string ans = "";
    func(ans,powcount,n - prenum - 1);
    cout << ans;
    return 0;
}
