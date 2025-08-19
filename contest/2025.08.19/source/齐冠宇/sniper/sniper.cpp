#include <bits/stdc++.h>
using namespace std;
constexpr int N=8005;
constexpr int val[]={0,100,100,97,96,95,90,85,80,82,78,75,70,65,55,50,15,12,10,8,5,2};
int n;
struct node{
	int w,u,t;
}e[N]; 
int f[N][25][2];
int ans;
inline void init(int id,int now,int last)
{
	for(int k=1;k<=20;k++)
	{
		for(int j=max(k-(now-last)*2,1);j<=min(k+(now-last)*2,20);j++)
			f[id][k][0]=f[id][k][1]=max(f[id][k][0],f[id-1][j][0]);
		for(int j=max(k-(now-last-1)*2,1);j<=min(k+(now-last-1)*2,20);j++)
		{
			if(now-last>1)
				f[id][k][1]=max(f[id][k][1],f[id-1][j][1]);
			f[id][k][0]=max(f[id][k][0],f[id-1][j][1]);
		}
	}
}
int main()
{
	freopen("sniper.in","r",stdin);
	freopen("sniper.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>e[i].w>>e[i].u>>e[i].t;
	int i=1,id=1;
	while(i<=n)
	{
		int last=e[i-1].t;
		int now=e[i].t;
		init(id,now,last);
		int sni=-1;
		while(i<=n && e[i].t==now)
		{
			f[id][e[i].u][1]+=val[e[i].w];
			if(e[i].w==15)
				sni=e[i].u;
			i++;
		}
		if(sni!=-1)
			for(int k=1;k<=20;k++)
			{
				f[id][k][0]=0;
				if(k!=sni)
					f[id][k][1]=0;
			}
		id++;
	}
	for(int i=1;i<=20;i++)
		ans=max(ans,max(f[id-1][i][0],f[id-1][i][1]));
	cout<<ans;
 	return 0;
}

