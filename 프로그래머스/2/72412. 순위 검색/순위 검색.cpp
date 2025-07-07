#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    unordered_map<string, vector<int>> data; // (언어 + 직군 + 경력 + 푸드) string을 키로, (점수) int vector를 밸류로 하는 unordered_map
    for(int i = 0; i < info.size(); i++)
    {
        stringstream ss(info[i]); // 공백 처리를 위한 stringstream 사용
        string str1,str2,str3,str4;
        int score;
        ss >> str1 >> str2 >> str3 >> str4 >> score; // 언어 직군 경력 푸드 점수
        vector<string> arr = {str1,str2,str3,str4};
        for(int i = 0; i < 16; i++) // 4자리 이진수 비트마스킹에 필요한 경우의 수(2^4 = 16, 0000, 0001 ... 1111)
        {
            string keystring = "";
            for(int j = 0; j < 4; j++)
            {
                if(i & (1 << j)) // j번째 비트가 1이면 -, 0이면 arr[j]
                {
                    keystring += '-';
                }
                else
                {
                    keystring += arr[j];
                }
            }
            data[keystring].push_back(score);
        }
    }
    for(auto iter = data.begin(); iter != data.end(); iter++)
    {
        sort(iter->second.begin(),iter->second.end()); // 각 key에 대한 vector를 sort
    }
    for(int i = 0; i < query.size(); i++)
    {
        stringstream ss(query[i]);
        string str1,str2,str3,str4,tmp;
        int stand;
        ss >> str1 >> tmp >> str2 >> tmp >> str3 >> tmp >> str4 >> stand;
        string keystring = str1 + str2 + str3 + str4;
        if(data.find(keystring) == data.end())
        {
            answer.push_back(0); // keystring에 대한 value가 없다면 0
            continue;
        }
        vector<int> curval = data[keystring];
        int count = curval.end() - lower_bound(curval.begin(),curval.end(),stand); // lower_bound가 반환한 반복자와 end()의 거리를 int로 캐스팅
        answer.push_back(count);
    }
    return answer;
}