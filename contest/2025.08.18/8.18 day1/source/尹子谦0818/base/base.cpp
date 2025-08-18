#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=10010;
int n,m;
int v[3][N],l[N],r[N],pre[3][N];
signed main()
{
	freopen("base4.in","r",stdin);
	freopen("base.out","w",stdout);
	cin>>n;
	for(int i=1;i<=2;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>v[i][j];
			pre[i][j]=pre[i][j-1]+v[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		l[i]=-1e9;
		int len=0;
		for(int j=i;j>=1;j--)
		{
			len+=v[1][j]+v[2][j];
			l[i]=max(l[i],len);
		}
	}
	for(int i=1;i<=n;i++)
	{
		r[i]=-1e9;
		int len=0;
		for(int j=i;j<=n;j++)
		{
			len+=v[1][j]+v[2][j];
			r[i]=max(r[i],len);
		}
	}
	//for(int i=1;i<=n;i++) cout<<l[i]<<' '<<r[i]<<endl;
	int ans=-1e9;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+2;j<=n;j++)
		{
			ans=max(ans,l[i]+r[j]+pre[2][j-1]-pre[2][i]);
			//ans=max(ans,l[i]+r[i]+pre[1][j-1]-pre[1][i]);
		}
	}
	cout<<ans;
	return 0;
} 
