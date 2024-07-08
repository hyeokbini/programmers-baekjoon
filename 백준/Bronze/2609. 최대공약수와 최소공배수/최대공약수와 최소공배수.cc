#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
    int c;
    while(b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int a, b;
    cin >> a >> b;
    if(b > a)
    {
        swap(a,b);
    }
    int gcdval = gcd(a,b);
    cout << gcdval << "\n";
    cout << a * b / gcdval; 
    return 0;
}
