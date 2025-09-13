#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

#define fi first
#define se second
#define pb push_back
#define mkp make_pair
typedef pair<int,int>pii;
typedef vector<int>vi;

#define maxn 2000005
#define inf 0x3f3f3f3f

bool mbe;
int n,L,R,fa[maxn];
char s[maxn];
int sum[maxn];

int gf(int x){
	while(x^fa[x])x=fa[x]=fa[fa[x]];
	return x;
}

//0~20 1024576
bool med;

pii o[maxn*2]; int len;
void merge(int x,int l,int r){
	if(l>r)return;
//	cout<<"merge "<<x<<' '<<l<<' '<<r<<"\n";
	int xl=l,xr=r;
	l=gf(l);
	while(l+1<=r)fa[l]=l+1,l=gf(l);
//	puts("done");
	o[++len]=mkp(x,xl);
}

signed main()
{
	freopen("virtual.in","r",stdin);
	freopen("virtual.out","w",stdout);
//	fprintf(stderr, "%.3lf MB\n", (&mbe - &med) / 1048576.0);
	n=read(),L=read(),R=read();
	scanf("%s",s+1);
	For(i,1,n)sum[i]=sum[i-1]+(s[i]=='a');
	For(i,1,n+1)fa[i]=i;
	int l=1,r=1;
	For(i,1,n){
		if(sum[i]<L)continue;
		while(sum[i]-sum[l-1]>R)++l;
		while(sum[i]-sum[r-1]>=L)++r;
		// [l,r)
		merge(i,l,r-1);
	}
	l=n,r=n;
	Rep(i,n,1){
		if(sum[n]-sum[i-1]<L)continue;
		while(sum[r]-sum[i-1]>R)--r;
		while(sum[l]-sum[i-1]>=L)--l;
		merge(i,l+1,r);
	}
	For(i,1,len){
		int u=o[i].fi,v=o[i].se;
		fa[gf(u)]=gf(v);
	}
	int Q=read();
	For(_,1,Q){
		int x=read(),y=read();
		puts(gf(x)==gf(y)?"Yes":"No"); 
	}
	return 0;
}