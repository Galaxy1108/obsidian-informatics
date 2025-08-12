#include <bits/stdc++.h>

using namespace std;

template<typename T>bool get_max(T &a,T b){if(a<b) return a=b,true;return false;}
template<typename T>bool get_min(T &a,T b){if(a>b) return a=b,true;return false;}

vector<long long> ans;
vector<pair<int,int> >ed[100];
vector<pair<long long,long long> >mind[100][100],tmp;
priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > G;
priority_queue<pair<long long,int> >G_;
long long dis[100][100],tr[100][100];

long long sid[100][100];

long long dis1[100],dis2[100];

int f[100][100];
bool vis[100];

vector<long long> calculate_necessary_time(
	int N, int M, long long S, int Q, vector<int> A, vector<int> B,
    vector<long long> L, vector<long long> C, vector<int> U,
    vector<int> V, vector<long long> T)
{
	ans.resize(Q);
	for(int i=0;i<M;i++)
		ed[A[i]].push_back(make_pair(B[i],i)),
		ed[B[i]].push_back(make_pair(A[i],i));
	
	//solve go in days

	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++) dis[i][j]=S*N,vis[j]=false;
		dis[i][i]=0;G.push(make_pair(0ll,i));
		while(!G.empty())
		{
			int v=G.top().second;G.pop();
			if(vis[v]) continue;
			vis[v]=true;
			for(pair<int,int> g:ed[v])
				if(dis[i][v]+L[g.second]<=C[g.second]&&dis[i][g.first]>dis[i][v]+L[g.second])
					G.push(make_pair(dis[i][g.first]=dis[i][v]+L[g.second],g.first));
		}
		for(int j=0;j<N;j++)
			f[i][j]=(dis[i][j]<S?1:N+1);
	}
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++) sid[i][j]=-1,vis[j]=false;
		sid[i][i]=S;G_.push(make_pair(S,i));
		while(!G_.empty())
		{
			int v=G_.top().second;G_.pop();
			if(vis[v]) continue;
			vis[v]=true;
			for(pair<int,int> g:ed[v])
				if(get_max(sid[i][g.first],min(sid[i][v],C[g.second])-L[g.second]))
					G_.push(make_pair(sid[i][g.first],g.first));
		}
	}

	// printf("------\n");
	// for(int i=0;i<N;i++)
	// for(int j=0;j<N;j++)
	// 	printf("%lld%c",dis[i][j]," \n"[j==N-1]);
	// printf("------\n");
	// for(int i=0;i<N;i++)
	// for(int j=0;j<N;j++)
	// 	printf("%lld%c",sid[i][j]," \n"[j==N-1]);
	// printf("------\n");

	for(int i=0;i<N;i++)
		f[i][i]=0;

	for(int k=0;k<N;k++)
	for(int i=0;i<N;i++)
	for(int j=0;j<N;j++)
		f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	for(int i=0;i<N;i++)
	for(int j=0;j<N;j++)
	{
		tr[i][j]=f[i][j]*S;
		for(int k=0;k<N;k++)
			tr[i][j]=min(tr[i][j],f[i][k]*S+dis[k][j]);
	}

	//solve go in one day

	for(int i=0;i<M;i++)
	{
		//A[i]->B[i]
		memset(dis1,0xcf,sizeof(dis1));
		memset(dis2,0x3f,sizeof(dis2));
		dis1[A[i]]=C[i]-L[i],dis2[B[i]]=C[i];
		memset(vis,0,sizeof(vis));
		for(int j=0,mx;j<N;j++)
		{
			mx=-1;
			for(int k=0;k<N;k++)
				if(!vis[k]&&(mx==-1||dis1[mx]<dis1[k]))
					mx=k;
			vis[mx]=true;
			for(pair<int,int> g:ed[mx])
				if(dis1[mx]<=C[g.second]&&dis1[g.first]<dis1[mx]-L[g.second])
					dis1[g.first]=dis1[mx]-L[g.second];
		}
		memset(vis,0,sizeof(vis));
		for(int j=0,mn;j<N;j++)
		{
			mn=-1;
			for(int k=0;k<N;k++)
				if(!vis[k]&&(mn==-1||dis2[mn]>dis2[k]))
					mn=k;
			vis[mn]=true;
			for(pair<int,int> g:ed[mn])
				if(dis2[mn]<=C[g.second]-L[g.second]&&dis2[g.first]>dis2[mn]+L[g.second])
					dis2[g.first]=dis2[mn]+L[g.second];
		}
		for(int x=0;x<N;x++)
		for(int y=0;y<N;y++)
			if(dis1[x]>=0&&dis2[y]<=S)
				mind[x][y].push_back(make_pair(dis1[x],dis2[y]-dis1[x]));
		
		//B[i]->A[i]
		memset(dis1,0xcf,sizeof(dis1));
		memset(dis2,0x3f,sizeof(dis2));
		dis1[B[i]]=C[i]-L[i],dis2[A[i]]=C[i];
		memset(vis,0,sizeof(vis));
		for(int j=0,mx;j<N;j++)
		{
			mx=-1;
			for(int k=0;k<N;k++)
				if(!vis[k]&&(mx==-1||dis1[mx]<dis1[k]))
					mx=k;
			vis[mx]=true;
			for(pair<int,int> g:ed[mx])
				if(dis1[mx]<=C[g.second]&&dis1[g.first]<dis1[mx]-L[g.second])
					dis1[g.first]=dis1[mx]-L[g.second];
		}
		memset(vis,0,sizeof(vis));
		for(int j=0,mn;j<N;j++)
		{
			mn=-1;
			for(int k=0;k<N;k++)
				if(!vis[k]&&(mn==-1||dis2[mn]>dis2[k]))
					mn=k;
			vis[mn]=true;
			for(pair<int,int> g:ed[mn])
				if(dis2[mn]<=C[g.second]-L[g.second]&&dis2[g.first]>dis2[mn]+L[g.second])
					dis2[g.first]=dis2[mn]+L[g.second];
		}
		for(int x=0;x<N;x++)
		for(int y=0;y<N;y++)
			if(dis1[x]>=0&&dis2[y]<=S)
				mind[x][y].push_back(make_pair(dis1[x],dis2[y]-dis1[x]));
	}

	for(int x=0;x<N;x++)
	for(int y=0;y<N;y++)
	if(mind[x][y].size())
	{
		sort(mind[x][y].begin(),mind[x][y].end(),[&](pair<long long,long long> A,pair<long long,long long> B)
		{if(A.first!=B.first) return A.first<B.first;else return A.second>B.second;});
		vector<pair<long long,long long> >().swap(tmp);
		for(pair<long long,long long> &g:mind[x][y])
		{
			while(!tmp.empty()&&tmp.rbegin()->second>g.second) tmp.pop_back();
			tmp.push_back(g);
		}
		swap(tmp,mind[x][y]);
	}

	vector<pair<long long,long long> >::iterator it;

	for(int i=0;i<Q;i++)
	{
		if((it=lower_bound(mind[U[i]][V[i]].begin(),mind[U[i]][V[i]].end(),make_pair(T[i],0ll)))!=mind[U[i]][V[i]].end())
			ans[i]=it->second;
		else ans[i]=(N+1)*S;

		// printf("~~ %d %lld ",i,ans[i]);

		if(T[i]<=sid[V[i]][U[i]])
			get_min(ans[i],S-sid[V[i]][U[i]]);
		
		// printf("%lld ~~\n",ans[i]);
		
		for(int j=0;j<N;j++)
			if(T[i]<=sid[j][U[i]])
				get_min(ans[i],S-T[i]+tr[j][V[i]]);
	}
	return ans;
}

#define getchar() ((p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2))?EOF:*p1++)
char buf[1<<20],*p1=buf,*p2=buf;

namespace solve{

	long long Qread()
	{
		long long x=0;char ch=getchar();
		while(ch<'0'||ch>'9') ch=getchar();
		while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
		return x;
	}
	void Qwrite(long long x)
	{
		if(x>=10) Qwrite(x/10),x%=10;
		putchar('0'+x);
	}

	int N,M,Q;
	long long S;
	vector<int> A,B,U,V;
	vector<long long> T,L,C;

	int main()
	{
		N=Qread(),M=Qread(),S=Qread(),Q=Qread();
		A.resize(M),B.resize(M);
		L.resize(M),C.resize(M);
		U.resize(Q),V.resize(Q),T.resize(Q);
		for(int i=0;i<M;i++)
			A[i]=Qread(),B[i]=Qread(),L[i]=Qread(),C[i]=Qread();
		for(int i=0;i<Q;i++)
			U[i]=Qread(),V[i]=Qread(),T[i]=Qread();
		vector<long long>ans=calculate_necessary_time(N,M,S,Q,A,B,L,C,U,V,T);
		for(int i=0;i<Q;i++)
			Qwrite(ans[i]),putchar('\n');
		return 0;
	}
}
int main()
{
	freopen("route.in","r",stdin);
	freopen("route.out","w",stdout);
	
	return solve::main();
}