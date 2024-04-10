#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    unordered_map<string,int> arr; // 인덱스를 위한 맵
    vector<vector<int>> giftmap(friends.size(), vector<int>(friends.size(),0));//주고받는 선물 확인을 위한 2차원 배열
    vector<int> giftscore(friends.size(),0);//선물지수 1차원 배열
    for(int i = 0; i < friends.size(); i++)
    {
        arr.insert(make_pair(friends[i],i));
    } // 인덱스 할당 친구이름,인덱스 순서
    for(auto i : gifts)
    {
        string give, take;
        stringstream tmp(i);
        tmp >> give >> take;
        int giveidx = arr[give];
        int takeidx = arr[take];
        giftmap[giveidx][takeidx]++;
        giftscore[giveidx]++;
        giftscore[takeidx]--;
    } // 선물 주고받은 횟수, 선물지수 입력
    vector<int> finalcheck(friends.size(),0); // 다음달 받을 선물개수 체크
    for(int i = 0; i < friends.size(); i++)
    {
        for(int j = i; j < friends.size(); j++)
        {
            if(i == j)
            {
                continue; // 스스로에게 선물 주는 경우 제외
            }
            if(giftmap[i][j] > giftmap[j][i])
            {
                finalcheck[i]++;
            }
            else if(giftmap[i][j] < giftmap[j][i])
            {
                finalcheck[j]++;
            }
            else if(giftmap[i][j] == giftmap[j][i])
            {
                if(giftscore[i] > giftscore[j])
                {
                    finalcheck[i]++;
                }
                else if(giftscore[i] < giftscore[j])
                {
                    finalcheck[j]++;
                }
                else if(giftscore[i] == giftscore[j])
                {
                    continue;
                }
            }
        }
    }
    for(auto i : finalcheck)
    {
        if(answer < i)
        {
            answer = i;
        }
    }
    return answer;
}