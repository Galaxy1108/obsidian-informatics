#include<cstdio>
using namespace std;
const int inf=999999999;
int f1[110][12];
int g[110][110];
int max(int a,int b){return a>b?a:b;}
void init(int* A,int n)
{
	for(int i=1;i<=n;++i)
		for(int j=i;j<=n;++j)
		{
			g[i][j]=-inf;
			int sum=0;
			for(int l=i;l<=j;++l)
			{
				sum+=A[l];
				g[i][j]=max(g[i][j],sum);
				if(sum<0)sum=0;
			}
		}
}
int solve(int* A,int n,int k)//n^3
{
	if(!k)return 0;
	init(A,n);
	for(int i=1;i<=n;++i)
		for(int l=1;l<=k;++l)
			f1[i][l]=-inf;
	f1[1][1]=A[1];
	for(int i=2;i<=n;++i)
		for(int l=1;l<=k;++l)
		{
			if(l>i)break;
			if(l==1){f1[i][l]=g[1][i];continue;}
			for(int mid=2;mid<=i;++mid)
				f1[i][l]=max(f1[i][l],f1[mid-1][l-1]+g[mid][i]);
		}
	return f1[n][k];
}
int n,m,k;
int a[110],b[110];
int main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	if(m==1)for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	if(m==2)for(int i=1;i<=n;++i)scanf("%d%d",&a[i],&b[i]);
	
	if(m==1)printf("%d",solve(a,n,k));
	else//k*n^3
	{
		int ans=-inf;
		for(int p=0;p<=k;++p)
			ans=max(ans,solve(a,n,p)+solve(b,n,k-p));
		printf("%d",ans);
	}
	return 0;
}
