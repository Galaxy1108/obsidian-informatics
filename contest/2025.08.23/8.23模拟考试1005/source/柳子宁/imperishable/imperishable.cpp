#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int Tid,n,Q,x,y,mx;
int a[200010];
long long val[200010];
priority_queue<pair<int,int> > q;
void solve(){
	while(!q.empty()){
		if(a[q.top().second]==q.top().first){
			mx=q.top().first;break;
		}
		else q.pop();
	}
	long long sum=0,ans=0;
	int f=0;
	for(int i=1;i<=n;++i){
		sum+=a[i];
		if(sum>=mx) {f=i;break;}
	}
	for(int i=f;i>=1;--i){
		if(sum-a[i]>=mx) sum-=a[i];
		else ans+=val[i];
	}
	cout<<ans%mod<<'\n';
	return;
}
int main()
{
	freopen("imperishable.in","r",stdin);
	freopen("imperishable.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>Tid>>n;
	val[0]=1;
	for(int i=1;i<=n;++i){
		cin>>a[i],val[i]=val[i-1]*2%mod;
		q.push(make_pair(a[i],i));
	}
	solve();
	cin>>Q;
	for(int i=1;i<=Q;++i){
		cin>>x>>y;
		a[x]=y;
		q.push(make_pair(y,x));
		solve();
	}
	return 0;
}
