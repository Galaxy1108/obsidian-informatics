#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=1e6+5,M=1e6+5;
int n,a[M],b[M],ans;
int s[M],mx; 
signed main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i],mx=max(mx,a[i]),s[a[i]]++;
	}
	for(int i=1;i<=mx;i++) s[i]+=s[i-1];
	for(int i=1;i<=mx;i++){
		int cnt=mx/i,sum=0;
		for(int j=1;j<=cnt;j++) b[j]=s[min(i*(j+1)-1ll,mx)]-s[i*j-1],sum+=b[j]&1;
		if(sum==1) if(b[1]&1) ans+=b[1];
		if(sum==2) for(int j=2;j<=cnt;j++) if((b[j]&1)&&(b[j-1]&1)) ans+=b[j];
	}
	cout<<ans;
	return 0;
}
