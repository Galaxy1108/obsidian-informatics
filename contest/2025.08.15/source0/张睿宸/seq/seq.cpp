#include<bits/stdc++.h>
#define F(i,a,b) for(int i(a),i##i##end(b);i<=i##i##end;++i)
#define R(i,a,b) for(int i(a),i##i##end(b);i>=i##i##end;--i)
#define ll long long
#define lowbit(i) (i&(-i))
const int MOD=998244353;
using namespace std;
int n,m,v,a[1000001],b[1000001];
int dp[1000001],nxt[1000001],pre[100001];
int ans;
struct tree_array{
	int c[100001];
	inline void add(int x,int k){
		for(;x<=v;x+=lowbit(x)){
			int&qwq(c[x]);
			qwq+=k;
			qwq>=MOD&&(qwq-=MOD);
			qwq<0&&(qwq+=MOD);
		}
		return;
	}
	inline int query(int x){
		int res(0);
		for(;x;x-=lowbit(x)){
			res+=c[x];
			res>=MOD&&(res-=MOD);
		}
		return res;
	}
}qwq;
int main(){
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	F(i,1,n) cin>>a[i],v=max(v,a[i]);
	cin>>m;
	F(i,1,m) cin>>b[i];
	int now(1);
	R(i,n,1){
		dp[i]=now;
		nxt[i]=pre[a[i]],pre[a[i]]=i;
		now+=dp[i]-dp[nxt[i]];
		now>=MOD&&(now-=MOD);
		now<0&&(now+=MOD);
	}
	F(i,1,v) if(pre[i]) qwq.add(i,dp[pre[i]]);
	now=1;
	F(i,1,m){
		ans+=qwq.query(b[i]-1)+1;
		ans>=MOD&&(ans-=MOD);
		ans<0&&(ans+=MOD);
		int qaq(pre[b[i]] + 1);
		for(;now<qaq;++now){
			pre[a[now]]=nxt[now];
			qwq.add(a[now],dp[nxt[now]]-dp[now]);
		}
	}
	cout<<ans;
	return 0;
} 
