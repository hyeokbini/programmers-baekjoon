#include <bits/stdc++.h>

using namespace std;

void func(vector<int> arr)
{
    if(arr[0] * arr[0] + arr[1] * arr[1] == arr[2] * arr[2])
    {
        cout << "right\n";
    }
    else
    {
        cout << "wrong\n";
    }
    return;
}

int main()
{
    vector<int> arr(3);
    while(1)
    {
        cin >> arr[0] >> arr[1] >> arr[2];
        sort(arr.begin(),arr.end());
        if(arr[0] == 0 && arr[1] == 0 && arr[2] == 0)
        {
            break;
        }
        func(arr);
    }
    return 0;
}
