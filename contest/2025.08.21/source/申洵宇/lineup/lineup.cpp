#include <bits/stdc++.h>
using namespace std;
constexpr int N=55,V=205;
int n,cnt[V];
pair<int,int>a[N],b[N];
int main(){
	freopen("lineup.in","r",stdin);
	freopen("lineup.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].first;
		a[i].second=++cnt[a[i].first];
		b[i]=a[i];
	}
	sort(b+1,b+n+1);
	int ans=0;
	for(int i=1;i<=n;i++){
		ans+=abs((lower_bound(b+1,b+n+1,a[i])-b)-i);
	}
	cout<<ans;
	return 0;
}

