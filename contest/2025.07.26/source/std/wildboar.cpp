#include <bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
int Qread()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
	return x;
}
inline bool get_min(long long &a,long long b){if(a>b) return a=b,true;return false;}

int N,M,T,L,P;
typedef pair<int,int> pr;
vector<pr> ed[6010];
int A[2010],B[2010],C[2010];
int vis[6010];long long dis[6010];int fro[6010],il,val[6010];
priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > >Q;

void add_edge(int u,int v,int w){ed[u].push_back(make_pair(v,w));}

struct Path{int s,t;long long val;};
bool operator<(Path A,Path B){return A.val<B.val;}
vector<Path> s[2010][2010];
Path p[2010][2010][4];

struct Matrix{
	long long f[4][4];
	long long* operator[](int i){return f[i];}
	void modify(int A1,int A2,int A3)
	{
		for(int i=0;i<4;i++) for(int j=0;j<4;j++)
			f[i][j]=(p[A1][A2][i].t==p[A2][A3][j].s?inf:p[A1][A2][i].val);
	}
};
Matrix operator*(Matrix A,Matrix B)
{
	Matrix C;memset(C.f,0x3f,sizeof(C.f));
	for(int i=0;i<4;i++) for(int j=0;j<4;j++) for(int k=0;k<4;k++)
		get_min(C[i][k],A[i][j]+B[j][k]);
	return C;
}

int X[100010];

#define ls (pos<<1)
#define rs (pos<<1|1)
#define mid (l+r>>1)
namespace Sege{
	Matrix s[400010];
	int loc[100010];
	void init(int pos,int l,int r)
	{
		if(l==r) loc[l]=pos,s[pos].modify(X[l],X[l+1],X[l+2]);
		else init(ls,l,mid),init(rs,mid+1,r),s[pos]=s[ls]*s[rs];
	}
	void update(int x)
	{
		s[loc[x]].modify(X[x],X[x+1],X[x+2]);
		for(int pos=(loc[x]>>1);pos;pos>>=1)
			s[pos]=s[ls]*s[rs];
	}
	long long get_ans()
	{
		long long ret=inf;
		for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			get_min(ret,s[1][i][j]+p[X[L-1]][X[L]][j].val);
		if(ret==inf) ret=-1;
		return ret;
	}
}
#undef ls
#undef rs
#undef mid

int rea;
long long ddd;

void Dijk(int S)
{
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[S]=0;Q.push(make_pair(0ll,S));
	while(!Q.empty())
	{
		rea=Q.top().second,ddd=Q.top().first;Q.pop();
		if(vis[rea]==2) continue;
		if(vis[rea]==0)
		{
			if(rea<=N)
			{
				if(fro[rea]<=N+M) il=fro[rea]+M;
				else il=fro[rea]-M;
			}
			else il=0;
			for(pr v:ed[rea])
				if(v.first!=il)
				{
					Q.push(make_pair(ddd+v.second,v.first));
					if(get_min(dis[v.first],ddd+v.second)) fro[v.first]=rea;
				}
				else val[rea]=v.second;
			vis[rea]=1;
		}
		else
		{
			if(rea<=N)
			{
				if(fro[rea]<=N+M) il=fro[rea]+M;
				else il=fro[rea]-M;
				Q.push(make_pair(ddd+val[rea],il));
				if(get_min(dis[il],ddd+val[rea])) fro[il]=rea;
			}
			vis[rea]=2;
		}
	}
}

int main()
{
	freopen("wildboar.in","r",stdin);
	freopen("wildboar.out","w",stdout);

	N=Qread(),M=Qread(),T=Qread(),L=Qread();
	for(int i=1;i<=M;i++)
	{
		A[i]=Qread(),B[i]=Qread(),C[i]=Qread();
		add_edge(A[i],N+i,0),add_edge(N+i,B[i],C[i]);
		add_edge(B[i],N+M+i,0),add_edge(N+M+i,A[i],C[i]);
	}

	for(int i=1;i<=M;i++)
	{
		Dijk(N+i);

		for(int j=1;j<=M;j++)
		{
			s[A[i]][B[j]].push_back(Path{i,j,dis[N+j]+C[j]});
			s[A[i]][A[j]].push_back(Path{i,j,dis[N+M+j]+C[j]});
		}

		Dijk(N+M+i);

		for(int j=1;j<=M;j++)
		{
			s[B[i]][B[j]].push_back(Path{i,j,dis[N+j]+C[j]});
			s[B[i]][A[j]].push_back(Path{i,j,dis[N+M+j]+C[j]});
		}
	}

	int siz;
	for(int i=1;i<=N;i++)
	for(int j=1;j<=N;j++)
	{
		sort(s[i][j].begin(),s[i][j].end());
		p[i][j][0]=s[i][j][0];
		siz=s[i][j].size();
		p[i][j][1]=p[i][j][2]=p[i][j][3]=Path{0,0,inf};
		for(int k=1;k<siz;k++)
			if(s[i][j][k].s!=p[i][j][0].s&&s[i][j][k].t!=p[i][j][0].t)
			{
				p[i][j][1]=s[i][j][k];
				break;
			}
		for(int k=1;k<siz;k++)
			if(s[i][j][k].s!=p[i][j][0].s&&s[i][j][k].t!=p[i][j][1].t)
			{
				p[i][j][2]=s[i][j][k];
				break;
			}
		for(int k=1;k<siz;k++)
			if(s[i][j][k].s!=p[i][j][1].s&&s[i][j][k].t!=p[i][j][0].t)
			{
				p[i][j][3]=s[i][j][k];
				break;
			}
	}

	for(int i=1;i<=L;i++)
		X[i]=Qread();
	if(L>=3) Sege::init(1,1,L-2);
	for(int i=1;i<=T;i++)
	{
		P=Qread();
		X[P]=Qread();
		if(P-2>=0) Sege::update(P-2);
		if(P-1>=0&&P+1<=L) Sege::update(P-1);
		if(P+2<=L) Sege::update(P);
		printf("%lld\n",Sege::get_ans());
	}
	return 0;
}