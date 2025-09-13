#include <bits/stdc++.h>
#define vi vector<int>
#define pb emplace_back
using namespace std;
constexpr int N=305;
int n,x,y;
int ans[N][N];
bool fl,vis[N*N];
struct BIT{
	vi a;
	inline void clr(){for(int i=0;i<=n*n;i++)a[i]=0;}
	inline void init(){a.resize(n*n+1),clr();}
	inline int lowbit(int x){return x&-x;}
	inline void add(int x){while(x<=n*n)a[x]++,x+=lowbit(x);}
	inline int ask(int x){int res=0;while(x)res+=a[x],x-=lowbit(x);return res;}
}tr;
inline int calc(vi& a)
{
	int res=0;
	tr.clr();
	for(int i=0;i<a.size();i++)
		res+=i-tr.ask(a[i]),tr.add(a[i]);
	return res;
}
void dfs(int x,int y)
{
	if(fl)return;
	if(x==n && y==n+1)
	{
		vi a,b;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				a.pb(ans[i][j]);
		for(int j=1;j<=n;j++)
			for(int i=1;i<=n;i++)
				b.pb(ans[i][j]);
		if(calc(a)==::x && calc(b)==::y)
			fl=1;
		return;
	}
	if(y==n+1)
		return void(dfs(x+1,1));
	for(int i=1;i<=n*n && !fl;i++)
		if(!vis[i] && !fl)
			vis[i]=1,ans[x][y]=i,dfs(x,y+1),vis[i]=0;
}
int main()
{
//	freopen("matrixcascade.in","r",stdin);
//	freopen("matrixcascade.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T;cin>>T;
	while(T--)
	{
		cin>>n>>x>>y;
		if(x==y && x==0)
		{
			if(n==1)
				cout<<"YES\n1\n";
			else
				cout<<"NO\n";
			continue;
		}
		fl=0;
		tr.init();
		dfs(1,1);
		if(fl)
		{
			cout<<"YES\n";
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					cout<<ans[i][j]<<(j==n?'\n':' ');
		}
		else
			cout<<"NO\n";
	}
	return 0;
}
