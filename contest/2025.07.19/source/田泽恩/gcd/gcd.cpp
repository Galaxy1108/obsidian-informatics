#include <bits/stdc++.h>
using namespace std;
int T,a,b,c,d,k;
long long ans;
int gcd(int x,int y){
	if(!y) return x;
	return gcd(y,x%y);
}
int main(){
	freopen("gcd.in","r",stdin);
	freopen("gcd.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		cin>>a>>b>>c>>d>>k;
		for(int i=(a+k-1)/k;i<=b/k;++i){
			for(int j=(c+k-1)/k;j<=d/k;++j) ans+=gcd(i,j)==1;
		}
		cout<<ans<<endl;
	}
	return 0;
}
