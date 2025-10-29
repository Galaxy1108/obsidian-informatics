#include<bits/stdc++.h>
#define gc getchar()
#define cin(a) a=read()
#define M 200011
#define P 1000000007
#define int long long
using namespace std;

//== == == =read== == == =
int read(){
	int x=0;bool fl=0;char s=gc;
	while(!isdigit(s)){if(s=='-')fl=1;s=gc;}
	while(isdigit(s))x=(x<<1)+(x<<3)+s-'0',s=gc;
	return fl?-x:x;
}

//== == == =type== == == =
int n,ans=P,a[M],s[M],f[M],g[M],p[M],q[M];

//== == == =Data== == == =
int Data2(int x){return !x?2:x&1;}
int Data1(int x){return !(x&1);}

//== == == =Segment_tree== == == =
struct Segment_tree{
	int data[M<<2],tag[M<<2];
	#define ls (p<<1)
	#define rs (p<<1|1)
	#define mid ((l+r)>>1)
	void Pushup(int p){data[p]=min(data[ls],data[rs]);}
	void Pushtag(int p,int x){data[p]+=x;tag[p]+=x;}
	void Pushdown(int p){Pushtag(ls,tag[p]);Pushtag(rs,tag[p]);tag[p]=0;}
	void Build(int p,int l,int r){
		data[p]=0;tag[p]=0;if(l==r)return;
		Build(ls,l,mid);Build(rs,mid+1,r);
	}
	void Update(int p,int l,int r,int L,int R,int x){
		if(L<=l&&R>=r){Pushtag(p,x);return;}
		Pushdown(p);
		if(mid>=L)Update(ls,l,mid,L,R,x);
		if(mid<R)Update(rs,mid+1,r,L,R,x);
		Pushup(p);
	}
	int Query(int p,int l,int r,int L,int R){
		if(L<=l&&R>=r)return data[p];int res=P;
		Pushdown(p);
		if(mid>=L)res=min(res,Query(ls,l,mid,L,R));
		if(mid<R)res=min(res,Query(rs,mid+1,r,L,R));
		return res;
	}
}st1,st2;

#undef int
//== == == =main== == == =
int main(){
#define int long long
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin(n);
	for(int i=1;i<=n;i++)cin(a[i]);
	int l=1,r=n;n=0;
	while(!a[l])l++;while(!a[r])r--;
	if(l>=r){puts("0");return 0;}
	for(int i=l;i<=r;i++)a[++n]=a[i];
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		st1.Update(1,1,n+1,1,i,Data1(a[i]));
		st1.Update(1,1,n+1,i+1,i+1,s[i]);
		st2.Update(1,1,n+1,1,i,Data2(a[i]));
		st2.Update(1,1,n+1,i+1,i+1,s[i]);
		f[i]=min(st1.Query(1,1,n+1,1,i+1),st2.Query(1,1,n+1,1,i+1));
	}
	st1.Build(1,1,n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+Data2(a[i]);
		st1.Update(1,1,n+1,1,i,Data1(a[i]));
		st1.Update(1,1,n+1,i+1,i+1,s[i]);
		p[i]=st1.Query(1,1,n+1,1,i+1);
	}
	st1.Build(1,1,n+1);st2.Build(1,1,n+1);
	for(int i=1;i<=n/2;i++)swap(a[i],a[n-i+1]);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		st1.Update(1,1,n+1,1,i,Data1(a[i]));
		st1.Update(1,1,n+1,i+1,i+1,s[i]);
		st2.Update(1,1,n+1,1,i,Data2(a[i]));
		st2.Update(1,1,n+1,i+1,i+1,s[i]);
		g[i]=min(st1.Query(1,1,n+1,1,i+1),st2.Query(1,1,n+1,1,i+1));
	}
	st1.Build(1,1,n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+Data2(a[i]);
		st1.Update(1,1,n+1,1,i,Data1(a[i]));
		st1.Update(1,1,n+1,i+1,i+1,s[i]);
		q[i]=st1.Query(1,1,n+1,1,i+1);
	}
	for(int i=0;i<=n;i++){
		ans=min(ans,f[i]+q[n-i]);
		ans=min(ans,g[n-i]+p[i]);
	}
	cout<<ans<<'\n';
	return 0;
}
