#include <bits/stdc++.h>
using namespace std;
const int N=505,mod=998244353;
int n,x,a[N],t[N],vis[N],ans=0;
inline void dfs(int step) {
    if(step==n) {
        for(int i=1;i<=n;i++)t[i]=a[i],vis[i]=0;
        int now=n-1;
        while(1) {int num=0,cnt=0;
            for(int i=1;i<=n;i++) {
                t[i]-=now;
                if(t[i]<1&&!vis[i])num++,vis[i]=1;
                if(t[i]>=1)cnt++;
            }now-=num;
            if(cnt==0)ans=(ans+1)%mod;
            if(cnt<=1)break;
        }
        return;
    }
    for(int i=1;i<=x;i++) {
        a[step+1]=i;
        dfs(step+1);
    }
}
int main() {
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    cin>>n>>x;
    dfs(0);cout<<ans;
    return 0;
}