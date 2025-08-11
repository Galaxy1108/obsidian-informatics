#include <bits/stdc++.h>
using namespace std;
int f[15][15];
int x[15];
int p[15],q[15];
int n,m,t,l;
void floyd()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				if(i!=j and j!=k and i!=k)
				{
					f[i][k]=min(f[i][j]+f[j][k],f[i][k]);
				}
			}
		}
	}
	return;
}
int main()
{
	freopen("wildboar.in","r",stdin);
	freopen("wildboar.out","w",stdout);
	memset(f,0x3f,sizeof(f));
	cin>>n>>m>>t>>l;
	for(int i=1;i<=m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		f[a][b]=c;
	}
	for(int i=1;i<=l;i++)
	{
		cin>>x[i];
	}
	for(int i=1;i<=t;i++)
	{
		cin>>p[i]>>q[i];
//		x[p[i]]=q[i];
//		int ans=0;
//		bool flag=true;
//		floyd();
//		for(int j=1;j<l;j++)
//		{
//			ans+=f[x[j]][x[j+1]];
//			if(f[x[j]][x[j+1]]==0x3f)
//			{
//				flag=false;
//				break;
//			}
//		}
//		if(flag)
//		{
//			cout<<ans<<endl;
//		}
//		else
//		{
			cout<<-1<<endl;
//		}
	}
	return 0;
}
