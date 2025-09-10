#include <bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
long long n,k,a[1145][1145],ans;
priority_queue<long long> q;
int solve(int x){
	int res=1;
	while(x){
		res*=x%10;
		x/=10;
	}
	return res;
}
int main(){
	freopen("find.in","r",stdin);
	freopen("find.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			a[solve(i)][solve(j)]++;
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j) q.push(a[i][j]);
	}
	for(int i=1;i<=k;++i){
		ans=(ans+q.top())%mod;
		q.pop();
	}
	cout<<ans;
	return 0;
}
