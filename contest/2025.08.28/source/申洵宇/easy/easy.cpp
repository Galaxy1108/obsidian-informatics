#include <bits/stdc++.h>
using namespace std;
#define N 200005
int n,q;
long long a[N];
int main(){
	freopen("easy.in","r",stdin);
	freopen("easy.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int op,l,r;
	long long v,ans=0;
	while(q--){
		cin>>op;
		if(op==1){
			cin>>v;
			for(int i=1;i<=n;i++){
				a[i]=min(a[i],v);
			}
		}
		else if(op==2){
			for(int i=1;i<=n;i++){
				a[i]+=i;
			}
		}
		else{
			cin>>l>>r;
			ans=0;
			for(int i=l;i<=r;i++)ans+=a[i];
			cout<<ans<<'\n';
		}
	}
	return 0;
}