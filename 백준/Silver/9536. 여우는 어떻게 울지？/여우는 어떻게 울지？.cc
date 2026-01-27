#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int T;
    cin >> T;
    cin.ignore();

    while (T--) {
        string line;
        getline(cin, line);
        stringstream ss(line);

        vector<string> recorded;
        string word;
        while (ss >> word) recorded.push_back(word);

        set<string> known_sounds;
        while (true) {
            getline(cin, line);
            if (line == "what does the fox say?") break;
            stringstream ss2(line);
            string animal, goes, sound;
            ss2 >> animal >> goes >> sound;
            known_sounds.insert(sound);
        }

        for (auto &s : recorded) {
            if (!known_sounds.count(s)) cout << s << " ";
        }
        cout << "\n";
    }
}
