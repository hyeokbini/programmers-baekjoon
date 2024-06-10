#include <bits/stdc++.h>

using namespace std;

void minvalarrfunc(vector<int> arr, vector<long long> &minvalarr)
{
    for (int i = 0; i < 6; i++)
    {
        minvalarr[0] = min(minvalarr[0], (long long)arr[i]);
    }

    for (int i = 0; i < 6; i++)
    {
        int cantchooseidx = 5 - i;
        for (int j = 0; j < 6; j++)
        {
            if (i == j || j == cantchooseidx)
            {
                continue;
            }
            minvalarr[1] = min(minvalarr[1], (long long)(arr[i] + arr[j]));
        }
    }

    for (int i = 0; i < 6; i++)
    {
        int cantchooseidx1 = 5 - i;
        for (int j = 0; j < 6; j++)
        {
            if (j == i || j == cantchooseidx1)
            {
                continue;
            }
            int cantchooseidx2 = 5 - j;
            for (int k = 0; k < 6; k++)
            {
                if (k == cantchooseidx1 || k == cantchooseidx2 || k == j || k == i)
                {
                    continue;
                }
                minvalarr[2] = min(minvalarr[2], (long long)(arr[i] + arr[j] + arr[k]));
            }
        }
    }
    return;
}

int main()
{
    //freopen("test.txt", "rt", stdin);
    int n;
    cin >> n;
    vector<int> dice(6);
    vector<long long> minvalarr(3, LLONG_MAX);
    for (int i = 0; i < 6; i++)
    {
        cin >> dice[i];
    }
    minvalarrfunc(dice, minvalarr);
    unsigned long long ans = 0;
    if (n == 1)
    {
        // 주사위 하나일 때는 가장 큰 값을 제외한 합
        ans = accumulate(dice.begin(), dice.end(), 0LL) - *max_element(dice.begin(), dice.end());
    }
    else
    {
        ans += (5ULL * (n - 2) * (n - 2) + 4ULL * (n - 2)) * minvalarr[0];
        ans += (8ULL * (n - 2) + 4ULL) * minvalarr[1];
        ans += 4ULL * minvalarr[2];
    }

    cout << ans;
}
