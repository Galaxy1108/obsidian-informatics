#include<bits/stdc++.h>
#define ll long long
using namespace std;
int u[2][2005],n;
ll su[2005],mi[2005],ma[2005],lo[2005];
int main(){
	freopen("base.in","r",stdin);
	freopen("base.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i) {
		scanf("%d",&u[0][i]);
	}
	for(int i=1;i<=n;++i) {
		scanf("%d",&u[1][i]);
		lo[i]=lo[i-1]+u[1][i];
	}
	for(int i=1;i<=n;++i){
		su[i]=su[i-1]+u[0][i]+u[1][i];
		mi[i]=min(su[i],mi[i-1]);
	}
	ma[n]=su[n];
	for(int i=n-1;i>=1;--i) {
		ma[i]=max(ma[i+1],su[i]);
	}
	ll maa=-1e10;
	for(int l=2;l<n;++l){
		for(int r=l;r<n;++r){
			maa=max(maa,lo[r]-lo[l-1]+su[l-1]-mi[l-2]+ma[r+1]-su[r]);
		}
	}
	cout<<maa;
	return 0;
}
