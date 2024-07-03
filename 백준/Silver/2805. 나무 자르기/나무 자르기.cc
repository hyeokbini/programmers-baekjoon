#include <bits/stdc++.h>

using namespace std;

long long n,m;
vector<long long> trees;

int main()
{
    //freopen("test.txt", "rt", stdin);
    long long tmp;
    cin >> n >> m;
    trees.resize(n);
    for(int i = 0; i < n; i++)
    {
        cin >> tmp;
        trees[i] = tmp;
    }
    sort(trees.begin(),trees.end());
    long long start = 0;
    long long end = trees[n-1];
    long long val = 0;

    while(start <= end)
    {
        long long cur = (start + end) / 2;
        long long sum = 0;

        for(int i = 0; i < n; i++)
        {
            if(trees[i] > cur)
            {
                sum += (trees[i] - cur);
            }
        }

        if(sum >= m)
        {
            val = cur;
            start = cur + 1;
        }
        else
        {
            end = cur - 1;
        }
    }

    cout << val;
    return 0;
}