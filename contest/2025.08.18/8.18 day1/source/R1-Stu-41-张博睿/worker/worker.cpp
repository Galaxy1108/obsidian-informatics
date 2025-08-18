#include<bits/stdc++.h>
using namespace std;
const int N=102;

int n;
int a[N],b[N],c[N];
bool vis[N*2];
int ans=0x3f3f3f3f;
int res=0;

inline void dfs(int rt,int num,int siz,int qa,int qb,int qc)
{
	if(num<=siz-1||num<=0)
	{
		if(qa!=0)res++;if(qb!=0)res++;if(qc!=0)res++;
		ans=min(res,ans);
		return ;
	}
	for(register int i=rt;i<=rt+9;i++)
		vis[i]=1;
	int aa=a[rt+9]-a[rt],bb=b[rt+9]-b[rt],cc=c[rt+9]-c[rt];
	for(register int i=1;i<=n-siz+1;i++)
	{
		if(vis[i])continue;
		int j=1;int t=i;
		while(j<=siz)
		{
			if(!vis[t])
			{
				qa+=a[t]-a[t-1];
				qb+=b[t]-b[t-1];
				qc+=c[t]-c[t-1];
				j++;
			}
			t++;
		}
		res++;
		dfs(i,num-aa,10-aa,0,qb,qc);
		dfs(i,num-bb,10-bb,qa,0,qc);
		dfs(i,num-cc,10-cc,qa,qb,0);
	}
}
int main()
{
	freopen("worker.in","r",stdin);
	freopen("worker.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		char x;
		cin>>x;
		if(x=='A')a[i]++;
		else if(x=='B')b[i]++;
		else if(x=='C')c[i]++;
		a[i]+=a[i-1];b[i]+=b[i-1];c[i]+=c[i-1];
	}
	if(n<=10)
	{
		int ot=0;
		if(a[n]!=0)ot++;if(b[n]!=0)ot++;if(c[n]!=0)ot++;
		cout<<ot<<endl;
		return 0;
	}
	for(int i=1;i<=n-10+1;i++)
	{
		res=0;
		memset(vis,0,sizeof(vis));
		dfs(i,n,10,0,0,0);
	}
	cout<<ans<<endl;
	return 0;
}
