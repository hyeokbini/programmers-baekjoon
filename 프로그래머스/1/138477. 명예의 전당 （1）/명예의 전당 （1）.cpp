#include <string>
#include <vector>
#include <algorithm>


using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> arr;
    if(score.size() > k)
    {
        for(int i = 0; i < k; i++)
        {
            arr.push_back(score[i]);
            sort(arr.begin(),arr.end());
            answer.push_back(arr[0]);
        }
        for(int i = k; i < score.size(); i++)
        {
            arr.push_back(score[i]);
            sort(arr.begin(),arr.end(),greater<>());
            answer.push_back(arr[k - 1]);
            arr.pop_back();
        }
    }
    else
    {
        for(int i = 0; i < score.size(); i++)
        {
            arr.push_back(score[i]);
            sort(arr.begin(),arr.end());
            answer.push_back(arr[0]);
        }
    }
    return answer;
}