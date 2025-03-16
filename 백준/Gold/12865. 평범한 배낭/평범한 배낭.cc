#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n,k;
    cin >> n >> k;
    vector<vector<int>> DP(n + 1,vector<int>(k + 1,0)); // 가로 인덱스는 가방 단위별 무게, 세로 인덱스는 물건의 인덱스
    vector<int> weight(n + 1); // 각 물건의 무게. DP인덱스와 인덱스 동일
    vector<int> value(n + 1); // 각 물건의 가치
    for(int i = 1; i <= n; i++)
    {
        cin >> weight[i] >> value[i];
    }
    for(int i = 1; i <= n; i++) // 물건을 순차적으로 하나씩 훑으면서
    {
        for(int j = 1; j <= k; j++) // 단위무게별 물건 넣기 판단 여부 갱신
        {
            if(weight[i] > j) // 누적 단위무게보다 물건이 큰 경우(못 넣음)
            {
                DP[i][j] = DP[i - 1][j]; // 앞 값 들고오기
            }
            else
            {
                DP[i][j] = max(DP[i - 1][j], value[i] + DP[i - 1][j - weight[i]]); // (이 물건을 제외한 가방 탐색값 최대치 + 물건의 가치)와 (이 물건을 넣지 않았을 때의 값) 중 최대치 갱신
            }
        }
    }
    cout << DP[n][k];
    return 0;
}
