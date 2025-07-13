#include <bits/stdc++.h>

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    vector<vector<int>> mindist(n,vector<int>(n,10000000));
    for(int i = 0; i < n; i++)
    {
        mindist[i][i] = 0;
    }
    for(int i = 0; i < fares.size(); i++)
    {
        mindist[fares[i][0] - 1][fares[i][1] - 1] = fares[i][2];
        mindist[fares[i][1] - 1][fares[i][0] - 1] = fares[i][2];
    }
    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                mindist[i][j] = min(mindist[i][j], mindist[i][k] + mindist[k][j]);
                // 플로이드-워셜 알고리즘 사용
            }
        }
    }
    int answer = mindist[s - 1][a - 1] + mindist[s - 1][b - 1];
    for(int i = 0; i < n; i++)
    {
        if(i == s - 1)
        {
            continue; // 출발지 제외
        }
        answer = min(answer,mindist[s - 1][i] + mindist[i][a - 1] + mindist[i][b - 1]);
    }
    return answer;
}