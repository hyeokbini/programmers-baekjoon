#include <bits/stdc++.h>

using namespace std;

string f = "Fizz";
string b = "Buzz";
string fb = "FizzBuzz";

bool check(string tmp)
{
    if (tmp != f && tmp != b && tmp != fb)
    {
        return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    vector<string> arr(3);
    for (int i = 0; i < 3; i++)
    {
        cin >> arr[i];
    }
    if(!check(arr[0]) && !check(arr[1]) && arr[2] == f)
    {
        if((stoi(arr[1]) + 2) % 5 == 0)
        {
            cout << b;
        }
        else
        {
            cout << stoi(arr[1]) + 2;
        }
    }
    else if(!check(arr[0]) && arr[1] == f && !check(arr[2]))
    {
        if((stoi(arr[2]) + 1) % 5 == 0)
        {
            cout << b;
        }
        else
        {
            cout << stoi(arr[2]) + 1;
        }
    }
    else if(arr[0] == f && !check(arr[1]) && arr[2] == b)
    {
        cout << f;
    }
    else if(!check(arr[0]) && arr[1] == b && arr[2] == f)
    {
        cout << stoi(arr[0]) + 3;
    }
    else if(arr[0] == b && arr[1] == f && !check(arr[2]))
    {
        cout << stoi(arr[2]) + 1;
    }
    else if(arr[0] == f && !check(arr[1]) && !check(arr[2]))
    {
        if((stoi(arr[2]) + 1) % 5 == 0)
        {
            cout << fb;
        }
        else
        {
            cout << f;
        }
    }
    else if(!check(arr[0]) && arr[1] == f && arr[2] == b)
    {
        cout << stoi(arr[0]) + 3;
    }
    else if(arr[0] == f && arr[1] == b && !check(arr[2]))
    {
        cout << f;
    }
    else if(arr[0] == b && !check(arr[1]) && arr[2] == f)
    {
        cout << stoi(arr[1]) + 2;
    }
    else if(!check(arr[0]) && !check(arr[1]) && arr[2] == fb)
    {
        cout << stoi(arr[1]) + 2;
    }
    else if(!check(arr[0]) && arr[1] == fb && !check(arr[2]))
    {
        cout << stoi(arr[2]) + 1;
    }
    else if(arr[0] == fb && !check(arr[1]) && !check(arr[2]))
    {
        cout << f;
    }
    return 0;
}
