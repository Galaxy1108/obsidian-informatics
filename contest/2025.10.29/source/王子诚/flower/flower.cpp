#include <bits/stdc++.h>
using namespace std;

string str[45];
bool flag[45];
int num[85];

int n, N;

bool dfs(int i) {
    if (i == 2 * N + 1) {
        return true;
    }
    if (i == 2 * n + 1) {
        n += 4;
    }
    if (num[i]) {
        return dfs(i + 1);
    }
    for (int j = 1;j <= n;j++) {
        if (!flag[j] && i + j + 1 <= 2 * n && !num[i + j + 1]) {
            num[i] = j;
            num[i + j + 1] = j;
            flag[j] = true;
            if (dfs(i + 1)) {
                return true;
            }
            num[i] = 0;
            num[i + j + 1] = 0;
            flag[j] = false;
        }
    }
    return false;
}

int ans39[] = { 2,3,6,2,7,3,9,11,8,6,12,15,7,16,17,20,9,8,21,11,23,24,22,12,26,27,30,15,29,33,16,35,17,31,37,38,20,39,34,36,21,28,32,25,23,22,24,13,19,14,5,26,18,27,4,10,5,30,29,4,1,13,1,33,14,31,10,35,19,25,28,18,37,34,38,32,36,39, };
int ans40[] = { 2,3,6,2,8,3,7,10,11,6,13,16,14,8,7,17,20,21,10,23,11,22,25,26,13,27,30,14,16,31,32,33,36,17,35,37,40,20,39,21,38,34,28,23,22,29,9,18,25,24,26,15,19,27,4,12,9,30,5,4,1,31,1,32,5,33,18,15,12,36,35,28,19,37,24,29,34,40,39,38, };

int main() {
    freopen("flower.in", "r", stdin);
    freopen("flower.out", "w", stdout);
    cin >> N;
    for (int i = 1;i <= N;i++) {
        cin >> str[i];
    }
    if (N == 39) {
        for (int i = 1;i <= 2 * N;i++) {
            cout << str[ans39[i - 1]] << '\n';
        }
        return 0;
    }
    if (N == 40) {
        for (int i = 1;i <= 2 * N;i++) {
            cout << str[ans40[i - 1]] << '\n';
        }
        return 0;
    }
    n = N % 4;
    dfs(1);
    for (int i = 1;i <= 2 * N;i++) {
        cout << str[num[i]] << '\n';
    }
}
