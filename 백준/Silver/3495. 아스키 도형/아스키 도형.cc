#include <bits/stdc++.h>

using namespace std;

int h,w;
vector<vector<char>> arr;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int ans = 0;
    cin >> h >> w;
    arr.resize(h,vector<char>(w));
    for(int i = 0; i < h; i++)
    {
        string tmp;
        cin >> tmp;
        for(int j = 0; j < w; j++)
        {
            arr[i][j] = tmp[j];
        }
    }
    for(int i = 0; i < h; i++)
    {
        bool check = false; // 초기상태는 닫힌(넓이에 포함되지 않는)상태
        int rowval = 0;
        for(int j = 0; j < w; j++)
        {
            if(arr[i][j] == '\\' || arr[i][j] == '/')
            {
                if(!check) // 변을 만나면 상태변환
                {
                    check = true;
                }
                else
                {
                    check = false;
                    rowval++;
                }
            }
            if(check && arr[i][j] == '.')
            {
                rowval++;
            }
        }
        ans += rowval;
    }
    cout << ans;
    return 0;
}