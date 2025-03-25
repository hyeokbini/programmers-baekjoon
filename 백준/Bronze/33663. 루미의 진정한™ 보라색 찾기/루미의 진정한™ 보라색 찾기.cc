#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    double hl, hh, sl, sh, vl, vh;
    double r,g,b;
    cin >> hl >> hh >> sl >> sh >> vl >> vh >> r >> g >> b;
    double M = max({r,g,b});
    double m = min({r,g,b});
    double S = 255 * ((M - m) / M);
    double H;
    if(M == r)
    {
        H = (60 * (g - b) / (M - m));
    }
    else if(M == g)
    {
        H = 120 + (60 * (b - r) / (M - m));
    }
    else
    {
        H = 240 + (60 * (r - g) / (M - m));
    }
    if(H < 0)
    {
        H += 360;
    }
    if(hl <= H && hh >= H && sl <= S && sh >= S && vl <= M && vh >= M)
    {
        cout << "Lumi will like it.";
    }
    else
    {
        cout << "Lumi will not like it.";
    }
    return 0;
}