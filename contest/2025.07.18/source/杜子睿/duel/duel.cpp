#include<bits/stdc++.h>
using namespace std;
int n,q,tr[800005],a[200005];
long long c[35];
void init(){
	c[0]=1;
	for(int i=1;i<=30;i++)
		c[i]=c[i-1]*2;
}
void build(int p,int l,int r){
	if(l==r){
		tr[p]=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	tr[p]=abs(tr[p<<1]-tr[p<<1|1]); 
}
void update(int p,int l,int r,int x,int y){
	if(l==r){
		tr[p]=y;
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)
		update(p<<1,l,mid,x,y);
	else
		update(p<<1|1,mid+1,r,x,y);
	tr[p]=abs(tr[p<<1]-tr[p<<1|1]);  
}
int query(int p,int s,int t,int l,int r){
	if(l<=s&&t<=r)
		return tr[p];
	int mid=(s+t)>>1;
	int fl=0,fr=0,ll=0,rr=0;
	if(l<=mid){
		fl=1;
		ll=query(p<<1,s,mid,l,r);
	}
	if(r>mid){
		fr=1;
		rr=query(p<<1|1,mid+1,t,l,r);
	}
	if(fl&&fr)
		return abs(ll-rr);
	return ll+rr;
}
int query1(int x,int y){
	if(x==y)
		return a[x];
	if(y==x+1)
		return abs(a[x]-a[y]);
	else
		return abs(query1(x,(x+y)>>1)-query1(((x+y)>>1)+1,y));
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n>>q; 
	for(int i=1;i<=n;i++)
		cin>>a[i];
	init();
	if(n<=10000||q<=10000){
		for(int i=0;i<q;i++){
			int opt,x,y;
			cin>>opt>>x>>y;
			if(opt==1)
				a[x]=y;
			else
				cout<<query1(x,x+c[y]-1)<<endl;
		}
		return 0;
	}
	else{
		build(1,1,n);
		for(int i=0;i<q;i++){
			int opt,x,y;
			cin>>opt>>x>>y;
			if(opt==1)
				update(1,1,n,x,y);
			else
				cout<<query(1,1,n,x,x+c[y]-1)<<endl; 
		}
	}
	return 0;
}

