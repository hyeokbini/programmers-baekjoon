#include <bits/stdc++.h>

using namespace std;

void fun(int n, int m, int curidx, int curnum, vector<int> arr)
{
    if(arr.size() == m)
    {
        for(int i = 0; i < arr.size(); i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    if(curnum > n)
    {
        return;
    }
    arr.push_back(curnum);
    fun(n,m,curidx + 1,curnum + 1,arr);
    arr.pop_back();
    fun(n,m,curidx,curnum + 1,arr);
}
int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> arr;
    fun(n,m,0,1,arr);
}