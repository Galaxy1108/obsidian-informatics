#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,lim;
int f[25005][25][2];
int e[25005][25];//第is在j处有价值为w的人 
int maxn;
int sniper[25005];//第i秒有sniper在u 
int v[]={0,100,100,97,96,95,90,85,80,82,78,75,70,65,55,50,15,12,10,8,5,2};
signed main()
{
	freopen("sniper.in","r",stdin);
	freopen("sniper.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	memset(sniper,-1,sizeof(sniper)); 
	for(int i=1,w,u,t;i<=n;i++)
	{
		cin>>w>>u>>t;
		e[t][u]=w;
		if(w==15)sniper[t]=u;
		if(i==n)lim=t;
	}
	for(int i=1;i<=lim;i++)
	{
		for(int j=1;j<=20;j++)
		{
			if(sniper[i]==-1)//当前不是狙击手才生效
			{
				f[i][j][0]=max(f[i][j][0],f[i-1][j][1]);//上一秒杀人，这一秒不动
				for(int p=j-2;p<=j+2;p++)f[i][j][0]=max(f[i][j][0],f[i-1][p][0]);//上一秒没杀人，这一秒可以移动 
			} 
			
			if(sniper[i+1]==-1 && e[i][j])//如果下一s没sniper那就看当前j处是否有敌人,如果这一秒有sniper只杀sniper 
			{
				if(sniper[i]!=-1 && sniper[i]!=j)continue;//当前有sniper但是不在当前位置 
				for(int p=j-2;p<=j+2;p++)f[i][j][1]=max(f[i][j][1],f[i-1][p][0]+v[e[i][j]]);
			}
		}
	}
	for(int j=1;j<=20;j++)maxn=max(maxn,max(f[lim][j][1],f[lim][j][0]));
	cout<<maxn;
	return 0;
} 
