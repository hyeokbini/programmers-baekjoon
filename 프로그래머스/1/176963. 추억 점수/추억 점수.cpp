#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    map<string,int> arr;
    for(int i = 0; i < name.size(); i++)
    {
        arr.insert({name[i],yearning[i]});
    }
    for(int i = 0; i < photo.size(); i++)
    {
        int tmp = 0;
        for(auto j : photo[i])
        {
            for(auto k : arr)
            {
                if(j == k.first)
                {
                    tmp += k.second;
                }
            }
        }
        answer.push_back(tmp);
    }
    return answer;
}