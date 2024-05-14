#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    for(int i = 1; i < words.size(); i++) 
    {
        if(words[i][0] != words[i - 1].back())
        {
            return vector<int>{i % n + 1,i / n + 1};
        }
        for(int j = 0; j < i; j++)
        {
            if(words[i] == words[j])
            {
                return vector<int>{i % n + 1,i / n + 1};
            }
        }
    }
    return vector<int>{0,0};
}