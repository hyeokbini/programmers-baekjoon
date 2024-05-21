#include <bits/stdc++.h>

using namespace std;

#define notvisited 0
#define visited_notcycle 1
#define visited_cycle 2

void dfs(int node, vector<int> &arr, vector<int> &check)
{
    int current = node;
    vector<int> path;

    while (true)
    {
        if (check[current] == visited_cycle)
        {
            return;
        }
        else if (check[current] == visited_notcycle)
        {
            bool in_cycle = false;
            for (int n : path)
            {
                if (n == current)
                {
                    in_cycle = true;
                }
                check[n] = in_cycle ? visited_cycle : visited_notcycle;
            }
            return;
        }
        else if (check[current] == notvisited)
        {
            path.push_back(current);
            check[current] = visited_notcycle;
            current = arr[current];
        }
    }
}

int main()
{
    int t;
    cin >> t;
    vector<int> results;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n + 1);
        vector<int> check(n + 1, notvisited);
        int answer = 0;

        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }

        for (int i = 1; i <= n; i++)
        {
            if (check[i] == notvisited)
            {
                dfs(i, arr, check);
            }
        }

        for (int i = 1; i <= n; i++)
        {
            if (check[i] == visited_notcycle)
            {
                answer++;
            }
        }

        results.push_back(answer);
    }

    for (int result : results)
    {
        cout << result << "\n";
    }

    return 0;
}
