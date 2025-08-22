#include<bits/stdc++.h>
#define LL long long
#define LLL __int128
#define uint unsigned
#define ldb long double
#define uLL unsigned long long
using namespace std;
const int N=1e7+5;
int n,m,P;
int g[N],h[N],ng[N],nh[N];
signed main(){
    cin.tie(0)->sync_with_stdio(0);
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	cin>>n>>m>>P;
	for(int i=1;i<=m;++i)g[i]=1ll*i*(m-i+1)%P,h[i]=(h[i-1]+(m-i+1))%P;
	for(int k=2;k<=n;++k){
		for(int l=m,s=0;l>=1;--l){
			s=(s+h[l])%P;
			ng[l]=(ng[l]+(m-l+1ll)*(g[l]-h[l])+s)%P;
			nh[l]=(nh[l]+(m-l+1ll)*(g[l]-h[l])+s)%P;
		}
		for(int r=1,s=0;r<m;++r){
			s=(s+g[r]-h[r])%P;
			ng[r+1]=(ng[r+1]-(1ll*r*h[r]+s))%P;
		}
		for(int i=1;i<=m;++i){
			g[i]=g[i-1]+ng[i],h[i]=h[i-1]+nh[i];
			if(g[i]<0)g[i]+=P;if(g[i]>=P)g[i]-=P;
			if(h[i]<0)h[i]+=P;if(h[i]>=P)h[i]-=P;
			ng[i]=0,nh[i]=0;
		}
	}
	cout<<h[m]<<'\n';
    return 0;
}