#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> inorder, postorder;
unordered_map<int, int> inorderidx; // [값, 인덱스]로 저장

// preorder 출력 함수
void func(int instart, int inend, int posstart, int posend)
{
    if (instart > inend || posstart > posend)
        return;

    int rootval = postorder[posend]; // postorder의 마지막이 모든 부분트리의 루트
    cout << rootval << " ";

    int rootidx = inorderidx[rootval]; // inorder에서 루트 위치 검색(인덱싱용)
    int leftsize = rootidx - instart;

    // 왼쪽 서브트리
    func(instart, rootidx - 1, posstart, posstart + leftsize - 1);
    // 오른쪽 서브트리
    func(rootidx + 1, inend, posstart + leftsize, posend - 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    cin >> n;
    inorder.resize(n);
    postorder.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> inorder[i];
        inorderidx[inorder[i]] = i;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> postorder[i];
    }
    func(0, n - 1, 0, n - 1);
    return 0;
}
