#include<bits/stdc++.h>
using namespace std;
int n,Q,T,f,N;
int a[200010],b[200010];
int ans[1000010];
struct Node{
	int t,x,id;
}q[1000010];
void work(){
	int f=1,g=n/2+1;
	for(int i=1;i<=N;++i){
		if(f>n/2) b[i]=a[g],++g;
		else if(g>n) b[i]=a[f],++f;
		else if(a[f]<a[g]) b[i]=a[f],++f;
		else b[i]=a[g],++g;
	}
}
bool cmpt(Node x,Node y) {return x.t<y.t;}
void get(){
	int v=0;
	for(int i=1;i<=n/2;++i) v=max(v,a[i]);
	for(int i=N;i>n/2;--i) if(a[i]>v) N=i-1;
	return;
}
int main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>Q;
	for(int i=1;i<=n;++i) cin>>a[i];
	T=0;
	for(int i=1;i<=Q;++i){
		cin>>q[i].t>>q[i].x;
		q[i].id=i;
	}
	sort(q+1,q+Q+1,cmpt);
	f=1;
	N=n;get();
	while(f<=Q&&q[f].t==T) ans[q[f].id]=a[q[f].x],++f;
	while(1){
		work();
		int tag=0;
		for(int i=1;i<=N;++i) if(a[i]!=b[i]) tag=1;
		if(tag==0) break;
		++T;
		for(int i=1;i<=N;++i) a[i]=b[i];
		get();
		while(f<=Q&&q[f].t==T) ans[q[f].id]=a[q[f].x],++f;
	}
	while(f<=Q){
		ans[q[f].id]=a[q[f].x];
		++f;
	}
	for(int i=1;i<=Q;++i) cout<<ans[i]<<'\n';
	return 0;
} 
