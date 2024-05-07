#include <bits/stdc++.h>

using namespace std;

struct Point {
    int x, y;
};

int N, M;
vector<vector<int>> icebergMap;
vector<vector<bool>> visited;

void bfs(Point start) {
    static const int dx[] = {-1, 1, 0, 0};
    static const int dy[] = {0, 0, -1, 1};
    queue<Point> q;
    q.push(start);
    visited[start.x][start.y] = true;

    while (!q.empty()) {
        Point current = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && icebergMap[nx][ny] > 0 && !visited[nx][ny]) {
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }
}

int findIceberg() {
    int count = 0;
    visited.assign(N, vector<bool>(M, false));

    for (int i = 1; i < N - 1; ++i) {
        for (int j = 1; j < M - 1; ++j) {
            if (icebergMap[i][j] > 0 && !visited[i][j]) {
                bfs({i, j});
                count++;
            }
        }
    }
    return count;
}

void meltIceberg() {
    vector<vector<int>> meltedMap = icebergMap;
    for (int i = 1; i < N - 1; ++i) {
        for (int j = 1; j < M - 1; ++j) {
            if (icebergMap[i][j] > 0) {
                int seaCount = 0;
                if (icebergMap[i - 1][j] == 0) seaCount++;
                if (icebergMap[i + 1][j] == 0) seaCount++;
                if (icebergMap[i][j - 1] == 0) seaCount++;
                if (icebergMap[i][j + 1] == 0) seaCount++;
                meltedMap[i][j] -= seaCount;
                if (meltedMap[i][j] < 0) meltedMap[i][j] = 0;
            }
        }
    }
    icebergMap = meltedMap;
}

int countYears() {
    int years = 0;
    while (true) {
        int icebergCount = findIceberg();
        if (icebergCount == 0) return 0; // No iceberg left
        if (icebergCount >= 2) return years; // Iceberg split
        years++;
        meltIceberg();
    }
}

int main() {
    cin >> N >> M;
    icebergMap.resize(N, vector<int>(M, 0));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> icebergMap[i][j];
        }
    }

    int years = countYears();
    cout << years << endl;

    return 0;
}
