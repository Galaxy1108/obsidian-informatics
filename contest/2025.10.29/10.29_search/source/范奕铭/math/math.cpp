#include<bits/stdc++.h>
using namespace std;
long long A,B,cnt,ans[1000005],m=1;
long long gcd(long long x,long long y){
	if(y==0) return x;
	return gcd(y,x%y);
}
int main()
{
    freopen("math.in","r",stdin);
    freopen("math.out","w",stdout);
	cin>>A>>B;
	while(1>0){
		if(B<A*m){
			long long k1=A*m-B;
			long long k2=B*m;
			long long k3=gcd(max(k1,k2),min(k1,k2));
			A=k1/k3; B=k2/k3;
			ans[++cnt]=m;
			if(A==1){
				ans[++cnt]=B;
				break;
			}
		}
		m++;
	}
	cout<<cnt<<endl;
	for(int i=1;i<=cnt;i++) cout<<ans[i]<<" ";
	return 0;
}
