#include<bits/stdc++.h>
#define FOR(i,s,t) for(int i=(s);i<=(t);++i)
#define ROF(i,s,t) for(int i=(s);i>=(t);--i)
#define lb(x) (x&(-x)) 
using namespace std;
inline int read() {
	int x=0;char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) x=x*10+(c^48),c=getchar();
	return x;
}
const int N=1e6+3,M=1e5+3,P=998244353;
inline void Add(int &x,int y) {(x+=y)>=P&&(x-=P);} 
int n,m,V,a[N],b[N],c[N],pw[N];
vector<int> p[M];
inline void upd(int x,int k) {for(;x<=V;x+=lb(x)) Add(c[x],k);}
inline int pre(int x) {int s=0;for(;x;x-=lb(x)) Add(s,c[x]);return s;} 
inline void add(int i) {if(!p[i].empty()) upd(i,pw[n-p[i].back()]);}
int main() {
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	n=read();FOR(i,1,n) a[i]=read(),V=max(V,a[i]);
	m=read();FOR(i,1,m) b[i]=read();
	pw[0]=1;FOR(i,1,n) pw[i]=pw[i-1]*2%P;
	ROF(i,n,1) p[a[i]].emplace_back(i);
	FOR(i,1,V) add(i);
	int res=1,cur=1;
	FOR(i,1,m) {
		Add(res,pre(b[i]-1));
		int j=p[b[i]].back();
		while(cur<=j) p[a[cur]].pop_back(),upd(a[cur],P-pw[n-cur]),add(a[cur++]);
	}
	cout<<res;
	return 0;
}
