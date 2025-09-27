#include<iostream>

using namespace std;
long long ans,maxn,now,n,a[2000086];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++)cin >> a[i];
	for(int i=1;i<=n;i++){
		maxn=a[i];
		now=a[i];
		ans++;
		for(int j=i+1;j<=n;j++){
			maxn=max(maxn,a[j]);
			now^=a[j];
			if(now<=maxn)ans++; 
		}
	} 
	cout << ans;
	return 0;
} 
