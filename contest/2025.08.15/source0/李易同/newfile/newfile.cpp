#include <iostream>
using namespace std;
const int p=1000000009;
int n,m,q;
int l,r,x;
void ad(int &x1,int x2)
{
	x1+=x2;
	if(x1>=p) x1-=p;
}
int val[5010][5010];
long long sum[5010][5010];
int u,d;
int main()
{
	freopen("newfile.in","r",stdin);
	freopen("newfile.out","w",stdout);
	cin>>n>>m>>q;
	for(int i=1;i<=m;++i)
	{
		cin>>l>>r>>x;
		for(int j=1;j<=n;++j) val[i][j]=val[i-1][j];
		for(int j=l;j<=r;++j) ad(val[i][j],x);
	}
	for(int i=1;i<=m;++i)
		for(int j=1;j<=n;++j)
			sum[i][j]=(sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+val[i][j]+p)%p;
	while(q--)
	{
		cin>>d>>u>>l>>r;
		cout<<(sum[u][r]+sum[d-1][l-1]-sum[u][l-1]-sum[d-1][r]+p+p)%p<<'\n';
	}
	return 0;
}
