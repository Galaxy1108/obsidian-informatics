#include<bits/stdc++.h>
using namespace std;
#define re register 

const int mod=9999973;
const int N=110;
int n,m;
int f[N][N];
int twopow[N*N];

inline int C(int a,int b)
{
	a%=mod;b%=mod;
	if(a==b)return 1;
	int pdct=1;
	for(re int i=1;i<=a;i++)
	{
		pdct*=(b-a+1)%mod;
		pdct%=mod;
	}
	for(re int i=1;i<=a;i++)
	{
		pdct/=(i)%mod;
		pdct%=mod;
	}
	return pdct;
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	twopow[0]=1;
	for(re int i=1;i<=10005;i++)twopow[i]=(twopow[i-1]%mod*2)%mod;
	for(re int i=1;i<=n;i++)
	{
		for(re int j=1;j<=m;j++)
		{
			f[i][j]= (  f[i-1][j]%mod+(i-1)*(i-2)/2+f[i][j-1]%mod+(j-1)*(j-2)/2 ) %mod;
//			cout<<i<<" "<<j<<" "<<f[i][j]<<endl;
		}
	}
	int ans=0;
	f[n][m]%=mod;
//	cout<<f[n][m]<<endl;
	for(re int i=1;i<=f[n][m];i++)
	{
		ans+=C(i%mod,f[n][m]%mod)%mod;
	}
//	ans=C(f[n][m]);
	cout<<(twopow[m*n]%mod-ans%mod+mod)%mod<<endl;
	
	return 0;
}
