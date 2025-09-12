#include <iostream>
#include <vector>
using namespace std;
int T;
int n;
vector<int>ne[200010];
bool del[200010];
int sz[200010];
int ms[200010];
int pc[1<<20];
namespace bl{
	bool vs[1<<20];
	int ans[1<<20];
	int dfs(int now,int st)
	{
		int rs=(1<<now-1);
		for(int s:ne[now]) if((1<<s-1)&st) rs+=dfs(s,st-(1<<now-1));
		return rs;
	}
	int solve(int st)
	{
		if(vs[st]) return ans[st];
		if(!st) return 0;
		vs[st]=1;
		if(pc[st]==1) return ans[st]=1;
		if(pc[st]==2) return ans[st]=2;
		for(int i=0;i<n;++i) if(st&(1<<i))
		{
			int rs=0;
			for(int s:ne[i+1]) if(st&(1<<s-1))
				rs=max(rs,solve(dfs(s,st-(1<<i)))+1);
			ans[st]=min(ans[st],rs);
		}
		return ans[st];
	}
	void man()
	{
		for(int s=0;s<(1<<n);++s) vs[s]=0,ans[s]=n+1;
		cout<<solve((1<<n)-1)<<'\n';
	}
}
namespace lg{
	int S,nr,rt;
	vector<int>yz;
	void gts(int now,int fa)
	{
		++S;
		int d=0;
		for(int s:ne[now]) if(s!=fa && !del[s]) gts(s,now),++d;
		d+=(fa!=0);
		if(d==1) yz.push_back(now);
		else nr=now;
	}
	void gr(int now,int fa)
	{
		sz[now]=1;
		ms[now]=0;
		for(int s:ne[now]) if(s!=fa && !del[s])
			gr(s,now),sz[now]+=sz[s],ms[now]=max(ms[now],sz[s]);
		ms[now]=max(ms[now],S-sz[now]);
		if(ms[now]+ms[now]<=S) rt=now;
	}
	int solve(int now)
	{
		S=0;
		yz.clear();
		gts(now,0);
		if(S==1) return 1;
		if(S==2) return 2;
		if(yz.size()*6>=S*11)
		{
			for(int s:yz) del[s]=1;
			return solve(nr)+1;
		}
		else
		{
			gr(now,0);
			del[rt]=1;
			int mx=0;
			for(int s:ne[rt]) if(!del[s]) mx=max(mx,solve(s));
			return mx+1;
		}
	}
	void man()
	{
		cout<<solve(1)<<'\n';
	}
}
int main()
{
	freopen("labyrinth.in","r",stdin);
	freopen("labyrinth.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	for(int s=1;s<(1<<20);++s) pc[s]=pc[s-(s&-s)]+1;
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1,u,v;i<n;++i)
		{
			cin>>u>>v;
			ne[u].push_back(v);
			ne[v].push_back(u);
		}
		if(n<=20) bl::man();
		else lg::man();
		for(int i=1;i<=n;++i) ne[i].clear(),del[i]=0;
	}
	return 0;
}
