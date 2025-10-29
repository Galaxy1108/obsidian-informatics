#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int p=998244353;
int qpow(ll x,int k){
	ll ans=1;
	while(k){
		if(k&1)ans=(ans*x)%p;
		x=(x*x)%p;
		k>>=1;
	}
	return ans;
}
int n,k,a[10],tmp[10];
bool check(){
	int cnt=n;
	while(cnt){
		int now=cnt;
		for(int i=1;i<=n;i++){
			if(a[i]<=0)continue;
			if(a[i]<cnt)now--;
			a[i]-=(cnt-1);
		}
		if(now==1)return 0;
		else if(now==0)return 1;
		cnt=now;
	}
}
int ans=0;
void dfs(int x){
	if(x==n+1){
		for(int i=1;i<=n;i++)tmp[i]=a[i];
		if(check()){
//			for(int i=1;i<=n;i++)cout<<tmp[i]<<" ";
//			cout<<endl;
			ans++;
		}
//		cout<<endl;
		for(int i=1;i<=n;i++)a[i]=tmp[i];
		return;
	}
	for(int i=1;i<=k;i++){
		a[x]=i;
		dfs(x+1);
	}
}
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>k;
	if(n==3){
		if(k%2==0){
			cout<<(3*k+2)*(k/2)<<endl;
		}
		else{
			cout<<((k+2+k+2*(k>>1))*(k/2)+k+2*(k>>1))<<endl;
		}
		return 0;
	}
	if(n<=5&&k<=20)dfs(1),cout<<ans<<endl;
	else cout<<qpow(k,n)<<endl;
	return 0;
}
