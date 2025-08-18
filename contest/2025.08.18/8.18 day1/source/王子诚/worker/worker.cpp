#include <bits/stdc++.h>
using namespace std;

int sn[105];
int dp[105][15][15][15];
int cnts[4];

#define inf 1000000000

int main(){
    freopen("worker.in", "r", stdin);
    freopen("worker.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++){
        char a;
        cin >> a;
        sn[i] = a - 'A' + 1;
    }
    for (int i = 0; i <= n;i++){
        for (int a = 0; a <= 10;a++){
            for (int b = 0; b <= 10;b++){
                for (int c = 0; c <= 10;c++){
                    dp[i][a][b][c] = inf;
                }
            }
        }
    }
    cnts[0] = cnts[1] = cnts[2] = 0;
    for (int p = 1; p <= min(n,10);p++){
        cnts[sn[p]]++;
    }
    if(n<=10){
        cout << !!cnts[1] + !!cnts[2] + !!cnts[3];
        return 0;
    }
    dp[10][cnts[1]][cnts[2]][cnts[3]] = 0;
    for (int i = 11; i <= n;i++){
        for (int k = 1; k <= 10;k++){
            cnts[1] = cnts[2] = cnts[3] = 0;
            for (int p = 0; p < k;p++){
                cnts[sn[i - p]]++;
            }
            for (int a = 0; a + k <= 10;a++){
                for (int b = 0; a + b + k <= 10;b++){
                    dp[i][cnts[1]][a + cnts[2]][b + cnts[3]] = min(dp[i][cnts[1]][a + cnts[2]][b + cnts[3]], dp[i - k][k][a][b] + 1);
                    dp[i][a + cnts[1]][cnts[2]][b + cnts[3]] = min(dp[i][a + cnts[1]][cnts[2]][b + cnts[3]], dp[i - k][a][k][b] + 1);
                    dp[i][a + cnts[1]][b + cnts[2]][cnts[3]] = min(dp[i][a + cnts[1]][b + cnts[2]][cnts[3]], dp[i - k][a][b][k] + 1);
                    if(i==n){
                        for (int c = k + 1; a + b + c <= 10;c++){
                            dp[i][cnts[1]][a + cnts[2]][b + cnts[3]] = min(dp[i][cnts[1]][a + cnts[2]][b + cnts[3]], dp[i - k][c][a][b] + 1);
                            dp[i][a + cnts[1]][cnts[2]][b + cnts[3]] = min(dp[i][a + cnts[1]][cnts[2]][b + cnts[3]], dp[i - k][a][c][b] + 1);
                            dp[i][a + cnts[1]][b + cnts[2]][cnts[3]] = min(dp[i][a + cnts[1]][b + cnts[2]][cnts[3]], dp[i - k][a][b][c] + 1);
                        }
                    }
                }
            }
        }           
    }
    int anss = inf;
    for (int a = 0; a <= 10;a++){
        for (int b = 0; a + b <= 10;b++){
            for (int c = 0; a + b + c <= 10;c++){
                anss = min(anss, dp[n][a][b][c] + !!a + !!b + !!c);
            }
        }
    }
    cout << anss;
    return 0;
}