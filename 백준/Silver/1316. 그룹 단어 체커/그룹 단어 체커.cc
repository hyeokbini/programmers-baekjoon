#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n, ans = 0;
    cin >> n;
    while(n--) // 단어 개수만큼 확인
    {
        string str;
        cin >> str;
        vector<bool> used(26); // 알파벳 사용 여부
        bool isgroupword = true;
        str.erase(unique(str.begin(), str.end()), str.end()); // 이어진 중복 원소 삭제 후 단어 사이즈 조절
        for(int i = 0; i < str.length(); i++)
        {
            int idx = str[i] - 'a'; // 아스키 코드 기반 인덱싱
            if(!used[idx])
            {
                used[idx] = true;
            }
            else
            {
                isgroupword = false;
                break;
            }
        }
        if(isgroupword)
        {
            ans++;
        }
    }
    cout << ans;
}
