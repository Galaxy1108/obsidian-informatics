#include<bits/stdc++.h>
using namespace std;
int V=2200000,delta=550000;
int n,m,l,r,x,y;
int a[500010],c[500010],tree[2200100];
vector<int> L[500010];
vector<int> R[500010];
void Add(int x,int val){
	while(x<=V) tree[x]+=val,x+=x&(-x);
}
int Ask(int x){
	int ans=0;
	while(x) ans+=tree[x],x-=x&(-x);
	return ans;
}
int Fndl(int x){
	int l=1,r=V;
	while(l<r){
		const int mid=(l+r)>>1;
		if(mid+Ask(mid)<x) l=mid+1;
		else r=mid;
	}
	return l;
}
int Fndr(int x){
	int l=1,r=V;
	while(l<r){
		const int mid=(l+r+1)>>1;
		if(mid+Ask(mid)>x) r=mid-1;
		else l=mid;
	}
	return l;
}
int main()
{
	freopen("thief.in","r",stdin);
	freopen("thief.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	clock_t st=clock();
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i],a[i]+=delta;
	for(int i=1;i<=m;++i){
		cin>>l>>r>>c[i];
		c[i]+=delta;
		L[l].push_back(i);
		R[r].push_back(i);
	}
	for(int i=1;i<=n;++i){
		for(auto v:L[i]) c[v]=Fndl(c[v]);
		x=Fndl(a[i]);y=Fndr(a[i]);
		Add(1,1);Add(x,-1);
		Add(y+1,-1);
		for(auto v:R[i]) c[v]=c[v]+Ask(c[v]);
	}
	for(int i=1;i<=m;++i) cout<<c[i]-delta<<'\n';
	cerr<<(clock()-st)*1.0/CLOCKS_PER_SEC<<'\n';
	return 0;
}