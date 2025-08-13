#include <bits/stdc++.h>
using namespace std;

int amax, bmax;
vector<vector<int>> v;
int dp[101][101][101];

int solve(int i, int a, int b) {
    // A나 B가 임계치 이상이면 가지치기
    if (a >= amax || b >= bmax) return INT_MAX;

    // 모든 물건 처리 완료 → 현재 A 흔적이 결과
    if (i == (int)v.size()) return a;

    // 이미 계산된 상태면 바로 반환
    if (dp[i][a][b] != -1) return dp[i][a][b];

    // 선택 1: A가 훔침
    int takeA = solve(i + 1, a + v[i][0], b);

    // 선택 2: B가 훔침
    int takeB = solve(i + 1, a, b + v[i][1]);

    // 두 경우 중 A 흔적이 더 작은 경우 저장
    dp[i][a][b] = min(takeA, takeB);
    return dp[i][a][b];
}

int solution(vector<vector<int>> info, int n, int m) {
    amax = n;
    bmax = m;
    v = info;
    memset(dp, -1, sizeof(dp));

    int ans = solve(0, 0, 0);
    if (ans == INT_MAX) return -1;
    return ans;
}
