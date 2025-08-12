#include<bits/stdc++.h>
using namespace std;
const int mx=120100;
int fa[mx],h[mx],cnt,pre[mx][40],DFS[mx],SHO[mx],dep[mx],size[mx],flag[mx];//DFS为树的dfs序，SHO为dfs序的映射 
map<int,int> l,r;
struct edge
{
	int to,nxt;
}e[2*mx];
struct question
{
	int l,r,lca;
}q[mx];
void build(int u,int v)
{
	e[++cnt].to=v;
	e[cnt].nxt=h[u];
	h[u]=cnt;
	return ;
}
int fread()
{
	int x=0,w=1;char ch=getchar();
	while(ch<'0'||ch>'9') w=ch=='-'?-1:1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch-'0'),ch=getchar();
	return x*w;
 } 
void getfather(int u)
{
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].to;
		if(!fa[v]) fa[v]=u,dep[v]=dep[u]+1,getfather(v),size[u]+=size[v];
	}
	size[u]+=1;
	return ;
} //O(N)
void prep(int u)
{
	pre[u][0]=fa[u];
	for(int j=1;j<=21;j++)
	{
		pre[u][j]=pre[pre[u][j-1]][j-1];
		if(pre[u][j]==-1) break;
	}
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].to;
		if(v!=fa[u]) prep(v);
	}
}//O(nlogn)
int LCA(int l,int r)
{
	if(dep[l]>dep[r]) swap(l,r);
//	cout<<dep[l]<<' '<<dep[r]<<endl;
	for(int i=21;i>=0;i--)
	{
		if(dep[l]==dep[r]) break;
		if(dep[pre[r][i]]>=dep[l]&&pre[r][i]>0) r=pre[r][i];
	}
	if(l==r) return l;
	for(int i=21;i>=0;i--)
	{
		if(pre[l][i]==pre[r][i]) continue;
		else l=pre[l][i],r=pre[r][i];
	}
	l=fa[l],r=fa[r];
	return l;
}//O(nlogn)
void dfs(int u)
{
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].to;
		if(v!=fa[u]) DFS[++cnt]=v,SHO[v]=cnt,dfs(v);
	}
}//O(n)
bool cmp(question x,question y)
{
	if(size[x.lca]==size[y.lca])
	{
		if(SHO[x.lca]==SHO[y.lca])
		return SHO[x.l]>SHO[y.l];
		return SHO[x.lca]<SHO[y.lca];
	}
	return size[x.lca]<size[y.lca];
}
int main()
{
	freopen("jail.in","r",stdin);
	freopen("jail.out","w",stdout);
	int Q=fread();
	while(Q--)
	{
		cnt=0;
		memset(h,0,sizeof(h));
		memset(e,0,sizeof(e));
		memset(pre,0,sizeof(pre));
		memset(size,0,sizeof(size));
		memset(fa,0,sizeof(fa));
		memset(flag,0,sizeof(flag));
		memset(DFS,0,sizeof(DFS));
		memset(SHO,0,sizeof(SHO));
		int b=1;
		int n=fread();
		for(int i=1;i<n;i++)
		{
			int u=fread(),v=fread();
			build(u,v),build(v,u);
		}
		fa[1]=-1;
//		cout<<"??????\n";
		getfather(1);
//		for(int i=1;i<=n;i++)
//		cout<<fa[i]<<' ';
//		cout<<"???????\n";
		prep(1);
		int m=fread();
//		cout<<"?????\n";
		for(int i=1;i<=m;i++)
		{
			q[i].l=fread(),q[i].r=fread();
			q[i].lca=LCA(q[i].l,q[i].r);
		}
		cnt=1;
		DFS[1]=1;
//		cout<<"????\n";
		dfs(1);
//		cout<<"???"<<endl;
		sort(q,q+m+1,cmp);//O(mlogm)
//		cout<<"??\n";
		int k=0,sum1=1,sum2=2;
		l[q[1].l]++,r[q[1].r]++;
		for(int i=2;i<=m;i++)
		{
//			cout<<"?"<<endl;
			if(q[i].lca==q[i-1].lca)
			{
				sum1++;
				if(l[q[i].r]==0) sum2+=1,l[q[i].r]++;
				if(r[q[i].l]==0) sum2+=1,r[q[i].l]++;
				if(sum1+2>sum2)
				{
					cout<<"No";
					b=0;
					break;
				 } 
				if(q[i].lca==q[i].l)
					flag[++k]=q[i].r;
				if(q[i].lca==q[i].r)
					flag[++k]=q[i].l;
				if(LCA(q[i].l,q[i-1].l)!=q[i].l&&LCA(q[i].l,q[i-1].l)!=q[i-1].l) continue;
				else if(LCA(q[i].r,q[i-1].r)!=q[i].r&&LCA(q[i].r,q[i-1].r)!=q[i-1].r) continue;
				else if(SHO[q[i].l]>SHO[q[i-1].l]&&SHO[q[i].r]<SHO[q[i-1].r]) continue;
				else
				{
					b=0;
					cout<<"No";
					break;
				}
			}
			else
			{
				l.clear(),r.clear();
				l[q[i].l]++,r[q[i].r]++;
				sum1=1,sum2=2;
				for(int i=1;i<=k;i++)
				{
					if(LCA(q[i].l,flag[i])==flag[i]||LCA(q[i].r,flag[i])==flag[i])
					{
						b=0;
						cout<<"No";
						break;
					}
				}
				if(b==1)
				{
					if(q[i].lca==q[i].l)
					flag[++k]=q[i].r;
					if(q[i].lca==q[i].r)
					flag[++k]=q[i].l;
				}
			}
			if(b==0) break;
		 } 
		 if(b==1) cout<<"Yes";
		 cout<<endl;
	}
	return 0;
}
