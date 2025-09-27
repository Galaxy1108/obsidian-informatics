#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n;
int a[maxn];
int ans;
int xorr,maxx;
int main(){
	freopen("xor.in","r",stdin);freopen("xor.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ans=n;
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			xorr=a[i],maxx=a[i];
			for(int k=i+1;k<=j;k++){
				xorr^=a[k];
				maxx=max(a[k],maxx);
			}
			if(xorr<=maxx){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
} 
