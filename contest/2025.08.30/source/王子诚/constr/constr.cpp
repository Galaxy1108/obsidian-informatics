#include <bits/stdc++.h>
using namespace std;

int num[11] = { 0,1,2,3,4,5,6,7,8,9,10 };
int anss[113405][11];
int num2[11];

int main() {
	freopen("constr.in", "r", stdout);
    freopen("constr.out", "w", stdout);
    cout << "7100\n";
    // cout << "10\n1 2 3 4 5 6 7 8 9 10 \n1 2 3 4 5 6 7 8 10 9 \n1 2 3 4 5 6 7 9 8 10 \n1 2 3 4 5 6 7 9 10 8 \n1 2 3 4 5 6 7 10 8 9 \n1 2 3 4 5 6 7 10 9 8 \n1 2 3 4 5 6 8 7 9 10 \n1 2 3 4 5 6 8 7 10 9 \n1 2 3 4 5 6 8 9 7 10 \n1 2 3 4 5 6 8 9 10 7 \n";
    for (int i = 1;i<=7100;i++) {
//        cerr << cnt << ' ' << i << '\n';
        for (int j = 1;j <= 10;j++) {
            cout << num[j] << ' ';
            anss[i][j] = num[j];
        }
        cout << '\n'; 
        while (1) {
            next_permutation(num + 1, num + 11);
            int flag2 = true;
            for (int k = 1;k <= i;k++) {
                bool flag = false;
                for (int p = 1;p <= 10;p++) {
                    if (abs(num[p] - anss[k][p]) > 1) {
                        flag = true;
                        break;
                    }
                }
                if (!flag) {
                    flag2 = false;
                    break;
                }
            }
            if (flag2) {
                break;
            }
        }
    }
}
