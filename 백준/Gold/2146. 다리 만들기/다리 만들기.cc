#include <bits/stdc++.h>
using namespace std;

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

int main() {
    
    int N;
    cin >> N;

    int map[N][N];
    bool visited[N][N] = {false};

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    vector<pair<int, int>> islands;
    int island_count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 1 && !visited[i][j]) {
                island_count++;
                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = true;
                map[i][j] = island_count;
                islands.push_back({i, j});

                while (!q.empty()) {
                    int y = q.front().first;
                    int x = q.front().second;
                    q.pop();

                    for (int k = 0; k < 4; k++) {
                        int ny = y + dy[k];
                        int nx = x + dx[k];

                        if (ny >= 0 && ny < N && nx >= 0 && nx < N && !visited[ny][nx]) {
                            if (map[ny][nx] == 1) {
                                q.push({ny, nx});
                                visited[ny][nx] = true;
                                map[ny][nx] = island_count;
                                islands.push_back({ny, nx});
                            }
                        }
                    }
                }
            }
        }
    }

        int min_bridge_length = INT_MAX;
        for (int i = 0; i < islands.size(); i++) {
            for (int j = i + 1; j < islands.size(); j++) {
                if (map[islands[i].first][islands[i].second] != map[islands[j].first][islands[j].second]) {
                    int bridge_length = abs(islands[i].first - islands[j].first) + abs(islands[i].second - islands[j].second) - 1;
                    min_bridge_length = min(min_bridge_length, bridge_length);
                }
            }
        }
        cout << min_bridge_length;

    return 0;
}