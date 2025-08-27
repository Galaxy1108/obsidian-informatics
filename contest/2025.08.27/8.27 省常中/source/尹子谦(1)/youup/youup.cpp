#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e4+10,p=998244353;
int qp(int a,int b) 
{
  int ans = 1;
  a = (a % p + p) % p;
  for (; b; b >>= 1) 
  {
    if (b & 1) ans = (a * ans) % p;
    a = (a * a) % p;
  }
  return ans;
}
vector<int>edge[N];
int jc[N],jcn[N],inv[N],d[N],dis[2010][2010],cnt,ch[N],num,n,x;
bool vis[N];
void dfs(int rt,int u,int fa,int len)
{
	dis[rt][u]=len;
	for(int v:edge[u]) if(v!=fa) dfs(rt,v,u,len+1);
}
void getans(int step,int tot)
{
	if(step>tot)
	{
		//for(int i=1;i<=tot;i++) cout<<ch[i]<<' ';
		//cout<<endl;
		cnt++; 
		return ;
	} 
	for(int i=1;i<=n;i++)
	{
		
		if(vis[i]) continue;
		bool can=1;
		for(int j=1;j<step;j++)
		{
			if(dis[i][ch[j]]>x)
			{
				can=0;
				break;
			}
		} 
		if(!can) continue;
		vis[i]=1;
		ch[step]=i;
		getans(step+1,tot);
		vis[i]=0;
	}
}
signed main()
{
	freopen("youup.in","r",stdin);
	freopen("youup.out","w",stdin);
	cin>>num;
	cin>>n>>x;
	jc[0]=1;
	for(int i=1;i<=n;i++) jc[i]=jc[i-1]*i%p;
	for(int i=1;i<=n;i++) jcn[i]=qp(jc[i],p-2)%p;
	for(int i=2;i<=n;i++)
	{
		int x,y;
		cin>>x>>y;
		edge[x].push_back(y);
		edge[y].push_back(x);
		d[x]++,d[y]++;
	} 
	if(x==0)
	{
		cout<<n<<' ';
		for(int i=2;i<=n;i++) cout<<0<<' ';
		return 0;
	}
	else if(d[x]==n-1)
	{
		if(x==1)
		{
			cout<<n<<' '<<n-1<<' ';
			for(int i=3;i<=n;i++) cout<<0<<' ';
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				cout<<jc[n]*jcn[i]%p*jcn[n-i]%p<<' ';
			}
		}
	}
	else
	{
		for(int i=1;i<=n;i++) dfs(i,i,-1,0);
		for(int i=1;i<=n;i++)
		{
			memset(vis,0,sizeof vis);
			cnt=0;
			getans(1,i);
			cout<<cnt*jcn[i]%p<<' ';
		}
	}
	return 0;
} 
