#include<bits/stdc++.h>
#include<queue>
using namespace std;
inline int qread()
{
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c))
	{
		x=x*10+(c^48);
		c=getchar();
	}
	return x*f;
}
#define re register
#define pii pair<int,int>
#define mkp make_pair
const int N=300+10;
int n;
struct edge
{
	int to,nxt;
} e[N*2];
int ttt,head[N];
inline void add(int a,int b)
{
	e[++ttt].to=b;
	e[ttt].nxt=head[a];
	head[a]=ttt;
}
int siz[N],son[N],fa[N];
inline void dfs(int rt,int father)
{
	siz[rt]=1;
	fa[rt]=father;
	son[rt]=-1;
	for(re int i=head[rt]; i; i=e[i].nxt)
	{
		int to=e[i].to;
		if(to==father)continue;
		dfs(to,rt);
		siz[rt]+=siz[to];
		if(son[rt]==-1||siz[son[rt]]<siz[to])son[rt]=to;
	}
}
queue< pii > q;
signed main()
{
	freopen("disease.in","r",stdin);
	freopen("disease.out","w",stdout);
	n=qread();
	int P=qread();
	while(P--)
	{
		int x=qread(),y=qread();
		add(x,y);
		add(y,x);
	}
	dfs(1,0);
	q.push(mkp(1,1));
	int last=1;
	int ans=0;
	int res=0;
	while(q.size())
	{
//		cout<<res<<endl;
		int now=q.front().first;
		int dep=q.front().second;
		ans++;
		q.pop();
		for(re int i=head[now]; i; i=e[i].nxt)
		{
			int to=e[i].to;
			if(to==fa[now])continue;
			if(to==son[now])continue;
			q.push(mkp(to,dep+1));
		}
	}
	cout<<ans<<endl;
	return 0;
}
/*
5 4
1 2
1 3
3 5
3 4

*/
