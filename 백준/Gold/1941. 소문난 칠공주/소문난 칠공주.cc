#include <bits/stdc++.h>

using namespace std;

vector<int> comb(7);
bool visited[25];
int ans = 0;
vector<vector<char>> stumap(5,vector<char>(5));
vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool check(vector<int> arr)
{
    int scount = 0;
    int ycount = 0;
    for(int i = 0; i < 7; i++)
    {
        if(stumap[arr[i] / 5][arr[i] % 5] == 'Y')
        {
            ycount++;
        }
        else
        {
            scount++;
        }
    }
    return (scount >= 4) ? true : false;
}

bool bfs(vector<int> arr)
{
    queue<int> q;
    vector<bool> connected(7, false);
    q.push(0);
    connected[0] = true;
    int connectcount = 1;

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        int cur_x = arr[current] / 5;
        int cur_y = arr[current] % 5;

        for (auto dir : directions)
        {
            int new_x = cur_x + dir.first;
            int new_y = cur_y + dir.second;

            for (int i = 0; i < 7; i++)
            {
                if (!connected[i] && new_x == arr[i] / 5 && new_y == arr[i] % 5)
                {
                    connected[i] = true;
                    q.push(i);
                    connectcount++;
                }
            }
        }
    }

    if(connectcount == 7)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void com(int cur, int start)
{
    if (cur == 7)
    {
        if (check(comb))
        {
            if (bfs(comb))
            {
                ans++;
            }
        }
        return;
    }
    for (int i = start; i < 25; i++)
    {
        if (!visited[i])
        {
            comb[cur] = i;
            visited[i] = true;
            com(cur + 1, i + 1);
            visited[i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 0; i < 5; i++)
    {
		string s;
		cin >> s;
		for (int j = 0; j < 5; j++)
        {
			stumap[i][j] = s[j];
		}
	}
    com(0,0);
    cout << ans;
}