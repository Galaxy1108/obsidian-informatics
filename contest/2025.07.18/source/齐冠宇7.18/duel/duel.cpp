#include <bits/stdc++.h>
using namespace std;
constexpr int N=2e5+5;
int n,q;
int a[N];
int f[N][20];
int len;
int find(int u,int l)
{
	return (l<=len)?f[u][l]:abs(find(u,l-1)-find(u+(1<<(l-1)),l-1));
}
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	len=log2(n)/2;
	for(int i=1;i<=n;i++)
		cin>>a[i],f[i][0]=a[i];
	for(int j=1;j<=len;j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
			f[i][j]=abs(f[i][j-1]-f[i+(1<<(j-1))][j-1]);
//	for(int i=1;i<=n;i++)
//	{
//		cout<<f[i][0]<<' '<<f[i][1]<<'\n';
//	}
	while(q--)
	{
		int op,l,r;
		cin>>op>>l>>r;
		if(op==1)
		{
			f[l][0]=r;
			for(int j=1;j<=len;j++)
				for(int i=l;i>=1 && i+(1<<j)-1>=l;i--)
					f[i][j]=abs(f[i][j-1]-f[i+(1<<(j-1))][j-1]);
		}
		else
			cout<<find(l,r)<<'\n';
	}
	return 0;
}
