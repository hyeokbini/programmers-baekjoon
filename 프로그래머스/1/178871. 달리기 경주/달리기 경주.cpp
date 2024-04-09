#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    string temp = "";
    map <string,int> arr;
    for(int i = 0; i < players.size(); i++)
    {
        arr.insert({players[i],i});
    }
    for(auto i : callings)
    {
        int tmp = arr[i];
        arr[players[tmp - 1]]++;
        arr[i]--;
        swap(players[tmp],players[tmp - 1]);
    }
    return players;
}