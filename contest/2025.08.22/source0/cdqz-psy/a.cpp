#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e7+5;
int n,m,mod,f[N],g[N];
int sf[N],sg[N],ssf[N],ssg[N]; 
inline void add(int &x,int val){
	x=(x+val)%mod;
}
inline void del(int &x,int val){
	x=(x-val+mod)%mod;
}
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	cin>>n>>m>>mod;
	f[m]=1,g[0]=1;
	for(int x=1;x<=m;x++){
		sf[x]=(sf[x-1]+f[x])%mod;
		ssf[x]=(ssf[x-1]+(ll)f[x]*x)%mod;
		sg[x]=(sg[x-1]+g[x])%mod;
		ssg[x]=(ssg[x-1]+(ll)g[x]*x)%mod;
	}
	for(int i=1;i<=n;i++){
		for(int x=1;x<=m;x++){
			f[x]=0,g[x]=0;
			add(f[x],(ll)sf[m]*x%mod);
			del(f[x],(ll)sg[m]*x%mod);
	 		add(f[x],(ll)sg[x]*x%mod);
	 		del(f[x],(ll)sf[x]*x%mod);
	 		add(f[x],ssf[x]);
		}
		for(int x=1;x<=m;x++){
			add(g[x],(ll)sf[m]*(m-x+1)%mod);
			del(g[x],(ll)sf[x-1]*(m-x+1)%mod);
			del(g[x],ssg[m]);
			add(g[x],ssg[x-1]);
			add(g[x],(ll)x*sg[m]%mod); 
			del(g[x],(ll)x*sg[x-1]%mod);
		}
		for(int x=1;x<=m;x++){
			sf[x]=(sf[x-1]+f[x])%mod;
			ssf[x]=(ssf[x-1]+(ll)f[x]*x)%mod;
			sg[x]=(sg[x-1]+g[x])%mod;
			ssg[x]=(ssg[x-1]+(ll)g[x]*x)%mod;
		}
	}
	cout<<sf[m]<<"\n";
}
