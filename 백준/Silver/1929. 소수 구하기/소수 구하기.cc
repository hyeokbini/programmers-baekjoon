#include <bits/stdc++.h>

using namespace std;

void func(int m, int n) {
    vector<bool> check(n+1,true);
    int answer = 0;
    for(int i = 2; i <= n; i++)
    {
        if(check[i] == true)
        {
            for(int j = 2; i*j <= n; j++)
            {
                check[i*j] = false;
            }
        }
    }
    for(int i = m; i <= n; i++)
    {
        if(i != 1 && check[i])
        {
            cout << i << "\n";
        }
    }
    return;
}

int main()
{
    //freopen("test.txt", "rt", stdin);
    int n,m;
    cin >> m >> n;
    func(m,n);
    return 0;
}
