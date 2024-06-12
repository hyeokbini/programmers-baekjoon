#include <bits/stdc++.h>

using namespace std;

int r,c;
int ans = 0;

void func(int x, int y, int len)
{
    if(len == 0)
    {
        return;
    }
    int halflen = len / 2;
    if(x <= r && r < x + halflen && y <= c && c < y + halflen)
    {
        func(x,y,halflen);
    }
    else if(x <= r && r < x + halflen && y + halflen <= c && c < y + len)
    {
        ans += (halflen * halflen);
        func(x,y + halflen, halflen);
    }
    else if(x + halflen <= r && r < x + len && y <= c && c < y + halflen)
    {
        ans += (halflen * halflen) * 2;
        func(x + halflen ,y, halflen);
    }
    else if(x + halflen <= r && r < x + len && y + halflen <= c && c < y + len)
    {
        ans += (halflen * halflen) * 3;
        func(x + halflen ,y + halflen, halflen);
    }
}

int main()
{
    //freopen("test.txt","rt",stdin);
    int n;
    cin >> n >> r >> c;
    int len = pow(2,n);
    func(0,0,len);
    cout << ans;
    return 0;
}
