#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> land)
{
    vector<vector<int>> arr(land.size(),vector<int>(land[0].size(),0));
    for(int i = 0; i < 4; i++)
    {
        arr[0][i] = land[0][i];
    }
    for(int i = 0; i < land.size() - 1; i++)
    {
        for(int j = 0; j < 4; j++) // i번째
        {
            for(int k = 0; k < 4; k++) // i + 1번째
            {
                if(j == k)
                {
                    continue;
                }
                else if(arr[i][j] + land[i + 1][k] > arr[i + 1][k])
                {
                    arr[i + 1][k] = arr[i][j] + land[i + 1][k];
                }
            }
        }
    }
    
    return *max_element(arr.back().begin(),arr.back().end());
}