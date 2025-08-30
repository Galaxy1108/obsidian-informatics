#include <bits/stdc++.h>
using namespace std;
int Qread()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
	return x;
}
int k;
struct Dp{
	long long f[210];
	bool emp;
	void show()
	{
		for(int i=0;i<=k;i++)
			printf("%d%c",f[i]," \n"[i==k]);
		return;
	}
};
typedef pair<Dp,int> pr;
Dp operator*(Dp A,Dp B)
{
	Dp ret;
	memset(ret.f,0xcf,sizeof(ret.f));
	for(int i=0;i<=k;++i)
	for(int j=k-i;~j;--j)
		ret.f[i+j]=max(ret.f[i+j],A.f[i]+B.f[j]);
	ret.emp=(A.emp||B.emp);
	return ret;
}
Dp operator<<(Dp A,int num)
{
	Dp ret;
	memset(ret.f,0xcf,sizeof(ret.f));
	for(int i=num;i<=k;++i)
		ret.f[i]=A.f[i-num];
	ret.emp=A.emp;
	return ret;
}
Dp operator+(Dp A,int num)
{
	Dp ret;
	for(int i=0;i<=k;++i)
		ret.f[i]=A.f[i]+num;
	ret.emp=A.emp;
	return ret;
}
void merg(Dp &A,Dp B)
{
	for(int i=0;i<=k;++i)
		A.f[i]=max(A.f[i],B.f[i]);
	A.emp&=B.emp;
	return;
}
Dp rem;
struct Point{
	int sta;
}p[510];
vector<int> yz[210];
vector<pr> F[210];
int ys[1000010];
Dp nw[210][2][210];
struct Edge{
	int nxt,poi;
}l[1010];
int cnt;
void add_edge(int u,int v)
{
	l[++cnt].poi=v,l[cnt].nxt=p[u].sta,p[u].sta=cnt;
	l[++cnt].poi=u,l[cnt].nxt=p[v].sta,p[v].sta=cnt;
	return;
}
int n,numb[510];
void dfs(int a,int fa)
{
	int lim=yz[a].size(),mil=0,gl=0,fro=0,too=0;
	int cnt=0;
	memset(nw[a],0xcf,sizeof(nw[a]));
	nw[a][0][lim-1].f[0]=0,nw[a][0][lim-1].emp=false;
	for(int g=p[a].sta,v;g;g=l[g].nxt)
	{
		if((v=l[g].poi)==fa) continue;
		dfs(v,a);
		++cnt;
		too=cnt&1,fro=1-too;
		memset(nw[a][too],0xcf,sizeof(nw[a][too]));
		for(int g=0;g<lim;g++)
			ys[yz[a][g]]=g;
		mil=F[v].size();
		for(int i=0,re;i<lim;++i)
		{
			re=yz[a][i];
			for(int h=0;h<mil;++h)
			{
				rem=F[v][h].first,gl=F[v][h].second;
				merg(nw[a][too][ys[__gcd(gl,re)]],nw[a][fro][i]*rem);
				merg(nw[a][too][i],nw[a][fro][i]*((rem+gl)<<1));
			}
		}
	}
	for(int g=0;g<lim;g++)
		if(!nw[a][cnt&1][g].emp)
			F[a].push_back(make_pair(nw[a][cnt&1][g],yz[a][g]));
//	printf("<%d %d>\n",a,numb[a]);
//	for(int g=0;g<lim;g++)
//	{
//		printf("%d:",F[a][g].second);
//		F[a][g].first.show();
//	}
//	printf("%d %d\n",a,fa);
	return;
}
int i,j;
long long ans;
int main()
{
	freopen("plan.in","r",stdin);
	freopen("plan.out","w",stdout);
	n=Qread(),k=Qread();
	for(i=1;i<n;i++)
		add_edge(Qread(),Qread());
	for(i=1;i<=n;i++)
		numb[i]=Qread();
	for(i=1;i<=n;i++)
	{
		for(j=1;j*j<=numb[i];j++)
			if(numb[i]%j==0)
				yz[i].push_back(j);
		j=yz[i].size()-2;
		if(yz[i].back()*yz[i].back()!=numb[i]) yz[i].push_back(numb[i]/yz[i].back());
		for(;~j;j--)
			yz[i].push_back(numb[i]/yz[i][j]);
//		printf("%d %d\n",i,yz[i].size());
	}
	dfs(1,0);
	j=F[1].size();
	for(i=0;i<j;i++)
		ans=max(ans,F[1][i].first.f[k]+F[1][i].second);
	printf("%lld\n",ans);
	return 0;
}