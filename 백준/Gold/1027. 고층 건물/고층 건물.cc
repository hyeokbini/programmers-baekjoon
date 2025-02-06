#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n;
    cin >> n;
    vector<double> height(n);
    vector<int> count(n,0);
    for(int i = 0; i < n; i++)
    {
        cin >> height[i];
    }
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(i + 1 == j)
            {
                count[i]++;
                count[j]++;
                continue;
            }
            bool flag = false;
            for(int k = i + 1; k < j; k++)
            {
                double stand = ((height[i] * (j - k)) + (height[j] * (k - i))) / (j - i);
                if(height[k] >= stand)
                {
                    flag = true;
                    break;
                }
            }
            if(!flag)
            {
                count[i]++;
                count[j]++;
            }
        }
    }
    cout << *max_element(count.begin(),count.end());
}
