#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    double maxval = -1;
    cin >> n;
    vector<double> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if(arr[i] > maxval)
        {
            maxval = arr[i];
        }
    }
    for(int i = 0; i < n; i++)
    {
        arr[i] = (arr[i] / maxval) * 100;
    }
    double avgsum = 0;
    for(int i = 0; i < n; i++)
    {
        avgsum += arr[i];
    }
    cout << avgsum / n;
    return 0;
}
