#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200005],pre[200005][2],nxt[200005][2],dp[200005],ans=1e18;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("walk.in","r",stdin);
    freopen("walk.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    fill(dp,dp+n+3,1e17);
    for(int i=n;i>=1;i--){
        if(a[i]){
            if(a[i]%2)nxt[i][1]=min(nxt[i+1][1],nxt[i+1][0])+1;
            else nxt[i][1]=min(nxt[i+1][1],nxt[i+1][0]);
            nxt[i][0]=nxt[i+1][0]+a[i];
        }
        else{
            nxt[i][0]=nxt[i+1][0];
            nxt[i][1]=nxt[i+1][1]+2;
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i]){
            if(a[i]%2)pre[i][1]=min(pre[i-1][1],pre[i-1][0])+1;
            else pre[i][1]=min(pre[i-1][1],pre[i-1][0]);
            pre[i][0]=pre[i-1][0]+a[i];
        }
        else{
            pre[i][0]=pre[i-1][0];
            pre[i][1]=pre[i-1][1]+2;
        }
        ans=min(ans,min(nxt[i][1]+pre[i-1][0],nxt[i+1][0]+pre[i][1]));
        if(a[i]%2)dp[i]=min(dp[i-1],min(pre[i-1][0],pre[i-1][1]));
        else dp[i]=dp[i-1]+1;
        ans=min(ans,dp[i]+min(nxt[i+1][0],nxt[i+1][1]));
    }
    ans=min(ans,pre[n][0]);
    cout<<ans;
    return 0;
}