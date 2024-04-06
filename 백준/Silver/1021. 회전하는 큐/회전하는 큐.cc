#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M, tmp;
    int answer = 0;
    deque<int> arr;
    vector<int> find;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        arr.push_back(i + 1);
    }
    for (int i = 0; i < M; i++)
    {
        cin >> tmp;
        find.push_back(tmp);
    }
    for (int j = 0; j < M; j++)
    {
        int idx, num;
        num = find[j];
        for (int i = 0; i < N; i++)
        {
            if (arr[i] == num)
            {
                idx = i;
                break;
            }
        }
        if (idx < arr.size() / 2 + 1)
        {
            for (int i = 0; i < arr.size(); i++)
            {
                if (arr.front() == num)
                {
                    arr.pop_front();
                    break;
                }
                arr.push_back(arr.front());
                arr.pop_front();
                answer++;
            }
        }
        else
        {
            for (int i = 0; i < arr.size(); i++)
            {
                if (arr.front() == num)
                {
                    arr.pop_front();
                    break;
                }
                arr.push_front(arr.back());
                arr.pop_back();
                answer++;
            }
        }
    }
    cout << answer;
    return 0;
}
