#include <bits/stdc++.h>
using namespace std;
int n,m,a[514114],l,r,c;
int main(){
	freopen("thief.in","r",stdin);
	freopen("thief.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	while(m--){
		cin>>l>>r>>c;
		for(int i=l;i<=r;++i){
			if(a[i]>c) ++c;
			else if(a[i]<c) --c;
		}
		cout<<c<<endl;
	}
	return 0;
}
