#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int a[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("thief.in","r",stdin);
	freopen("thief.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++)cin >> a[i];
	for(int i=1;i<=m;i++){
		int k,l,r;
		cin >> l >> r >> k;
		for(int j=l;j<=r;j++){
			if(k>a[j]){
				k--;
			}
			else if(k<a[j])k++;
		}
		cout << k << '\n';
	} 
	return 0;
}
