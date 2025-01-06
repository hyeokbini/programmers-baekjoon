#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("test.txt", "rt", stdin);
	int n, subval, standval = 1;
	cin >> n;
	vector<int> dir(6);
	vector<int> dist(6);
	vector<bool> used(5, false);
	for(int i = 0; i < 6; i++)
	{
		cin >> dir[i] >> dist[i];
	}
	for(int i = 0; i < 6; i++)
	{
		if(dir[i % 6] == dir[(i + 2) % 6] && dir[(i + 1) % 6] == dir[(i + 3) % 6])
		{
			subval = dist[(i + 1) % 6] * dist[(i + 2) % 6];
			used[dir[i % 6]] = true;
			used[dir[(i + 1) % 6]] = true;
			break;
		}
	}
	for(int i = 0; i < 6; i++)
	{
		if(!used[dir[i]])
		{
			standval *= dist[i];
		}
	}
	cout << (standval - subval) * n;
	return 0;
}
