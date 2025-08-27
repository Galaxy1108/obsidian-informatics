#include<cstdio>
#define ll long long
using namespace std;
const int N=2e4+10,M=2263,B=500;
int mod,len,n,p[M],u[M],f[N][M],s[N][M];
struct matrix{
	int a[2][2];
}h1[M][B+1],h2[M][B+1],c,I;
int vis[N];
matrix operator *(matrix a,matrix b)
{
	matrix c;
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			c.a[i][j]=(1ll*a.a[i][0]*b.a[0][j]
				+1ll*a.a[i][1]*b.a[1][j])%mod;
	return c;
}
void work(int s,int id)
{
	for(int i=s;i<=n;i+=s)
		f[i][id]++;
}
int calc(int i,int x)
{
	if(x==0) return 1;
	c=h1[i][x%B]*h2[i][x/B];
	return c.a[1][0]+c.a[1][1];
}
int main()
{
	freopen("gonna.in","r",stdin);
	freopen("gonna.out","w",stdout);
	scanf("%d%d",&n,&mod);
	for(int i=2;i<=n;i++)
	{
		if(!vis[i]) p[++len]=i;
		for(int j=1;j<=len&&i*p[j]<=n;j++)
		{
			vis[i*p[j]]=1;
			if(i%p[j]==0) break;
		}
	}
	I.a[0][0]=I.a[1][1]=1;
	for(int i=1;i<=len;i++)
	{
		for(int s=p[i];s<=n;s*=p[i])
			work(s,i);
		h1[i][0]=h2[i][0]=I;
		h1[i][1].a[0][0]=h1[i][1].a[1][0]=p[i];
		h1[i][1].a[1][1]=1;
		for(int j=2;j<=B;j++) h1[i][j]=h1[i][j-1]*h1[i][1];
		h2[i][1]=h1[i][B];
		for(int j=2;j<=B;j++) h2[i][j]=h2[i][j-1]*h2[i][1];
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=len;j++)
			s[i][j]=s[i-1][j]+f[i][j];
	ll sum=0,ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=len;j++)
			u[j]+=i*f[i][j]-s[i][j];
		ans=1;
		for(int j=1;j<=len;j++)
			ans=ans*calc(j,u[j])%mod;
		sum=(sum+ans)%mod;
	}
	printf("%lld",sum);
}