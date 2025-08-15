#include<bits/stdc++.h>
#define mod 998244353
#define ll long long
using namespace std;
const int N=1000010;
int n,m;
int A[N],B[N];
bool vis[100010];
int b[11];
int tmp[11];
map<ll,bool> mp;
int ans;
bool check(int top){
	for(int i=1;i<=top;i++){
		if(B[i]==tmp[i]) continue;
		if(B[i]<tmp[i]) return false;
		else return true;
	}
	if(top<m) return true;
	else return false;
}
void dfs(int now,int tot){
	if(now>n){
		if(tot==0) return;
		ll sit=0;
		for(int i=1;i<=tot;i++) sit=sit*11+tmp[i];
		if(!check(tot)||mp[sit]) return;
		mp[sit]=1; ans++;
		return;
	}
	dfs(now+1,tot);
	tmp[++tot]=A[now];
	dfs(now+1,tot);
}
void solve1(){
	for(int i=1;i<=n;i++){
		b[i]=A[i];
	}
	sort(b+1,b+n+1);
	int lenb=unique(b+1,b+n+1)-(b+1);
	for(int i=1;i<=n;i++){
		A[i]=lower_bound(b+1,b+lenb+1,A[i])-b;
	}
	for(int i=1;i<=m;i++){
		B[i]=lower_bound(b+1,b+lenb+1,B[i])-b;
	}
	dfs(1,0);
	cout<<ans+1;
}
int main(){
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>A[i];
	cin>>m;
	for(int i=1;i<=m;i++) cin>>B[i];
	if(n<=10) solve1();
	return 0;
}

