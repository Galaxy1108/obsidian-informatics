#include <bits/stdc++.h>
#define Mod 1000000007
using namespace std;
int Qread()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
	return x;
}
inline int chk(int a){return a>=Mod?a-Mod:a;}
inline void add(int &a,int b){a+=b;if(a>=Mod) a-=Mod;}
int n,cnt1,cnt0,ans;
bool sd[1210];
int C[610][610],g[610],f[1210][610];
int main()
{
	freopen("ruin.in","r",stdin);
	freopen("ruin.out","w",stdout);
	n=Qread();
	for(int i=1;i<=n;i++)
		sd[Qread()]=true;
	for(int i=0;i<=n;i++)
	for(int j=0;j<=i;j++)
		if(j==0||i==j) C[i][j]=1;
		else C[i][j]=chk(C[i-1][j]+C[i-1][j-1]);
	g[0]=1;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=i;j++)
		add(g[i],(long long)C[i-1][j-1]*(j+1)%Mod*g[i-j]%Mod*g[j-1]%Mod);

	f[2*n][0]=1;
	for(int i=2*n;i;i--)
	{
		for(int j=0;j<=n;j++)
		if(f[i][j])
		{
			if(sd[i])
			{
				add(f[i-1][j],f[i][j]);
				for(int k=j+1;k<=n;k++)
					add(f[i-1][k],(long long)f[i][j]*C[cnt1-j][k-j-1]%Mod*(k-j+1)%Mod*g[k-j-1]%Mod);
			}
			else
			{
				add(f[i-1][j],(long long)f[i][j]*(j-cnt0)%Mod);
			}
		}
		if(sd[i]) cnt1++;else cnt0++;
	}

	ans=f[0][n];
	for(int i=1;i<=n;i++)
		ans=(long long)ans*500000004%Mod;
	printf("%d\n",ans);
	return 0;
}