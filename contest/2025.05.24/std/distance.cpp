#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int maxn = 1e5 + 50;
const int mod = 1e9 + 7;

char s[maxn];
char t[maxn];
int f[maxn][30];
int dp[30][30];

int main()
{
    freopen("distance.in", "r", stdin);
    freopen("distance.out", "w", stdout);
    scanf("%s %s", s, t);
    int n = strlen(s);
    int m = strlen(t);
    for (int j = 0; j < 26; ++j)
    {
        int r = n;
        for (int i = n-1; i >= 0; --i)
        {
            if (j + 'a' == s[i]) r = i;
            f[i][j] = r;
        }
    }
    int q;
    scanf("%d", &q);
    while (q--)
    {
        int l, r;
        scanf("%d %d", &l, &r);
        l --; r --;
        for (int i = 0; i <= m; ++i)
            for (int j = 0; j <= m; ++j)
                dp[i][j] = n;
        dp[0][0] = l - 1;
        dp[0][1] = f[l][t[0]-'a'] <= r ? f[l][t[0]-'a'] : n;
        for (int i = 1; i < m; ++i)
        {
            dp[i][0] = l - 1;
            for (int j = 1; j <= i + 1; ++j)
            {
                if (j <= i) dp[i][j] = dp[i-1][j];
                if (dp[i-1][j-1] + 1 <= r && f[dp[i-1][j-1]+1][t[i]-'a'] <= r)
                    dp[i][j] = min(dp[i][j], f[dp[i-1][j-1]+1][t[i]-'a']);
            }
        }
        int lcs = 0;
        for (int i = 0; i <= m; ++i)
            if (dp[m-1][i] >= l && dp[m-1][i] <= r)
                lcs = i;
        printf("%d\n", (r-l+1) + m - lcs*2);
    }
    return 0;
}
