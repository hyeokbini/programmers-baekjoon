#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int idxsort;

bool cmp(vector<int> arr1, vector<int> arr2)
{
    return arr1[idxsort] < arr2[idxsort];
}


vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    int idx = 0;
    if(ext == "code")
    {
        idx = 0;
    }
    else if(ext == "date")
    {
        idx = 1;
    }
    else if(ext == "maximum")
    {
        idx = 2;
    }
    else
    {
        idx = 3;
    }
    
    if(sort_by == "code")
    {
        idxsort = 0;
    }
    else if(sort_by == "date")
    {
        idxsort = 1;
    }
    else if(sort_by == "maximum")
    {
        idxsort = 2;
    }
    else
    {
        idxsort = 3;
    }
    
    for(auto i : data)
    {
        if(i[idx] < val_ext)
        {
            answer.push_back(i);
        }
    }
    sort(answer.begin(),answer.end(),cmp);
    return answer;
}