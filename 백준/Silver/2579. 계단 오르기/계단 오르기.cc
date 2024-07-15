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
    cin >> n;
    stairs.resize(n + 1);
    score.resize(n + 1,0);
    for(int i = 0; i < n; i++)
    {
        cin >> stairs[i];
    }
    score[0] = stairs[0];
    score[1] = stairs[1] + stairs[0];
    score[2] = max(stairs[0] + stairs[2],stairs[1] + stairs[2]);

    for(int i = 3; i < n; i++)
    {
        score[i] = max(score[i - 2] + stairs[i], score[i - 3] + stairs[i] + stairs[i - 1]);
    }

    cout << score[n - 1];
    return 0;
}