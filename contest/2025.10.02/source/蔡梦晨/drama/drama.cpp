#include<bits/stdc++.h>
using namespace std;
#define N 1000005
#define ll long long
ll h[2*N];
int n;
int main(){
	freopen("drama.in","r",stdin);
	freopen("drama.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>h[i];
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			ll mn=h[i],mx=h[i];
			for(int l=i+1;l<=j;l++){
				mn=min(mn,h[l]);
				mx=max(mx,h[l]);
			}
			ans=max(ans,mn*mx*(j-i+1));
		}
	}
	cout<<ans;
	return 0;
}
