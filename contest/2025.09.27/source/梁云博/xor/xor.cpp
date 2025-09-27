#include <bits/stdc++.h>
#define N 100005
#define int long long
using namespace std;
int n;
int a[N],s[N];
signed main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],s[i]=a[i]^s[i-1],cout<<s[i]<<" ";
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
    	int maxn=-1e18;
        for(int j=i;j<=n;j++)
        {
        	maxn=max(maxn,a[j]);
            if((s[j]^s[i-1])<=maxn)cnt++;
        }
    }
    cout<<cnt;
    return 0;
}