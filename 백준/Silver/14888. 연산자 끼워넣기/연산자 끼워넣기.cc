#include <bits/stdc++.h>

using namespace std;

int maxans = INT_MIN;
int minans = INT_MAX;

void func(vector<int> arr, vector<int> op, int count, int curval)
{
    if(count == arr.size())
    {
        maxans = max(maxans,curval);
        minans = min(minans,curval);
        return;
    }
    for(int i = 0; i < 4; i++)
    {
        if(op[i] == 0)
        {
            continue;
        }
        switch(i)
        {
            case 0:
            op[0]--;
            func(arr,op,count + 1,curval + arr[count]);
            op[0]++;
            break;

            case 1:
            op[1]--;
            func(arr,op,count + 1,curval - arr[count]);
            op[1]++;
            break;

            case 2:
            op[2]--;
            func(arr,op,count + 1,curval * arr[count]);
            op[2]++;
            break;

            case 3:
            op[3]--;
            func(arr,op,count + 1,curval / arr[count]);
            op[3]++;
            break;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> op(4);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for(int i = 0; i < 4; i++)
    {
        cin >> op[i];
    }
    func(arr,op,1,arr[0]);
    cout << maxans << "\n" << minans;
    return 0;
}