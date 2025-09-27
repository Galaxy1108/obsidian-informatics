#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[100005],st[100005][20],st_max[100005][20],st_xor[100005][20],LOG[100005],POW[25];
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	cin>>n;
	int ans=n;
	LOG[1]=0;
	for(int i=2;i<=n;i++)
		LOG[i]=LOG[i/2]+1;
	POW[0]=1;
	for(int i=1; ;i++)
	{
		POW[i]=POW[i-1]*2;
		if(POW[i]>=n)
			break;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		st[i][0]=i+1;
		st_max[i][0]=a[i];
		st_xor[i][0]=a[i];
	}
	for(int j=1;(1LL<<j)<=n;j++)
	{
		for(int i=1;i+(1LL<<j)-1<=n;i++)
		{
			st[i][j]=st[st[i][j-1]][j-1];
			st_max[i][j]=max(st_max[i][j-1],st_max[st[i][j-1]][j-1]);
			st_xor[i][j]=st_xor[i][j-1]^st_xor[st[i][j-1]][j-1];
		}
	}
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
		{
			int x=LOG[j-i+1];
			int maxn=max(st_max[i][x],st_max[j-POW[x]+1][x]);
			int pos=st[i][x];
			int xorr=st_xor[i][x];
			while(pos<=j)
			{
				int y=LOG[j-pos+1];
				xorr^=st_xor[pos][y];
				pos=st[pos][y];
			}
			if(xorr<=maxn)
				ans++;
		}
	cout<<ans;
	return 0;
}
