#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    for (auto target : targets)
    {
        int total_press = 0;
        bool possible = true;

        for (auto c : target)
        {
            bool found = false;
            int min_press = 101;
            for (auto key : keymap)
            {
                int idx = key.find(c);
                if (idx != string::npos)
                {
                    found = true;
                    min_press = min(min_press, idx + 1);
                }
            }
            if (!found)
            {
                possible = false;
                break;
            }
            total_press += min_press;
        }

        if (possible)
        {
            answer.push_back(total_press);
        }
        else
        {
            answer.push_back(-1);
        }
    }

    return answer;
}
