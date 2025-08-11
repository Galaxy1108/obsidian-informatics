#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
const int mod=1e9+7;
const int N=100010;
int n;
ll h[N],w[N];
bool flag1=1;
ll totw,ans;
ll C2(ll x){
	return (ll)x*(x-1)/2%mod;
}
bool bk[N];
struct node{
	ll x,y;
};
//void solve1(){
//	for(int i=1;i<=n;i++){
//		ll sum=w[i];
//		while(h[i]==h[i+1]){
//			bk[i]=1; i++;//标记直接跳过这个矩形，将这个矩形加到后面 
//			sum+=w[i];
//		}
//		w[i]=sum;
//	}	
//	ll now=totw;
//	int las=0;
//	for(int i=1;i<=n;i++){
//		if(bk[i]) continue;
//		ans+=(C2(now+1)*C2(h[i]+1)%mod-C2(las+1)*C2(w[i]+1)%mod+mod)%mod;
//		ans%=mod;
//		now-=w[i]; las=h[i]; 
//	}
//	cout<<ans;
//}
signed main(){
	freopen("fence.in","r",stdin);
	freopen("fence.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>h[i];
		if(h[i]<h[i-1]) flag1=0;
	} 
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	stack<int> k;
	k.push(0);
	for(int i=1;i<=n+1;i++){
		ll sw=0;
		while(h[k.top()]>h[i]){
			int u=k.top();
			k.pop();
			sw+=w[u]; sw%=mod;
			ans+=((C2(h[u]+1)-C2(max(h[i],h[k.top()])+1))*C2(sw+1)%mod+mod)%mod;
			ans%=mod;
		}
		w[i]+=sw;
		k.push(i);
	}
	cout<<ans;
//	solve1();
	return 0;
}

