#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) // 테스트 케이스의 개수만큼 반복
    {
        int M, N, K;
        cin >> M >> N >> K;
        
        vector<vector<int>> map(N, vector<int>(M, 0)); // M과 N을 반대로 사용하여 초기화
        vector<vector<bool>> vis(N, vector<bool>(M, false)); // M과 N을 반대로 사용하여 초기화

        for (int i = 0; i < K; i++)
        {
            int x, y;
            cin >> x >> y;
            map[y][x] = 1; // (y, x)로 배열에 값을 설정
        }

        int answer = 0;

        for (int i = 0; i < N; i++) // N으로 바꿔서 변경
        {
            for (int j = 0; j < M; j++) // M으로 바꿔서 변경
            {
                if (map[i][j] == 0 || vis[i][j] == true) // 인덱스 접근 부분 수정
                    continue;

                answer++;

                queue<pair<int, int>> Q;
                vis[i][j] = true;
                Q.push({i, j});

                while (!Q.empty())
                {
                    pair<int, int> cur = Q.front();
                    Q.pop();

                    for (int k = 0; k < 4; k++)
                    {
                        int nx = cur.first + dx[k];
                        int ny = cur.second + dy[k];

                        if (nx < 0 || ny < 0 || nx >= N || ny >= M) // 인덱스 범위 검사 수정
                            continue;

                        if (map[nx][ny] == 0 || vis[nx][ny] == true)
                            continue;

                        vis[nx][ny] = true;
                        Q.push({nx, ny});
                    }
                }
            }
        }

        cout << answer << "\n";
    }

    return 0;
}
