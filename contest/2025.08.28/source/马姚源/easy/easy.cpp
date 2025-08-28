#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("easy.in","r",stdin);
	freopen("easy.out","w",stdout);
	int n,q;
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=q;i++){
		int op;
		cin >> op;
		if(op==1){
			int v;
			cin >> v;
			for(int j=1;j<=n;j++){
				a[j]=min(a[j],v);
			}
		}
		if(op==2){
			for(int j=1;j<=n;j++){
				a[j]+=j;
			}
		}
		if(op==3){
			int l,r;
			cin >> l>> r;
			int ans=0;
			for(int j=l;j<=r;j++){
				ans+=a[j];
			}
			cout << ans << "\n";
		}
	}
	return 0;
}


