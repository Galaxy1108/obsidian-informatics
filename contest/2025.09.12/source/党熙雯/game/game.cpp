#include<bits/stdc++.h>
#define int long long
//#pragma GCC optimize(2)
using namespace std;
int g[200010];
int G[13][13];
int fread()
{
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9') f=ch=='-'?-1:1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}
signed main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int T=fread();
	while(T--)
	{
		int n=fread(),m=fread();
		if(n<=3000)
		{
			memset(G,0,sizeof(G));
			for(int i=1;i<=m;i++)
			{
				int u=fread(),v=fread(),w=fread();
				G[u][v]+=w; 
			}
			int maxn=0,se=0;
			for(int i=1;i<=n;i++)
			{
				for(int  j=1;j<=n;j++)
				{
					if(G[i][j]>=maxn) se=maxn,maxn=G[i][j];
					else if(G[i][j]<maxn) se=max(se,G[i][j]);
				}
			}
			cout<<se<<endl;
		}
		else
		{
			memset(g,0,sizeof(g));
			for(int i=1;i<=m;i++)
			{
				int u=fread();
				int v=fread(),w=fread();
				g[v]+=w;
			}
			int M=g[1];
			g[1]=0;
			sort(g+1,g+n+1);
			for(int i=n;g[i]!=0&&i!=1;i--)
			{
				M+=((n-i+1)%2==0)*g[i];
	//			A+=(i%2==1)*g[i];
			}
			cout<<M<<endl;
		}
	}
	return 0;
}


