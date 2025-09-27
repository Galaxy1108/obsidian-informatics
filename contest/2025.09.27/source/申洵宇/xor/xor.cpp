#include <bits/stdc++.h>
using namespace std;
#define N 100005
int n,a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		static int maxn,xors;maxn=0,xors=0;
		for(int j=i;j<=n;j++){
			xors^=a[j];
			maxn=(a[j]<maxn?maxn:a[j]);
			ans+=(xors<=maxn);
		}
	}
	cout<<ans<<'\n';
	return 0;
}

