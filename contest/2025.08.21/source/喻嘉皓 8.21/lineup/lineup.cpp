#include<bits/stdc++.h>
#define pb push_back
using namespace std;
int n;
int h[51],tmp[51];
vector<int> ad[51];
int cnt[210];
int main(){
	freopen("lineup.in","r",stdin);
	freopen("lineup.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>h[i],tmp[i]=h[i];
	sort(tmp+1,tmp+n+1);
	for(int i=1;i<=n;i++){
		ad[tmp[i]].pb(i);
	} 
	int ans=0;
	for(int i=1;i<=n;i++){
		ans+=abs(i-ad[h[i]][cnt[h[i]]]);
		cnt[h[i]]++;
	}
	cout<<ans;
	return 0;
}

