#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("test.txt", "rt", stdin);
    int n;
    cin >> n;
    vector<int> arr(10001,0);
    for(int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        arr[tmp]++;
    }
    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i] == 0)
        {
            continue;
        }
        else
        {
            for(int j = 0; j < arr[i]; j++)
            {
                cout << i << "\n";
            }
        }
    }
    return 0;
}