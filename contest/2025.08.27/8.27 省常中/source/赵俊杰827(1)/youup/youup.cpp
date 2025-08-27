#include<bits/stdc++.h>
using namespace std;
const int N=300005;
typedef long long ll;
const int MOD=998244353;
struct T
{
	int ne,to;
}e[2*N];
int he[N],idx,q[N],vis[25],f[25],dis[105][105],ans[N],x[N];
ll jc[N];
long long id,n,k;
void add(int x,int y)
{
	e[++idx].ne=he[x];
	e[idx].to=y;
	he[x]=idx;
}
ll mypow(ll a,ll b)
{
	if(b==0)return 1;
	ll mi=mypow(a,b>>1);
	mi=mi*mi%MOD;
	if(b&1)mi=mi*a%MOD;
	return mi;
}
ll C(int n,int k)
{
	return jc[n]*mypow(jc[k],MOD-2)%MOD*mypow(jc[n-k],MOD-2)%MOD;
}
void dfs(int p,int cnt)
{
	if(p>n)
	{
		ans[cnt]++;
		return;
	}
	dfs(p+1,cnt);
	bool flag=1;
	for(int i=1;i<=cnt;i++)
	{
		if(dis[x[i]][p]>k)
		{
			flag=0;
			break;
		}
	}
	if(flag)
	{
		cnt++;
		x[cnt]=p;
		dfs(p+1,cnt);
	}
}
int main()
{
	freopen("youup.in","r",stdin);
	freopen("youup.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>id>>n>>k;
	jc[0]=1;
	for(int i=1;i<=n;i++)jc[i]=jc[i-1]*i%MOD;
	if(k==0)
	{
		cout<<n<<' ';
		for(int i=2;i<=n;i++)cout<<0<<' ';
		cout<<'\n';
		return 0;
	}
	if(id==4)
	{
		if(k==1)
		{
			cout<<n<<' '<<n-1<<' ';
			for(int i=3;i<=n;i++)cout<<0<<' ';
			cout<<'\n';
			return 0;
		}
		for(int i=1;i<=n;i++)cout<<C(n,i)<<' ';
		cout<<'\n';
		return 0;
	}
	if(id==2)
	{
		for(int i=1;i<n;i++)
		{
			int x,y;
			cin>>x>>y;
			add(x,y);
			add(y,x);
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				int l=1,r=0;
				q[++r]=i;
				memset(f,0x3f,sizeof(f));
				memset(vis,0,sizeof(vis));
				f[i]=0;vis[i]=1;
				while(r>=l)
				{
					int x=q[l];l++;
					for(int i=he[x];i;i=e[i].ne)
					{
						int y=e[i].to;
						if(vis[y])continue;
						q[++r]=y;
						vis[y]=1;
						f[y]=f[x]+1;
					}
				}
				dis[i][j]=f[j];
			}
		}
		dfs(1,0);
		for(int i=1;i<=n;i++)cout<<ans[i]<<' ';
		return 0;
	}
	for(int i=1;i<=n;i++)cout<<C(n,i)<<' ';
	cout<<'\n';
	return 0;
}
