#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n;
    cin >> n;
    long long int x = 1; // 1로 끝나는 수의 개수
    long long int y = 0; // 0으로 끝나는 수의 개수
    if(n == 1)
    {
        cout << x + y;
        return 0;
    }
    for(int i = 2; i <= n; i++)
    {
        long long int tmp = y; // 변수 임시 저장
        y = x + y; // 앞의 수들이 0으로 끝나든 1로 끝나든 0으로 끝나는 경우의 수가 생김
        x = tmp; // 새로 만들어지는 1로 끝나는 수 개수는 0으로 끝나는 수의 개수
    }
    cout << x + y;
    return 0;
}
