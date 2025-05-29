#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int chocolate = 0;
    int r, c, k;
    cin >> r >> c >> k;
    vector<vector<int>> arr(r, vector<int>(c, 0));
    vector<vector<int>> record(r, vector<int>(c, 0));
    queue<tuple<int, int, int>> heaterQ;
    vector<pair<int, int>> checkarea;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 1 || arr[i][j] == 2 || arr[i][j] == 3 || arr[i][j] == 4)
            {
                // 큐에 온풍기 push
                heaterQ.push({i, j, arr[i][j]});
            }
            if (arr[i][j] == 5)
            {
                // 체크해야 할 곳 기록
                checkarea.push_back({i, j});
            }
        }
    }
    int w;
    cin >> w;
    vector<vector<int>> walllist(r, vector<int>(c, -1));
    for (int i = 0; i < w; i++)
    {
        int x, y, val;
        cin >> x >> y >> val;
        if (walllist[x - 1][y - 1] != -1)
        {
            // 두 조건 다 겹치는 경우는 2로 처리
            walllist[x - 1][y - 1] = 2;
        }
        else
        {
            walllist[x - 1][y - 1] = val;
        }
    }
    while (1)
    {
        // 1. 온풍기에서 바람 발사
        int count = heaterQ.size();
        while (count--)
        {
            auto curheater = heaterQ.front();
            heaterQ.pop();
            int curheaterx = get<0>(curheater);
            int curheatery = get<1>(curheater);
            int curheaterdir = get<2>(curheater);
            if (curheaterdir == 1)
            {
                if (curheatery + 1 >= c)
                {
                    continue;
                }
                // 원뿔 모양으로 바람 분사(x,y,온도,방향)
                queue<tuple<int, int, int, int>> windQ;
                vector<vector<bool>> visited(r, vector<bool>(c, false));
                windQ.push({curheaterx, curheatery + 1, 5, curheaterdir});
                visited[curheaterx][curheatery + 1] = true;
                record[curheaterx][curheatery + 1] += 5;
                while (!windQ.empty())
                {
                    auto curwind = windQ.front();
                    int curwindx = get<0>(curwind);
                    int curwindy = get<1>(curwind);
                    int curwindtemp = get<2>(curwind);
                    windQ.pop();
                    // 오른쪽 위
                    if (curwindx - 1 >= 0 && curwindy + 1 < c && curwindtemp != 0)
                    {
                        if (walllist[curwindx][curwindy] != 0 && walllist[curwindx][curwindy] != 2 && walllist[curwindx - 1][curwindy] != 1 && walllist[curwindx - 1][curwindy] != 2 && visited[curwindx - 1][curwindy + 1] != true)
                        {
                            visited[curwindx - 1][curwindy + 1] = true;
                            record[curwindx - 1][curwindy + 1] += curwindtemp - 1;
                            windQ.push({curwindx - 1, curwindy + 1, curwindtemp - 1, curheaterdir});
                        }
                    }

                    // 오른쪽
                    if (curwindy + 1 < c && curwindtemp != 0)
                    {
                        if (walllist[curwindx][curwindy] != 1 && walllist[curwindx][curwindy] != 2 && visited[curwindx][curwindy + 1] != true)
                        {
                            visited[curwindx][curwindy + 1] = true;
                            record[curwindx][curwindy + 1] += curwindtemp - 1;
                            windQ.push({curwindx, curwindy + 1, curwindtemp - 1, curheaterdir});
                        }
                    }

                    // 오른쪽 아래
                    if (curwindx + 1 < r && curwindy + 1 < c && curwindtemp != 0)
                    {
                        if (walllist[curwindx + 1][curwindy] != 1 && walllist[curwindx + 1][curwindy] != 2 && walllist[curwindx + 1][curwindy] != 0 && visited[curwindx + 1][curwindy + 1] != true)
                        {
                            visited[curwindx + 1][curwindy + 1] = true;
                            record[curwindx + 1][curwindy + 1] += curwindtemp - 1;
                            windQ.push({curwindx + 1, curwindy + 1, curwindtemp - 1, curheaterdir});
                        }
                    }
                }
            }
            if (curheaterdir == 2)
            {
                if (curheatery - 1 < 0)
                {
                    continue;
                }
                // 원뿔 모양으로 바람 분사(x,y,온도,방향)
                queue<tuple<int, int, int, int>> windQ;
                vector<vector<bool>> visited(r, vector<bool>(c, false));
                windQ.push({curheaterx, curheatery - 1, 5, curheaterdir});
                visited[curheaterx][curheatery - 1] = true;
                record[curheaterx][curheatery - 1] += 5;
                while (!windQ.empty())
                {
                    auto curwind = windQ.front();
                    int curwindx = get<0>(curwind);
                    int curwindy = get<1>(curwind);
                    int curwindtemp = get<2>(curwind);
                    windQ.pop();
                    // 왼쪽 위
                    if (curwindx - 1 >= 0 && curwindy - 1 >= 0 && curwindtemp != 0)
                    {
                        if (walllist[curwindx][curwindy] != 0 && walllist[curwindx][curwindy] != 2 && walllist[curwindx - 1][curwindy - 1] != 1 && walllist[curwindx - 1][curwindy - 1] != 2 && visited[curwindx - 1][curwindy - 1] != true)
                        {
                            visited[curwindx - 1][curwindy - 1] = true;
                            record[curwindx - 1][curwindy - 1] += curwindtemp - 1;
                            windQ.push({curwindx - 1, curwindy - 1, curwindtemp - 1, curheaterdir});
                        }
                    }

                    // 왼쪽
                    if (curwindy - 1 >= 0 && curwindtemp != 0)
                    {
                        if (walllist[curwindx][curwindy - 1] != 1 && walllist[curwindx][curwindy - 1] != 2 && visited[curwindx][curwindy - 1] != true)
                        {
                            visited[curwindx][curwindy - 1] = true;
                            record[curwindx][curwindy - 1] += curwindtemp - 1;
                            windQ.push({curwindx, curwindy - 1, curwindtemp - 1, curheaterdir});
                        }
                    }

                    // 왼쪽 아래
                    if (curwindx + 1 < r && curwindy - 1 >= 0 && curwindtemp != 0)
                    {
                        if (walllist[curwindx + 1][curwindy - 1] != 1 && walllist[curwindx + 1][curwindy - 1] != 2 && walllist[curwindx + 1][curwindy] != 0 && walllist[curwindx + 1][curwindy] != 2 && visited[curwindx + 1][curwindy - 1] != true)
                        {
                            visited[curwindx + 1][curwindy - 1] = true;
                            record[curwindx + 1][curwindy - 1] += curwindtemp - 1;
                            windQ.push({curwindx + 1, curwindy - 1, curwindtemp - 1, curheaterdir});
                        }
                    }
                }
            }
            if (curheaterdir == 3)
            {
                if (curheaterx - 1 < 0)
                {
                    continue;
                }
                // 원뿔 모양으로 바람 분사(x,y,온도)
                queue<tuple<int, int, int, int>> windQ;
                vector<vector<bool>> visited(r, vector<bool>(c, false));
                windQ.push({curheaterx - 1, curheatery, 5, curheaterdir});
                visited[curheaterx - 1][curheatery] = true;
                record[curheaterx - 1][curheatery] += 5;
                while (!windQ.empty())
                {
                    auto curwind = windQ.front();
                    int curwindx = get<0>(curwind);
                    int curwindy = get<1>(curwind);
                    int curwindtemp = get<2>(curwind);
                    windQ.pop();
                    // 왼쪽 위
                    if (curwindx - 1 >= 0 && curwindy - 1 >= 0 && curwindtemp != 0)
                    {
                        if (walllist[curwindx][curwindy - 1] != 1 && walllist[curwindx][curwindy - 1] != 2 && walllist[curwindx][curwindy - 1] != 0 && visited[curwindx - 1][curwindy - 1] != true)
                        {
                            visited[curwindx - 1][curwindy - 1] = true;
                            record[curwindx - 1][curwindy - 1] += curwindtemp - 1;
                            windQ.push({curwindx - 1, curwindy - 1, curwindtemp - 1, curheaterdir});
                        }
                    }

                    // 위
                    if (curwindx - 1 >= 0 && curwindtemp != 0)
                    {
                        if (walllist[curwindx][curwindy] != 0 && walllist[curwindx][curwindy] != 2 && visited[curwindx - 1][curwindy] != true)
                        {
                            visited[curwindx - 1][curwindy] = true;
                            record[curwindx - 1][curwindy] += curwindtemp - 1;
                            windQ.push({curwindx - 1, curwindy, curwindtemp - 1, curheaterdir});
                        }
                    }

                    // 오른쪽 위
                    if (curwindx - 1 >= 0 && curwindy + 1 < c && curwindtemp != 0)
                    {
                        if (walllist[curwindx][curwindy] != 1 && walllist[curwindx][curwindy] != 2 && walllist[curwindx][curwindy + 1] != 0 && walllist[curwindx][curwindy + 1] != 2 && visited[curwindx - 1][curwindy + 1] != true)
                        {
                            visited[curwindx - 1][curwindy + 1] = true;
                            record[curwindx - 1][curwindy + 1] += curwindtemp - 1;
                            windQ.push({curwindx - 1, curwindy + 1, curwindtemp - 1, curheaterdir});
                        }
                    }
                }
            }
            if (curheaterdir == 4)
            {
                if (curheaterx + 1 >= r)
                {
                    continue;
                }
                // 원뿔 모양으로 바람 분사(x,y,온도)
                queue<tuple<int, int, int, int>> windQ;
                vector<vector<bool>> visited(r, vector<bool>(c, false));
                windQ.push({curheaterx + 1, curheatery, 5, curheaterdir});
                visited[curheaterx + 1][curheatery] = true;
                record[curheaterx + 1][curheatery] += 5;
                while (!windQ.empty())
                {
                    auto curwind = windQ.front();
                    int curwindx = get<0>(curwind);
                    int curwindy = get<1>(curwind);
                    int curwindtemp = get<2>(curwind);
                    windQ.pop();
                    // 왼쪽 아래
                    if (curwindx + 1 < r && curwindy - 1 >= 0 && curwindtemp != 0)
                    {
                        if (walllist[curwindx][curwindy - 1] != 1 && walllist[curwindx][curwindy - 1] != 2 && walllist[curwindx + 1][curwindy - 1] != 0 && walllist[curwindx + 1][curwindy - 1] != 2 && visited[curwindx + 1][curwindy - 1] != true)
                        {
                            visited[curwindx + 1][curwindy - 1] = true;
                            record[curwindx + 1][curwindy - 1] += curwindtemp - 1;
                            windQ.push({curwindx + 1, curwindy - 1, curwindtemp - 1, curheaterdir});
                        }
                    }

                    // 아래
                    if (curwindx + 1 < r && curwindtemp != 0)
                    {
                        if (walllist[curwindx + 1][curwindy] != 0 && walllist[curwindx + 1][curwindy] != 2 && visited[curwindx + 1][curwindy] != true)
                        {
                            visited[curwindx + 1][curwindy] = true;
                            record[curwindx + 1][curwindy] += curwindtemp - 1;
                            windQ.push({curwindx + 1, curwindy, curwindtemp - 1, curheaterdir});
                        }
                    }

                    // 오른쪽 아래
                    if (curwindx + 1 < r && curwindy + 1 < c && curwindtemp != 0)
                    {
                        if (walllist[curwindx][curwindy] != 1 && walllist[curwindx][curwindy] != 2 && walllist[curwindx + 1][curwindy + 1] != 0 && walllist[curwindx + 1][curwindy + 1] != 2 && visited[curwindx + 1][curwindy + 1] != true)
                        {
                            visited[curwindx + 1][curwindy + 1] = true;
                            record[curwindx + 1][curwindy + 1] += curwindtemp - 1;
                            windQ.push({curwindx + 1, curwindy + 1, curwindtemp - 1, curheaterdir});
                        }
                    }
                }
            }

            heaterQ.push(curheater);
        }

        // 2. 온도 조절
        // 원본 벡터를 손상시키지 않기 위한 복사본 생성(record에서 연산하고, 기록은 temparr에)
        vector<vector<int>> tempMap(r, vector<int>(c, 0));

        for (int x = 0; x < r; x++)
        {
            for (int y = 0; y < c; y++)
            {
                // 오른쪽 (x, y) → (x, y + 1)
                if (y + 1 < c)
                {
                    bool rightBlocked = (walllist[x][y] == 1 || walllist[x][y] == 2);
                    if (!rightBlocked)
                    {
                        int diff = abs(record[x][y] - record[x][y + 1]) / 4;
                        if (record[x][y] > record[x][y + 1])
                        {
                            tempMap[x][y] -= diff;
                            tempMap[x][y + 1] += diff;
                        }
                        else if (record[x][y] < record[x][y + 1])
                        {
                            tempMap[x][y] += diff;
                            tempMap[x][y + 1] -= diff;
                        }
                    }
                }

                // 아래 (x, y) → (x + 1, y)
                if (x + 1 < r)
                {
                    bool downBlocked = (walllist[x + 1][y] == 0 || walllist[x + 1][y] == 2);
                    if (!downBlocked)
                    {
                        int diff = abs(record[x][y] - record[x + 1][y]) / 4;
                        if (record[x][y] > record[x + 1][y])
                        {
                            tempMap[x][y] -= diff;
                            tempMap[x + 1][y] += diff;
                        }
                        else if (record[x][y] < record[x + 1][y])
                        {
                            tempMap[x][y] += diff;
                            tempMap[x + 1][y] -= diff;
                        }
                    }
                }
            }
        }

        // 변화 반영
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                record[i][j] += tempMap[i][j];
            }
        }
        // 3. 바깥쪽 온도 감소
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (i == 0 || j == 0 || i == r - 1 || j == c - 1)
                {
                    if (record[i][j] > 0)
                    {
                        record[i][j]--;
                    }
                }
            }
        }
        // 4. 초콜릿
        chocolate++;
        if(chocolate > 100)
        {
            cout << 101;
            return 0;
        }
        // 5. 검사
        bool flag = true;
        for (int i = 0; i < checkarea.size(); i++)
        {
            if (record[checkarea[i].first][checkarea[i].second] < k)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            cout << chocolate;
            return 0;
        }
    }
    return 0;
}
