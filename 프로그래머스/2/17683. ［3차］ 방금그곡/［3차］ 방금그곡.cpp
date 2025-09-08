#include <bits/stdc++.h>

using namespace std;

vector<pair<int,string>> ans;

bool comp(pair<int,string> a1, pair<int,string> a2)
{
    return a1.first > a2.first;
}

int timetosec(string str)
{
    int time = stoi(str.substr(0,2));
    int sec = stoi(str.substr(3,2));
    return time * 60 + sec;
}

string makemusic(int len, string origin)
{
    int n = origin.length();

    // 최소길이 이상을 위한 반복횟수
    int repeat = (len + n - 1) / n;
    string result = "";

    for (int i = 0; i < repeat; i++)
    {
        result += origin;
    }

    // 길이만큼만 잘라서 return
    return result.substr(0, len);
}

string preprocess(string origin)
{
    string newstring = "";
    for(int i = 0; i < origin.length(); i++)
    {
        if(origin[i] == '#')
        {
            newstring.back() = tolower(newstring.back());
        }
        else
        {
            newstring += origin[i];
        }
    }
    return newstring;
}

void check(string minfo, string m)
{
    vector<string> info;
    stringstream ss(minfo);
    string temp;

    while (getline(ss, temp, ','))
    {
        info.push_back(temp);
    }
    int playtime = timetosec(info[1]) - timetosec(info[0]);
    string musname = info[2];
    string makenmusic = makemusic(playtime, preprocess(info[3]));
    if(makenmusic.find(m) != string::npos)
    {
        ans.push_back({playtime,info[2]});
    }
}

string solution(string m, vector<string> musicinfos) {
    string newm = preprocess(m);
    for(auto i : musicinfos)
    {
        check(i,newm);
    }
    if(ans.empty())
    {
        return "(None)";
    }
    sort(ans.begin(),ans.end(),comp);
    return ans[0].second;
}