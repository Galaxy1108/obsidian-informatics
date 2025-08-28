#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
const int mod=998244353;
int n,m,A[250005],B[250005],C[250005],cnt,k;
struct node{
	long long a,b,c,tag1,tag2=1,tag3=-1;
	int val; 
}tr[1000005];
queue<pair<int,int> > tag[500000];
node operator+(node x,node y){
	node z;
	z.a=(x.a+y.a)%mod;
	z.b=(x.b+y.b)%mod;
	z.c=(x.c+y.c)%mod;
	return z;
}
void build(int p,int l,int r){
	if(r-l<k)
		tr[p].val=++cnt; 
	if(l==r){
		tr[p].a=A[l];
		tr[p].b=B[l];
		tr[p].c=C[l];
		return;
	}
	int mid=(l+r)>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	tr[p].a=(tr[p<<1].a+tr[p<<1|1].a)%mod;
	tr[p].b=(tr[p<<1].b+tr[p<<1|1].b)%mod;
	tr[p].c=(tr[p<<1].c+tr[p<<1|1].c)%mod;
}
void down(int p,int l,int r,int mid){
	while(!tag[tr[p].val].empty()){
		pair<int,int> q=tag[tr[p].val].front();
		switch(q.fi){
			case 1:
				tr[p<<1].a=(tr[p<<1].a+tr[p<<1].b)%mod;
				tr[p<<1|1].a=(tr[p<<1|1].a+tr[p<<1|1].b)%mod;
				break;
			case 2:
				tr[p<<1].b=(tr[p<<1].b+tr[p<<1].c)%mod;
				tr[p<<1|1].b=(tr[p<<1|1].b+tr[p<<1|1].c)%mod;
				break;
			case 3:
				tr[p<<1].c=(tr[p<<1].c+tr[p<<1].a)%mod;
				tr[p<<1|1].c=(tr[p<<1|1].c+tr[p<<1|1].a)%mod;
				break;
			case 4:
				tr[p<<1].a=(tr[p<<1].a+1ll*(mid-l+1)*1ll*q.se%mod)%mod;
				tr[p<<1|1].a=(tr[p<<1|1].a+1ll*(r-mid)*1ll*q.se%mod)%mod;
				break;
			case 5:
				tr[p<<1].b=(1ll*q.se*tr[p<<1].b)%mod;
				tr[p<<1|1].b=(1ll*q.se*tr[p<<1|1].b)%mod;
				break;
			case 6:
				tr[p<<1].c=(1ll*(mid-l+1)*1ll*q.se)%mod;
				tr[p<<1|1].c=(1ll*(r-mid)*1ll*q.se)%mod;
				break;
		}
		tag[tr[p].val].pop();
		tag[tr[p<<1].val].push(q);
		tag[tr[p<<1|1].val].push(q);
	}
}
void modify(int p,int s,int t,int opt,int l,int r){
	if(l<=s&&t<=r&&t-s<k){
		switch(opt){
			case 1:
				tr[p].a=(tr[p].a+tr[p].b)%mod;
				break;
			case 2:
				tr[p].b=(tr[p].b+tr[p].c)%mod;
				break;
			case 3:
				tr[p].c=(tr[p].c+tr[p].a)%mod;
				break;
		}
		tag[tr[p].val].push({opt,0});
		return;
	}
	int mid=(s+t)>>1;
	if(t-s<k)
		down(p,s,t,mid);
	if(l<=mid)
		modify(p<<1,s,mid,opt,l,r);
	if(r>mid)
		modify(p<<1|1,mid+1,t,opt,l,r);
	tr[p].a=(tr[p<<1].a+tr[p<<1|1].a)%mod;
	tr[p].b=(tr[p<<1].b+tr[p<<1|1].b)%mod;
	tr[p].c=(tr[p<<1].c+tr[p<<1|1].c)%mod;
}
void change(int p,int s,int t,int opt,int l,int r,long long x){
	if(l<=s&&t<=r&&t-s<k){
		switch(opt){
			case 4:
				tr[p].a=(tr[p].a+1ll*(t-s+1)*1ll*x%mod)%mod;
				break;
			case 5:
				tr[p].b=(1ll*x*tr[p].b)%mod;
				break;
			case 6:
				tr[p].c=(1ll*(t-s+1)*1ll*x)%mod;
				break;
		}
		tag[tr[p].val].push({opt,x});
		return;
	}
	int mid=(s+t)>>1;
	if(t-s<k)
		down(p,s,t,mid);
	if(l<=mid)
		change(p<<1,s,mid,opt,l,r,x);
	if(r>mid)
		change(p<<1|1,mid+1,t,opt,l,r,x);
	tr[p].a=(tr[p<<1].a+tr[p<<1|1].a)%mod;
	tr[p].b=(tr[p<<1].b+tr[p<<1|1].b)%mod;
	tr[p].c=(tr[p<<1].c+tr[p<<1|1].c)%mod;
}
node query(int p,int s,int t,int l,int r){
	if(l<=s&&t<=r)
		return tr[p];
	int mid=(s+t)>>1;
	if(t-s<k)
		down(p,s,t,mid);
	if(l<=mid&&r>mid)
		return query(p<<1,s,mid,l,r)+query(p<<1|1,mid+1,t,l,r);
	if(l<=mid)
		return query(p<<1,s,mid,l,r);
	return query(p<<1|1,mid+1,t,l,r);
}
void downe(int p,int l,int r,int mid){
	if(tr[p].tag1){
		tr[p<<1].a=(tr[p<<1].a+1ll*(mid-l+1)*1ll*tr[p].tag1%mod)%mod;
		tr[p<<1|1].a=(tr[p<<1|1].a+1ll*(r-mid)*1ll*tr[p].tag1%mod)%mod;
		tr[p<<1].tag1=(tr[p].tag1+tr[p<<1].tag1)%mod;
		tr[p<<1|1].tag1=(tr[p].tag1+tr[p<<1|1].tag1)%mod;
		tr[p].tag1=0;
	}
	if(tr[p].tag2!=1){
		tr[p<<1].b=(tr[p<<1].b*tr[p].tag2)%mod;
		tr[p<<1|1].b=(tr[p<<1|1].b*tr[p].tag2)%mod;
		tr[p<<1].tag2=(tr[p].tag2*tr[p<<1].tag2)%mod;
		tr[p<<1|1].tag2=(tr[p].tag2*tr[p<<1|1].tag2)%mod;
		tr[p].tag2=1;
	}
	if(tr[p].tag3!=-1){
		tr[p<<1].c=(1ll*(mid-l+1)*1ll*tr[p].tag3)%mod;
		tr[p<<1|1].c=(1ll*(r-mid)*1ll*tr[p].tag3)%mod;
		tr[p<<1].tag3=tr[p].tag3;
		tr[p<<1|1].tag3=tr[p].tag3;
		tr[p].tag3=-1;
	}
}
void changee(int p,int s,int t,int opt,int l,int r,long long x){
	if(l<=s&&t<=r){
		switch(opt){
			case 4:
				tr[p].a=(tr[p].a+(1ll*(t-s+1)*1ll*x)%mod)%mod;
				tr[p].tag1=(tr[p].tag1+x)%mod;
				break;
			case 5:
				tr[p].b=(1ll*x*tr[p].b)%mod;
				tr[p].tag2=(tr[p].tag2*1ll*x)%mod;
				break;
			case 6:
				tr[p].c=(1ll*(t-s+1)*1ll*x)%mod;
				tr[p].tag3=x;
				break;
		}
		return;
	}
	int mid=(s+t)>>1;
	downe(p,s,t,mid);
	if(l<=mid)
		changee(p<<1,s,mid,opt,l,r,x);
	if(r>mid)
		changee(p<<1|1,mid+1,t,opt,l,r,x);
	tr[p].a=(tr[p<<1].a+tr[p<<1|1].a)%mod;
	tr[p].b=(tr[p<<1].b+tr[p<<1|1].b)%mod;
	tr[p].c=(tr[p<<1].c+tr[p<<1|1].c)%mod;
}
node querye(int p,int s,int t,int l,int r){
	if(l<=s&&t<=r)
		return tr[p];
	int mid=(s+t)>>1;
	downe(p,s,t,mid);
	if(l<=mid&&r>mid)
		return querye(p<<1,s,mid,l,r)+querye(p<<1|1,mid+1,t,l,r);
	if(l<=mid)
		return querye(p<<1,s,mid,l,r);
	return querye(p<<1|1,mid+1,t,l,r);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>A[i]>>B[i]>>C[i];
	k=sqrt(n);
	build(1,1,n);
	cin>>m;
	if(n<=1000){
		for(int i=0;i<m;i++){
			int opt,x,y,z;
			cin>>opt;
			switch(opt){
				case 1:
					cin>>x>>y;
					modify(1,1,n,1,x,y);
					break;
				case 2:
					cin>>x>>y;
					modify(1,1,n,2,x,y);
					break;
				case 3:
					cin>>x>>y;
					modify(1,1,n,3,x,y);
					break;
				case 4:
					cin>>x>>y>>z;
					change(1,1,n,4,x,y,z);
					break;
				case 5:
					cin>>x>>y>>z;
					change(1,1,n,5,x,y,z);
					break;
				case 6:
					cin>>x>>y>>z;
					change(1,1,n,6,x,y,z);
					break;
				case 7:
					cin>>x>>y;
					node ttt=query(1,1,n,x,y);
					cout<<ttt.a<<" "<<ttt.b<<" "<<ttt.c<<endl;
					break;
			}
		}
	}
	else{
		for(int i=0;i<m;i++){
			long long opt,x,y,z;
			cin>>opt;
			switch(opt){
				case 4:
					cin>>x>>y>>z;
					changee(1,1,n,4,x,y,z);
					break;
				case 5:
					cin>>x>>y>>z;
					changee(1,1,n,5,x,y,z);
					break;
				case 6:
					cin>>x>>y>>z;
					changee(1,1,n,6,x,y,z);
					break;
				case 7:
					cin>>x>>y;
					node ttt=querye(1,1,n,x,y);
					cout<<ttt.a<<" "<<ttt.b<<" "<<ttt.c<<endl;
					break;
			}
		}
	}
	return 0;
} 
