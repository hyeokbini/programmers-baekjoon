#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    string anstmp = "";
    vector<int> tmp;
    for(int i = 1; i < food.size(); i++)
    {
        tmp.push_back(food[i] / 2);
    }
    for(int i = 0; i < tmp.size(); i++)
    {
        for(int j = 0; j < tmp[i]; j++)
        {
            anstmp += to_string(i + 1);
        }
    }
    answer += anstmp;
    answer += '0';
    reverse(anstmp.begin(),anstmp.end());
    answer += anstmp;
    return answer;
}