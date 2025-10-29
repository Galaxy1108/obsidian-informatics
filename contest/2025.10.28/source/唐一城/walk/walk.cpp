#include <bits/stdc++.h>
using namespace std;
#define il inline
const int N=1e5+5;
int n,a[N],t[N]={0},ans=INT_MAX,mx;
il void dfs(int x,int to,int step) {
    if(step==15)return;
    int res=0;
    for(int i=1;i<=n;i++)res+=abs(a[i]-t[i]);
    ans=min(ans,res);
    if(to==0) {
        for(int i=x-1;i>=0;i--) {t[i+1]++;
            dfs(i,to^1,step+1);
        }    
        for(int i=1;i<=x;i++)t[i]--;
    } else {
        for(int i=x+1;i<=n;i++) {t[i]++;
            dfs(i,to^1,step+1);
        }    
        for(int i=x+1;i<=n;i++)t[i]--;
    }
}
int main() {
    freopen("walk.in","r",stdin);
    freopen("walk.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){cin>>a[i];mx=max(mx,a[i]);}
    for(int i=0;i<=n;i++) {
        dfs(i,0,0);
        dfs(i,1,0);
        // for(int j=1;j<=n;j++)cout<<t[j]<<' ';cout<<'\n';
    }
    cout<<ans;
    return 0;
}
/*
4
1
0
2
3

5
0
7
2
4
8

*/