#include<bits/stdc++.h>
using namespace std;
#define ll long long
int T;
int n,q;
int aa[200005];
int a,b,c=1;
int main(){
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
cin>>T;
while(T--){
	int l,r;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>aa[i];
	}
	cin>>q;
	for(int i=1;i<=q;i++){
		cin>>l>>r;
		if(l==r) cout<<0<<' '<<aa[l]<<' '<<1<<'\n';
		else{
			b=aa[l];a=aa[l+1]-aa[l];
			cout<<a<<' '<<b<<" "<<c<<'\n';
		}
	}
}
	return 0;
}
