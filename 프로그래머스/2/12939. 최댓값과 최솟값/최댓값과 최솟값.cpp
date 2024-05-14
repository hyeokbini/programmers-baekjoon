#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<int>arr;
    istringstream get(s);
    string temp;
    while(getline(get,temp,' '))
    {
        arr.push_back(stoi(temp));
    }
    sort(arr.begin(),arr.end());
    answer += to_string(arr[0]);
    answer += " ";
    answer += to_string(arr.back());
    return answer;
}