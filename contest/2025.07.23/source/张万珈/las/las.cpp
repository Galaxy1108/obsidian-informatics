#include <bits/stdc++.h>
using namespace std;
int a[1000010];
int dp[1000010];
int n;
void print()
{
    for(int i=1;i<=n;i++)
    {
    	if(dp[i] > n) cout << dp[i]-n << ' ';
        else cout << dp[i] << ' ';
    }
    return;
}

int main()
{
	freopen("las.in","r",stdin);
	freopen("las.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        dp[i] = i;
        a[i] <<= 1;
    }
    dp[n+1] = n+1;
    a[n+1] = a[1];
    int v1,v2;
    for(int i=n;i>=1;i--)
    {
        v1 = a[i],v2 = a[i+1];
        if(dp[i+1] == i+1)v2 >>= 1;
        if(v2 > v1) 
        {
            dp[i] = i+1;
            for(int j=i+1;j<=n;j++)
            {
                v1 = a[j],v2 = a[j+1];
                if(dp[j+1] == j+1) v2 >>= 1;
                if(dp[j-1] == j) v1 >>= 1;
                if(v2 > v1 && dp[j] == j) dp[j] = j+1;
                else break;
            }
        }
    }
    for(int i=1;i>=1;i--)
    {
        v1 = a[i],v2 = a[i+1];
        if(dp[i+1] == i+1) v2 >>= 1;
        if(dp[n] == n+1) v1 >>= 1;
        if(v2 > v1) dp[i] = i+1;
    }
    if(a[1] == 2)
    {
    int i=n;
    for(;i>=1;i--)
    {
        v1 = a[i],v2 = a[i+1];
        if(dp[i+1] == i+1)v2 >>= 1;
        if(v2 > v1) dp[i] = i+1;
        else break;
    }
    if(i==1){cout << "NIE";return 0;}
    }
    print();
    return 0;
}
