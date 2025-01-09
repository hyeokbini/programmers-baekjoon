#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n;
    vector<int> mindp(3,0);
    vector<int> maxdp(3,0);
	vector<int> tmpdp(3,0);
    cin >> n;
    cin >> mindp[0] >> mindp[1] >> mindp[2];
    maxdp = mindp;
    for(int i = 1; i < n; i++)
    {
        int fir,sec,thr;
        cin >> fir >> sec >> thr;
		tmpdp = maxdp;
        maxdp[0] = max(tmpdp[0],tmpdp[1]) + fir;
        maxdp[1] = max(max(tmpdp[0],tmpdp[1]),tmpdp[2]) + sec;
        maxdp[2] = max(tmpdp[1],tmpdp[2]) + thr;
		tmpdp = mindp;
        mindp[0] = min(tmpdp[0],tmpdp[1]) + fir;
        mindp[1] = min(min(tmpdp[0],tmpdp[1]),tmpdp[2]) + sec;
        mindp[2] = min(tmpdp[1],tmpdp[2]) + thr;
    }
    cout << max(max(maxdp[0],maxdp[1]),maxdp[2]) << " " << min(min(mindp[0],mindp[1]),mindp[2]);
    return 0;
}
