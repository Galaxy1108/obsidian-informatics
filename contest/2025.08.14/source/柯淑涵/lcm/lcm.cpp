#include <bits/stdc++.h>
using namespace std;
long long T,n,mod,ans1=0;
__int128 z,ans=0,g;
__int128 gcd(__int128 x,__int128 y){
	while(y!=0){
		z=x%y;
		x=y;
		y=z;
	}
	return x;
}
int main(){
	freopen("lcm.in","r",stdin);
	freopen("lcm.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		cin>>n>>mod;
		__int128 f1=1,f2=1,f3=0;
		g=1;
		ans=1;
		for(__int128 i=2;i<=n;i++){
			f1=2*f2+f3;
			f3=f2;
			f2=f1;
			g=g*f1/gcd(g,f1);
			ans+=g*i;
			ans%=__int128(mod);
		}
		ans1=ans;
		cout<<abs(ans1)<<endl;
	}
	return 0;
} 
