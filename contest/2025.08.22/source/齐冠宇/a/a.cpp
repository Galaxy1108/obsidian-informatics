#include<bits/stdc++.h>
using namespace std;
constexpr int N=1e7+5;
int n,m,mod;
int f[N],g[N];
int s1[N],s2[N];
int s3[N],s4[N];
inline int add(int x,int y)
{
	x+=y;if(x>mod) x-=mod;
	return x; 
}
inline int del(int x,int y)
{
	x-=y;if(x<0) x+=mod;
	return x;
}
#define id(i,j) ((j)==0?0:(i-1)*m+(j))
void init()
{
	for(int i=1;i<=m;i++)
		f[i]=m-i+1,g[i]=i;
	for(int j=1;j<=m;j++)
	{
		s1[id(1,j)]=(s1[id(1,j-1)]+f[id(1,j)])%mod;
		s2[id(1,j)]=(s2[id(1,j-1)]+g[id(1,j)])%mod;
		s3[id(1,j)]=(s3[id(1,j-1)]+1ll*f[id(1,j)]*j%mod)%mod;
		s4[id(1,j)]=(s4[id(1,j-1)]+1ll*g[id(1,j)]*j%mod)%mod;
	}
}
inline void upd(int *s,int *f,int i,int j,int vl)
{
	s[id(i,j)]=(s[id(i,j-1)]+1ll*vl*f[id(i,j)]%mod)%mod;
}
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0); 
	cin>>n>>m>>mod;
	init();
	for(int i=2;i<=n;i++)
	{
		int sum=s1[id(i-1,m)];
		for(int j=1;j<=m;j++)
			f[id(i,j)]=add(del(1ll*sum*(m-j+1)%mod,add(1ll*s2[id(i-1,j-1)]*(m-j+1)%mod,del(s3[id(i-1,m)],s3[id(i-1,j)]))),1ll*del(s1[id(i-1,m)],1ll*s1[id(i-1,j)])*j%mod),g[id(i,j)]=add(del(1ll*sum*j%mod,add(1ll*del(s1[id(i-1,m)],s1[id(i-1,j)])*j%mod,1ll*s2[id(i-1,j-1)]*j%mod)),s4[id(i-1,j-1)]);
		for(int j=1;j<=m;j++)
			upd(s1,f,i,j,1),upd(s2,g,i,j,1),upd(s3,f,i,j,j),upd(s4,g,i,j,j);
	}
	cout<<s1[id(n,m)];
	return 0;
}
