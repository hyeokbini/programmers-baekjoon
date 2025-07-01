#include <bits/stdc++.h>

using namespace std;

string solution(string new_id) {
    string temp = "";
    for(int i = 0; i < new_id.length(); i++)
    {
        new_id[i] = tolower(new_id[i]); // 1단계
    }
    for(int i = 0; i < new_id.length(); i++)
    {
        if(isalnum(new_id[i]) || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.')
        {
            temp += new_id[i]; // 2단계
        }
    }
    new_id = temp;
    temp = "";
    for(int i = 0; i < new_id.length(); i++)
    {
        temp += new_id[i];
        while(new_id[i] == '.' && new_id[i + 1] == '.')
        {
            i++; // 3단계
        }
    }
    new_id = temp;
    if(new_id.front() == '.')
    {
        new_id.erase(0,1);
    }
    if(new_id.back() == '.')
    {
        new_id.pop_back();
    } // 4단계
    if(new_id.empty())
    {
        new_id += 'a';
    } // 5단계
    if(new_id.length() >= 16)
    {
        new_id.erase(new_id.begin() + 15,new_id.end());
        if(new_id.back() == '.')
        {
            new_id.pop_back();
        }
    } // 6단계
    if(new_id.length() <= 2)
    {
        while(new_id.length() < 3)
        {
            new_id += new_id.back();
        }
    }
    return new_id;
}