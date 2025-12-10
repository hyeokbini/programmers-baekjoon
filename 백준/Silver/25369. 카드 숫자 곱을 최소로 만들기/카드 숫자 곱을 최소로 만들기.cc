#include <bits/stdc++.h>

using namespace std;

int n;
int val = 1;
bool flag = false;

void check(vector<int> arr)
{
    int tmp = 1;
    for(int i = 0; i < arr.size(); i++)
    {
        tmp *= arr[i];
    }
    if(val < tmp)
    {
        sort(arr.begin(),arr.end());
        for(int i = 0; i < arr.size(); i++)
        {
            cout << arr[i] << " ";
        }
        flag = true;
    }
    return;
}

void func(int curdepth, vector<int> arr)
{
    if(flag)
    {
        return;
    }
    if(curdepth == n)
    {
        check(arr);
        return;
    }
    for(int i = 1; i <= 9; i++)
    {
        arr.push_back(i);
        func(curdepth + 1, arr);
        arr.pop_back();
        if(flag)
        {
            return;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        val *= temp;
    }
    vector<int> arr(0);
    func(0,arr);

    if(!flag)
    {
        cout << -1;
    }
    return 0;
}
