#include <bits/stdc++.h>
typedef long long ll;
#define vl vector<ll>
#define pb emplace_back
#define ps emplace
#define ump unordered_map
using namespace std;
constexpr int N=15,mod=1e9+7;
ll n,k;
ump<ll,ll>f[N][2][2];
vl d,s;
struct node{
	int x,fl1,fl2;ll val;
	node(){}
	node(int x,int fl1,int fl2,ll val):x(x),fl1(fl1),fl2(fl2),val(val){}
};
struct nnode{
	int cnt,id;ll val;
	nnode(){}
	nnode(int cnt,int id,ll val):cnt(cnt),id(id),val(val){}
};
bool operator<(nnode x,nnode y){return x.val<y.val;}
queue<node>q;
priority_queue<nnode>qq;
ll ans;
void solve(ll x)
{
	d.resize(14);
	for(int i=1;i<=13;i++)
		d[i]=x%10,x/=10;
	f[13][0][0][1]=1;
	q.ps(13,0,0,1);
	while(!q.empty())
	{
		node u=q.front();
		q.pop();
		if(!u.x)
		{
			if(u.fl1 && u.fl2)s.pb(f[u.x][u.fl1][u.fl2][u.val]);
			continue;
		}
		int st=(!u.fl1)?0:1,ed=(!u.fl2)?d[u.x]:9;
		for(int i=st;i<=ed;i++)
		{
			bool fl1=i||u.fl1,fl2=(i!=d[u.x])||u.fl2;
			ll val=u.val*max(1,i);
			if(!f[u.x-1][fl1][fl2][val])
				q.ps(u.x-1,fl1,fl2,val);
			f[u.x-1][fl1][fl2][val]+=f[u.x][u.fl1][u.fl2][u.val];
		}
	}
}
int main()
{
	freopen("find.in","r",stdin);
	freopen("find.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;n++;
	solve(n);
	sort(s.begin(),s.end(),greater<>());
//	for(int i=0;i<s.size();i++)
//	{
//		cout<<s[i]<<' ';
//	}
	for(int i=0;i<s.size();i++)
		qq.ps(0,i,s[0]*s[i]);
	while(k-- && !qq.empty())
	{
		nnode u=qq.top();
		qq.pop();
		ans=(ans+u.val)%mod;
		u.cnt++;
		if(u.cnt==s.size())continue;
		qq.ps(u.cnt,u.id,s[u.id]*s[u.cnt]);
	}
	cout<<ans;
	return 0;
}
