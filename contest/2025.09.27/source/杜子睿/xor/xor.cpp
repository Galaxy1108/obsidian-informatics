#include<bits/stdc++.h>
using namespace std;
int n,a[100005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	int ans=0;
	for(int i=0;i<n;i++){
		int x=a[i],maxn=a[i];
		ans++;
		for(int j=i+1;j<n;j++){
			x^=a[j];
			maxn=max(maxn,a[j]);
			ans+=(x<=maxn);
		}
	}
	cout<<ans;
	return 0;
}

