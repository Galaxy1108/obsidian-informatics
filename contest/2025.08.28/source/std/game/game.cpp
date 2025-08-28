#include <bits/stdc++.h>
using namespace std;
int Qread()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
	return x;
}
struct Node{
	int son0,son1;
	int cnt,laz;
}s[4000010];
int bg;
int get_node()
{
	int ret=bg;bg=s[bg].son1;s[ret].son1=0;
	return ret;
}
void del_node(int x)
{
	s[x].son0=s[x].cnt=s[x].laz=0;
	s[x].son1=bg;bg=x;
}
void giv_laz(int pos,int laz,int nw)
{
	s[pos].laz^=laz;
	if(laz&nw) swap(s[pos].son0,s[pos].son1);
}
void pushdown(int pos,int nw)
{
	if(s[pos].laz)
		giv_laz(s[pos].son0,s[pos].laz,nw>>1),
		giv_laz(s[pos].son1,s[pos].laz,nw>>1),
		s[pos].laz=0;
}
void update(int pos)
{
	s[pos].cnt=s[s[pos].son0].cnt+s[s[pos].son1].cnt;
}
void add_num(int x,int &pos,int nw)
{
	if(!pos) pos=get_node();
	if(nw==0) return s[pos].cnt=1,void();
	pushdown(pos,nw);
	if(x&nw) add_num(x,s[pos].son1,nw>>1);
	else add_num(x,s[pos].son0,nw>>1);
	update(pos);
}
void merge(int &pos1,int pos2,int nw)
{
	if(pos1&&pos2)
	{
		if(nw==0) s[pos1].cnt|=s[pos2].cnt;
		else pushdown(pos1,nw),pushdown(pos2,nw),
			merge(s[pos1].son0,s[pos2].son0,nw>>1),
			merge(s[pos1].son1,s[pos2].son1,nw>>1),
			update(pos1);
		del_node(pos2);
	}
	else pos1^=pos2;
}
int qry(int pos,int nw)
{
	if(nw==0) return 0;
	pushdown(pos,nw);
	if(s[s[pos].son0].cnt==nw) return qry(s[pos].son1,nw>>1)^nw;
	else return qry(s[pos].son0,nw>>1);
}
int n,bas;
int fa,nxt[2000010],p[2000010];
int val[2000010],bson[2000010];
int stk[2000010],top,cur[2000010];
void dfs(int a)
{
	val[a]=1,bson[a]=0;
	for(int v=p[a];v;v=nxt[v])
	{
		dfs(v);
		val[a]+=val[v];
		if(val[v]>val[bson[a]]) bson[a]=v;
	}
}
int rt[2000010];
void calc(int a)
{
	int tmp=0;
	if(bson[a])
	{
		calc(bson[a]);
		rt[a]=rt[bson[a]];
		tmp=val[bson[a]];
	}
	for(int v=p[a];v;v=nxt[v]) if(v!=bson[a])
	{
		calc(v);
		giv_laz(rt[a],val[v],bas),giv_laz(rt[v],tmp,bas);
		tmp^=val[v];
		merge(rt[a],rt[v],bas);
	}
	add_num(tmp,rt[a],bas);
	val[a]=qry(rt[a],bas);
}
int u;
int solve()
{
	memset(p,0,(n+1)<<2),memset(nxt,0,(n+1)<<2);
	memset(rt,0,(n+1)<<2),memset(val,0,(n+1)<<2);

	n=Qread();
	bas=1;while((bas<<1)<=n) bas<<=1;
	for(int i=2;i<=n;i++)
	{
		fa=Qread();
		nxt[i]=p[fa],p[fa]=i;
	}

	memcpy(cur,p,(n+1)<<2);
	memset(val,0,(n+1)<<2);
	stk[top=1]=1;
	while(top)
	{
		u=stk[top];
		if(cur[u])
		{
			stk[++top]=cur[u],val[cur[u]]=1,bson[cur[u]]=0;
			cur[u]=nxt[cur[u]];
		}
		else
		{
			top--;
			val[stk[top]]+=val[u];
			if(val[u]>val[bson[stk[top]]]) bson[stk[top]]=u;
		}
	}

	memset(cur,-1,(n+1)<<2);
	memset(val,0,(n+1)<<2);
	stk[top=1]=1;
	while(top)
	{
		u=stk[top];
		if(cur[u]==-1)
		{
			if(bson[u]) stk[++top]=bson[u];
			cur[u]=p[u];
		}
		else
		{
			while(cur[u]&&cur[u]==bson[u]) cur[u]=nxt[cur[u]];
			if(cur[u]) stk[++top]=cur[u],cur[u]=nxt[cur[u]];
			else
			{
				top--;
				add_num(val[u],rt[u],bas);
				val[u]=qry(rt[u],bas);
				if(top)
				{
					giv_laz(rt[stk[top]],val[u],bas),giv_laz(rt[u],val[stk[top]],bas);
					val[stk[top]]^=val[u];
					merge(rt[stk[top]],rt[u],bas);
				}
			}
		}
	}

	return val[1];
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	
	bg=1;
	for(int i=1;i<=4000000;i++)
		s[i].son1=i+1;

	int T=Qread(),ans=0;
	while(T--) ans^=solve();
	printf("%d\n",ans);
	return 0;
}