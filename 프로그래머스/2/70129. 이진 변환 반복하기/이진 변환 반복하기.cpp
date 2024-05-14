#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    int zerocount = 0;
    int count = 0;
    string tmp = "";
    while(1)
    {
        count++;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '0')
            {
                zerocount++;
            }
            else
            {
                tmp += '1';
            }
        }
        if(tmp == "1")
        {
            break;
        }
        int tmpint = tmp.length();
        tmp = "";
        while(tmpint > 0)
        {
            tmp += (tmpint % 2) + '0';
            tmpint /= 2;
        }
        reverse(tmp.begin(),tmp.end());
        s = tmp;
        tmp = "";
    }
    return vector<int>{count,zerocount};
}