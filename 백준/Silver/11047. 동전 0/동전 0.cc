#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, k, idx, ans = 0;
	//freopen("test.txt", "rt", stdin);
	cin >> n >> k;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		if (arr[i] <= k)
		{
			idx = i;
		}
	}
	while (1)
	{
		if (k % arr[idx] == 0)
		{
			ans += k / arr[idx];
			break;
		}
		else
		{
			ans += k / arr[idx];
			k %= arr[idx];
			idx--;
		}
	}
	cout << ans;
}
