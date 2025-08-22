/*
思考起点 8:15

n 个1-m合法区间，相邻重叠个数
反过来思考，交集是空集？
这不好思考，区间 i 和区间 i+2 依然可以不重叠
注意到区间 i 不需要在区间 i+1 前面
对于一个好的区间，他们两两是可以交换的 -> 顺序是任意的
需要注意区间 i 等于区间 i+1 的情况，这对答案统计不利
不，这不可以交换
若区间 i 为 [a,b]，区间 i+1 可以是 [1~b,a~m]
dp?
dp_{i,l,r} 表示 n 个区间，上一个区间为 [l,r]，转移简单

- 里程碑：20min 20pts 8:35

需要优化，为了优化至 40 pts，dp 需要为 dp_{i,j}，其中 j 为 m
考虑 20pts 的转移
dp_{i,l,r} <- dp_{i-1,L,R} | (l<=R && r>=L)
是否可以优化转移
可以，记
g_R(x) 为 dp[i-1] 下所有 R>=x 的总数
g_L(x) 为 dp[i-1] 下所有 L>x  的总数
dp_{i,l,r} 为 g_R(l)-g_L(r)，g_R(x) 和 g_L(x) 可以差分处理
时间复杂度 O(nm + nm^2)

- 里程碑：40min ~40pts 8:55

从宏观考虑问题，长度！
dp_{i,j} 为第 i 个序列，长度为 j，试一试

- 里程碑：45min 40pts 9:00
- Check failed: 60min 9:15 (WA on sample #1) 

怒！怒！怒！怒！怒！怒！怒！怒！怒！怒！怒！怒！怒！怒！怒！怒！怒！怒！
这年头 T1 都这么 hard
问题在于长度不一定可以取满，会出现超出 m 边界的情况

考虑 ~40pts 的思路是否可以优化
考虑固定 r，移动 l，会有 \sum dp_{i,r} = \sum(i->1~m) g_R(i) - m*g_L(r)
无法在正确时间内算出 g_R 和 g_L

- Check failed: 120min 10:08 (WA on sample #2)
Time limit Skip 10:08

recode 10:40
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll dp[2][3200][3200];
ll g[2][3200][3200];

int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    ll n, m, p;
    cin >> n >> m >> p;
    if(n==1){
        cout << (((m + 1) % p) * m / 2) % p;
    	return 0;
	}
    for (ll i = 1;i <= m;i++) {
        int I = 1;
        for (int j = 1;j < i;j++) {
            g[I][i][j] = (g[I][i - 1][j] + g[I][i][j - 1] - g[I][i - 1][j - 1]) % p;
        }
        for (ll j = i;j <= m;j++) {
            dp[1][i][j] = 1;
            g[I][i][j] = (g[I][i - 1][j] + g[I][i][j - 1] - g[I][i - 1][j - 1] + dp[I][i][j]) % p;
        }
    }
    for (ll i = 2;i <= n;i++) {
        bool I = i & 1;
        g[I][0][0] = 0;
        for (ll l = 1;l <= m;l++) {
            g[I][0][l] = 0;
            g[I][l][0] = 0;
            for (int r = 1;r < l;r++) {
                g[I][l][r] = (g[I][l - 1][r] + g[I][l][r - 1] - g[I][l - 1][r - 1]) % p;
            }
            for (ll r = l;r <= m;r++) {
                dp[I][l][r] = (g[I ^ 1][r][m] - g[I ^ 1][r][l - 1] + p) % p;
                g[I][l][r] = (g[I][l - 1][r] + g[I][l][r - 1] - g[I][l - 1][r - 1] + dp[I][l][r]) % p;
            }
        }
    }
    ll sums = 0;
    for (ll l = 1;l <= m;l++) {
        for (ll r = l;r <= m;r++) {
            sums = (dp[n & 1][l][r] + sums) % p;
        }
    }
    cout << sums;
    return 0;
}
