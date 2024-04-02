#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int zero = 0;
    int minn = 0;
    sort(lottos.begin(),lottos.end());
    sort(win_nums.begin(),win_nums.end());
    for(int i = 0; i < 6; i++)
    {
        if(lottos[i] == 0)
        {
            zero++;
        }
    }
    for(int i = zero - 1; i < 6; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            if(lottos[i] == win_nums[j])
            {
                minn++;
            }
        }
    }
    if(minn == 0)
    {
        if(zero < 2)
        {
            answer = {6,6};
        }
        else
        {
            answer = {7 - zero, zero};
        }
    }
    else
    {
        answer = {7 - (minn + zero),7 - minn};
    }
    return answer;
}