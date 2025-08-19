#include<bits/stdc++.h>
using namespace std;
const int mx=10000;
int s[25100];
int sc[22]={0,100,100,97,96,95,90,85,80,82,78,75,70,65,55,50,15,12,10,8,5,2};
int f[25100][30][3];
int a[25100][30];
int n;
struct sod
{
	int w,u,t;
}so[mx];
int fread()
{
	int x=0,w=1;char ch=getchar();
	while(ch>'9'||ch<'0') w=ch=='-'?-1:1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch-'0'),ch=getchar();
	return x*w;
 } 
int main()
{
	freopen("sniper.in","r",stdin);
	freopen("sniper.out","w",stdout);
	n=fread();
	int tmax=0;
	for(int i=1;i<=n;i++)
	{
		so[i].w=fread(),so[i].u=fread(),so[i].t=fread();
		tmax=max(tmax,so[i].t);
		if(so[i].w==15) s[so[i].t]=so[i].u;
		a[so[i].t][so[i].u]=sc[so[i].w];
	}
//	memset(f,-0x3f,sizeof(f));
//	f[0][0][0]=f[0][0][1]=0;
	for(int i=1;i<=tmax;i++)
	{
		for(int j=1;j<=20;j++)
		{
			if(s[i]&&s[i]!=j) continue;
			for(int k=max(0,j-2);k<=min(20,j+2);k++)
			{
				f[i][j][1]=max(f[i][j][1],f[i-1][k][0]+a[i][j]);
				f[i][j][0]=max(f[i][j][0],f[i-1][k][0]);
			}
			f[i][j][0]=max(f[i][j][0],f[i-1][j][1]);
			if(s[i]) f[i][j][0]=0;
//			cout<<i<<' '<<j<<' '<<f[i][j][0]<<' '<<f[i][j][1]<<endl;
		}
	 } 
	 int ans=-2e9;
	 for(int i=1;i<=20;i++)
	 {
	 	ans=max(ans,f[tmax][i][0]);
	 	ans=max(ans,f[tmax][i][1]);
	 }
	 cout<<ans;
	return 0;
}
