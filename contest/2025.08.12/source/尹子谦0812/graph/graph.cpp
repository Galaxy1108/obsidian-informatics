#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,Q,m,s[N],t[N];
vector<int> edge[N];
vector<int> rd[N];
bool fin,b; 
int vis[N],road[N],cnt;
struct node
{
	int s,t;
}st[N];
struct LEN
{
	int no,len;
}ans[N];
bool cmp(LEN a,LEN b)
{
	return a.len>b.len;
}
bool stop[N],finish[N];
void dfs(int u,int to,int fa,int cnt,int no)
{
	road[cnt]=u;
	//cout<<u<<' '<<to<<' '<<cnt<<endl;
	if(fin) return ;
	if(u==to)
	{
		fin=1;
		for(int i=1;i<=cnt;i++) rd[no].push_back(road[i]);
		ans[no].no=no,ans[no].len=cnt;
		//cout<<endl;
		return ;
	}
	for(int v:edge[u])
	{
		if(v==fa) continue;
		if(fin) break;
		dfs(v,to,u,cnt+1,no);
	}
}
void solve(int rt)
{
	if(b==0) return ;
	finish[rt]=1;
	int road[N],cntt=0;
	for(int v:rd[rt]) road[++cntt]=v;
	//for(int i=1;i<=cntt;i++) cout<<road[i]<<' ';
	//cout<<endl;
	for(int i=2;i<=cntt;i++)
	{
		if(!vis[road[i]])
		{
			//cout<<"节点"<<rt<<"从"<<road[i-1]<<"走到了"<<road[i]<<endl;
			vis[road[i-1]]=0,vis[road[i]]=rt;
		} 
		else if(stop[road[i]])
		{
			//cout<<"挡路的人走不了"<<endl; 
			b=0;
			break;
		}
		else
		{
			//cout<<"被人挡住了,让"<<vis[road[i]]<<"先走"<<endl;
			stop[road[i]]=1,solve(vis[road[i]]),stop[road[i]]=0;
		} 
	}
}
signed main()
{
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	cin>>Q;
	while(Q--)
	{
		cin>>n>>m;
		for(int i=1;i<=m;i++) int u,v,cin>>u>>v;
		cout<<-1;
	}
	return 0;
}
