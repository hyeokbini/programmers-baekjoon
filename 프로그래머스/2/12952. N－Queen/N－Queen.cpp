#include <string>
#include <vector>

using namespace std;

int fin;
int ans = 0;
vector<bool> col, dia1, dia2;

void check(int level)
{
    if (level == fin)
    {
        ans++;
        return;
    }
    for (int i = 0; i < fin; i++)
    {
        if (!col[i] && !dia1[level + i] && !dia2[level - i + fin - 1])
        {
            col[i] = dia1[level + i] = dia2[level - i + fin - 1] = true;
            check(level + 1);
            col[i] = dia1[level + i] = dia2[level - i + fin - 1] = false;
        }
    }
    return;
}

int solution(int n) {
    fin = n;
    col.resize(n, false);
    dia1.resize(2 * n - 1, false);
    dia2.resize(2 * n - 1, false);
    check(0);
    return ans;
}