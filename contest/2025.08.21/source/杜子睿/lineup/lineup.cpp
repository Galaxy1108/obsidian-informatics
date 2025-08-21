#include<bits/stdc++.h>
using namespace std;
int h[105],a[105],n,id[105];
int main(){
	freopen("lineup.in","r",stdin);
	freopen("lineup.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		h[i]=a[i];
	}
	sort(h+1,h+1+n);
	for(int i=1;i<=n;i++)
		if(!id[h[i]])
			id[h[i]]=i;
	int ans=0;
	for(int i=1;i<=n;i++){
		ans+=abs(i-id[a[i]]);
		id[a[i]]++;
	}
	cout<<ans;
	return 0;
}  
