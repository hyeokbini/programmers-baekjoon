#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    int count = 0;
    vector<int> arr;
    sort(tangerine.begin(),tangerine.end());
    int stand = tangerine[0];
    for(int i = 0; i < tangerine.size(); i++)
    {
        if(tangerine[i] == stand)
        {
            count++;
        }
        else
        {
            arr.push_back(count);
            count = 1;
            stand = tangerine[i];
        }
        if(i == tangerine.size() - 1)
        {
            arr.push_back(count);
        }
    }
    sort(arr.begin(),arr.end(),greater<>());
    int tmpsum = 0;
    for(auto i : arr)
    {
        tmpsum += i;
        answer++;
        if(tmpsum >= k)
        {
            break;
        }
    }
    return answer;
}