#include <bits/stdc++.h>
using namespace std;
int n,m,a[100001],b[100001],sum=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	int t,ma=0;
	int ans=n;
	for(int i=1;i<=n;i++){
		ma=a[i];
		t=a[i];
		for(int j=i+1;j<=n;j++){
			ma=max(ma,a[j]);
			t^=a[j];
			if(t>=ma) ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
} 
/*
5 5 
7 6 1 2 10 
9 11 6 3 12
*/
