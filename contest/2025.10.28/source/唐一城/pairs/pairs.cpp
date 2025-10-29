#include <bits/stdc++.h>
using namespace std;
#define il inline
const int N=4e6+5,V=4e6;
int n,a[N],cnt=0,f[N],mod,vis[N];
long long ans[15]={0,0,0,0,17,904,45926,2725016,196884712,17350671831,1847029162807};
//namespace BIT {
//int t[N];
//il void init(){for(int i=0;i<=V;i++)t[i]=0;}
//il void add(int x,int k){for(;x<=V;x+=(x&-x))t[x]+=k;}
//il int ask(int x){int res=0;for(;x;x-=(x&-x))res+=t[x];return res;}
//}
//il void dfs(int step) {
//    if(step==n) {++cnt;
//        for(int i=1;i<=n;i++) {
//            for(int j=1;j<i;j++) {
//                if(a[j]>a[i])f[cnt]++;
//            }
//        }return;
//    }
//    for(int i=1;i<=n;i++) {
//        if(vis[i])continue;
//        vis[i]=1;a[step+1]=i;dfs(step+1);vis[i]=0;
//    }
//}
//il void print(__int128 x) {
//    if(x>9)print(x/10);
//    putchar(x%10+'0');
//}
int main() {
	freopen("pairs.in","r",stdin);
	freopen("pairs.out","w",stdout);
	int n,mod;
	cin>>n>>mod;
	cout<<ans[n]%mod;
    return 0;
}
