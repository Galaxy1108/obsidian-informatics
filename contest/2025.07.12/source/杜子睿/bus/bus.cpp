#include<bits/stdc++.h>
using namespace std;
int n,m,x,t,w;
long long s[200005],d[200005],c[200005],ans;
int main(){
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>x>>n>>m>>w>>t;
	for(int i=0;i<n;i++)
		cin>>s[i];
	for(int i=0;i<m;i++){
		cin>>d[i]>>c[i];
		ans+=c[i];
	}
	cout<<ans;
	return 0;
}

