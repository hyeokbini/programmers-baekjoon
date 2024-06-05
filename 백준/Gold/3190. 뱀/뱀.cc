#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0, 1, 0, -1}; // 초기 배열 첫값(인덱스  0)은 오른쪽, 시계방향이 D, 인덱스 증가
int dy[4] = {1, 0, -1, 0}; // 동 남 서 북
int curdir = 0; // 초기 방향값은 0
int anstime = 0;

int idx(int n)
{
    return (n % 4 + 4) % 4;
}

void func(vector<vector<int>> &map, vector<pair<int, char>> snakeval)
{
    int validx = 0; // 뱀의 이동 배열을 읽을 인덱스
    pair<int,int> snakehead = {0,0};
    queue<pair<int,int>> Q; // 꼬리 저장할 큐
    Q.push({0,0});
    while (1)
    {
        anstime++;
        map[snakehead.first][snakehead.second] = 1;
        snakehead.first += dx[curdir];
        snakehead.second += dy[curdir];
        if (snakehead.first < 0 || snakehead.second < 0 || snakehead.first >= map.size() || snakehead.second >= map.size() || map[snakehead.first][snakehead.second] == 1)
        {
            return; // 게임오버
        }
        Q.push({snakehead.first,snakehead.second});
        if(map[snakehead.first][snakehead.second] != 2)
        {
            pair<int,int> snakeend = Q.front();
            Q.pop();
            map[snakeend.first][snakeend.second] = 0;
        }
        if(snakeval[validx].first == anstime) // 방향전환 
        {
            if(snakeval[validx].second == 'D')
            {
                curdir = idx(curdir + 1);
            }
            else
            {
                curdir = idx(curdir - 1);
            }
            validx++;
        }
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> map(n, vector<int>(n, 0));
    for (int i = 0; i < k; i++)
    {
        int tmpx;
        int tmpy;
        cin >> tmpx >> tmpy;
        map[tmpx - 1][tmpy - 1] = 2;
    }
    int snakerotcount;
    cin >> snakerotcount;
    vector<pair<int, char>> snakeval;
    for (int i = 0; i < snakerotcount; i++)
    {
        int tmp;
        char tmpchar;
        cin >> tmp >> tmpchar;
        snakeval.push_back(make_pair(tmp,tmpchar));
    }
    func(map,snakeval);
    cout << anstime;
    return 0;
}
