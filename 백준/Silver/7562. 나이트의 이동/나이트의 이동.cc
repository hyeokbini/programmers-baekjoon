#include <bits/stdc++.h>

using namespace std;

int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};

int knight_moves(int l, pair<int, int> start, pair<int, int> end) {
    vector<vector<bool>> visited(l, vector<bool>(l, false));
    queue<pair<pair<int, int>, int>> q;
    q.push({start, 0});
    visited[start.first][start.second] = true;

    while (!q.empty()) {
        pair<pair<int, int>, int> cur = q.front();
        q.pop();
        if (cur.first == end) {
            return cur.second;
        }
        for (int i = 0; i < 8; ++i) {
            int nx = cur.first.first + dx[i];
            int ny = cur.first.second + dy[i];
            if (nx >= 0 && nx < l && ny >= 0 && ny < l && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({{nx, ny}, cur.second + 1});
            }
        }
    }
    return -1;
}

int main() {
    int cases;
    cin >> cases;

    vector<pair<int, pair<pair<int, int>, pair<int, int>>>> tests;

    for (int i = 0; i < cases; ++i) {
        int l;
        cin >> l;
        pair<int, int> start, end;
        cin >> start.first >> start.second;
        cin >> end.first >> end.second;
        tests.push_back({l, {start, end}});
    }

    for (const auto &test : tests) {
        int l = test.first;
        pair<int, int> start = test.second.first;
        pair<int, int> end = test.second.second;

        if (start == end) {
            cout << 0 << endl;
            continue;
        }

        cout << knight_moves(l, start, end) << endl;
    }

    return 0;
}
