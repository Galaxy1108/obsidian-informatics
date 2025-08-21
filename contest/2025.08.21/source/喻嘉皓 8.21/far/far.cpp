#include<bits/stdc++.h>
#define ll long long
#define add(x,y) x=(x+y)%mod 
#define pb push_back
using namespace std;
const int mod=998244353;
int n,m;
ll L[41],R[41];
int tmp[61];
vector<int> num;
bool check(int num){
	int now=0;
	while(num){
		tmp[++now]=num&1;
		num>>=1;
	}
	while(now<m) tmp[++now]=0;
	for(int i=1;i<=m/2;i++){
		if(tmp[i]!=tmp[m-i+1]) return false;
	}
	return true;
}
ll f[2][(1<<20)],top;
bool flag1=1;
ll Cnt;//回文串数量 
void solve1(){
	ll now=1;
	for(int i=1;i<=n;i++){
		ll ans=now*Cnt%mod;
		cout<<ans<<'\n'; 
		now=now*top%mod;
	}
}
void solve2(){
	for(int i=0;i<top;i++){
		if(check(i)) num.pb(i);
	}
	int now=1,las=0;
	f[now][0]=1;
	for(int i=1;i<=n;i++){
		swap(now,las);
		for(int j=0;j<top;j++){
			f[now][j]=0;
//			cout<<j<<' '<<L[i]<<' '<<R[i]<<'\n';
			for(int k=L[i];k<=R[i];k++){
				add(f[now][j],f[las][j^k]);
//				cout<<(j^k)<<' ';
			}
//			cout<<'\n'<<'\n';
		}
		ll ans=0;
		for(int to:num){
			add(ans,f[now][to]);
		}
		cout<<ans<<'\n';	
	}
}
signed main(){
	freopen("far.in","r",stdin);
	freopen("far.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	if(m&1) Cnt=(1ll<<(m/2+1));
	else Cnt=(1ll<<(m/2));
	for(int i=1;i<=n;i++){
		cin>>L[i]>>R[i];
		if(L[i]!=0) flag1=0;
	}
	top=(1ll<<m)%mod;
	if(flag1) solve1();
	else solve2();
//	solve2();
//	int sum=0;
//	for(int i=0;i<(1<<m);i++){
//		if(check(i)) sum++;
//	} 
//	cout<<sum<<' '<<Cnt;
	return 0;
}

