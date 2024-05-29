#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> elements) {
    vector<int> ans;
    int tmpans = 0;
    for(int i = 1; i <= elements.size(); i++) // 만들 수열 원소 개수(예시에서는 1~5)
    {
        for(int j = 0; j < elements.size(); j++) //인덱스 따라 반복횟수(예시에서는 5)
        {
            for(int k = j; k < j + i; k++) // 인덱스
            {
                int idx = k % elements.size();
                tmpans += elements[idx];
            }
            ans.push_back(tmpans);
            tmpans = 0;
        }
    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()),ans.end());
    return ans.size();
}