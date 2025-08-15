#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005;
int n,m,q,ver,ary[N][N],sum[N][N];
signed main()
{
	freopen("newfile.in","r",stdin);
	freopen("newfile.out","w",stdout);
	cin>>n>>m>>q;
	for(int num=1;num<=m;num++)
	{
		int l,r,x;
		cin>>l>>r>>x;
		ver++;
		for(int i=1;i<=n;i++)ary[ver][i]=ary[ver-1][i];
		for(int i=l;i<=r;i++)ary[ver][i]+=x;
	}
	for(int num=1;num<=m;num++)
		for(int i=1;i<=n;i++)
			sum[num][i]=sum[num][i-1]+ary[num][i];
	while(q--)
	{
		int u,d,l,r;
		cin>>u>>d>>l>>r;
		int anslt=0;
		for(int i=u;i<=d;i++)anslt+=(sum[i][r]-sum[i][l-1]);
		cout<<anslt<<endl;
	}
	
	return 0;
} 
