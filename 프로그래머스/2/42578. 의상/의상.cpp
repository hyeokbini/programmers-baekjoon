#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string,int> arr;
    int ans = 1;
    for(int i = 0; i < clothes.size(); i++)
    {
        if(arr.find(clothes[i][1]) != arr.end())
        {
            arr[clothes[i][1]]++;
        }
        else
        {
            arr.insert({clothes[i][1],1});
        }
    }
    for(auto i = arr.begin(); i != arr.end(); i++)
    {
        ans *= (i->second + 1);
    }
    ans--;
    return ans;
}