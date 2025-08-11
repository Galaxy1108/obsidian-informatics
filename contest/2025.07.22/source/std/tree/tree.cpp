#include <bits/stdc++.h>
#define Mod 998244353
using namespace std;
int Qread()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
	return x;
}
inline void add(int &a,int b){a+=b;if(a>=Mod) a-=Mod;}
inline void del(int &a,int b){a-=b;if(a<0) a+=Mod;}
int inv[5010];
int n,m;
int l[5010],r[5010];
int dp[5010][5010];
int ad[5010][5010];
int ans[5010],gx;
inline void recta(int l,int r,int u,int d,int x)
{
	add(ad[l][d],x),add(ad[r+1][u-1],x);
	del(ad[l][u-1],x),del(ad[r+1][d],x);
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	
	n=Qread();
	for(int i=2;i<=n;i++) l[i]=Qread(),r[i]=Qread();
	m=Qread();
	for(int i=1,u,v;i<=m;i++)
	{
		u=Qread(),v=Qread();
		if(u>v) swap(u,v);
		add(dp[u][v],Qread());
	}

	inv[1]=1;
	for(int i=2;i<=n;i++) inv[i]=1ll*(Mod-Mod/i)*inv[Mod%i]%Mod;
	
	for(int j=n;j>1;j--)
	{
		for(int i=1;i<=j;i++) add(ad[i][j],ad[i-1][j]);
		for(int i=1;i<=j;i++) add(ad[i][j],ad[i][j+1]),add(dp[i][j],ad[i][j]);
		for(int i=1;i<j;i++)
		{
			add(ans[j],dp[i][j]);
			gx=1ll*inv[r[j]-l[j]+1]*dp[i][j]%Mod;
			if(r[j]<=i) recta(l[j],r[j],i,i,gx);
			else if(i<l[j]) recta(i,i,l[j],r[j],gx);
			else recta(l[j],i,i,i,gx),recta(i,i,i+1,r[j],gx);
		}
	}

	for(int i=2;i<=n;i++) printf("%d%c",ans[i]," \n"[i==n]);
	return 0;
}