#include <bits/stdc++.h>

using namespace std;

void fun(vector<int> arr, vector<int> ans, int count)
{
    if(count == ans.size())
    {
        for(int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = 0; i < arr.size(); i++)
    {
        ans[count] = arr[i];
        fun(arr,ans,count + 1);
    }
}

int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> arr;
    vector<int> ans(m);
    for(int i = 1; i <= n; i++)
    {
        arr.push_back(i);
    }
    fun(arr,ans,0);
}