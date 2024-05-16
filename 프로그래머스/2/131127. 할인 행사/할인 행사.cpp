#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    unordered_map <string,int> map1;
    vector<int> arr(number.size(),0);
    bool check = true;
    for(int i = 0; i < number.size(); i++)
    {
        map1.insert(make_pair(want[i],i));
    }
    for(int i = 0; i < discount.size() - 9; i++)
    {
        for(int j = i; j < i + 10; j++)
        {
            if(map1.find(discount[j]) != map1.end())
            {
                arr[map1[discount[j]]]++;
            }
        }
        for(int j = 0; j < number.size(); j++)
        {
            if(number[j] != arr[j])
            {
                check = false;
                break;
            }
        }
        if(check)
        {
            answer++;
        }
        check = true;
        fill(arr.begin(), arr.end(), 0);
    }
    return answer;
}