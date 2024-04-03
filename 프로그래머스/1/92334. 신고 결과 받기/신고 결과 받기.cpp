#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    report.erase(unique(report.begin(), report.end()), report.end());

    vector<int> report_count(id_list.size(), 0);
    vector<vector<string>> reported_users(id_list.size());

    for (const string& r : report)
    {
        string reporter = r.substr(0, r.find(' '));
        string reported_user = r.substr(r.find(' ') + 1);
        
        int tmp = distance(id_list.begin(), find(id_list.begin(), id_list.end(), reported_user));
        if (find(reported_users[tmp].begin(), reported_users[tmp].end(), reporter) == reported_users[tmp].end())
        {
            reported_users[tmp].push_back(reporter);
            report_count[tmp]++;
        }
    }

    vector<int> mail(id_list.size(), 0);
    for (int i = 0; i < id_list.size(); i++)
    {
        if (report_count[i] >= k)
        {
            for (const string& reporter : reported_users[i])
            {
                int t = distance(id_list.begin(), find(id_list.begin(), id_list.end(), reporter));
                mail[t]++;
            }
        }
    }

    return mail;
}
