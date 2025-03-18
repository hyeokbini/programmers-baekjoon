#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int left, right;
    cin >> left >> right;
    int leftcount = 0, rightcount = 0;
    while(left > 1 && right > 1)
    {
        if(left >= right)
        {
            leftcount += (left / right);
            left %= right;
        }
        else
        {
            rightcount += (right / left);
            right %= left;
        }
    }
    if (left > 1)
    {
        leftcount += left - 1;
    }
    if (right > 1)
    {
        rightcount += right - 1;
    }

    cout << leftcount << " " << rightcount;
    return 0;
}
