#include<bits/stdc++.h>
#define ll long long
#define INF 9991145141919810
using namespace std;
const int N=300010;
int n,m;
ll x[N],a[N];
ll ans=-INF;
void dfs(int now){
	if(now>m){
		ll sum=0;
		for(int i=1;i<=n;i++) sum+=a[i];
		ans=max(ans,sum);	
		return;
	}
	for(int i=1;i<=n;i++){
		ll tmp=a[i];
		a[i]=x[now]-a[i];
		dfs(now+1);
		a[i]=tmp;
	}
}
void clear(){
	for(int i=1;i<=n;i++) a[i]=0;
	ans=0;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	int T;
	cin>>T;
	while(T--){
		cin>>n>>m;
		clear();
		for(int i=1;i<=m;i++){
			cin>>x[i];
		}
		dfs(1);
		cout<<ans<<'\n';
	}
	return 0;
}

